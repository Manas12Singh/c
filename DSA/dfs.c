#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct TreeNode
{
    int data;
    struct TreeNode *left, *right;
};

struct TreeNode *createNode(int data)
{
    struct TreeNode *temp = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

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

struct TreeNode *toTree(int *a, int i, int n)
{
    struct TreeNode *root = NULL;
    if (i < n && a[i] != -1)
    {
        root = createNode(a[i]);
        root->left = toTree(a, 2 * i + 1, n);
        root->right = toTree(a, 2 * i + 2, n);
    }
    return root;
}

int main()
{
    int n, k;
    printf("Enter number of levels:");
    scanf("%d", &n);
    k = pow(2, n) - 1;
    int a[k];
    for (int i = 0; i < k; i++)
        scanf("%d", &a[i]);
    struct TreeNode *root = toTree(a, 0, k);
    preorder(root);
    printf("\n");
    inorder(root);
    printf("\n");
}