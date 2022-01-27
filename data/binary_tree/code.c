/*
    二分探索木
    ・自然数のみ
    ・あるノードに注目した時, 左側の子ノードの値 < 注目したノードの値 <= 右側子ノードの値
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

TreeNode* init(int data) {
    // 自然数のみ
    if (data <= 0)
        return NULL;

    TreeNode *node;

    node = (TreeNode *)malloc(sizeof(TreeNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return node;
}

void print(TreeNode* node) {
    if (node == NULL)
        return;

    printf("%d->[{", node->data);
    print(node->left);
    printf("}{");
    print(node->right);
    printf("}]");
}

/* 
    ☆引数のnodeはポインタなので値渡し（☓参照渡し）
    そのため返り値を返さないと実体ができない
    （参考：http://www.nct9.ne.jp/m_hiroi/linux/clang13.html）
*/
TreeNode* add(TreeNode* node, int data) {
    if (node == NULL) 
        return init(data);

    if (data < node->data) 
        node->left = add(node->left, data);
    else 
        node->right = add(node->right, data);
    return node;
}

void all_delete(TreeNode* node) {
    if (node == NULL) 
        return;

    all_delete(node->left);
    all_delete(node->right);
    
    free(node);
}

// ノードがあったら最小値(自然数), ノードがなかったらfalse(=0)
int search_min(TreeNode* node) {
    if (node == NULL)
        return false;
    return (node->left == NULL) ? node->data : search_min(node->left);
}
// ノードがあったら最大値(自然数), ノードがなかったらfalse(=0)
int search_max(TreeNode* node) {
    if (node == NULL)
        return false;
    return (node->right == NULL) ? node->data : search_max(node->right);
}

// int traversal(TreeNode* node) {

// }

int main(int argc, char *argv[])
{
    TreeNode* root = NULL;

    root = add(root, 4);
    root = add(root, 3);
    root = add(root, 5);
    root = add(root, 6);

    print(root);
    printf("\n");
    printf("min: %d, max: %d\n", search_min(root), search_max(root));
    all_delete(root);
    return 0;
}