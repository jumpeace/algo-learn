#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct tabNode
{
    struct tabNode *prev; // 前の要素へのポインタ
    struct tabNode *next; // 後の要素へのポインタ
    int data;
} Node;

typedef struct
{
    Node *first_node;
    Node *last_node;
} Queue;

// 引数にQueue*型を取るとうまく行かない(ポインタは参照渡しができないから)
Queue *queue_init()
{
    Queue *queue;

    queue = (Queue *)malloc(sizeof(Queue));

    queue->first_node = NULL;
    queue->last_node = NULL;

    return queue;
}

void queue_add(Queue *queue, int data)
{
    Node *new_node = (Node *)malloc(sizeof(Node));

    new_node->data = data;
    new_node->prev = NULL;
    
    if (queue->first_node == NULL)
    {
        new_node->next = NULL;
        queue->first_node = new_node;
        queue->last_node = new_node;
    }
    else
    {
        new_node->next = queue->first_node;
        queue->first_node->prev = new_node;
        queue->first_node = new_node;
    }
}

bool queue_remove(Queue *queue)
{
    Node *remove_node = queue->last_node;
    if (remove_node == NULL)
        return false;

    Node *next_last_node = remove_node->prev;
    if (next_last_node == NULL)
    {
        queue->first_node = NULL;
        queue->last_node = NULL;
    }
    else
    {
        next_last_node->next = NULL;
        queue->last_node = next_last_node;
    }

    free(remove_node);

    return true;
}

void queue_print(Queue *queue)
{
    printf("[");
    for (Node *this_node = queue->first_node; this_node != NULL; this_node = this_node->next)
    {
        if (this_node == queue->first_node)
            printf("%d", this_node->data);
        else
            printf(", %d", this_node->data);
    }
    printf("]");
}

Queue *queue_initByAry(int ary[], int ary_size)
{
    Queue *queue = queue_init();

    for (int i = 0; i < ary_size; i++)
        queue_add(queue, ary[i]);

    return queue;
}

Queue *queue_removeAll(Queue *queue)
{
    while (queue_remove(queue))
        ;
}

int main(int argc, char *argv[])
{
    int ary[3] = {1, 2, 2};
    Queue *queue = queue_initByAry(ary, 3);
    printf("queue=");
    queue_print(queue);
    printf("\n");

    queue_remove(queue);

    printf("queue=");
    queue_print(queue);
    printf("\n");

    queue_removeAll(queue);
    printf("queue=");
    queue_print(queue);
    printf("\n");
    
    return 0;
}
