#include <stdio.h>

#define ITER 100
#define shift_args(argc, argv) ((argc)--, *(argv)++)

int main(int argc, char **argv)
{
    const char *program = shift_args(argc, argv);
    puts(program);
    const char *restrict msg = "Hello, World\n";
    for(int i = 0; i < ITER; ++i)
    {
        puts(msg);
    }
    return 0;
}
