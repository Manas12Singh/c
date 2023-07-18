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
    struct Node *start = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter the value: ");
    scanf("%d%*c", &(start->data));
    start->link = NULL;
    return start;
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
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter the value: ");
    scanf("%d%*c", &(temp->data));
    temp->link = NULL;
    start->link = temp;
}

void addToIndex(struct Node *start)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    unsigned i = 1;
    int j;
    printf("Enter the index: ");
    scanf("%u", &j);
    printf("Enter the value: ");
    scanf("%d", &(temp->data));
    while(i<j || start==NULL)
    {

    }
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