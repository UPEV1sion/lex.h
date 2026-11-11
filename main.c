#include <stdio.h>
#include <stdlib.h>

#define LEX_IMPLEMENTATION
#include "lex.h"

#include <assert.h>

#define shift_args(argc, argv) ((argc)--, *(argv)++)

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
        FILE *f_expected = fopen(path, "r");
        assert(f_expected);

        // TODO clang translation

        Token tok;
        do
        {
            char expected[4096];
            assert(fgets(expected, sizeof(expected), f_expected));
            lex_next_tok(&lexer, &tok);
            char actual[4096];
            snprintf(actual, sizeof(actual), "%s:%zu:%zu:%s: %.*s\n", 
                    path,
                    tok.loc.row, 
                    tok.loc.col, 
                    lex_stringify_token_type(tok.type), 
                    (int) tok.lexeme.len, 
                    tok.lexeme.data
            );
            assert(strcmp(expected, actual) == 0);
            printf("%s:%zu:%zu:%s: %.*s\n", 
                    path,
                    tok.loc.row, 
                    tok.loc.col, 
                    lex_stringify_token_type(tok.type), 
                    (int) tok.lexeme.len, 
                    tok.lexeme.data
            );

        } while(tok.type != TOK_EOF && tok.type != TOK_ERR);

        fclose(f);
        fclose(f_expected);
        free(buf);
    }

    return 0;
}
