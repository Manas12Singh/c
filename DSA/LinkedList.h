#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void createList(struct Node **head)
{
    if (*head)
    {
        printf("The list already exists!\n");
        return;
    }
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    if (n < 1)
    {
        printf("Invalid number.\n");
        return;
    }
    struct Node *trav = NULL;
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++)
    {
        struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
        scanf("%d",&(temp->data));
        temp->next=NULL;
        if (*head==NULL)
            *head=trav=temp;
        else
        {
            trav->next=temp;
            trav=trav->next;
        }
    }
}

void printList(struct Node *head)
{
    if (head==NULL)
        printf("List is empty.\n");
    while(head!=NULL)
    {
        printf("%d ",head->data);
        head=head->next;
    }
}