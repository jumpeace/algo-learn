#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct tagNode
{
    struct tagNode *prev; // 前の要素へのポインタ
    struct tagNode *next; // 後の要素へのポインタ
    int data;
} Node;

typedef struct
{
    Node *first_node;
    Node *last_node;
} Stack;

// 引数にStack*型を取るとうまく行かない(ポインタは参照渡しができないから)
Stack *stack_init()
{
    Stack *stack;

    stack = (Stack *)malloc(sizeof(Stack));

    stack->first_node = NULL;
    stack->last_node = NULL;

    return stack;
}

void stack_add(Stack *stack, int data)
{
    Node *new_node = (Node *)malloc(sizeof(Node));

    new_node->data = data;
    new_node->next = NULL;

    if (stack->last_node == NULL)
    {
        new_node->prev = NULL;
        stack->first_node = new_node;
        stack->last_node = new_node;
    }
    else
    {
        new_node->prev = stack->last_node;
        stack->last_node->next = new_node;
        stack->last_node = new_node;
    }
}

bool stack_remove(Stack *stack)
{
    Node *remove_node = stack->last_node;
    if (remove_node == NULL)
        return false;

    Node *next_last_node = remove_node->prev;
    if (next_last_node == NULL)
    {
        stack->first_node = NULL;
        stack->last_node = NULL;
    }
    else
    {
        next_last_node->next = NULL;
        stack->last_node = next_last_node;
    }

    free(remove_node);

    return true;
}

void stack_print(Stack *stack)
{
    printf("[");
    for (Node *this_node = stack->first_node; this_node != NULL; this_node = this_node->next)
    {
        if (this_node == stack->first_node)
            printf("%d", this_node->data);
        else
            printf(", %d", this_node->data);
    }
    printf("]");
}

Stack *stack_initByAry(int ary[], int ary_size)
{
    Stack *stack = stack_init();

    for (int i = 0; i < ary_size; i++)
        stack_add(stack, ary[i]);

    return stack;
}

Stack *stack_removeAll(Stack *stack)
{
    while (stack_remove(stack))
        ;
}

int main(int argc, char *argv[])
{
    int ary[3] = {1, 2, 2};
    Stack *stack = stack_initByAry(ary, 3);
    printf("stack=");
    stack_print(stack);
    printf("\n");

    stack_removeAll(stack);
    printf("stack=");
    stack_print(stack);
    printf("\n");
    
    return 0;
}
