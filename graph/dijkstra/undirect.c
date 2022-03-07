#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "../../helpers/ary.h"

#define SIZE 8
#define INF 10000
int dists[SIZE][SIZE];

void setDist(int node1, int node2, int root_num)
{
    if (node1 < 0 || node1 >= SIZE)
        return;
    if (node2 < 0 || node2 >= SIZE)
        return;
    dists[node1][node2] = root_num;
    dists[node2][node1] = root_num;
}
void setup()
{
    // distsの初期化
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            dists[j][i] = INF;
    for (int i = 0; i < SIZE; i++)
        dists[i][i] = 0;

    setDist(0, 1, 1);
    setDist(0, 2, 7);
    setDist(0, 3, 2);
    setDist(1, 4, 2);
    setDist(1, 5, 4);
    setDist(2, 5, 2);
    setDist(2, 6, 3);
    setDist(3, 6, 5);
    setDist(4, 5, 1);
    setDist(5, 7, 6);
    setDist(6, 7, 2);
}

/*
    --- ダイクストラ法 ---
    (1) スタートの節点を決める
    (2) スタートの節点の距離を0とする
    (3) すべての節点の最短距離が決まるまでループする (ループではスタートから節点Pの最短距離が増加していく)
        ①未定節点の中で, スタートから最短距離の節点(節点Pとする)を探す。
        ②節点Pはスタートからの最短距離が確定する。
    　      (今までのループの③で確定節点を利用した最短ルートを探せているし, 未定節点を通るルートだと現在値以上になるから)
        ③節点Pを経由した場合のスタートから未定節点までの距離をすべて調べ, 現在値よりも小さかったら更新する。
    ※ 用語
        ・未定節点 ... まだ最短距離が決まっていない節点
        ・確定節点 ... すでに最短距離が決まっている節点
*/

void findMinRoot(int start_node)
{
    bool is_defined[SIZE];
    int leng[SIZE];
    int prev_nodes[SIZE];

    for (int i = 0; i < SIZE; i++)
    {
        is_defined[i] = false;
        leng[i] = INF;
    }
    leng[start_node] = 0;
    prev_nodes[start_node] = -1;

    while (true)
    {
        // スタートから最短の節点を探す
        int min_node = -1;  // スタートから最短の節点
        int min_leng = INF; // 最短の節点までの距離
        for (int this_node = 0; this_node < SIZE; this_node++)
        {
            if (is_defined[this_node])
                continue;
            if (leng[this_node] < min_leng)
            {
                min_node = this_node;
                min_leng = leng[this_node];
            }
        }

        if (min_node == -1)
        {
            printf("グラフは連結されていない\n");
            break;
        }
        // 最短距離を確定する
        is_defined[min_node] = true;

        // 現状よりも最短のルートを見つけたら, その距離を反映させる
        for (int this_node = 0; this_node < SIZE; this_node++)
        {
            if (leng[min_node] + dists[min_node][this_node] < leng[this_node])
            {
                leng[this_node] = leng[min_node] + dists[min_node][this_node];
                prev_nodes[this_node] = min_node;
            }
        }

        // すべての節点の最短距離が計算できたら終了
        bool is_all_defined = true;
        for (int j = 0; j < SIZE; j++)
        {
            if (!is_defined[j])
            {
                is_all_defined = false;
                break;
            }
        }
        if (is_all_defined)
            break;
    }

    printf("start: %d\n", start_node);
    for (int this_node = 0; this_node < SIZE; this_node++) {
        printf("%d->%d[%d]: %d", start_node, this_node, leng[this_node], this_node);

        int prev_node = this_node, this_node2 = prev_nodes[this_node];
        while(this_node2 != -1) {
            printf(" <-(%d)- %d", dists[prev_node][this_node2], this_node2);
            prev_node = this_node2;
            this_node2 = prev_nodes[this_node2];
        }
        printf("\n");
    }

}

int main(int argc, char *args[])
{
    setup();
    findMinRoot(2);
    return 0;
}