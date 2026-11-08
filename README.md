# Header-Only Scratch Lexer

This serves as replacement for stb\_lexer.

## API

```c
int lex_next_tok(Lexer *lexer, Token *tok);
void lex_init(Lexer *lexer, const char *source);
void lex_init_sv(Lexer *lexer, StringView source);
const char* lex_stringify_token_type(TokenType type);
``` 
## Usage

```c
#include <stdio.h>

#define LEX_IMPLEMENTATION
#include "lex.h"

int main(void)
{
    char buffer[4096];
    FILE *f = fopen("test.c", "r");
    size_t size = fread(buffer, 1, sizeof(buffer), f);

    Lexer lexer;
    lex_init_sv(&lexer, sv(buffer, size));

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

    return 0;
}
``` 
