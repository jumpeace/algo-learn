#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifndef __ARY_H__

#define __ARY_H__

int initAryByRandom(int[], int, int, int, int);

int initAryBySorted(int[], int, int);

int getArySize(int[]);

void printAry(int[], int, int);

void reverseAry(int[], int, int);

#endif