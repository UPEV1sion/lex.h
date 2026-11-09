#ifndef LEX_H_
#define LEX_H_

#include <ctype.h>
#include <stddef.h>
#include <stdbool.h>

#define TOKEN_TYPE_LIST \
	/* SEPARATORS */ \
    X(TOK_OPAREN) \
    X(TOK_CPAREN) \
    X(TOK_OBRACE) \
    X(TOK_CBRACE) \
    X(TOK_OBRACKET) \
    X(TOK_CBRACKET) \
    X(TOK_SEMICOLON) \
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
    X(TOK_PLUS_PLUS) \
    X(TOK_MINUS_MINUS) \
    X(TOK_EQ_EQ) \
    X(TOK_BANG_EQ) \
    X(TOK_GREATER) \
    X(TOK_LESS) \
    X(TOK_GREATER_EQ) \
    X(TOK_LESS_EQ) \
    X(TOK_BANG) \
    X(TOK_AND_AND) \
    X(TOK_OR_OR) \
    X(TOK_TILDE) \
    X(TOK_AND) \
    X(TOK_OR) \
    X(TOK_XOR) \
    X(TOK_SHIFT_LEFT) \
    X(TOK_SHIFT_RIGHT) \
    X(TOK_EQ) \
    X(TOK_PLUS_EQ) \
    X(TOK_MINUS_EQ) \
    X(TOK_STAR_EQ) \
    X(TOK_SLASH_EQ) \
    X(TOK_MOD_EQ) \
    X(TOK_AND_EQ) \
    X(TOK_OR_EQ) \
    X(TOK_XOR_EQ) \
    X(TOK_SHIFT_LEFT_EQ) \
    X(TOK_SHIFT_RIGHT_EQ) \
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

int lex_next_tok(Lexer *lexer, Token *tok);
void lex_init(Lexer *lexer, const char *source);
void lex_init_sv(Lexer *lexer, StringView source);
const char* lex_stringify_token_type(TokenType type);

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

#line 1 "keywords.gperf"

#include <string.h>
#include "lex.h"

typedef struct KeywordEntry {
    char *name;
    TokenType id;
} KeywordEntry;

#line 17 "keywords.gperf"
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
#line 40 "keywords.gperf"
    {"short", TOK_SHORT},
#line 44 "keywords.gperf"
    {"struct", TOK_STRUCT},
    {"",0},
#line 57 "keywords.gperf"
    {"_Alignas", TOK__ALIGNAS},
    {"",0},
#line 24 "keywords.gperf"
    {"const", TOK_CONST},
#line 43 "keywords.gperf"
    {"static", TOK_STATIC},
#line 59 "keywords.gperf"
    {"_Atomic", TOK__ATOMIC},
#line 60 "keywords.gperf"
    {"_Generic", TOK__GENERIC},
#line 62 "keywords.gperf"
    {"_Static_assert", TOK__STATIC_ASSERT},
#line 32 "keywords.gperf"
    {"float", TOK_FLOAT},
#line 42 "keywords.gperf"
    {"sizeof", TOK_SIZEOF},
#line 46 "keywords.gperf"
    {"typedef", TOK_TYPEDEF},
#line 58 "keywords.gperf"
    {"_Alignof", TOK__ALIGNOF},
#line 61 "keywords.gperf"
    {"_Noreturn", TOK__NORETURN},
#line 54 "keywords.gperf"
    {"_Imaginary", TOK__IMAGINARY},
#line 41 "keywords.gperf"
    {"signed", TOK_SIGNED},
#line 26 "keywords.gperf"
    {"default", TOK_DEFAULT},
#line 56 "keywords.gperf"
    {"restrict", TOK_RESTRICT},
#line 23 "keywords.gperf"
    {"char", TOK_CHAR},
#line 51 "keywords.gperf"
    {"while", TOK_WHILE},
#line 45 "keywords.gperf"
    {"switch", TOK_SWITCH},
#line 27 "keywords.gperf"
    {"do", TOK_DO},
#line 33 "keywords.gperf"
    {"for", TOK_FOR},
#line 22 "keywords.gperf"
    {"case", TOK_CASE},
#line 21 "keywords.gperf"
    {"break", TOK_BREAK},
#line 39 "keywords.gperf"
    {"return", TOK_RETURN},
    {"",0},
#line 25 "keywords.gperf"
    {"continue", TOK_CONTINUE},
#line 34 "keywords.gperf"
    {"goto", TOK_GOTO},
    {"",0},
#line 31 "keywords.gperf"
    {"extern", TOK_EXTERN},
    {"",0},
#line 38 "keywords.gperf"
    {"register", TOK_REGISTER},
#line 49 "keywords.gperf"
    {"void", TOK_VOID},
    {"",0},
#line 28 "keywords.gperf"
    {"double", TOK_DOUBLE},
    {"",0},
#line 36 "keywords.gperf"
    {"int", TOK_INT},
#line 29 "keywords.gperf"
    {"else", TOK_ELSE},
#line 47 "keywords.gperf"
    {"union", TOK_UNION},
    {"",0}, {"",0},
#line 50 "keywords.gperf"
    {"volatile", TOK_VOLATILE},
