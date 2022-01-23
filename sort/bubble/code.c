#include <stdio.h>
#include <stdbool.h>

#include "../../helpers/base.h"
#include "../../helpers/ary.h"

void bubbleSort(int ary[], int bottom, int top) {
    // 左側から1個, 2個, 3個...というようにソートしていく
    for (int i = bottom; i <= top; i++) {
        // iより左側はソート済なので, iより右側の要素と比較してソートする
        // 後ろから前へソートするとほしい値が前の方に来る
        for (int j = top; j > i; j--) {
            if (ary[i] > ary[j]) {
                swap(&ary[i], &ary[j]);
            }
        }
    }
}

#define N 6
int main(int argc, char const *argv[])
{
    srandom(time(NULL));

    int ary[N];
    initAryByRandom(ary, 0, N - 1, 0, 99);
    
    printf("ソート前　");
    printAry(ary, 0, N - 1);
    printf("\n");

    bubbleSort(ary, 0, N - 1);

    printf("\nソート後　");
    printAry(ary, 0, N - 1);
    printf("\n");
    return 0;
}
