# Header-Only Scratch Lexer

> [!WARNING]
> This lexer is work in progress! Anything can change at any moment without any notice! Use this lexer at your own risk!

This serves as an scratch lexer for quickly prototyping parsers.
It _can_ recoginize all keywords of C up to C11.
However if such behavior is unwanted and all keywords should be recognized as identifier the `LEX_NO_KEYWORDS` macro should be defined _before_ including the header.

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

// #define LEX_NO_KEYWORDS
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

## Testing

I validate my lexer against the clang lexer.
I wrote some C files with increasing complexity and the run `clang -cc1 -dump-tokens ...` on the file and saved the output in the `.expected` files.
The output of the clang lexer is then parsed by `test.c` and validated against my lexer output.
This test set is by no means complete and work in progress.
