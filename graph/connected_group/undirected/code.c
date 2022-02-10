#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "../../../helpers/ary.h"

#define SIZE 5
int nodes[SIZE][SIZE];
int visited[SIZE];
typedef struct {
    int data[SIZE];
    int count;
} Nodes;
typedef struct {
    Nodes data[SIZE];
    int count;
} Nodess;

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
        depth_visit(i);
    }
}

// 非連結グラフの探索
void print_con_nodess() {

    Nodess con_nodess;
    con_nodess.count = 0;

    puts("[print_con_nodess]");
    for (int i = 0; i < SIZE; i++)
    {
        // 非連結グラフのいずれかのグループにあるかを判定
        bool is_in_con_nodes = false;
        for (int j = 0; j < con_nodess.count; j++) {
            Nodes jnodes = con_nodess.data[j];
            for (int k = 0; k < jnodes.count; k++) {
                if (i == jnodes.data[k]) {
                    is_in_con_nodes = true;
                    break;
                }
            }
            if (is_in_con_nodes)
                break;
        }
        if (is_in_con_nodes)
            continue;

        // 非連結グラフのグループを作成
        for (int j = 0; j < SIZE; j++)
            visited[j] = false;
        depth_visit(i);

        con_nodess.data[con_nodess.count].count = 0;
        for (int j = 0; j < SIZE; j++)
            if (visited[j]) 
                con_nodess.data[con_nodess.count].data[con_nodess.data[con_nodess.count].count++] = j;
        con_nodess.count++;
    }

    for (int i = 0; i < con_nodess.count; i++) {
        Nodes inodes = con_nodess.data[i];
        printAry(inodes.data, 0, inodes.count - 1);
        printf("\n");
    }
}

int main(int argc, char *argv[])
{
    setup();
    print_con_nodess();
    return 0;
}