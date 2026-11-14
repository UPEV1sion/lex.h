#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>

#define LEX_IMPLEMENTATION
#include "../lex.h"

#include "clang_mapping.h"

#define shift_args(argc, argv) ((argc)--, *(argv)++)
#define assert_test(cond, file, line, context) \
    do { \
        if(!(cond)) { \
            printf("Assertion '%s' failed at %s:%zu for %s\n", #cond, file, line, context); \
            exit(1); \
        } \
    } while(0)

StringView sv_field(StringView *sv)
{
    while(sv->len > 0 && isspace((unsigned char) sv->data[0]))
    {
        sv->data++;
        sv->len--;
    }

    if(sv->len == 0) return (StringView) {0};

    const char *start = sv->data;
    size_t i = 0;
    char quote = 0;

    while(i < sv->len)
    {
        char c = sv->data[i];

        if(quote)
        {
            bool closes = (i + 1 >= sv->len) || isspace((unsigned char) sv->data[i + 1]);
            if(c == quote && closes) quote = 0;
        }
        else if(isspace((unsigned char) c))
        {
            break;
        }
        else if(c == '\'' || c == '"')
        {
            quote = c;
        }

        i++;
    }

    StringView field = { .data = start, .len = i };

    sv->data += i;
    sv->len  -= i;

    return field;
}


bool sv_eq(StringView sv1, StringView sv2)
{
    return sv1.len == sv2.len && strncmp(sv1.data, sv2.data, sv1.len) == 0;
}

int main(int argc, char **argv)
{
    shift_args(argc, argv);

    while(argc > 0)
    {
        const char *path = shift_args(argc, argv);
        FILE *f = fopen(path, "r");
        assert(f);
        fseek(f, 0, SEEK_END);
        long size = ftell(f);
        fseek(f, 0, SEEK_SET);

        char *buf = malloc(size + 1);
        size_t read = fread(buf, 1, size, f);
        assert(read == (size_t) size);
        buf[size] = 0;

        Lexer lexer;
        lex_init_sv(&lexer, sv(buf, size));

        char expected_path[1024];
        snprintf(expected_path, sizeof(expected_path), "%s.expected", path); 
        FILE *expected_f = fopen(expected_path, "r");
        assert(expected_f);

        Token tok;
        do 
        {
            lex_next_tok(&lexer, &tok);
            if(TOK_EOF == tok.type) break;
            char expected_line[4096];
            assert(fgets(expected_line, sizeof(expected_line), expected_f));

            StringView expected_line_sv = sv(expected_line, strlen(expected_line));

            StringView tokens[64];
            size_t tok_count = 0;

            while (expected_line_sv.len > 0) 
            {
                assert(tok_count < (sizeof(tokens)/sizeof(tokens[0])));
                StringView slice = sv_field(&expected_line_sv);
                if (slice.len > 0) tokens[tok_count++] = slice;
            }

            assert(tok_count >= 3);
            StringView type_sv    = tokens[0];
            StringView literal_sv = tokens[1];
            StringView loc_sv     = tokens[tok_count - 1];

            const ClangMapping *mapping = clang_lookup_function(type_sv.data, type_sv.len);
            assert_test(mapping != NULL, path, tok.loc.row, expected_line);
            assert_test(mapping->type == tok.type, path, tok.loc.row, expected_line);

            // strip quotes...
            assert(literal_sv.len >= 2);
            literal_sv.data += 1;
            literal_sv.len -= 2;
            assert_test(sv_eq(literal_sv, tok.lexeme), path, tok.loc.row, expected_line);

            const bool starts_with_loc = loc_sv.len >= 4 && strncmp(loc_sv.data, "Loc=", 4) == 0;
            assert_test(starts_with_loc, path, tok.loc.row, expected_line);

            size_t expected_row, expected_col;
            const int scanned = sscanf(loc_sv.data, "Loc=<%*[^:]:%zu:%zu>", &expected_row, &expected_col);
            assert(scanned == 2);

            assert_test(tok.loc.row + 1 == expected_row, path, expected_row, expected_line);
            assert_test(tok.loc.col + 1 == expected_col, path, expected_row, expected_line);
        } 
        while(tok.type != TOK_EOF && tok.type != TOK_ERR);

        fclose(f);
        fclose(expected_f);
        free(buf);

        printf("Test for file '%s' succeed\n", path);
    }

    return 0;
}