#line 30 "keywords.gperf"
    {"enum", TOK_ENUM},
#line 52 "keywords.gperf"
    {"_Bool", TOK__BOOL},
    {"",0},
#line 35 "keywords.gperf"
    {"if", TOK_IF},
#line 48 "keywords.gperf"
    {"unsigned", TOK_UNSIGNED},
#line 20 "keywords.gperf"
    {"auto", TOK_AUTO},
    {"",0}, {"",0}, {"",0},
#line 63 "keywords.gperf"
    {"_Thread_local", TOK__THREAD_LOCAL},
    {"",0}, {"",0}, {"",0}, {"",0},
#line 53 "keywords.gperf"
    {"_Complex", TOK__COMPLEX},
    {"",0}, {"",0},
#line 55 "keywords.gperf"
    {"inline", TOK_INLINE},
    {"",0}, {"",0},
#line 37 "keywords.gperf"
    {"long", TOK_LONG}
  };

const struct KeywordEntry *
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
#line 64 "keywords.gperf"

// GPERF code end

Token lex__generic_tok(Lexer *lexer, TokenType type, StringView lexeme)
{
    return (Token) {
        .type = type,
        .lexeme = lexeme,
        .loc = lexer->tok_start_loc,
    };
}

Token lex__make_tok(Lexer *lexer, TokenType type)
{
    return lex__generic_tok(
               lexer, 
               type,
               sv(lexer->input.data + lexer->tok_start_offset, lexer->offset - lexer->tok_start_offset)
           );
}

Token lex__error_tok(Lexer *lexer, StringView err_msg)
{
    return lex__generic_tok(lexer, TOK_ERR, err_msg);
}

bool lex__is_end(Lexer *lexer)
{
    return lexer->offset >= lexer->input.len;
}

char lex__peek(Lexer *lexer)
{
    return lexer->input.data[lexer->offset];
}

char lex__peek_next(Lexer *lexer)
{
    if(lex__is_end(lexer)) return 0;
    return lexer->input.data[lexer->offset + 1];
}

char lex__advance(Lexer *lexer)
{
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

bool lex__match(Lexer *lexer, char expected)
{
    if(lex__is_end(lexer)) return false;
    if(lexer->input.data[lexer->offset] != expected) return false;
    lexer->offset++;
    return true;
}

bool lex__expect(Lexer *lexer, char expected, StringView err_msg, Token *tok)
{
    if(lex__is_end(lexer) || lexer->input.data[lexer->offset] != expected)
    {
        *tok = lex__error_tok(lexer, err_msg);
        return false;
    }

    lexer->offset++;
    return true;
}

void lex__trim_left(Lexer *lexer)
{
    
    for(;;)
    {
        while(isspace((unsigned char) lex__peek(lexer)))
        {
            lex__advance(lexer);
        }

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
                lex__advance(lexer);
                lex__advance(lexer);
                while(!lex__is_end(lexer))
                {
                    if('*' == lex__peek(lexer) && '/' == lex__peek_next(lexer))
                    {
                        lex__advance(lexer);
                        lex__advance(lexer);
                        break;
                    }
                    else
                    {
                        lex__advance(lexer); 
                    }
                }
            }
        }
        else
        {
            break;
        }
    }
}

bool lex__is_ident(char c)
{
    return isalpha((unsigned char) c) || '_' == c;
}

TokenType lex__lookup_keyword(Lexer *lexer)
{
    const KeywordEntry *entry = lex__lookup_function(lexer->input.data + lexer->tok_start_offset, lexer->offset - lexer->tok_start_offset);
    if(entry) return entry->id;
    return TOK_ID;
}

Token lex__ident(Lexer *lexer)
{
    while(lex__is_ident(lex__peek(lexer)) || isdigit((unsigned char) lex__peek(lexer))) lex__advance(lexer);
    return lex__make_tok(lexer, lex__lookup_keyword(lexer));    
}


Token lex__number(Lexer *lexer)
{
    while (isdigit((unsigned char) lex__peek(lexer))) lex__advance(lexer);

    if ('.' == lex__peek(lexer) && isdigit((unsigned char) lex__peek_next(lexer)))
    {
        // TODO alnum may have been better here
        lex__advance(lexer);
        while(isdigit((unsigned char) lex__peek(lexer))) lex__advance(lexer);
        while(isalpha((unsigned char) lex__peek(lexer))) lex__advance(lexer);
        return lex__make_tok(lexer, TOK_NUM_LIT);
    }

    while (isalnum((unsigned char) lex__peek(lexer))) lex__advance(lexer);

    return lex__make_tok(lexer, TOK_NUM_LIT);
}

Token lex__string(Lexer *lexer)
{
    while ('"' != lex__peek(lexer) && !lex__is_end(lexer))
    {
        if('\n' == lex__peek(lexer)) return lex__error_tok(lexer, sv_lit("Multiline strings are not supported."));
        lex__advance(lexer);
    }

    if (lex__is_end(lexer)) return lex__error_tok(lexer, sv_lit("Unterminated string."));

    lex__advance(lexer);
    return lex__make_tok(lexer, TOK_STR_LIT);
}

