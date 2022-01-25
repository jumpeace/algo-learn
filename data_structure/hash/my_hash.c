#include <stdio.h>
#include <string.h>

int myHash(char str[], int r1) {
    int r2 = 4200000000;
    int len = strlen(str);
    int sum = 0, mul = 1;

    for (int i = 0; i < len; i++) {
        sum += r2 * (str[i] / r1);
        mul *= str[i];
    }
    
    int result1 = (100000 - sum) * ((str[len / 2] + 1) * (str[len / 2] + 1));
    int result2 = mul * (100000 - (str[len / 3] * str[len / 3]));
    int result = result1 * result2;

    return (result < 0) ? -result : result;
}

int main(int argc, char *argv[])
{
    int n;
    for (int i = 1; i < argc; i++) 
        printf("%s -> %d\n", argv[i], myHash(argv[i], 78));
    return 0;
}