#include "ary.h"
#include "ary.h"
#include "base.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int initAryByRandom(int ary[], int bottom, int top, int rand_min, int rand_max)
{
    int rand_gap = rand_max - rand_min + 1;
    for (int i = bottom; i <= top; i++)
        ary[i] = random() % rand_gap + rand_min;
}

int initAryBySorted(int ary[], int ary_size, int max_interval)
{
    int val = 0;
    for (int i = 0; i < ary_size; i++)
    {
        val += random() % (max_interval + 1);
        ary[i] = val;
    }
}

int getArySize(int *ary)
{
    return sizeof(ary) / sizeof(ary[0]);
}

void printAry(int ary[], int bottom, int top)
{
    printf("[");
    for (int i = bottom; i <= top; i++)
    {
        if (i == bottom)
            printf("%d", ary[i]);
        else
            printf(", %d", ary[i]);
    }
    printf("]");
}

void reverseAry(int ary[], int bottom, int top)
{
    for (int i = bottom; i < bottom + ((top + 1) - bottom) / 2; i++)
        swap(&ary[i], &ary[top - i]);
}