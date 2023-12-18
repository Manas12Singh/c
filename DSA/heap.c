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
TreeNode *minHeap();