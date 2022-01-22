#include <stdio.h>
#include <stdbool.h>

#include "../../helpers/base.h"
#include "../../helpers/ary.h"

void shellSort(int *ary, int bottom, int top)
{
    // 前の方の値から交換を行う
    for (int i = bottom + 1; i <= top; i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            // 上から1つずつ値を確認して, 自分の値のほうが小さかったら配列の前の方に移動させる
            if (ary[j] > ary[j + 1])
                swap(&ary[j], &ary[j + 1]);
            // そうでなかったらそこにとどまらせる
            else
                break;
        }
    }
}

#define N 6
int main(int argc, char *argv[])
{
    srandom(time(NULL));

    int ary[N];
    initAryByRandom(ary, N);

    printf("ソート前　");
    printAry(ary, 0, N - 1);
    printf("\n");

    shellSort(ary, 0, N - 1);

    printf("\nソート後　");
    printAry(ary, 0, N - 1);
    printf("\n");

    return 0;
}