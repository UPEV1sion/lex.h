m4_dnl avoid accidential replacements
m4_changequote($[, ]$)m4_dnl
/*  lex.h 3.0.0 - lexer for creating languages with C-like grammar

Quick Example:

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
    lex_init_sv(&lexer, lex_sv(buffer, size));

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

Flags:

- LEX_IMPLEMENTATION: include the implementations of the declarations.
  By default it acts as a normal C header. See https://github.com/nothings/stb/blob/f58f558c120e9b32c217290b80bad1a0729fbb2c/docs/stb_howto.txt for more information.

- LEX_NO_KEYWORDS: do not recoginize C keywords and output them as identifier.

Redefinable Macros:

- LEXDEF: prepend things to function declarations. Most common usecase is `#define LEXDEF static inline`

*/

#ifndef LEX_H_
#define LEX_H_

#include <ctype.h>
#include <stddef.h>
#include <stdbool.h>
#include <string.h>

#ifndef LEXDEF
#define LEXDEF
#endif // LEXDEF

#define TOKEN_TYPE_LIST \
    /* SEPARATORS */ \
    X(TOK_OPAREN) \
    X(TOK_CPAREN) \
    X(TOK_OBRACE) \
    X(TOK_CBRACE) \
    X(TOK_OBRACKET) \
    X(TOK_CBRACKET) \
    X(TOK_SEMI) \
    /* KEYWORDS */ \
    X(TOK_AUTO) \
    X(TOK_BREAK) \
    X(TOK_CASE) \
    X(TOK_CHAR) \
    X(TOK_CONST) \
    X(TOK_CONTINUE) \
    X(TOK_DEFAULT) \
    X(TOK_DO) \
    X(TOK_DOUBLE) \
    X(TOK_ELSE) \
    X(TOK_ENUM) \
    X(TOK_EXTERN) \
    X(TOK_FLOAT) \
    X(TOK_FOR) \
    X(TOK_GOTO) \
    X(TOK_IF) \
    X(TOK_INT) \
    X(TOK_LONG) \
    X(TOK_REGISTER) \
    X(TOK_RETURN) \
    X(TOK_SHORT) \
    X(TOK_SIGNED) \
    X(TOK_SIZEOF) \
    X(TOK_STATIC) \
    X(TOK_STRUCT) \
    X(TOK_SWITCH) \
    X(TOK_TYPEDEF) \
    X(TOK_UNION) \
    X(TOK_UNSIGNED) \
    X(TOK_VOID) \
    X(TOK_VOLATILE) \
    X(TOK_WHILE) \
    X(TOK__BOOL) \
    X(TOK__COMPLEX) \
    X(TOK__IMAGINARY) \
    X(TOK_INLINE) \
    X(TOK_RESTRICT) \
    X(TOK__ALIGNAS) \
    X(TOK__ALIGNOF) \
    X(TOK__ATOMIC) \
    X(TOK__GENERIC) \
    X(TOK__NORETURN) \
    X(TOK__STATIC_ASSERT) \
    X(TOK__THREAD_LOCAL) \
    /* OPERATORS */ \
    X(TOK_DOT) \
    X(TOK_ELLIPSIS) \
    X(TOK_ARROW) \
    X(TOK_QUESTION) \
    X(TOK_COLON) \
    X(TOK_COMMA) \
    X(TOK_PLUS) \
    X(TOK_MINUS) \
    X(TOK_STAR) \
    X(TOK_SLASH) \
    X(TOK_MOD) \
    X(TOK_INC) \
    X(TOK_DEC) \
    X(TOK_EQ) \
    X(TOK_NE) \
    X(TOK_GT) \
    X(TOK_LT) \
    X(TOK_GE) \
    X(TOK_LE) \
    X(TOK_BANG) \
    X(TOK_AND_AND) \
    X(TOK_OR_OR) \
    X(TOK_TILDE) \
    X(TOK_AND) \
    X(TOK_OR) \
    X(TOK_XOR) \
    X(TOK_LSHIFT) \
    X(TOK_RSHIFT) \
    X(TOK_ASSIGN) \
    X(TOK_PLUS_ASSIGN) \
    X(TOK_MINUS_ASSIGN) \
    X(TOK_STAR_ASSIGN) \
    X(TOK_SLASH_ASSIGN) \
    X(TOK_MOD_ASSIGN) \
    X(TOK_AND_ASSIGN) \
    X(TOK_OR_ASSIGN) \
    X(TOK_XOR_ASSIGN) \
    X(TOK_LSHIFT_ASSIGN) \
    X(TOK_RSHIFT_ASSIGN) \
    /* LITERALS */ \
    X(TOK_NUM_LIT) \
    X(TOK_CHAR_LIT) \
    X(TOK_STR_LIT) \
    /* IDENTIFIER */ \
    X(TOK_ID) \
    /* SPECIAL */ \
    X(TOK_EOF) \
    X(TOK_ERR)

