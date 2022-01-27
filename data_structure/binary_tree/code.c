#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

typedef struct {
    TreeNode* root_node;
} Tree;

TreeNode* treeNode_init(int data) {
    TreeNode *node;

    node = (TreeNode *)malloc(sizeof(TreeNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return node;
}
Tree* tree_init() {
    Tree *tree;

    tree = (Tree *)malloc(sizeof(Tree));
    tree->root_node = NULL;

    return tree;
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
void tree_print(Tree* tree) {
    treeNode_print(tree->root_node);
    printf("\n");
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
void tree_add(Tree* tree, int data) {
    tree->root_node =  treeNode_add(tree->root_node, data);
}

void treeNode_all_delete(TreeNode* node) {
    if (node == NULL) 
        return;

    treeNode_delete(node->left);
    treeNode_delete(node->right);
    
    free(node);
}
void tree_all_delete(Tree* tree) {
    treeNode_all_delete(tree->root_node);
}

int main(int argc, char *argv[])
{
    Tree* tree = tree_init();
    tree_add(tree, 3);
    tree_add(tree, 4);
    tree_add(tree, 3);
    // tree_add(tree, 1);
    tree_print(tree);
    tree_all_delete(tree);
    free(tree);
    return 0;
}