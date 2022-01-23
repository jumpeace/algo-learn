#include <stdio.h>
#include <stdbool.h>

#include "../../helpers/base.h"
#include "../../helpers/ary.h"

/*
    gap_0 = 1, gap_n = gap_{n-1}*3+1 で, 
    a_nがぎりぎりsizeを超えないようなgap_nを選ぶ
*/
int defineInitGap(int size)
{
    for (int gap = 4, prev_gap = 1;; prev_gap = gap, gap = gap * 3 + 1)
        if (gap > size)
            return prev_gap;
}

void insertSort(int *ary, int bottom, int top)
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

void shellSort(int *ary, int bottom, int top)
{
    if (bottom >= top)
        return;

    const int size = (top + 1) - bottom;

    // gapを1/2していって狭めていく
    for (int gap = defineInitGap(size); gap > 0; gap /= 2) {
        int tmp[size];
        // gapごとの配列を作ってソート
        for (int i = bottom; i * gap <= top; i++)
            tmp[i] = ary[i * gap];

        insertSort(tmp, 0, (size - 1) / gap);

        for (int i = bottom; i * gap <= top; i++)
            ary[i * gap] = tmp[i];

        // 途中経過表示
        printf("[gap: %d] ", gap);
        printAry(ary, bottom, top);
        printf("\n");
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

    printf("ソート後　");
    printAry(ary, 0, N - 1);
    printf("\n");

    return 0;
}