#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "../../helpers/ary.h"

#define SIZE 4
int nodes[SIZE][SIZE];

int r_nodes[SIZE * SIZE];
int r_node_num;
int r_node_count;

void connect_undirect(int idx1, int idx2, int root_num) {
    if (idx1 < 0 || idx1 >= SIZE)
        return;
    if (idx2 < 0 || idx2 >= SIZE)
        return;
    nodes[idx1][idx2] = root_num;
    nodes[idx2][idx1] = root_num;
    r_node_num += root_num;
}
void setup()
{
    // nodesの初期化
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            nodes[j][i] = 0;
    r_node_num= 0;

    connect_undirect(0, 1, 1);
    connect_undirect(0, 3, 1);
    connect_undirect(1, 2, 1);
    connect_undirect(1, 3, 2);
    connect_undirect(2, 3, 1);
}

int start_idx;
int find_num;
void find_one_stroke(int visit_idx)
{
    r_nodes[r_node_count] = visit_idx;
    if (r_node_count == r_node_num && visit_idx == start_idx)
    {
        printf("解%d: ", ++find_num);
        for (int j = 0; j <= r_node_num; j++)
            (j == r_node_num) ? printf("%d", r_nodes[j]) : printf("%d->", r_nodes[j]);
        printf("\n");
        return;
    }

    for (int next_idx = 0; next_idx < SIZE; next_idx++)
    {
        if (nodes[visit_idx][next_idx] == 0)
            continue;

        nodes[visit_idx][next_idx]--;
        nodes[next_idx][visit_idx]--;
        r_node_count++;
        
        find_one_stroke(next_idx);

        nodes[visit_idx][next_idx]++;
        nodes[next_idx][visit_idx]++;
        r_node_count--;
    }
}

void find_one_stroke_proc(int visit_idx)
{
    start_idx = visit_idx;
    find_num = 0;
    for (int i = 0; i < r_node_num; i++)
        r_nodes[i] = 0;
    r_node_count = 0;
    find_one_stroke(visit_idx);
}

int main(int argc, char *argv[])
{
    setup();
    find_one_stroke_proc(0);
    return 0;
}