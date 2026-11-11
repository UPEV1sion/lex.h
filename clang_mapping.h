/* ANSI-C code produced by gperf version 3.1 */
/* Command-line: gperf -H clang_hash -W clang_wordlist --constants-prefix=CLANG_ --initializer-suffix=,0 --output-file=clang_mapping.h clang_mapping.gperf  */
/* Computed positions: -k'1-2,$' */

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

#line 1 "clang_mapping.gperf"

#include <string.h>
#include "lex.h"

typedef struct ClangMapping {
    char *name;
    TokenType type;
} ClangMapping;

#line 16 "clang_mapping.gperf"
struct ClangMapping;

#define CLANG_TOTAL_KEYWORDS 94
#define CLANG_MIN_WORD_LENGTH 2
#define CLANG_MAX_WORD_LENGTH 19
#define CLANG_MIN_HASH_VALUE 4
#define CLANG_MAX_HASH_VALUE 165
/* maximum key range = 162, duplicates = 0 */

#ifdef __GNUC__
__inline
#else
#ifdef __cplusplus
inline
#endif
#endif
static unsigned int
clang_hash (register const char *str, register size_t len)
{
  static const unsigned char asso_values[] =
    {
      166, 166, 166, 166, 166, 166, 166, 166, 166, 166,
      166, 166, 166, 166, 166, 166, 166, 166, 166, 166,
      166, 166, 166, 166, 166, 166, 166, 166, 166, 166,
      166, 166, 166, 166, 166, 166, 166, 166, 166, 166,
      166, 166, 166, 166, 166, 166, 166, 166, 166, 166,
      166, 166, 166, 166, 166, 166, 166, 166, 166, 166,
      166, 166, 166, 166, 166, 166,  45,   0,  75, 166,
      166, 166,  25, 166,   0, 166, 166, 166, 166,  20,
      166, 166, 166, 166,   0,  10, 166, 166, 166, 166,
      166, 166, 166, 166, 166,  45,  45,  50,  15,  40,
        5,  30,  10,  35,   0,  25,  20,   0,   5,   0,
       40,  40,   0,   5,   0,   0,  45,  80,  15,  55,
        0,  65,  15, 166, 166, 166, 166, 166, 166, 166,
      166, 166, 166, 166, 166, 166, 166, 166, 166, 166,
      166, 166, 166, 166, 166, 166, 166, 166, 166, 166,
      166, 166, 166, 166, 166, 166, 166, 166, 166, 166,
      166, 166, 166, 166, 166, 166, 166, 166, 166, 166,
      166, 166, 166, 166, 166, 166, 166, 166, 166, 166,
      166, 166, 166, 166, 166, 166, 166, 166, 166, 166,
      166, 166, 166, 166, 166, 166, 166, 166, 166, 166,
      166, 166, 166, 166, 166, 166, 166, 166, 166, 166,
      166, 166, 166, 166, 166, 166, 166, 166, 166, 166,
      166, 166, 166, 166, 166, 166, 166, 166, 166, 166,
      166, 166, 166, 166, 166, 166, 166, 166, 166, 166,
      166, 166, 166, 166, 166, 166, 166, 166, 166, 166,
      166, 166, 166, 166, 166, 166, 166
    };
  return len + asso_values[(unsigned char)str[1]+1] + asso_values[(unsigned char)str[0]] + asso_values[(unsigned char)str[len - 1]];
}

