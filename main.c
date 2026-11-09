#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define LEX_NO_KEYWORDS
#define LEX_IMPLEMENTATION
#include "lex.h"

int main(void)
{
    const char *path = "test.c";
    FILE *f = fopen(path, "r");
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

    return 0;
}
