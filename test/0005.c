#include <stdio.h>

#define ITER 100

int main(void)
{
    const char *restrict msg = "Hello, World\n";
    for(int i = 0; i < ITER; ++i)
    {
        puts(msg);
    }
    return 0;
}
