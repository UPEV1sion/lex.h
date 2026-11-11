#include <stdio.h>
#include <stdarg.h>

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
    const char *restrict msg = "Hello, World\n";
    for(int i = 0; i < 100; ++i)
    {
        puts(msg);
    }
    foo(msg, 42);

    return 0;
}
