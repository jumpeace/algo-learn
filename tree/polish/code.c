#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct tagNode
{
    char val;
    struct tagNode *left;
    struct tagNode *right;
} Node;

// ノードの初期化
Node *init(char val)
{
    Node *node = malloc(sizeof(Node));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// 数式記号かどうか
bool isSymbol(char chr)
{
    switch (chr)
    {
    case '+':
    case '-':
    case '*':
    case '/':
        return true;
    default:
        return false;
    }
}

// ポーランド記法から式の木を作成
Node *createByPrefix(char eq_str[])
{
    int eq_len = strlen(eq_str);
    if (eq_len <= 0)
        return NULL;
    int target_idx = 0;

    Node *node = init(eq_str[target_idx]);
    for (int i = 0; i < eq_len - 1; i++)
        eq_str[i] = eq_str[i + 1];
    eq_str[eq_len - 1] = '\0';

    if (!isSymbol(node->val))
        return node;

    node->left = createByPrefix(eq_str);
    node->right = createByPrefix(eq_str);

    return node;
}

// 逆ポーランド記法から式の木を作成
Node *createByPostfix(char eq_str[])
{
    int eq_len = strlen(eq_str);
    if (eq_len <= 0)
        return NULL;
    int target_idx = eq_len - 1;

    Node *node = init(eq_str[target_idx]);
    eq_str[target_idx] = '\0';

    if (!isSymbol(node->val))
        return node;

    node->right = createByPostfix(eq_str);
    node->left = createByPostfix(eq_str);

    return node;
}

// ポーランド記法で表示
void printByPrefix(Node* node) {
    if (node == NULL) 
        return;
    putchar(node->val);
    printByPrefix(node->left);
    printByPrefix(node->right);
}

// 通常の記法で表示
void printByInfix(Node* node) {
    if (node == NULL) 
        return;
    printByInfix(node->left);
    putchar(node->val);
    printByInfix(node->right);
}

// 逆ポーランド記法で表示
void printByPostfix(Node* node) {
    if (node == NULL) 
        return;
    printByPostfix(node->left);
    printByPostfix(node->right);
    putchar(node->val);
}

int main(int argc, char *argv[])
{
    // char eq_str[] = "-*ab/+cde";
    // Node* root = createByPrefix(eq_str);
    char eq_str[] = "ab*cd+e/-";
    Node* root = createByPostfix(eq_str);

    printf("prefix: ");
    printByPrefix(root);
    printf("\n");

    printf("infix: ");
    printByInfix(root);
    printf("\n");
    
    printf("postfix: ");
    printByPostfix(root);
    printf("\n");
    return 0;
}