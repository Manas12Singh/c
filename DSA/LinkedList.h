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
        scanf("%d", &(temp->data));
        temp->next = NULL;
        if (*head == NULL)
            *head = trav = temp;
        else
        {
            trav->next = temp;
            trav = trav->next;
        }
    }
}

void printList(struct Node *head)
{
    if (head == NULL)
        printf("List is empty.\n");
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void insertInBegin(struct Node **head, int value)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    if (!temp)
    {
        printf("Memory full!\n");
        return;
    }
    temp->data = value;
    temp->next = *head;
    *head = temp;
}

void insertAtEnd(struct Node **head, int value)
{
    struct Node *trav = *head, *temp = (struct Node *)malloc(sizeof(struct Node));
    if (!temp)
    {
        printf("Memory full!\n");
        return;
    }
    temp->data = value;
    temp->next = NULL;
    if (!*head)
    {
        *head = temp;
        return;
    }
    while (trav->next != NULL)
        trav = trav->next;
    trav->next = temp;
}

void insertAfterk(struct Node **head, int value, int k)
{
    struct Node *trav = *head, *temp = (struct Node *)malloc(sizeof(struct Node));
    if (!temp)
    {
        printf("Memory full!\n");
        return;
    }
    temp->data = value;
    temp->next = NULL;
    if (!*head)
    {
        *head = temp;
        return;
    }
    while (trav->next != NULL && trav->data != k)
    {
        trav = trav->next;
    }
    temp->next = trav->next;
    trav->next = temp;
}

void insertBeforek(struct Node **head, int value, int k)
{
    struct Node *trav = *head, *temp = (struct Node *)malloc(sizeof(struct Node));
    if (!temp)
    {
        printf("Memory full!\n");
        return;
    }
    temp->data = value;
    temp->next = NULL;
    if (!*head || (*head)->data == k)
    {
        temp->next = *head;
        *head = temp;
        return;
    }
    while (trav->next != NULL)
    {
        if (trav->next->data == k)
        {
            temp->next = trav->next;
            trav->next = temp;
            return;
        }
        trav = trav->next;
    }
    temp->next = *head;
    *head = temp;
}

void freeList(struct Node **head)
{
    if ((*head)->next != NULL)
        freeList(&((*head)->next));
    free(*head);
    *head = NULL;
}
