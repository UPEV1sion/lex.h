
// // // Comment
// /* Comment */
/* Comment /* */

typedef struct {
    int bit : 1;
    int nibble: 4;
} Bitfield;

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

void print_int(const int x)
{
    printf("%d", x);
}

void print_double(const double x)
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

int main(int argc, char **argv)
{
    const char *program = argv[0];
    puts(program);
    const char *restrict msg = "\"Hello, World\n\\\r\n\a\b\v\"";
    for(int i = 0; i < 100; ++i)
    {
        puts(msg);
    }
    foo(msg, 42);
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
    print(1.);
    return 0;
}
