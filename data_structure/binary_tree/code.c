#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

TreeNode* treeNode_init(int data) {
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

bool treeNode_isGoLeft(TreeNode* node, int data) {
    return (data < node->data) ? true : false;
}

/* 
    ☆引数のnodeはポインタなので値渡し（☓参照渡し）
    そのため返り値を返さないと実体ができない
*/
TreeNode* treeNode_add(TreeNode* node, int data) {
    if (node == NULL) 
        return treeNode_init(data);

    if (treeNode_isGoLeft(node, data)) 
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

int main(int argc, char *argv[])
{
    TreeNode* root = NULL;

    root = treeNode_add(root, 4);
    root = treeNode_add(root, 3);
    root = treeNode_add(root, 5);
    root = treeNode_add(root, 6);

    treeNode_print(root);
    printf("\n");
    treeNode_all_delete(root);
    return 0;
}