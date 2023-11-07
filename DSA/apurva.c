#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *createnode(int data)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}
struct node *create_BST(struct node *root, int data)
{
    if (root == NULL)
    {
        root = createnode(data);
        return root;
    }
    else if (data <= root->data)
    {
        root->left = create_BST(root->left, data);
    }
    else
    {
        root->right = create_BST(root->right, data);
    }
    return root;
}
void inorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}
struct node *inorderpredecessor(struct node *root)
{
    root = root->left;
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}
struct node *deletenode(struct node *root, int value)
{
    struct node *ipre;
    if (root == NULL)
    {
        return NULL;
    }
    if (value < root->data)
    {
        root->left = deletenode(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = deletenode(root->right, value);
    }
    else
    { // We had find the node which we have to delete
        // Case 1 : It is a leaf node
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }
        // Case 2 : One child
        else if (root->left == NULL)
        {
            struct node *temp = root;
            root = root->right;
            free(temp);
        }
        else if (root->right == NULL)
        {
            struct node *temp = root;
            root = root->left;
            free(temp);
        }
        // Case 3 : 2 children
        else
        {
            ipre = inorderpredecessor(root);
            root->data = ipre->data;
            root->left = deletenode(root->left, ipre->data);
        }
    }
    return root;
}
int main()
{
    struct node *root = NULL;
    root = create_BST(root, 12);
    root = create_BST(root, 5);
    root = create_BST(root, 15);
    root = create_BST(root, 3);
    root = create_BST(root, 7);
    root = create_BST(root, 13);
    root = create_BST(root, 17);
    root = create_BST(root, 1);
    root = create_BST(root, 9);
    printf("Inoreder Is : ");
    inorder(root);
    printf("\n");
    printf("Tree after deleting is : ");
    root = deletenode(root, 5);
    inorder(root);
    return 0;
}