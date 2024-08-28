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
TreeNode *search(TreeNode *root, int val)
{
    if (root == NULL || root->data == val)
        return root;
    if (root->data > val)
        return search(root->left, val);
    return search(root->right, val);
}
TreeNode *delete(TreeNode *root, int val)
{
    if (root == NULL)
        return NULL;
    if (root->data > val)
        root->left = delete (root->left, val);
    else if (root->data < val)
        root->right = delete (root->right, val);
    else
    {
        TreeNode *temp = root, *trav = root->left;
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            root = NULL;
        }
        else if (root->left == NULL)
        {
            root = root->right;
            free(temp);
        }
        else if (root->right == NULL)
        {
            root = root->left;
            free(temp);
        }
        else
        {
            while (trav->right != NULL)
                temp = trav, trav = trav->right;
            if (temp != root)
                temp->right = trav->left;
            else
                temp->left = trav->left;
            root->data = trav->data;
            free(trav);
        }
    }
    return root;
}
void freeTree(TreeNode **root)
{
    if (*root == NULL)
        return;
    freeTree(&((*root)->left));
    freeTree(&((*root)->right));
    free(*root);
    *root = NULL;
}
int main()
{
    TreeNode *root = NULL;
    int n, k, opt;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the elements: ");
    for (int i = 0; i < n; ++i)
        scanf("%d", &k), root = insert(root, k);
    do
    {
        printf("Options: \n1. Search. \n2. Delete. \n3. Exit.\n");
        printf("Enter your choice (1 to 3): ");
        scanf("%d", &opt);
        switch (opt)
        {
        case 1:
            printf("Enter the value: ");
            scanf("%d", &k);
            TreeNode *temp = search(root, k);
            if (temp == NULL)
                printf("Not found.\n");
            else
                printf("Found.\n");
            break;
        case 2:
            printf("Enter the value: ");
            scanf("%d", &k);
            root = delete (root, k);
            break;
        case 3:
            break;
        default:
            printf("Wrong Choice!\n");
        }
        printf("\n");
    } while (opt != 3);
    freeTree(&root);
    return 0;
}