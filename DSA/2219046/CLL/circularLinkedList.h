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
    temp->next = *head;
    if (*head)
    {
        struct Node *trav = *head;
        while (trav->next != *head)
            trav = trav->next;
        trav->next = temp;
    }
    else
        *head = temp;
}

void insertAfterk(struct Node **head, int val, int k)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    if (!temp)
    {
        printf("Memory full!\n");
        return;
    }
    temp->data = val;
    if (!*head)
    {
        temp->next = NULL;
        *head = temp;
        return;
    }
    struct Node *trav = *head;
    while (trav->next != *head && trav->data != k)
        trav = trav->next;
    temp->next = trav->next;
    trav->next = temp;
}

void insertBeforek(struct Node **head, int val, int k)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    if (!temp)
    {
        printf("Memory full!\n");
        return;
    }
    temp->data = val;
    if (!*head)
    {
        temp->next = NULL;
        *head = temp;
        return;
    }
    struct Node *trav = *head;
    while (trav->next != *head)
    {
        if (trav->next->data == k)
            break;
        trav = trav->next;
    }
    temp->next = trav->next;
    trav->next = temp;
    if (temp->next == *head)
        *head = temp;
}

void deleteBegin(struct Node **head)
{
    if (!*head)
    {
        printf_s("List already empty!\n");
        return;
    }
    struct Node *temp = *head, *trav = *head;
    if ((*head)->next != (*head))
    {
        while (trav->next != *head)
            trav = trav->next;
        trav->next = *head = (*head)->next;
    }
    else
        *head = NULL;
    free(temp);
}

void deleteEnd(struct Node **head)
{
    if (!*head)
    {
        printf_s("List already empty!\n");
        return;
    }
    struct Node *temp, *trav = *head;
    if ((*head)->next == *head)
    {
        temp = *head;
        *head = NULL;
        free(temp);
        return;
    }
    while (trav->next->next != *head)
        trav = trav->next;
    temp = trav->next;
    trav->next = trav->next->next;
    free(temp);
}

void deletek(struct Node **head, int k)
{
    if (!*head)
    {
        printf_s("List already empty!\n");
        return;
    }
    struct Node *temp, *trav = *head;
    if ((*head)->data == k)
    {
        temp = *head;
        if ((*head)->next = *head)
            *head = NULL;
        else
        {
            while (trav->next != *head)
                trav = trav->next;
            trav->next = (*head)->next;
            *head = (*head)->next;
        }
        free(temp);
        return;
    }
    while (trav->next->data != k)
        trav = trav->next;
    temp = trav->next;
    trav->next = trav->next->next;
    free(temp);
}

void freeList(struct Node **head)
{
    while ((*head)->next != NULL)
    {
        freeList(&((*head)->next));
    }
    free(*head);
    *head = NULL;
}