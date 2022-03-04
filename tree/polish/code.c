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

Node *init(char val)
{
    Node *node = malloc(sizeof(Node));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

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

Node *createTreeByPrefix(char eq_str[])
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

    node->left = createTreeByPrefix(eq_str);
    node->right = createTreeByPrefix(eq_str);

    return node;
}

Node *createTreeByPostfix(char eq_str[])
{
    int eq_len = strlen(eq_str);
    if (eq_len <= 0)
        return NULL;
    int target_idx = eq_len - 1;

    Node *node = init(eq_str[target_idx]);
    eq_str[target_idx] = '\0';

    if (!isSymbol(node->val))
        return node;

    node->right = createTreeByPostfix(eq_str);
    node->left = createTreeByPostfix(eq_str);

    return node;
}

void printByPrefix(Node* node) {
    if (node == NULL) 
        return;
    putchar(node->val);
    printByPrefix(node->left);
    printByPrefix(node->right);
}

void printByInfix(Node* node) {
    if (node == NULL) 
        return;
    printByInfix(node->left);
    putchar(node->val);
    printByInfix(node->right);
}

void printByPostfix(Node* node) {
    if (node == NULL) 
        return;
    printByPostfix(node->left);
    printByPostfix(node->right);
    putchar(node->val);
}

int main(int argc, char *argv[])
{
    char eq_str[] = "-*ab/+cde";
    Node* root = createTreeByPrefix(eq_str);
    // char eq_str[] = "ab*cd+e/-";
    // Node* root = createTreeByPostfix(eq_str);

    // ポーランド法で表示
    printf("prefix: ");
    printByPrefix(root);
    printf("\n");
    // 通常の表記で表示
    printf("infix: ");
    printByInfix(root);
    printf("\n");
    // 逆ポーランド法で表示
    printf("postfix: ");
    printByPostfix(root);
    printf("\n");
    return 0;
}