#include "ary.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int initAryByRandom(int ary[], int ary_size) {
    for (int i = 0; i < ary_size; i++) {
        ary[i] = random() % 100;
    }
}

void printAry(int ary[], int bottom, int top) {
    printf("[");
    for (int i = bottom; i <= top; i++) {
        if (i == bottom)
            printf("%d", ary[i]);
        else
            printf(", %d", ary[i]);
    }
    printf("]");
}