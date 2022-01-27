#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct tagListNode
{
    struct tagListNode *prev; // 前の要素へのポインタ
    struct tagListNode *next; // 後の要素へのポインタ
    int data;
} ListNode;

typedef struct
{
    ListNode *first_node;
    ListNode *last_node;
} List;

// 引数にList*型を取るとうまく行かない(ポインタは参照渡しができないから)
List *list_init()
{
    List *list;

    list = (List *)malloc(sizeof(List));

    list->first_node = NULL;
    list->last_node = NULL;

    return list;
}

void list_addFirst(List *list, int data)
{
    ListNode *new_node = (ListNode *)malloc(sizeof(ListNode));

    new_node->data = data;
    new_node->prev = NULL;
    
    if (list->first_node == NULL)
    {
        new_node->next = NULL;
        list->first_node = new_node;
        list->last_node = new_node;
    }
    else
    {
        new_node->next = list->first_node;
        list->first_node->prev = new_node;
        list->first_node = new_node;
    }
}

void list_addLast(List *list, int data)
{
    ListNode *new_node = (ListNode *)malloc(sizeof(ListNode));

    new_node->data = data;
    new_node->next = NULL;

    if (list->last_node == NULL)
    {
        new_node->prev = NULL;
        list->first_node = new_node;
        list->last_node = new_node;
    }
    else
    {
        new_node->prev = list->last_node;
        list->last_node->next = new_node;
        list->last_node = new_node;
    }
}

bool list_removeFirst(List *list)
{
    ListNode *remove_node = list->first_node;
    if (remove_node == NULL)
        return false;

    ListNode *next_first_node = remove_node->next;
    if (next_first_node == NULL)
    {
        list->first_node = NULL;
        list->last_node = NULL;
    }
    else
    {
        next_first_node->prev = NULL;
        list->first_node = next_first_node;
    }

    free(remove_node);

    return true;
}

bool list_removeLast(List *list)
{
    ListNode *remove_node = list->last_node;
    if (remove_node == NULL)
        return false;

    ListNode *next_last_node = remove_node->prev;
    if (next_last_node == NULL)
    {
        list->first_node = NULL;
        list->last_node = NULL;
    }
    else
    {
        next_last_node->next = NULL;
        list->last_node = next_last_node;
    }

    free(remove_node);

    return true;
}

void list_print(List *list)
{
    printf("[");
    for (ListNode *this_node = list->first_node; this_node != NULL; this_node = this_node->next)
    {
        if (this_node == list->first_node)
            printf("%d", this_node->data);
        else
            printf(", %d", this_node->data);
    }
    printf("]");
}

int list_size(List *list)
{
    int size = 0;

    for (ListNode *this_node = list->first_node; this_node != NULL; this_node = this_node->next)
        size++;

    return size;
}

List *list_initByAry(int ary[], int ary_size)
{
    List *list = list_init();

    for (int i = 0; i < ary_size; i++)
        list_addLast(list, ary[i]);

    return list;
}

List *list_removeAll(List *list)
{
    while (list_removeLast(list))
        ;
}

int main(int argc, char *argv[])
{
    int ary[3] = {1, 2, 2};
    List *list = list_initByAry(ary, 3);
    printf("list=");
    list_print(list);
    printf("\n");

    list_removeAll(list);
    printf("list=");
    list_print(list);
    printf("\n");
    
    return 0;
}
