#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode
{
    int data;
    struct TreeNode *left, *right;
} TreeNode;

TreeNode *createNode(int data)
{
    TreeNode *temp = (TreeNode *)malloc(sizeof(TreeNode));
    if (temp == NULL)
        printf("Memory Full!\n");
    else
    {
        temp->data = data;
        temp->left = temp->right = NULL;
    }
    return temp;
}

TreeNode *insert(TreeNode *root, int data)
{
    if (root == NULL)
        return createNode(data);
    if (root->data > data)
        root->left = insert(root->left, data);
    if (root->data > data)
        root->right = insert(root->right, data);
    return root;
}

TreeNode *createTree(int *data, int n)
{
    TreeNode *root = NULL;
    for (int i = 0; i < n; i++)
        root = insert(root, data[i]);
    return root;
}

short search(TreeNode *root, int key)
{
    if (root == NULL)
        return 0;
    if (root->data == key)
        return 1;
    else if (root->data > key)
        return (root->left, key);
    else
        return (root->right, key);
}

TreeNode *deleteNode(TreeNode *root, int val)
{
    if (root == NULL)
        return NULL;
    if (root->data > val)
        root->left = deleteNode(root->left, val);
    else if (root->data < val)
        root->right = deleteNode(root->right, val);
    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }
        if (root->left == NULL)
        {
            TreeNode *temp = root;
            root = root->right;
            free(temp);
            return root;
        }
        if (root->right == NULL)
        {
            TreeNode *temp = root;
            root = root->left;
            free(temp);
            return root;
        }
    }
}