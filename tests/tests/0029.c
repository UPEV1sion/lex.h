
// // // Comment
// /* Comment */
/* Comment /* */

typedef struct {
    int bit : 1;
    int nibble: 4;
} Bitfield;

enum {
    ANONYM
};

typedef struct {
    enum {INT, FLOAT} type;
    union {
        int i;
        float f;
    };
} TaggedUnion;

typedef struct {
    int x, y;
} Coord;

typedef union {
    int i;
    double d;
} Typepun;

typedef enum {
    GCC,
    CLANG,
    TCC,
    MSCV,   
} CCompilers;

struct Aligned {
    _Alignas(64) double x1;
    _Alignas(64) double x2;
};

inline void print_int(const int x)
{
    printf("%d", x);
}

inline void print_double(const double x)
{
    printf("%f", x);
}

void foo(void *first, ...)
{
    va_list ap;
    va_start(ap, first);
    int arg = va_arg(ap, int);
    printf("%d\n", arg);
    va_end(ap);
}

_Static_assert((sizeof(int) - 1) & 1 == 0);

int main(int argc, char **argv)
{
    const char *program = argv[0];
    puts(program);
    const char *restrict msg = "\"Hello, World\n\\\r\n\a\b\v\"";
    puts("str1""str2");
    for(int i = 0; i < 100; ++i)
    {
        puts(msg);
    }
    const char *name = _Generic(program,
            const char *: "string",
            int: "int"
    );

    foo(msg, 42 == 0 ? 0 : 42);
    foo(msg, 00123);
    foo(msg, 0xFF);
    foo(msg, (int) 1.f);
    foo(msg, (int) 1.0f);
    foo(msg, (int) 1e-3f);
    foo(msg, (int) 1e+3f);
    foo(msg, (int) 1E3f);
    foo(msg, (int) 1.E-3f);
    foo(msg, (int) 1E+3f);

    print(123 & 0xFF);
    print(1 << 2);
    print(8 >> 1);
    print(.3f);
    print(0x1.8p-3);
    print(0x1.921fb54442d18p+1);
    print(0x1P10);
    int x = 42;
    int y = 3;
    print(x+++++y);
    print(x
    + +1);
    int a = 1/* this is a comment */+/* another one */2;
    int n = 0;
    while(n --> 0) {/* */}
    int a = 1, b = 2, c = 3;
    int res1 = a+++b;
    int res2 = a---b;
    int res3 = a+++++--b;

    int shift1 = 1 <<= 2;
    int shift2 = 1 <<<= 2;

    _Atomic int count = 0;

    printf("%zu\n", _Alignof(double));
    printf("%f\n", 1.f * 42 / 2 + 123 -1);
    putchar('\xff');
    putchar('\xf');
    putchar('asdf');
    putchar('\'asdf');

    return 0;
}

/**/