typedef enum {
    #define X(name) name,
        TOKEN_TYPE_LIST
    #undef X
} TokenType;

typedef struct {
    const char *data;
    size_t len;
} StringView;

#define lex_sv(data1, len1) ((StringView) {.data = data1, .len = len1 })
#define lex_sv_lit(data1) ((StringView) {.data = data1, .len = sizeof(data1) - 1})

typedef struct {
    size_t col;
    size_t row;
} Location;

typedef struct {
    TokenType type;
    StringView lexeme;
    Location loc;
} Token;

typedef struct {
    StringView input;
    Location loc;
    Location tok_start_loc;
    size_t tok_start_offset;
    size_t offset;
} Lexer;

LEXDEF void lex_next_tok(Lexer *lexer, Token *tok);
LEXDEF void lex_init(Lexer *lexer, const char *source);
LEXDEF void lex_init_sv(Lexer *lexer, StringView source);
LEXDEF const char* lex_stringify_token_type(TokenType type);

#ifdef LEX_IMPLEMENTATION

// GPERF code start

m4_include($[keywords.h]$)m4_dnl
m4_dnl
// GPERF code end

LEXDEF Token lex__generic_tok(Lexer *lexer, TokenType type, StringView lexeme)
{
    return (Token) {
        .type = type,
        .lexeme = lexeme,
        .loc = lexer->tok_start_loc,
    };
}

LEXDEF Token lex__make_tok(Lexer *lexer, TokenType type)
{
    return lex__generic_tok(
               lexer,
               type,
               lex_sv(lexer->input.data + lexer->tok_start_offset, lexer->offset - lexer->tok_start_offset)
           );
}

LEXDEF Token lex__error_tok(Lexer *lexer, StringView err_msg)
{
    return lex__generic_tok(lexer, TOK_ERR, err_msg);
}

LEXDEF bool lex__is_end(Lexer *lexer)
{
    return lexer->offset >= lexer->input.len;
}

LEXDEF char lex__peek_at(Lexer *lexer, size_t n)
{
    if(lexer->offset + n >= lexer->input.len) return 0;
    return lexer->input.data[lexer->offset + n];
}

LEXDEF char lex__peek(Lexer *lexer)
{
    return lex__peek_at(lexer, 0);
}

LEXDEF char lex__peek_next(Lexer *lexer)
{
    return lex__peek_at(lexer, 1);
}

LEXDEF char lex__advance(Lexer *lexer)
{
    if(lex__is_end(lexer)) return 0;
    const char c = lexer->input.data[lexer->offset++];
    if('\n' == c)
    {
        lexer->loc.row++;
        lexer->loc.col = 0;
    }
    else
    {
        lexer->loc.col++;
    }
    return c;
}

LEXDEF bool lex__match(Lexer *lexer, char expected)
{
    if(lex__is_end(lexer)) return false;
    if(lexer->input.data[lexer->offset] != expected) return false;
    lex__advance(lexer);
    return true;
}

LEXDEF bool lex__expect(Lexer *lexer, char expected, StringView err_msg, Token *tok)
{
    if(lex__is_end(lexer) || lexer->input.data[lexer->offset] != expected)
    {
        *tok = lex__error_tok(lexer, err_msg);
        return false;
    }

    lex__advance(lexer);
    return true;
}

LEXDEF int lex__trim_left(Lexer *lexer, Token *tok)
{
    for(;;)
    {
        while(isspace((unsigned char) lex__peek(lexer)))
        {
            lex__advance(lexer);
        }

        size_t comment_start_offset = lexer->offset;
        Location comment_start_loc = lexer->loc;

        if('/' == lex__peek(lexer))
        {
            if('/' == lex__peek_next(lexer))
            {
                lex__advance(lexer);
                lex__advance(lexer);
                while(!lex__is_end(lexer) && '\n' != lex__peek(lexer)) lex__advance(lexer);
            }
            else if('*' == lex__peek_next(lexer))
            {
                bool closed = false;
                lex__advance(lexer);
                lex__advance(lexer);
                while(!lex__is_end(lexer))
                {
                    if('*' == lex__peek(lexer) && '/' == lex__peek_next(lexer))
                    {
                        lex__advance(lexer);
                        lex__advance(lexer);
                        closed = true;
                        break;
                    }
                    else
                    {
                        lex__advance(lexer);
                    }
                }
                if(!closed)
                {
                    lexer->tok_start_offset = comment_start_offset;
                    lexer->tok_start_loc = comment_start_loc;
                    *tok = lex__error_tok(lexer, lex_sv_lit("Unterminated multiline comment."));
                    return 1;
                }
            }
            else
            {
                break;
            }
        }
        else
        {
            break;
        }
    }

    return 0;
}

