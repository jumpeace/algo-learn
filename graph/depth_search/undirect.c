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
    // nodesの初期化
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            nodes[j][i] = false;

    nodes[0][1] = true;
    nodes[1][0] = true;

    nodes[1][2] = true;
    nodes[2][1] = true;

    nodes[3][4] = true;
    nodes[4][3] = true;

    // visitedの初期化
    for (int i = 0; i < SIZE; i++)
        visited[i] = false;
}
void depth_visit(int visit_i)
{
    if (visited[visit_i])
        return;
    visited[visit_i] = true;
    for (int i = 0; i < SIZE; i++)
    {
        if ((i == visit_i || visited[i]) || !nodes[visit_i][i])
            continue;
        printf("%d->%d ", visit_i, i);
        depth_visit(i);
    }
}
void depth_visit_all()
{
    for (int j = 0; j < SIZE; j++)
        visited[j] = false;

    puts("[visit_all]");
    for (int i = 0; i < SIZE; i++)
        depth_visit(i);
    printf("\n");
}

void depth_visit_from_all()
{
    puts("[visit_from_all]");
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
            visited[j] = false;

        printf("%d: ", i);
        depth_visit(i);
        printf("\n");
    }
}

int main(int argc, char *argv[])
{
    setup();
    depth_visit_all();
    depth_visit_from_all();
    return 0;
}