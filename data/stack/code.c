#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "../../helpers/ary.h"

typedef struct
{
    int size;
    int *data;
    int count;
} Stack;

Stack *init(int size)
{
    if (size < 1)
        return NULL;

    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->size = size;
    stack->data = (int *)malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++)
        stack->data[i] = 0;
    stack->count = 0;
    return stack;
}

bool stack_add(Stack *stack, int val)
{
    if (stack->count >= stack->size - 1)
        return false;
    if (val <= 0)
        return false;

    stack->data[stack->count++] = val;
    return true;
}

int stack_remove(Stack *stack)
{
    if (stack->count <= 0)
        return false;
    
    stack->count--;
    int result = stack->data[stack->count];
    stack->data[stack->count] = 0;

    return result;
}

int stack_print(Stack *stack)
{
    printAry(stack->data, 0, stack->count - 1);
}

int stack_free(Stack *stack)
{
    free(stack->data);
    free(stack);
}

int main(int argc, char *argv[])
{
    Stack *stack = init(10);

    printf("stack:");
    stack_print(stack);
    printf("\n");

    stack_add(stack, 1);
    stack_add(stack, 2);
    stack_add(stack, 3);

    printf("stack:");
    stack_print(stack);
    printf("\n");

    while (true)
    {
        int result = stack_remove(stack);
        printf("remove: %d <- ", result);
        stack_print(stack);
        printf("\n");
        if (!result)
            break;
    }

    stack_free(stack);

    return 0;
}