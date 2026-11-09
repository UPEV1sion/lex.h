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


