/* ANSI-C code produced by gperf version 3.3 */
/* Command-line: gperf --initializer-suffix=,0 keywords.gperf  */
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

typedef struct Lex__KeywordEntry {
    char *name;
    TokenType id;
} Lex__KeywordEntry;

struct Lex__KeywordEntry;

#define LEX__TOTAL_KEYWORDS 44
#define LEX__MIN_WORD_LENGTH 2
#define LEX__MAX_WORD_LENGTH 14
#define LEX__MIN_HASH_VALUE 5
#define LEX__MAX_HASH_VALUE 69
/* maximum key range = 65, duplicates = 0 */

#ifdef __GNUC__
__inline
#else
#ifdef __cplusplus
inline
#endif
#endif
static unsigned int
lex__hash (register const char *str, register size_t len)
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

static const struct Lex__KeywordEntry lex__wordlist[] =
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

const struct Lex__KeywordEntry *
lex__lookup_function (register const char *str, register size_t len)
{
  if (len <= LEX__MAX_WORD_LENGTH && len >= LEX__MIN_WORD_LENGTH)
    {
      register unsigned int key = lex__hash (str, len);

      if (key <= LEX__MAX_HASH_VALUE)
        {
          register const char *s = lex__wordlist[key].name;

          if (*str == *s && !strncmp (str + 1, s + 1, len - 1) && s[len] == '\0')
            return &lex__wordlist[key];
        }
    }
  return (struct Lex__KeywordEntry *) 0;
}


