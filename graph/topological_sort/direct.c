#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "../../helpers/ary.h"

#define SIZE 5
int nodes[SIZE][SIZE];
// 通過しただけのもの
int passed[SIZE];
// 枝もすべて通過したもの
int visited[SIZE];

int passed_idxs[SIZE];
int passed_idxs_count;

int print_idxs[SIZE];
int print_idxs_count;

void setup()
{
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            nodes[j][i] = false;

    nodes[0][1] = true;
    nodes[0][3] = true;

    nodes[1][2] = true;
    nodes[1][3] = true;

    nodes[2][0] = true;

    nodes[3][2] = true;

    for (int i = 0; i < SIZE; i++)
    {
        passed[i] = false;
        visited[i] = false;
    }

    passed_idxs_count = 0;
    print_idxs_count = 0;
}

// TODO (あとでもいい) 0->1->3, 0->1->3->2のループがあったとき, 0->1->3->2のループを見つけられない
void depth_visit(int visit_idx)
{

    if (visited[visit_idx] == true)
        return;

    if (!visited[visit_idx] && passed[visit_idx])
    {
        if (passed_idxs_count >= 2) {
            printf("loop: ");
            for (int j = 0; j < passed_idxs_count; j++)
                (j == 0) ? printf("%d", passed_idxs[j]) : printf(", %d", passed_idxs[j]);
            printf("\n");
        }
        return;
    }

    passed[visit_idx] = true;
    passed_idxs[passed_idxs_count++] = visit_idx;

    for (int next_visit_idx = 0; next_visit_idx < SIZE; next_visit_idx++)
    {
        if (next_visit_idx == visit_idx || !nodes[visit_idx][next_visit_idx])
            continue;
        depth_visit(next_visit_idx);
    }

    visited[visit_idx] = true;
    passed_idxs_count--;
    print_idxs[print_idxs_count++] = visit_idx;
}

void depth_visit_all()
{
    for (int i = 0; i < SIZE; i++)
    {
        passed[i] = false;
        visited[i] = false;
    }

    passed_idxs_count = 0;
    print_idxs_count = 0;

    for (int i = 0; i < SIZE; i++)
        depth_visit(i);

    printf("[topological_sort] ");
    for (int i = print_idxs_count - 1; i >= 0; i--)
        (i == print_idxs_count - 1) ? printf("%d", print_idxs[i]) : printf(", %d", print_idxs[i]);
    printf("\n");
}

int main(int argc, char *argv[])
{
    setup();
    depth_visit_all();
    return 0;
}