LEXDEF bool lex__is_id(char c)
{
    return isalpha((unsigned char) c) || '_' == c;
}

LEXDEF TokenType lex__lookup_keyword(Lexer *lexer)
{
    const Lex__KeywordEntry *entry = lex__lookup_function(lexer->input.data + lexer->tok_start_offset, lexer->offset - lexer->tok_start_offset);
    if(entry) return entry->id;
    return TOK_ID;
}

LEXDEF Token lex__id(Lexer *lexer)
{
    while(lex__is_id(lex__peek(lexer)) || isdigit((unsigned char) lex__peek(lexer))) lex__advance(lexer);
#ifndef LEX_NO_KEYWORDS
    return lex__make_tok(lexer, lex__lookup_keyword(lexer));
#else
    return lex__make_tok(lexer, TOK_ID);
#endif // LEX_NO_KEYWORDS
}

LEXDEF Token lex__number(Lexer *lexer)
{
    for(;;)
    {
        const char c = lex__peek(lexer);
        const char n = lex__peek_next(lexer);
        if(('e' == tolower((unsigned char) c) || 'p' == tolower((unsigned char) c)) && ('+' == n || '-' == n))
        {
            lex__advance(lexer);
            lex__advance(lexer);
        }
        else if(isalnum((unsigned char) c) || '_' == c || '.' == c)
        {
            lex__advance(lexer);
        }
        else
        {
            break;
        }
    }
    return lex__make_tok(lexer, TOK_NUM_LIT);
}

LEXDEF Token lex__string(Lexer *lexer)
{
    while ('"' != lex__peek(lexer) && !lex__is_end(lexer))
    {
        if('\n' == lex__peek(lexer)) return lex__error_tok(lexer, lex_sv_lit("Multiline strings are not supported."));
        lex__match(lexer, '\\');
        lex__advance(lexer);
    }

    if (lex__is_end(lexer)) return lex__error_tok(lexer, lex_sv_lit("Unterminated string detected."));

    lex__advance(lexer);
    return lex__make_tok(lexer, TOK_STR_LIT);
}

LEXDEF Token lex__char(Lexer *lexer)
{
    if('\'' == lex__peek(lexer)) return lex__error_tok(lexer, lex_sv_lit("Empty char detected."));

    while('\'' != lex__peek(lexer) && !lex__is_end(lexer))
    {
        if('\n' == lex__peek(lexer)) return lex__error_tok(lexer, lex_sv_lit("Multiline chars are not supported."));
        lex__match(lexer, '\\');
        lex__advance(lexer);
    }

    if (lex__is_end(lexer)) return lex__error_tok(lexer, lex_sv_lit("Unterminated char detected."));

    lex__advance(lexer);
    return lex__make_tok(lexer, TOK_CHAR_LIT);
}

