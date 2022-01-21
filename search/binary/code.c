#include <stdio.h>
#include <stdbool.h>

#include "../../helpers/ary.h"

#define N 6

int binarySearch(int key, int ary[], int bottom, int top) {
    if (bottom > top)
        return -1;

    int mid = (bottom + top) / 2;

    if (ary[mid] == key) 
        return mid;

    if (ary[mid] < key) 
        return binarySearch(key, ary, mid + 1, top);
    else
        return binarySearch(key, ary, bottom, mid - 1);
}

int main(int argc, char *argv[])
{
    srandom(time(NULL));

    int ary[N];
    initAryBySorted(ary, N, 5);
    printf("ary = ");
    printAry(ary, 0, N - 1);
    printf("\n");

    int result = binarySearch(10, ary, 0, N - 1);
    printf("result: %d\n", result);

    return 0;
}