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
    nodes[0][1] = true;

    nodes[1][2] = true;
    nodes[2][1] = true;

    nodes[2][3] = true;
    nodes[3][2] = true;

    nodes[1][4] = true;
    nodes[4][1] = true;

    for (int i = 0; i < SIZE; i++) 
        visited[i] = false;
}

void visit(int visit_i)
{
    if (visited[visit_i] == true)
        return;
    visited[visit_i] = true;
    for (int i = visit_i + 1; i < SIZE; i++) {
        if (!nodes[visit_i][i])
            continue;
        printf("%d->%d ", visit_i, i);
        visit(i);
    }
}
int main(int argc, char *argv[])
{
    setup();
    visit(0);
    printf("\n");
    return 0;
}
