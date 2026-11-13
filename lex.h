/*  lex.h 1.0.0 - lexer for creating languages with C-like grammar

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

#define sv(data1, len1) ((StringView) {.data = data1, .len = len1 })
#define sv_lit(data1) ((StringView) {.data = data1, .len = sizeof(data1) - 1})

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

LEXDEF int lex_next_tok(Lexer *lexer, Token *tok);
LEXDEF void lex_init(Lexer *lexer, const char *source);
LEXDEF void lex_init_sv(Lexer *lexer, StringView source);
LEXDEF const char* lex_stringify_token_type(TokenType type);

#ifdef LEX_IMPLEMENTATION

// GPERF code start

// TODO find a way to automate the concat of these files
/* ANSI-C code produced by gperf version 3.1 */
/* Command-line: gperf --initializer-suffix=,0 --output-file=keywords.h keywords.gperf  */
/* Computed positions: -k'1,$' */

#if !((' ' == 32) && ('!' == 33) && ('"' == 34) && ('#' == 35) \
      && ('%' == 37) && ('&' == 38) && ('\'' == 39) && ('(' == 40) \
      && (')' == 41) && ('*' == 42) && ('+' == 43) && (',' == 44) \
      && ('-' == 45) && ('.' == 46) && ('/' == 47) && ('0' == 48) \
      && ('1' == 49) && ('2' == 50) && ('3' == 51) && ('4' == 52) \
      && ('5' == 53) && ('6' == 54) && ('7' == 55) && ('8' == 56) \
      && ('9' == 57) && (':' == 58) && (';' == 59) && ('<' == 60) \
      && ('=' == 61) && ('>' == 62) && ('?' == 63) && ('A' == 65) \
      && ('B' == 66) && ('C' == 67) && ('D' == 68) && ('E' == 69) \
      && ('F' == 70) && ('G' == 71) && ('H' == 72) && ('I' == 73) \
      && ('J' == 74) && ('K' == 75) && ('L' == 76) && ('M' == 77) \
      && ('N' == 78) && ('O' == 79) && ('P' == 80) && ('Q' == 81) \
      && ('R' == 82) && ('S' == 83) && ('T' == 84) && ('U' == 85) \
      && ('V' == 86) && ('W' == 87) && ('X' == 88) && ('Y' == 89) \
      && ('Z' == 90) && ('[' == 91) && ('\\' == 92) && (']' == 93) \
      && ('^' == 94) && ('_' == 95) && ('a' == 97) && ('b' == 98) \
      && ('c' == 99) && ('d' == 100) && ('e' == 101) && ('f' == 102) \
      && ('g' == 103) && ('h' == 104) && ('i' == 105) && ('j' == 106) \
      && ('k' == 107) && ('l' == 108) && ('m' == 109) && ('n' == 110) \
      && ('o' == 111) && ('p' == 112) && ('q' == 113) && ('r' == 114) \
      && ('s' == 115) && ('t' == 116) && ('u' == 117) && ('v' == 118) \
      && ('w' == 119) && ('x' == 120) && ('y' == 121) && ('z' == 122) \
      && ('{' == 123) && ('|' == 124) && ('}' == 125) && ('~' == 126))
/* The character set is not based on ISO-646.  */
#error "gperf generated tables don't work with this execution character set. Please report a bug to <bug-gperf@gnu.org>."
#endif


#include <string.h>
#include "lex.h"

typedef struct KeywordEntry {
    char *name;
    TokenType id;
} KeywordEntry;

struct KeywordEntry;

#define TOTAL_KEYWORDS 44
#define MIN_WORD_LENGTH 2
#define MAX_WORD_LENGTH 14
#define MIN_HASH_VALUE 5
#define MAX_HASH_VALUE 69
/* maximum key range = 65, duplicates = 0 */