Token lex__char(Lexer *lexer)
{
    Token tok;

    const char c = lex__advance(lexer);
    if('\\' == c)
    {
        lex__advance(lexer);
    }

    if(!lex__expect(lexer, '\'', sv_lit("Non terminated char detected."), &tok)) return tok;
    return lex__make_tok(lexer, TOK_CHAR_LIT);
}

int lex_next_tok(Lexer *lexer, Token *tok)
{
    lex__trim_left(lexer);
    lexer->tok_start_offset = lexer->offset;
    lexer->tok_start_loc = lexer->loc;

    if(lex__is_end(lexer))
    {
        *tok = lex__make_tok(lexer, TOK_EOF);
        return 0;
    }

    const char c = lex__advance(lexer);
    if(lex__is_ident(c))
    {
        *tok = lex__ident(lexer);
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
        case ';': *tok = lex__make_tok(lexer, TOK_SEMICOLON); return 0;
        case ',': *tok = lex__make_tok(lexer, TOK_COMMA); return 0;
        case '.': {
            if('.' == lex__peek(lexer) && '.' == lex__peek_next(lexer))
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
            else if (lex__match(lexer, '-')) *tok = lex__make_tok(lexer, TOK_MINUS_MINUS);
            else if (lex__match(lexer, '=')) *tok = lex__make_tok(lexer, TOK_MINUS_EQ);
            else                             *tok = lex__make_tok(lexer, TOK_MINUS);
            return 0;
        } 
        case '+':  {
            if (lex__match(lexer, '+'))      *tok = lex__make_tok(lexer, TOK_PLUS_PLUS);
            else if (lex__match(lexer, '=')) *tok = lex__make_tok(lexer, TOK_PLUS_EQ);
            else                             *tok = lex__make_tok(lexer, TOK_PLUS);
            return 0;
        }
        case '*': *tok = lex__make_tok(lexer, lex__match(lexer, '=') ? TOK_STAR_EQ : TOK_STAR); return 0;
        case '/': *tok = lex__make_tok(lexer, lex__match(lexer, '=') ? TOK_SLASH_EQ : TOK_SLASH); return 0;
        case '!': *tok = lex__make_tok(lexer, lex__match(lexer, '=') ? TOK_BANG_EQ : TOK_BANG); return 0;
        case '=': *tok = lex__make_tok(lexer, lex__match(lexer, '=') ? TOK_EQ_EQ : TOK_EQ); return 0;
        case '<':  {
            if (lex__match(lexer, '<'))      *tok = lex__make_tok(lexer, lex__match(lexer, '=') ? TOK_SHIFT_LEFT_EQ : TOK_SHIFT_LEFT);
            else if (lex__match(lexer, '=')) *tok = lex__make_tok(lexer, TOK_LESS_EQ);
            else                             *tok = lex__make_tok(lexer, TOK_LESS);
            return 0;
        }
        case '>':  {
            if (lex__match(lexer, '>'))      *tok = lex__make_tok(lexer, lex__match(lexer, '=') ? TOK_SHIFT_RIGHT_EQ : TOK_SHIFT_RIGHT);
            else if (lex__match(lexer, '=')) *tok = lex__make_tok(lexer, TOK_GREATER_EQ);
            else                             *tok = lex__make_tok(lexer, TOK_GREATER);
            return 0;
        }
        case '^': *tok = lex__make_tok(lexer, lex__match(lexer, '=') ? TOK_XOR_EQ : TOK_XOR); return 0;
        case '|': {
            if(lex__match(lexer, '|'))       *tok = lex__make_tok(lexer, TOK_OR_OR);
            else if(lex__match(lexer, '='))  *tok = lex__make_tok(lexer, TOK_OR_EQ);
            else                             *tok = lex__make_tok(lexer, TOK_OR);
            return 0;
        }
        case '&': {
            if(lex__match(lexer, '&'))       *tok = lex__make_tok(lexer, TOK_AND_AND);
            else if(lex__match(lexer, '='))  *tok = lex__make_tok(lexer, TOK_AND_EQ);
            else                             *tok = lex__make_tok(lexer, TOK_AND);
            return 0;
        }
        case '~': *tok = lex__make_tok(lexer, TOK_TILDE); return 0;
        case '%': *tok = lex__make_tok(lexer, lex__match(lexer, '=') ? TOK_MOD_EQ : TOK_MOD); return 0;
        case '?': *tok = lex__make_tok(lexer, TOK_QUESTION); return 0;
        case ':': *tok = lex__make_tok(lexer, TOK_COLON); return 0;
        case '"': *tok = lex__string(lexer); return 0;
        case '\'': *tok = lex__char(lexer); return 0;
    }

    *tok = lex__error_tok(lexer, sv_lit("Unrecognized symbol."));
    return 1;
}

void lex_init_sv(Lexer *lexer, StringView source)
{
    memset(lexer, 0, sizeof(Lexer));
    lexer->input = source;
}

void lex_init(Lexer *lexer, const char *source)
{
    lex_init_sv(lexer, sv(source, strlen(source)));
}

const char* lex_stringify_token_type(TokenType type)
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
