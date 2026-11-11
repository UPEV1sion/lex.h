#include <stdio.h>

int main(int argc, char **argv)
{
    const char *program = argv[0];
    puts(program);
    const char *restrict msg = "Hello, World\n";
    for(int i = 0; i < 100; ++i)
    {
        puts(msg);
    }
    return 0;
}
