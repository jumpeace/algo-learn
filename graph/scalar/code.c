#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "../../helpers/ary.h"

#define SIZE 5
int nodes[SIZE][SIZE];
int visited[SIZE];
void setup()
{
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            nodes[j][i] = false;

    nodes[0][1] = true;
    nodes[1][0] = true;

    nodes[1][2] = true;
    nodes[2][1] = true;

    nodes[3][4] = true;
    nodes[4][3] = true;

    for (int i = 0; i < SIZE; i++)
        visited[i] = false;
}
void visit(int visit_i)
{
    if (visited[visit_i])
        return;
    visited[visit_i] = true;
    for (int i = 0; i < SIZE; i++)
    {
        if ((i == visit_i || visited[i]) || !nodes[visit_i][i])
            continue;
        printf("%d->%d ", visit_i, i);
        visit(i);
    }
}
void visit_all()
{
    for (int j = 0; j < SIZE; j++)
        visited[j] = false;

    puts("[visit_all]");
    for (int i = 0; i < SIZE; i++)
        visit(i);
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
        visit(i);
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