LEXDEF void lex_next_tok(Lexer *lexer, Token *tok)
{
    if(lex__trim_left(lexer, tok) != 0) return;
    lexer->tok_start_offset = lexer->offset;
    lexer->tok_start_loc = lexer->loc;


    if(lex__is_end(lexer))
    {
        *tok = lex__make_tok(lexer, TOK_EOF);
        return;
    }

    const char c = lex__advance(lexer);
    if(lex__is_id(c))
    {
        *tok = lex__id(lexer);
        return;
    }
    if(isdigit((unsigned char) c))
    {
        *tok = lex__number(lexer);
        return;
    }

    switch(c)
    {
        case '(': *tok = lex__make_tok(lexer, TOK_OPAREN); return;
        case ')': *tok = lex__make_tok(lexer, TOK_CPAREN); return;
        case '{': *tok = lex__make_tok(lexer, TOK_OBRACE); return;
        case '}': *tok = lex__make_tok(lexer, TOK_CBRACE); return;
        case '[': *tok = lex__make_tok(lexer, TOK_OBRACKET); return;
        case ']': *tok = lex__make_tok(lexer, TOK_CBRACKET); return;
        case ';': *tok = lex__make_tok(lexer, TOK_SEMI); return;
        case ',': *tok = lex__make_tok(lexer, TOK_COMMA); return;
        case '.': {
            if(isdigit((unsigned char) lex__peek(lexer)))
            {
                *tok = lex__number(lexer);
            }
            else if('.' == lex__peek(lexer) && '.' == lex__peek_next(lexer))
            {
                lex__advance(lexer);
                lex__advance(lexer);
                *tok = lex__make_tok(lexer, TOK_ELLIPSIS);
            }
            else
            {
                *tok = lex__make_tok(lexer, TOK_DOT);
            }
            return;
        }
        case '-': {
            if (lex__match(lexer, '>'))      *tok = lex__make_tok(lexer, TOK_ARROW);
            else if (lex__match(lexer, '-')) *tok = lex__make_tok(lexer, TOK_DEC);
            else if (lex__match(lexer, '=')) *tok = lex__make_tok(lexer, TOK_MINUS_ASSIGN);
            else                             *tok = lex__make_tok(lexer, TOK_MINUS);
            return;
        }
        case '+':  {
            if (lex__match(lexer, '+'))      *tok = lex__make_tok(lexer, TOK_INC);
            else if (lex__match(lexer, '=')) *tok = lex__make_tok(lexer, TOK_PLUS_ASSIGN);
            else                             *tok = lex__make_tok(lexer, TOK_PLUS);
            return;
        }
        case '*': *tok = lex__make_tok(lexer, lex__match(lexer, '=') ? TOK_STAR_ASSIGN : TOK_STAR); return;
        case '/': *tok = lex__make_tok(lexer, lex__match(lexer, '=') ? TOK_SLASH_ASSIGN : TOK_SLASH); return;
        case '!': *tok = lex__make_tok(lexer, lex__match(lexer, '=') ? TOK_NE : TOK_BANG); return;
        case '=': *tok = lex__make_tok(lexer, lex__match(lexer, '=') ? TOK_EQ : TOK_ASSIGN); return;
        case '<':  {
            if (lex__match(lexer, '<'))      *tok = lex__make_tok(lexer, lex__match(lexer, '=') ? TOK_LSHIFT_ASSIGN : TOK_LSHIFT);
            else if (lex__match(lexer, '=')) *tok = lex__make_tok(lexer, TOK_LE);
            else                             *tok = lex__make_tok(lexer, TOK_LT);
            return;
        }
        case '>':  {
            if (lex__match(lexer, '>'))      *tok = lex__make_tok(lexer, lex__match(lexer, '=') ? TOK_RSHIFT_ASSIGN : TOK_RSHIFT);
            else if (lex__match(lexer, '=')) *tok = lex__make_tok(lexer, TOK_GE);
            else                             *tok = lex__make_tok(lexer, TOK_GT);
            return;
        }
        case '^': *tok = lex__make_tok(lexer, lex__match(lexer, '=') ? TOK_XOR_ASSIGN : TOK_XOR); return;
        case '|': {
            if(lex__match(lexer, '|'))       *tok = lex__make_tok(lexer, TOK_OR_OR);
            else if(lex__match(lexer, '='))  *tok = lex__make_tok(lexer, TOK_OR_ASSIGN);
            else                             *tok = lex__make_tok(lexer, TOK_OR);
            return;
        }
        case '&': {
            if(lex__match(lexer, '&'))       *tok = lex__make_tok(lexer, TOK_AND_AND);
            else if(lex__match(lexer, '='))  *tok = lex__make_tok(lexer, TOK_AND_ASSIGN);
            else                             *tok = lex__make_tok(lexer, TOK_AND);
            return;
        }
        case '~': *tok = lex__make_tok(lexer, TOK_TILDE); return;
        case '%': *tok = lex__make_tok(lexer, lex__match(lexer, '=') ? TOK_MOD_ASSIGN : TOK_MOD); return;
        case '?': *tok = lex__make_tok(lexer, TOK_QUESTION); return;
        case ':': *tok = lex__make_tok(lexer, TOK_COLON); return;
        case '"': *tok = lex__string(lexer); return;
        case '\'': *tok = lex__char(lexer); return;
    }

    *tok = lex__error_tok(lexer, lex_sv_lit("Unrecognized symbol."));
}

LEXDEF void lex_init_sv(Lexer *lexer, StringView source)
{
    memset(lexer, 0, sizeof(Lexer));
    lexer->input = source;
}

LEXDEF void lex_init(Lexer *lexer, const char *source)
{
    lex_init_sv(lexer, lex_sv(source, strlen(source)));
}

LEXDEF const char* lex_stringify_token_type(TokenType type)
{
    switch(type)
    {
        #define X(name) case name: return #name;
            TOKEN_TYPE_LIST
        #undef X
    }

    return NULL;
}

#endif // LEX_IMPLEMENTATION

#endif // LEX_H_

/*
  Revision History:

    3.0.0 (2026-11-14) renamed: `sv` to `lex_sv` and `sv_lit` to `lex_sv_lit`. prefixed everything by gperf with lex__ or Lex__
    2.0.0 (2026-11-13) removed the return value of `lex_next_tok` because its redundant information
    1.1.0 (2026-11-13) added support for hex literals/multi character char literals
    1.0.0 (2026-11-13) first release of lex.h
*/