#ifdef __GNUC__
__inline
#else
#ifdef __cplusplus
inline
#endif
#endif
static unsigned int
hash (register const char *str, register size_t len)
{
  static const unsigned char asso_values[] =
    {
      70, 70, 70, 70, 70, 70, 70, 70, 70, 70,
      70, 70, 70, 70, 70, 70, 70, 70, 70, 70,
      70, 70, 70, 70, 70, 70, 70, 70, 70, 70,
      70, 70, 70, 70, 70, 70, 70, 70, 70, 70,
      70, 70, 70, 70, 70, 70, 70, 70, 70, 70,
      70, 70, 70, 70, 70, 70, 70, 70, 70, 70,
      70, 70, 70, 70, 70, 70, 70, 70, 70, 70,
      70, 70, 70, 70, 70, 70, 70, 70, 70, 70,
      70, 70, 70, 70, 70, 70, 70, 70, 70, 70,
      70, 70, 70, 70, 70,  0, 70, 40, 15,  5,
      15, 20, 10, 20, 20, 40, 70, 10, 45, 25,
      10, 10, 70, 70, 15,  0,  0, 30, 20,  0,
      55, 10, 70, 70, 70, 70, 70, 70, 70, 70,
      70, 70, 70, 70, 70, 70, 70, 70, 70, 70,
      70, 70, 70, 70, 70, 70, 70, 70, 70, 70,
      70, 70, 70, 70, 70, 70, 70, 70, 70, 70,
      70, 70, 70, 70, 70, 70, 70, 70, 70, 70,
      70, 70, 70, 70, 70, 70, 70, 70, 70, 70,
      70, 70, 70, 70, 70, 70, 70, 70, 70, 70,
      70, 70, 70, 70, 70, 70, 70, 70, 70, 70,
      70, 70, 70, 70, 70, 70, 70, 70, 70, 70,
      70, 70, 70, 70, 70, 70, 70, 70, 70, 70,
      70, 70, 70, 70, 70, 70, 70, 70, 70, 70,
      70, 70, 70, 70, 70, 70, 70, 70, 70, 70,
      70, 70, 70, 70, 70, 70, 70, 70, 70, 70,
      70, 70, 70, 70, 70, 70
    };
  return len + asso_values[(unsigned char)str[len - 1]] + asso_values[(unsigned char)str[0]];
}

static const struct KeywordEntry wordlist[] =
  {
    {"",0}, {"",0}, {"",0}, {"",0}, {"",0},
    {"short", TOK_SHORT},
    {"struct", TOK_STRUCT},
    {"",0},
    {"_Alignas", TOK__ALIGNAS},
    {"",0},
    {"const", TOK_CONST},
    {"static", TOK_STATIC},
    {"_Atomic", TOK__ATOMIC},
    {"_Generic", TOK__GENERIC},
    {"_Static_assert", TOK__STATIC_ASSERT},
    {"float", TOK_FLOAT},
    {"sizeof", TOK_SIZEOF},
    {"typedef", TOK_TYPEDEF},
    {"_Alignof", TOK__ALIGNOF},
    {"_Noreturn", TOK__NORETURN},
    {"_Imaginary", TOK__IMAGINARY},
    {"signed", TOK_SIGNED},
    {"default", TOK_DEFAULT},
    {"restrict", TOK_RESTRICT},
    {"char", TOK_CHAR},
    {"while", TOK_WHILE},
    {"switch", TOK_SWITCH},
    {"do", TOK_DO},
    {"for", TOK_FOR},
    {"case", TOK_CASE},
    {"break", TOK_BREAK},
    {"return", TOK_RETURN},
    {"",0},
    {"continue", TOK_CONTINUE},
    {"goto", TOK_GOTO},
    {"",0},
    {"extern", TOK_EXTERN},
    {"",0},
    {"register", TOK_REGISTER},
    {"void", TOK_VOID},
    {"",0},
    {"double", TOK_DOUBLE},
    {"",0},
    {"int", TOK_INT},
    {"else", TOK_ELSE},
    {"union", TOK_UNION},
    {"",0}, {"",0},
    {"volatile", TOK_VOLATILE},
    {"enum", TOK_ENUM},
    {"_Bool", TOK__BOOL},
    {"",0},
    {"if", TOK_IF},
    {"unsigned", TOK_UNSIGNED},
    {"auto", TOK_AUTO},
    {"",0}, {"",0}, {"",0},
    {"_Thread_local", TOK__THREAD_LOCAL},
    {"",0}, {"",0}, {"",0}, {"",0},
    {"_Complex", TOK__COMPLEX},
    {"",0}, {"",0},
    {"inline", TOK_INLINE},
    {"",0}, {"",0},
    {"long", TOK_LONG}
  };

