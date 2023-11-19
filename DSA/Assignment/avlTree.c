#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left, *right;
} TreeNode;

TreeNode *createNode(int val)
{
    TreeNode *temp = (TreeNode *)malloc(sizeof(TreeNode));
    temp->data = val;
    temp->left = temp->right = NULL;
    return temp;
}

int height(TreeNode *root)
{
    if (root == NULL)
        return 0;
    int lh = height(root->left);
    int rh = height(root->right);
    return ((lh > rh) ? lh : rh) + 1;
}

int isbalanced(TreeNode *root)
{
    if (root == NULL)
        return 0;
    int lh = height(root->left);
    int rh = height(root->right);
    return lh - rh;
}

TreeNode *insert(TreeNode *root, int *left, int *right, int val)
{
    if (root == NULL)
        root = createNode(val);
    else if (root->data > val)
        root->left = insert(root->left, &left, &right, val);
    else
        root->right = insert(root->right, &l, &r, val);
    if (isbalanced(root)==0)
        return root;
    
}