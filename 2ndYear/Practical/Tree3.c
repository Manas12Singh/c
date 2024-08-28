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
void BFS(TreeNode *root)
{
    if (root == NULL)
        return;
    TreeNode *queue[100];
    int front = -1, rear = -1;
    queue[++rear] = root;
    while (front != rear)
    {
        TreeNode *temp = queue[++front];
        printf("%d ", temp->data);
        if (temp->left != NULL)
            queue[++rear] = temp->left;
        if (temp->right != NULL)
            queue[++rear] = temp->right;
    }
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
    printf("BFS: ");
    BFS(root);
    printf("\n");
    return 0;
}