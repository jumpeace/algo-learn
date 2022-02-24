#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "../../helpers/ary.h"

typedef struct
{
    int size;
    int *data;
    int in_p;
    int out_p;
} Ling;

Ling *init(int size)
{
    if (size < 1)
        return NULL;

    Ling *ling = (Ling *)malloc(sizeof(Ling));
    ling->size = size;
    ling->data = (int *)malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++)
        ling->data[i] = 0;
    ling->in_p = 0;
    ling->out_p = 0;
    return ling;
}

bool ling_add(Ling *ling, int val)
{
    if (ling->in_p == ling->out_p && ling->data[ling->in_p] != 0)
        return false;
    if (val <= 0)
        return false;

    ling->data[ling->in_p] = val;
    ling->in_p = (ling->in_p + (ling->size - 1)) % ling->size;
    return true;
}

int ling_remove(Ling *ling)
{
    if (ling->out_p == ling->in_p && ling->data[ling->in_p] == 0)
        return false;
    
    int result = ling->data[ling->out_p];
    ling->data[ling->out_p] = 0;
    ling->out_p = (ling->out_p + (ling->size - 1)) % ling->size;

    return result;
}

void ling_print(Ling *ling)
{
    printf("[");

    int prev_in_p = (ling->in_p + 1) % ling->size;
    if (!(ling->in_p == ling->out_p && ling->data[ling->in_p] == 0)) {
        if (prev_in_p > ling->out_p) {
            for (int i = prev_in_p; i < ling->size; i++)
                if (i == prev_in_p)
                    printf("%d", ling->data[i]);
                else
                    printf(", %d", ling->data[i]);
            for (int i = 0; i <= ling->out_p; i++)
                printf(", %d", ling->data[i]);
        }
        else {
            for (int i = prev_in_p; i <= ling->out_p; i++)
                if (i == prev_in_p)
                    printf("%d", ling->data[i]);
                else
                    printf(", %d", ling->data[i]);
        }
    }
    printf("]");
}

int ling_free(Ling *ling)
{
    free(ling->data);
    free(ling);
}

int main(int argc, char *argv[])
{
    Ling *ling = init(5);

    printf("ling:");
    ling_print(ling);
    printf("\n");

    ling_add(ling, 1);
    ling_add(ling, 3);
    ling_add(ling, 5);
    ling_add(ling, 7);
    ling_add(ling, 9);
    ling_add(ling, 11);

    printf("ling:");
    ling_print(ling);
    printf("\n");

    while (true)
    {
        int result = ling_remove(ling);
        printf("remove: %d <- ", result);
        ling_print(ling);
        printf("\n");
        if (!result)
            break;
    }

    ling_free(ling);

    return 0;
}