#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "../../helpers/ary.h"

typedef struct
{
    int size;
    int *data;
    int count;
} Queue;

Queue *init(int size)
{
    if (size < 1)
        return NULL;

    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->size = size;
    queue->data = (int *)malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++)
        queue->data[i] = 0;
    queue->count = 0;
    return queue;
}

bool queue_add(Queue *queue, int val)
{
    if (queue->count >= queue->size - 1)
        return false;
    if (val <= 0)
        return false;

    for (int i = queue->count - 1; i >= 0; i--) {
        queue->data[i + 1] = queue->data[i];
    }
    queue->data[0] = val;
    queue->count++;
    return true;
}

int queue_remove(Queue *queue)
{
    if (queue->count <= 0)
        return false;
    
    queue->count--;
    int result = queue->data[queue->count];
    queue->data[queue->count] = 0;

    return result;
}

int queue_print(Queue *queue)
{
    printAry(queue->data, 0, queue->count - 1);
}

int queue_free(Queue *queue)
{
    free(queue->data);
    free(queue);
}

int main(int argc, char *argv[])
{
    Queue *queue = init(10);

    printf("queue:");
    queue_print(queue);
    printf("\n");

    queue_add(queue, 1);
    queue_add(queue, 2);
    queue_add(queue, 3);

    printf("queue:");
    queue_print(queue);
    printf("\n");

    while (true)
    {
        int result = queue_remove(queue);
        printf("remove: %d <- ", result);
        queue_print(queue);
        printf("\n");
        if (!result)
            break;
    }

    queue_free(queue);

    return 0;
}