static const struct ClangMapping clang_wordlist[] =
  {
    {"",0}, {"",0}, {"",0}, {"",0},
#line 32 "clang_mapping.gperf"
    {"plus", TOK_PLUS},
#line 42 "clang_mapping.gperf"
    {"slash", TOK_SLASH},
#line 89 "clang_mapping.gperf"
    {"switch", TOK_SWITCH},
    {"",0},
#line 33 "clang_mapping.gperf"
    {"plusplus", TOK_INC},
    {"",0}, {"",0}, {"",0}, {"",0},
#line 78 "clang_mapping.gperf"
    {"for", TOK_FOR},
#line 34 "clang_mapping.gperf"
    {"plusequal", TOK_PLUS_ASSIGN},
#line 43 "clang_mapping.gperf"
    {"slashequal", TOK_SLASH_ASSIGN},
    {"",0}, {"",0},
#line 83 "clang_mapping.gperf"
    {"register", TOK_REGISTER},
#line 46 "clang_mapping.gperf"
    {"less", TOK_LT},
#line 66 "clang_mapping.gperf"
    {"break", TOK_BREAK},
#line 25 "clang_mapping.gperf"
    {"period", TOK_DOT},
    {"",0},
#line 47 "clang_mapping.gperf"
    {"lessless", TOK_LSHIFT},
#line 93 "clang_mapping.gperf"
    {"void", TOK_VOID},
#line 35 "clang_mapping.gperf"
    {"minus", TOK_MINUS},
    {"",0},
#line 45 "clang_mapping.gperf"
    {"percentequal", TOK_MOD_ASSIGN},
    {"",0},
#line 48 "clang_mapping.gperf"
    {"lessequal", TOK_LE},
#line 37 "clang_mapping.gperf"
    {"minusminus", TOK_DEC},
#line 86 "clang_mapping.gperf"
    {"signed", TOK_SIGNED},
    {"",0},
#line 49 "clang_mapping.gperf"
    {"lesslessequal", TOK_LSHIFT_ASSIGN},
#line 58 "clang_mapping.gperf"
    {"pipeequal", TOK_OR_ASSIGN},
#line 38 "clang_mapping.gperf"
    {"minusequal", TOK_MINUS_ASSIGN},
    {"",0}, {"",0},
#line 26 "clang_mapping.gperf"
    {"ellipsis", TOK_ELLIPSIS},
#line 61 "clang_mapping.gperf"
    {"semi", TOK_SEMI},
#line 62 "clang_mapping.gperf"
    {"equal", TOK_ASSIGN},
#line 73 "clang_mapping.gperf"
    {"double", TOK_DOUBLE},
#line 50 "clang_mapping.gperf"
    {"greater", TOK_GT},
#line 108 "clang_mapping.gperf"
    {"eof", TOK_EOF},
#line 82 "clang_mapping.gperf"
    {"long", TOK_LONG},
#line 63 "clang_mapping.gperf"
    {"equalequal", TOK_EQ},
    {"",0},
#line 72 "clang_mapping.gperf"
    {"do", TOK_DO},
    {"",0},
#line 51 "clang_mapping.gperf"
    {"greatergreater", TOK_RSHIFT},
    {"",0}, {"",0},
#line 52 "clang_mapping.gperf"
    {"greaterequal", TOK_GE},
#line 94 "clang_mapping.gperf"
    {"volatile", TOK_VOLATILE},
#line 56 "clang_mapping.gperf"
    {"pipe", TOK_OR},
#line 101 "clang_mapping.gperf"
    {"_Bool", TOK__BOOL},
#line 84 "clang_mapping.gperf"
    {"return", TOK_RETURN},
    {"",0},
#line 57 "clang_mapping.gperf"
    {"pipepipe", TOK_OR_OR},
#line 53 "clang_mapping.gperf"
    {"greatergreaterequal", TOK_RSHIFT_ASSIGN},
#line 77 "clang_mapping.gperf"
    {"float", TOK_FLOAT},
    {"",0},
#line 44 "clang_mapping.gperf"
    {"percent", TOK_MOD},
#line 97 "clang_mapping.gperf"
    {"restrict", TOK_RESTRICT},
#line 74 "clang_mapping.gperf"
    {"else", TOK_ELSE},
#line 109 "clang_mapping.gperf"
    {"identifier", TOK_ID},
    {"",0},
#line 71 "clang_mapping.gperf"
    {"default", TOK_DEFAULT},
#line 59 "clang_mapping.gperf"
    {"question", TOK_QUESTION},
#line 68 "clang_mapping.gperf"
    {"char", TOK_CHAR},
#line 55 "clang_mapping.gperf"
    {"caretequal", TOK_XOR_ASSIGN},
    {"",0},
#line 80 "clang_mapping.gperf"
    {"if", TOK_IF},
#line 107 "clang_mapping.gperf"
    {"_Thread_local", TOK__THREAD_LOCAL},
#line 75 "clang_mapping.gperf"
    {"enum", TOK_ENUM},
#line 85 "clang_mapping.gperf"
    {"short", TOK_SHORT},
    {"",0},
#line 90 "clang_mapping.gperf"
    {"typedef", TOK_TYPEDEF},
#line 70 "clang_mapping.gperf"
    {"continue", TOK_CONTINUE},
#line 79 "clang_mapping.gperf"
    {"goto", TOK_GOTO},
    {"",0}, {"",0},
#line 24 "clang_mapping.gperf"
    {"r_brace", TOK_CBRACE},
#line 20 "clang_mapping.gperf"
    {"r_square", TOK_CBRACKET},
#line 30 "clang_mapping.gperf"
    {"star", TOK_STAR},
#line 60 "clang_mapping.gperf"
    {"colon", TOK_COLON},
    {"",0},
#line 23 "clang_mapping.gperf"
    {"l_brace", TOK_OBRACE},
#line 19 "clang_mapping.gperf"
    {"l_square", TOK_OBRACKET},
#line 67 "clang_mapping.gperf"
    {"case", TOK_CASE},
#line 69 "clang_mapping.gperf"
    {"const", TOK_CONST},
    {"",0},
#line 22 "clang_mapping.gperf"
    {"r_paren", TOK_CPAREN},
#line 27 "clang_mapping.gperf"
    {"amp", TOK_AND},
#line 31 "clang_mapping.gperf"
    {"starequal", TOK_STAR_ASSIGN},
#line 64 "clang_mapping.gperf"
    {"comma", TOK_COMMA},
#line 28 "clang_mapping.gperf"
    {"ampamp", TOK_AND_AND},
#line 21 "clang_mapping.gperf"
    {"l_paren", TOK_OPAREN},
#line 98 "clang_mapping.gperf"
    {"_Alignas", TOK__ALIGNAS},
#line 111 "clang_mapping.gperf"
    {"string_literal", TOK_STR_LIT},
#line 39 "clang_mapping.gperf"
    {"tilde", TOK_TILDE},
#line 96 "clang_mapping.gperf"
    {"inline", TOK_INLINE},
#line 40 "clang_mapping.gperf"
    {"exclaim", TOK_BANG},
#line 29 "clang_mapping.gperf"
    {"ampequal", TOK_AND_ASSIGN},
#line 106 "clang_mapping.gperf"
    {"_Static_assert", TOK__STATIC_ASSERT},
#line 54 "clang_mapping.gperf"
    {"caret", TOK_XOR},
    {"",0}, {"",0},
#line 99 "clang_mapping.gperf"
    {"_Alignof", TOK__ALIGNOF},
#line 65 "clang_mapping.gperf"
    {"auto", TOK_AUTO},
#line 36 "clang_mapping.gperf"
    {"arrow", TOK_ARROW},
    {"",0},
#line 41 "clang_mapping.gperf"
    {"exclaimequal", TOK_NE},
#line 81 "clang_mapping.gperf"
    {"int", TOK_INT},
#line 105 "clang_mapping.gperf"
    {"_Noreturn", TOK__NORETURN},
#line 95 "clang_mapping.gperf"
    {"while", TOK_WHILE},
#line 110 "clang_mapping.gperf"
    {"numeric_constant", TOK_NUM_LIT},
    {"",0},
#line 104 "clang_mapping.gperf"
    {"_Generic", TOK__GENERIC},
    {"",0},
#line 103 "clang_mapping.gperf"
    {"_Imaginary", TOK__IMAGINARY},
    {"",0}, {"",0},
#line 112 "clang_mapping.gperf"
    {"char_constant", TOK_CHAR_LIT},
    {"",0}, {"",0},
#line 87 "clang_mapping.gperf"
    {"static", TOK_STATIC},
    {"",0},
#line 102 "clang_mapping.gperf"
    {"_Complex", TOK__COMPLEX},
    {"",0}, {"",0},
#line 88 "clang_mapping.gperf"
    {"struct", TOK_STRUCT},
    {"",0},
#line 92 "clang_mapping.gperf"
    {"unsigned", TOK_UNSIGNED},
    {"",0}, {"",0}, {"",0},
#line 100 "clang_mapping.gperf"
    {"_Atomic", TOK__ATOMIC},
    {"",0}, {"",0}, {"",0},
#line 76 "clang_mapping.gperf"
    {"extern", TOK_EXTERN},
    {"",0}, {"",0}, {"",0}, {"",0}, {"",0}, {"",0}, {"",0},
    {"",0}, {"",0}, {"",0}, {"",0}, {"",0}, {"",0}, {"",0},
    {"",0}, {"",0}, {"",0}, {"",0}, {"",0}, {"",0}, {"",0},
    {"",0}, {"",0},
#line 91 "clang_mapping.gperf"
    {"union", TOK_UNION}
  };

const struct ClangMapping *
clang_lookup_function (register const char *str, register size_t len)
{
  if (len <= CLANG_MAX_WORD_LENGTH && len >= CLANG_MIN_WORD_LENGTH)
    {
      register unsigned int key = clang_hash (str, len);

      if (key <= CLANG_MAX_HASH_VALUE)
        {
          register const char *s = clang_wordlist[key].name;

          if (*str == *s && !strcmp (str + 1, s + 1))
            return &clang_wordlist[key];
        }
    }
  return 0;
}
#line 113 "clang_mapping.gperf"


