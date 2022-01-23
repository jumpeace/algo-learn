#include <stdio.h>
#include "../../helpers/ary.h"

/*
    Hornerの方法
    f(x) = {a_n}{x^n}+{a_{n-1}}{x^{n-1}}+ ... +{a_1}x+{a_0} の値を計算する
    →f(x)=(...(({a_n}x + {a_{n-1}})x + {a_{n-2}})x ... {a_1})x + {a_0}
*/

int fn(int x, int a[], int n) {
    int result = a[n];
    for (int i = n - 1; i >= 0; i--) 
        result = result * x + a[i];
    return result;
}

#define n 3
int main(int argc, char *argv[])
{
    srandom(time(NULL));
    int a[n + 1];
    initAryByRandom(a, 0, n, 0, 9);

    printf("a=");
    printAry(a, 0, n);
    printf("\n");

    for(int x = 1; x <= 3; x++) 
        printf("fn(%d)=%d\n", x, fn(x, a, n));

    return 0;
}