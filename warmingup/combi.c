#include <stdio.h>

// ループ
int combiLp(int n, int r)
{
    int result = 1;
    for (int k = 1; k <= r; k++)
        result = ((n - k + 1) / k) * result;
    return result;
}

// 再帰
int combiRe(int n, int r)
{
    if (r == 0)
        return 1;
    return ((n - r + 1) / r) * combiRe(n, r - 1);
}

int main(int argc, char *argv[])
{
    int n = 10, r = 2;
    int resultLp = combiLp(n, r);
    printf("[ループ] %dC%d = %d\n", n, r, resultLp);

    int resultRe = combiRe(n, r);
    printf("[再帰　] %dC%d = %d\n", n, r, resultRe);

    return 0;
}