#include <stdio.h>
#include <stdlib.h>
typedef struct TreeNode
{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;
TreeNode *createNode(int data)
{
    TreeNode *newNode = (TreeNode *)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
TreeNode *insert(TreeNode *root, int val)
{
    if (root == NULL)
        return createNode(val);
    if (root->data > val)
        root->left = insert(root->left, val);
    else if (root->data < val)
        root->right = insert(root->right, val);
    return root;
}
void preorder(TreeNode *root)
{
    if (root == NULL)
        return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}
void inorder(TreeNode *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}
void postorder(TreeNode *root)
{
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}
int main()
{
    TreeNode *root = NULL;
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    int a;
    printf("Enter the nodes: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a);
        root = insert(root, a);
    }
    printf("Preorder: ");
    preorder(root);
    printf("\nInorder: ");
    inorder(root);
    printf("\nPostorder: ");
    postorder(root);
    printf("\n");
    return 0;
}
