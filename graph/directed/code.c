#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "../../helpers/ary.h"

#define SIZE 5
int nodes[SIZE][SIZE];
int visited[SIZE];
typedef struct
{
    int data[SIZE];
    int count;
} Nodes;
typedef struct
{
    Nodes data[SIZE];
    int count;
} Nodess;

void setup()
{
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            nodes[j][i] = false;

    nodes[0][1] = true;

    nodes[1][0] = true;
    nodes[1][3] = true;

    nodes[2][4] = true;

    nodes[3][0] = true;

    for (int i = 0; i < SIZE; i++)
        visited[i] = false;
}

void visit(int visit_i, bool is_print)
{
    if (visited[visit_i] == true)
        return;
    visited[visit_i] = true;
    for (int i = 0; i < SIZE; i++)
    {
        if (i == visit_i || !nodes[visit_i][i])
            continue;
        if (is_print)
            printf("%d->%d ", visit_i, i);
        visit(i, true);
    }
}

void visit_all()
{
    for (int j = 0; j < SIZE; j++)
        visited[j] = false;

    puts("[visit_all]");
    for (int i = 0; i < SIZE; i++)
        visit(i, true);
    printf("\n");
}

void visit_from_all()
{
    puts("[visit_from_all]");
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
            visited[j] = false;

        printf("%d: ", i);
        visit(i, true);
        printf("\n");
    }
}

int main(int argc, char *argv[])
{
    setup();
    visit_all();
    visit_from_all();
    return 0;
}
