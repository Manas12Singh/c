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
    if (root->data < data)
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

short searchNode(TreeNode *root, int key)
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
            root = NULL;
        }
        else if (root->left == NULL)
        {
            TreeNode *temp = root;
            root = root->right;
            free(temp);
        }
        else if (root->right == NULL)
        {
            TreeNode *temp = root;
            root = root->left;
            free(temp);
        }
        else
        {
            TreeNode *trav = root->left, *t = root;
            while (trav->right != NULL)
            {
                t = trav;
                trav = trav->right;
            }
            if (t == root)
                t->left = trav->left;
            else
                t->right = trav->left;
            root->data = trav->data;
            free(trav);
        }
    }
    return root;
}

int countLeaves(TreeNode *root)
{
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 1;
    return countLeaves(root->left) + countLeaves(root->right);
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int findHeight(TreeNode *root)
{
    if (root == NULL)
        return 0;
    return 1 + max(findHeight(root->left), findHeight(root->right));
}

int kthLargest(TreeNode *root, int k, int *c)
{
    if (root == NULL)
        return -1;
    int res = kthLargest(root->right, k, c);
    if (res != -1)
        return res;
    (*c)++;
    if (*c == k)
        return root->data;
    return kthLargest(root->left, k, c);
}

int kthLargestElement(TreeNode *root, int k)
{
    int c = 0;
    return kthLargest(root, k, &c);
}

void freeTree(TreeNode *root)
{
    if (root == NULL)
        return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main()
{
    int n, key, *data = NULL;
    TreeNode *root = NULL;
    int opt;
    do
    {
        printf("1. Create Tree\n2. Search key\n3. Delete Node\n4. Count Leaves\n5. Find Height\n6. Kth Largest Element\n7. Exit\nEnter your choice: ");
        scanf("%d", &opt);
        switch (opt)
        {
        case 1:
            if (data != NULL)
                free(data);
            if(root != NULL)
            {
                freeTree(root);
                root = NULL;
            }
            printf("Enter the number of nodes: ");
            scanf("%d", &n);
            data = (int *)malloc(n * sizeof(int));
            printf("Enter the data: ");
            for (int i = 0; i < n; i++)
                scanf("%d", &data[i]);
            TreeNode *root = createTree(data, n);
            break;
        case 2:
            printf("Enter the key to search: ");
            scanf("%d", &key);
            if (searchNode(root, key))
                printf("Key Found!\n");
            else
                printf("Key Not Found!\n");
            break;
        case 3:
            printf("Enter the key to delete: ");
            scanf("%d", &key);
            root = deleteNode(root, key);
            break;
        case 4:
            printf("Number of leaves: %d\n", countLeaves(root));
            break;
        case 5:
            printf("Height of the tree: %d\n", findHeight(root));
            break;
        case 6:
            printf("Enter the value of k: ");
            scanf("%d", &key);
            printf("Kth Largest Element: %d\n", kthLargestElement(root, key));
            break;
        case 7:
            break;
        default:
            printf("Invalid Option!\n");
        }
    } while (opt != 7);
    freeTree(root);
    return 0;
}