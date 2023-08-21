#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *link;
};

struct Node *newList()
{
    struct Node *start, *node, *temp;
    int n;
    printf("Enter the number of elements: ");
    scanf("%d%*c", &n);
    node = start = (struct Node *)calloc(1, sizeof(struct Node));
    for (int i = 0; i < n; i++)
    {
        temp = (struct Node *)calloc(1, sizeof(struct Node));
        printf("Enter the value: ");
        scanf("%d%*c", &(node->data));
    }
    start->link = NULL;
    return start;
}

struct Node *insertToStart(struct Node *start)
{
    struct Node *temp = (struct Node *)calloc(1, sizeof(struct Node));
    printf("Enter the value: ");
    scanf("%d%*c", &(temp->data));
    temp->link = start;
    return temp;
}

void addToEnd(struct Node *start)
{
    if (start == NULL)
    {
        puts("Kindly begin by creating a list.");
        return;
    }
    while (start->link != NULL)
        start = start->link;
    struct Node *temp = (struct Node *)calloc(1, sizeof(struct Node));
    printf("Enter the value: ");
    scanf("%d%*c", &(temp->data));
    temp->link = NULL;
    start->link = temp;
}

struct Node *addToIndex(struct Node *node, unsigned index)
{
    if (node == NULL)
    {
        puts("Kindly begin by creating a list.");
        return;
    }
    struct Node *temp = (struct Node *)calloc(1, sizeof(struct Node));
    unsigned i = 1;
    printf("Enter the value: ");
    scanf("%d", &(temp->data));
    while (i < index && node->link != NULL)
        node = node->link;
    temp->link = node;
}

void printList(struct Node *start)
{
    if (start == NULL)
        printf("No list created.");
    while (start != NULL)
    {
        printf("%d ", start->data);
        start = start->link;
    }
    printf("\n");
}
