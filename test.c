#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define LEX_IMPLEMENTATION
#include "lex.h"

#include "clang_mapping.h"

#define shift_args(argc, argv) ((argc)--, *(argv)++)
#define assert_test(cond, file, line, context) \
    do { \
        if(!(cond)) { \
            printf("Assertion '%s' failed at %s:%zu for %s\n", #cond, file, line, context); \
            abort(); \
        } \
    } while(0)

int main(int argc, char **argv)
{
    shift_args(argc, argv);

    while(argc > 0)
    {
        const char *path = shift_args(argc, argv);
        FILE *f = fopen(path, "r");
        assert(f);
        fseek(f, 0, SEEK_END);
        int size = ftell(f);
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

        // TODO clang translation

        Token tok;
        do
        {
            lex_next_tok(&lexer, &tok);
            // TODO convert this to StringViews
            char expected_line[4096];
            char context[4096];
            assert(fgets(expected_line, sizeof(expected_line), expected_f));
            memcpy(context, expected_line, sizeof(expected_line));
            int tok_count = 0;
            
            char *slice = strtok(expected_line, " \t");
            while(slice)
            {
                const ClangMapping *mapping = clang_lookup_function(slice, strlen(slice));
                if(tok_count == 0 && mapping == NULL)
                {
                    printf("Non registered mapping: %s\n", lex_stringify_token_type(tok.type));
                }

                if(mapping) 
                {
                    assert_test(mapping->type == tok.type, path, tok.loc.row, context);
                    if(tok.type == TOK_EOF) break;
                }
                else if(0 == strncmp(slice, "Loc=", 4))
                {
                    size_t expected_row, expected_col;
                    assert(sscanf(slice, "Loc=<%*[^:]:%zu:%zu>", &expected_row, &expected_col) == 2);
                    assert_test(tok.loc.row + 1 == expected_row, path, expected_row, context);
                    assert_test(tok.loc.col + 1 == expected_col, path, expected_row, context);
                }
                slice = strtok(NULL, " \t");
                tok_count++;
            }


        } while(tok.type != TOK_EOF && tok.type != TOK_ERR);

        fclose(f);
        fclose(expected_f);
        free(buf);
    }

    return 0;
}
