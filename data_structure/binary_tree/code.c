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

TreeNode* treeNode_init(int data) {
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

void treeNode_print(TreeNode* node) {
    if (node == NULL)
        return;

    printf("%d->[{", node->data);
    treeNode_print(node->left);
    printf("}{");
    treeNode_print(node->right);
    printf("}]");
}

/* 
    ☆引数のnodeはポインタなので値渡し（☓参照渡し）
    そのため返り値を返さないと実体ができない
*/
TreeNode* treeNode_add(TreeNode* node, int data) {
    if (node == NULL) 
        return treeNode_init(data);

    if (data < node->data) 
        node->left = treeNode_add(node->left, data);
    else 
        node->right = treeNode_add(node->right, data);
    return node;
}

void treeNode_all_delete(TreeNode* node) {
    if (node == NULL) 
        return;

    treeNode_all_delete(node->left);
    treeNode_all_delete(node->right);
    
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

int main(int argc, char *argv[])
{
    TreeNode* root = NULL;

    root = treeNode_add(root, 4);
    root = treeNode_add(root, 3);
    root = treeNode_add(root, 5);
    root = treeNode_add(root, 6);

    treeNode_print(root);
    printf("\n");
    printf("min: %d, max: %d\n", search_min(root), search_max(root));
    treeNode_all_delete(root);
    return 0;
}