static const struct KeywordEntry *
lex__lookup_function (register const char *str, register size_t len)
{
  if (len <= MAX_WORD_LENGTH && len >= MIN_WORD_LENGTH)
    {
      register unsigned int key = hash (str, len);

      if (key <= MAX_HASH_VALUE)
        {
          register const char *s = wordlist[key].name;

          if (*str == *s && !strncmp (str + 1, s + 1, len - 1) && s[len] == '\0')
            return &wordlist[key];
        }
    }
  return 0;
}

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
               sv(lexer->input.data + lexer->tok_start_offset, lexer->offset - lexer->tok_start_offset)
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
                    *tok = lex__error_tok(lexer, sv_lit("Unterminated multiline comment."));
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
    const KeywordEntry *entry = lex__lookup_function(lexer->input.data + lexer->tok_start_offset, lexer->offset - lexer->tok_start_offset);
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
        if('\n' == lex__peek(lexer)) return lex__error_tok(lexer, sv_lit("Multiline strings are not supported."));
        lex__match(lexer, '\\');
        lex__advance(lexer);
    }

    if (lex__is_end(lexer)) return lex__error_tok(lexer, sv_lit("Unterminated string detected."));

    lex__advance(lexer);
    return lex__make_tok(lexer, TOK_STR_LIT);
}

LEXDEF Token lex__char(Lexer *lexer)
{
    if('\'' == lex__peek(lexer)) return lex__error_tok(lexer, sv_lit("Empty char detected."));

    while('\'' != lex__peek(lexer) && !lex__is_end(lexer))
    {
        if('\n' == lex__peek(lexer)) return lex__error_tok(lexer, sv_lit("Multiline chars are not supported."));
        lex__match(lexer, '\\');
        lex__advance(lexer);
    }

    if (lex__is_end(lexer)) return lex__error_tok(lexer, sv_lit("Unterminated char detected."));

    lex__advance(lexer);
    return lex__make_tok(lexer, TOK_CHAR_LIT);
}

