#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct TreeNode
{
    int data;
    struct TreeNode *left, *right;
};

void preorder(struct TreeNode *root)
{
    if (root == NULL)
        return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorder(struct TreeNode *root)
{
    if (root == NULL)
        return;
    preorder(root->left);
    printf("%d ", root->data);
    preorder(root->right);
}

void postorder(struct TreeNode *root)
{
    if(root==NULL)
}