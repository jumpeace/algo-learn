#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "../../../helpers/ary.h"

#define SIZE 5
int nodes[SIZE][SIZE];
int visited[SIZE];

void setup()
{
    // nodesの初期化
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            nodes[j][i] = false;

    nodes[0][1] = true;
    nodes[1][0] = true;

    nodes[0][2] = true;
    nodes[2][0] = true;

    nodes[1][3] = true;
    nodes[3][1] = true;

    nodes[3][4] = true;
    nodes[4][3] = true;

    // visitedの初期化
    for (int i = 0; i < SIZE; i++)
        visited[i] = false;
}

void width_visit(int visit_i, bool is_print)
{
    if (is_print)
        puts("[width_visit]");

    int queue[SIZE];
    int head = 0, tail = 0;
    queue[tail++] = visit_i;
    visited[visit_i] = true;
    while (true)
    {
        int this_node = queue[head++];
        for (int branch_node = 0; branch_node < SIZE; branch_node++)
        {
            if (!visited[branch_node] && nodes[this_node][branch_node])
            {
                printf("%d->%d ", this_node, branch_node);
                queue[tail++] = branch_node;
                visited[branch_node] = true;
            }
        }
        if (head == tail)
            break;
    }
    printf("\n");
}

void width_visit_from_all()
{
    puts("[width_visit_from_all]");
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
            visited[j] = false;

        printf("%d: ", i);
        width_visit(i, false);
    }
}

int main(int argc, char *argv[])
{
    setup();
    width_visit(0, true);
    width_visit_from_all();
    return 0;
}