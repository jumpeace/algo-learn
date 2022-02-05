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

// 上方移動
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

void addHeap(Heap* heap, int data) {
    heap->data[heap->num++] = data;
}

// 下方移動
void moveDown(Heap *heap, int top) {
    if (top > heap->num - 1)
        return;

    int parent_i, child_i;
    int max_i = top;

    // 下側からすべての親に関して実行
    for (int i = max_i / 2; i >= 0; i--) {
        parent_i = i;
        child_i = (parent_i + 1) * 2 - 1;

        while(child_i <= max_i) {
            // ある親の子の中で最小の子を選ぶ
            if (child_i <= max_i - 1 && heap->data[child_i + 1] < heap->data[child_i])
                child_i++;
            // 親 <= 最小の子ならOK
            if (heap->data[parent_i] <= heap->data[child_i])
                break;
            // 親 > 最小の子ならば交換する
            swap(&heap->data[parent_i], &heap->data[child_i]);

            // 親と交換した子とその子に関してもう一度調べる
            parent_i = child_i;
            child_i = parent_i * 2;
        }
    }
}

int main(void) {
    // 上方移動
    Heap* heap = init();
    addByRise(heap, 1);
    addByRise(heap, 5);
    addByRise(heap, 3);
    addByRise(heap, 9);
    addByRise(heap, 2);

    printf("addedByRise=");
    printAry(heap->data, 0, heap->num - 1);
    printf("\n");

    free(heap);


    heap = init();
    addHeap(heap, 1);
    addHeap(heap, 5);
    addHeap(heap, 3);
    addHeap(heap, 9);
    addHeap(heap, 2);

    printf("added=");
    printAry(heap->data, 0, heap->num - 1);
    printf("\n");

    moveDown(heap, heap->num - 1);

    printf("moveedDown=");
    printAry(heap->data, 0, heap->num - 1);
    printf("\n");

    free(heap);


    return 0;
}