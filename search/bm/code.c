#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char character;
    int value;
} Skip;

int searchSkipTable(Skip skip_table[], char character, int bottom, int top)
{
    int result = -1;
    for (int skip_i = bottom; skip_i <= top; skip_i++)
    {
        if (character == skip_table[skip_i].character)
        {
            result = skip_i;
            break;
        }
    }
    return result;
}

Skip *getSkipTable(char key[])
{
    int key_len = strlen(key);
    Skip *skip_table = (Skip *)malloc(sizeof(Skip) * (key_len - 1));

    int skip_count = 0;
    for (int key_i = 0; key_i < key_len - 1; key_i++)
    {
        int key_right_p = (key_len - 2) - key_i;

        // スキップテーブルにすでにあったらスキップ
        if (searchSkipTable(skip_table, key[key_right_p], 0, skip_count - 1) != -1)
            continue;

        skip_table[skip_count].character = *(key + key_right_p);
        skip_table[skip_count].value = key_i + 1;
        skip_count++;
    }

    return skip_table;
}

int bmSearch(char text[], char key[])
{
    int text_len = strlen(text);
    int key_len = strlen(key);

    // スキップテーブルを作成
    Skip *skip_table = getSkipTable(key);

    int result = -1;
    int text_p = 0;
    int key_p = key_len - 1;
    while ((text_p + key_len - 1) <= text_len - 1)
    {
        if (text[text_p + key_p] == key[key_p])
        {
            // key文字列を左端まで一致したらOK
            if (key_p == 0)
            {
                result = text_p;
                break;
            }
            // key文字列を左端まで探索する
            key_p--;
        }
        else
        {
            // スキップ値を決定
            int skip_idx = searchSkipTable(skip_table, text[text_p + (key_len - 1)],
                                           0, key_len - 2);
            int skip_value = (skip_idx != -1) ? skip_table[skip_idx].value : key_len;

            // textポインタとkeyポインタを更新
            text_p += skip_value;
            key_p = key_len - 1;
            continue;
        }
    }

    return result;
}

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        printf("コマンド引数は2つ必要です。\n");
        return -1;
    }

    char *text = argv[1];
    char *key = argv[2];
    int result = bmSearch(text, key);
    printf("被検索文字列:%s, 検索文字列:%s\n", text, key);
    if (result != -1) 
        printf("%d~%d文字目に見つかりました。\n", result + 1, (result + 1) + ((int)strlen(key) - 1));
    else
        printf("見つかりませんでした。\n");

    return 0;
}