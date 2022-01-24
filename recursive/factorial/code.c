#include <stdio.h>

int factorial(int n) {
    if (n == 0)
        return 1;

    return n * factorial(n - 1);
}

int main(int argc, char *argv[])
{
    int n = 6;
    printf("%d!=%d\n", n, factorial(n));
    return 0;
}