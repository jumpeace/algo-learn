#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../../helpers/base.h"
#include "../../helpers/ary.h"

typedef struct {
    int data[100];
    int num;
} Heap;

Heap* init() {
    Heap* heap = (Heap*)malloc(sizeof(Heap));
    heap->num = 0;
    return heap;
}

void addByRise(Heap *heap, int data) {
    heap->data[heap->num] = data;

    int child_i = heap->num;
    int parent_i = child_i / 2;
    while (child_i >= 2 && heap->data[child_i] < heap->data[parent_i]){
        swap(&heap->data[child_i], &heap->data[parent_i]);
        child_i = parent_i;
        parent_i = child_i / 2;
    }

    heap->num++;
}

int main(void) {
    Heap* heap = init();
    addByRise(heap, 1);
    addByRise(heap, 5);
    addByRise(heap, 3);
    addByRise(heap, 9);
    addByRise(heap, 2);

    printf("heap=");
    printAry(heap->data, 0, heap->num - 1);
    printf("\n");

    return 0;
}