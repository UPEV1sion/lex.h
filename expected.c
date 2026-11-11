#define LEX_IMPLEMENTATION
#include "lex.h"

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#define shift_args(argc, argv) ((argc)--, *(argv)++)

int main(int argc, char **argv)
{
    shift_args(argc, argv);

    puts("--------------------");
    while(argc > 0)
    {
        const char *path = shift_args(argc, argv);
        puts(path);
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

        Token tok;
        do
        {
            lex_next_tok(&lexer, &tok);

            printf("%zu:%zu:%s: %.*s\n", 
                    tok.loc.row, 
                    tok.loc.col, 
                    lex_stringify_token_type(tok.type), 
                    (int) tok.lexeme.len, 
                    tok.lexeme.data
                  );

        } while(tok.type != TOK_EOF && tok.type != TOK_ERR);

        fclose(f);
        free(buf);
        puts("--------------------");
    }

    return 0;
}
