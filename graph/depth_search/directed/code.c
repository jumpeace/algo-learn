#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "../../../helpers/ary.h"

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

    nodes[4][2] = true;

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
        visit(i, is_print);
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

// 非連結グラフの探索
void print_con_nodess()
{
    Nodess con_nodess;
    con_nodess.count = 0;

    puts("[print_con_nodess]");
    for (int i = 0; i < SIZE; i++)
    {

        // 非連結グラフのグループを作成
        for (int j = 0; j < SIZE; j++)
            visited[j] = false;
        visit(i, false);

        // 非連結グラフのいずれかのグループに変数iか訪問したところがあるかを判定
        int con_nodess_idx = con_nodess.count;
        bool is_in_con_nodes = false;
        for (int j = 0; j < con_nodess.count; j++)
        {
            Nodes jnodes = con_nodess.data[j];
            for (int k = 0; k < jnodes.count; k++)
            {
                if (i == jnodes.data[k])
                {
                    is_in_con_nodes = true;
                    con_nodess_idx = j;
                    break;
                }
                for (int l = 0; l < SIZE; l++)
                {
                    if (visited[l] && l == jnodes.data[k])
                    {
                        is_in_con_nodes = true;
                        con_nodess_idx = j;
                        break;
                    }
                }
                if (is_in_con_nodes)
                    break;
            }
            if (is_in_con_nodes)
                break;
        }

        if (!is_in_con_nodes)
            con_nodess.data[con_nodess_idx].count = 0;
        for (int j = 0; j < SIZE; j++)
        {
            if (!visited[j])
                continue;

            // すでにグループにあるか
            bool is_exists = false;
            if (is_in_con_nodes)
            {
                for (int k = 0; k < con_nodess.data[con_nodess_idx].count; k++)
                {
                    if (j == con_nodess.data[con_nodess_idx].data[k])
                    {
                        is_exists = true;
                        break;
                    }
                }
            }
            if (!is_exists)
                con_nodess.data[con_nodess_idx].data[con_nodess.data[con_nodess_idx].count++] = j;
        }
        if (!is_in_con_nodes)
            con_nodess.count++;
    }

    for (int i = 0; i < con_nodess.count; i++)
    {
        Nodes inodes = con_nodess.data[i];
        printAry(inodes.data, 0, inodes.count - 1);
        printf("\n");
    }
}

int main(int argc, char *argv[])
{
    setup();
    visit_all();
    visit_from_all();
    print_con_nodess();
    return 0;
}
