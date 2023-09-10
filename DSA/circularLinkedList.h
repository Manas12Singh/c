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
    for (int i = 0; i < n; i++)
    {
        struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
        scanf("%d", &(temp->data));
        temp->next = NULL;
        if (!*head)
            *head = trav = temp;
        else
        {
            trav->next = temp;
            trav = trav->next;
        }
    }
    trav->next = *head;
}

void printList(struct Node *head)
{
    if (!head)
    {
        printf("The list is empty!\n");
        return;
    }
    struct Node *trav = head;
    do
    {
        printf("%d ", trav->data);
        trav = trav->next;
    } while (trav != head);
    printf("\n");
}

void insertAtBegin(struct Node **head, int val)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    if (!temp)
    {
        printf("Memory full!\n");
        return;
    }
    temp->data = val;
    temp->next = *head;
    if (*head)
    {
        struct Node *trav = *head;
        while (trav->next != *head)
            trav = trav->next;
        trav->next = temp;
    }
    *head = temp;
}

void insertAtEnd(struct Node **head, int val)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    if (!temp)
    {
        printf("Memory full!\n");
        return;
    }
    temp->data = val;
    if (!*head)
        *head = temp;
    else
    {
        struct Node *trav = *head;
        while (trav->next != *head)
            trav = trav->next;
        trav->next = temp;
    }
    temp->next = *head;
}