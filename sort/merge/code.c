#include <stdio.h>
#include <stdbool.h>

#include "../../helpers/ary.h"

void mergeSort(int ary[], int bottom, int top) {
    int size = (top + 1) - bottom;
    if (size <= 1)
        return;
    
    int mid = (bottom + top + 1) / 2;

    // 左右の配列をソートする
    mergeSort(ary, bottom, mid - 1);
    mergeSort(ary, mid, top);

    // 左右の配列を前の方から比較していって小さい方を順々に入れていく
    int sorted[size];
    int sorted_i = 0, left_i = bottom, right_i = mid;
    while(true) {
        bool is_left_ok = left_i <= mid - 1;
        bool is_right_ok = right_i <= top;

        if (!is_left_ok && !is_right_ok) 
            break;
        
        if (is_left_ok && is_right_ok) 
            sorted[sorted_i++] = (ary[left_i] < ary[right_i]) ? ary[left_i++] : ary[right_i++];
        else 
            sorted[sorted_i++] =  is_left_ok ? ary[left_i++] : ary[right_i++];
    }

    for (int i = 0; i < size; i++) 
        ary[i + bottom] = sorted[i];
}

int main(int argc, char *argv[])
{
    int ary[10];
    initAryByRandom(ary, 0, 9, 1, 100);

    printf("not sort=");
    printAry(ary, 0, 9);
    printf("\n");

    mergeSort(ary, 0, 9);

    printf("sorted=");
    printAry(ary, 0, 9);
    printf("\n");

    return 0;
}