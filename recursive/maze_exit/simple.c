#include <stdio.h>
#include <stdbool.h>

typedef struct
{
    int x;
    int y;
} Xy;

#define MAP_H 7
#define MAP_W 7

#define WAL 0   // 壁
#define FLR 1   // 訪問済でない床
#define VSD 2   // 訪問済

int map[MAP_H][MAP_W] = {
    {WAL, WAL, WAL, WAL, WAL, WAL, WAL},
    {WAL, FLR, FLR, FLR, FLR, FLR, WAL},
    {WAL, FLR, WAL, FLR, WAL, FLR, WAL},
    {WAL, FLR, FLR, WAL, FLR, WAL, WAL},
    {WAL, WAL, FLR, WAL, FLR, WAL, WAL},
    {WAL, FLR, FLR, FLR, FLR, FLR, WAL},
    {WAL, WAL, WAL, WAL, WAL, WAL, WAL},
};

Xy record[(MAP_H - 2) * (MAP_W - 2)];
int record_p;

// 1経路の迷路の探索
bool visit(int x, int y, Xy end)
{
    map[y][x] = VSD;

    record[record_p].x = x;
    record[record_p].y = y;
    record_p++;

    if (x == end.x && y == end.y) 
        return true;

    bool is_success = false;

    if (!is_success && map[y][x + 1] == FLR) 
        is_success = visit(x + 1, y, end);
    if (!is_success && map[y + 1][x] == FLR) 
        is_success = visit(x, y + 1, end);
    if (!is_success && map[y][x - 1] == FLR) 
        is_success = visit(x - 1, y, end);
    if (!is_success && map[y - 1][x] == FLR) 
        is_success = visit(x, y - 1, end);
    
    if (!is_success) 
        record_p--;
    return is_success;
}

int main(int argc, char *argv[])
{
    Xy start;
    start.x = 1;
    start.y = 1;
    Xy end;
    end.x = 5;
    end.y = 5;

    record_p = 0;

    bool is_success = visit(start.x, start.y, end);
    if (!is_success)
        printf("出口までの経路が見つかりませんでした\n");
    else {
        printf("出口までの経路が見つかりました\n出口までの経路: ");
        for (int p = 0; p < record_p; p++) 
            printf("(%d, %d) ", record[p].x, record[p].y);   
        printf("\n");
    }
    return 0;
}