LEXDEF int lex_next_tok(Lexer *lexer, Token *tok)
{
    if(lex__trim_left(lexer, tok) != 0) return 1;
    lexer->tok_start_offset = lexer->offset;
    lexer->tok_start_loc = lexer->loc;


    if(lex__is_end(lexer))
    {
        *tok = lex__make_tok(lexer, TOK_EOF);
        return 0;
    }

    const char c = lex__advance(lexer);
    if(lex__is_id(c))
    {
        *tok = lex__id(lexer);
        return 0;
    }
    if(isdigit((unsigned char) c))
    {
        *tok = lex__number(lexer);
        return 0;
    }

    switch(c)
    {
        case '(': *tok = lex__make_tok(lexer, TOK_OPAREN); return 0;
        case ')': *tok = lex__make_tok(lexer, TOK_CPAREN); return 0;
        case '{': *tok = lex__make_tok(lexer, TOK_OBRACE); return 0;
        case '}': *tok = lex__make_tok(lexer, TOK_CBRACE); return 0;
        case '[': *tok = lex__make_tok(lexer, TOK_OBRACKET); return 0;
        case ']': *tok = lex__make_tok(lexer, TOK_CBRACKET); return 0;
        case ';': *tok = lex__make_tok(lexer, TOK_SEMI); return 0;
        case ',': *tok = lex__make_tok(lexer, TOK_COMMA); return 0;
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
            return 0;
        }
        case '-': {
            if (lex__match(lexer, '>'))      *tok = lex__make_tok(lexer, TOK_ARROW);
            else if (lex__match(lexer, '-')) *tok = lex__make_tok(lexer, TOK_DEC);
            else if (lex__match(lexer, '=')) *tok = lex__make_tok(lexer, TOK_MINUS_ASSIGN);
            else                             *tok = lex__make_tok(lexer, TOK_MINUS);
            return 0;
        }
        case '+':  {
            if (lex__match(lexer, '+'))      *tok = lex__make_tok(lexer, TOK_INC);
            else if (lex__match(lexer, '=')) *tok = lex__make_tok(lexer, TOK_PLUS_ASSIGN);
            else                             *tok = lex__make_tok(lexer, TOK_PLUS);
            return 0;
        }
        case '*': *tok = lex__make_tok(lexer, lex__match(lexer, '=') ? TOK_STAR_ASSIGN : TOK_STAR); return 0;
        case '/': *tok = lex__make_tok(lexer, lex__match(lexer, '=') ? TOK_SLASH_ASSIGN : TOK_SLASH); return 0;
        case '!': *tok = lex__make_tok(lexer, lex__match(lexer, '=') ? TOK_NE : TOK_BANG); return 0;
        case '=': *tok = lex__make_tok(lexer, lex__match(lexer, '=') ? TOK_EQ : TOK_ASSIGN); return 0;
        case '<':  {
            if (lex__match(lexer, '<'))      *tok = lex__make_tok(lexer, lex__match(lexer, '=') ? TOK_LSHIFT_ASSIGN : TOK_LSHIFT);
            else if (lex__match(lexer, '=')) *tok = lex__make_tok(lexer, TOK_LE);
            else                             *tok = lex__make_tok(lexer, TOK_LT);
            return 0;
        }
        case '>':  {
            if (lex__match(lexer, '>'))      *tok = lex__make_tok(lexer, lex__match(lexer, '=') ? TOK_RSHIFT_ASSIGN : TOK_RSHIFT);
            else if (lex__match(lexer, '=')) *tok = lex__make_tok(lexer, TOK_GE);
            else                             *tok = lex__make_tok(lexer, TOK_GT);
            return 0;
        }
        case '^': *tok = lex__make_tok(lexer, lex__match(lexer, '=') ? TOK_XOR_ASSIGN : TOK_XOR); return 0;
        case '|': {
            if(lex__match(lexer, '|'))       *tok = lex__make_tok(lexer, TOK_OR_OR);
            else if(lex__match(lexer, '='))  *tok = lex__make_tok(lexer, TOK_OR_ASSIGN);
            else                             *tok = lex__make_tok(lexer, TOK_OR);
            return 0;
        }
        case '&': {
            if(lex__match(lexer, '&'))       *tok = lex__make_tok(lexer, TOK_AND_AND);
            else if(lex__match(lexer, '='))  *tok = lex__make_tok(lexer, TOK_AND_ASSIGN);
            else                             *tok = lex__make_tok(lexer, TOK_AND);
            return 0;
        }
        case '~': *tok = lex__make_tok(lexer, TOK_TILDE); return 0;
        case '%': *tok = lex__make_tok(lexer, lex__match(lexer, '=') ? TOK_MOD_ASSIGN : TOK_MOD); return 0;
        case '?': *tok = lex__make_tok(lexer, TOK_QUESTION); return 0;
        case ':': *tok = lex__make_tok(lexer, TOK_COLON); return 0;
        case '"': *tok = lex__string(lexer); return 0;
        case '\'': *tok = lex__char(lexer); return 0;
    }

    *tok = lex__error_tok(lexer, sv_lit("Unrecognized symbol."));
    return 1;
}

LEXDEF void lex_init_sv(Lexer *lexer, StringView source)
{
    memset(lexer, 0, sizeof(Lexer));
    lexer->input = source;
}

LEXDEF void lex_init(Lexer *lexer, const char *source)
{
    lex_init_sv(lexer, sv(source, strlen(source)));
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

    1.1.0 (2026-11-13) added support for hex literals/multi character char literals
    1.0.0 (2026-11-13) first release of lex.h
*/
