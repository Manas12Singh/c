#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int data;
    struct Node *prev, *next;
};

void createList(struct Node **head)
{
    if (*head)
    {
        printf_s("The list already exists!\n");
        return;
    }
    int n;
    printf_s("Enter the number of initialising nodes: ");
    scanf_s("%d", &n);
    if (n < 1)
    {
        printf_s("Invalid number of node.\n");
        return;
    }
    struct Node *trav = NULL;
    for (int i = 0; i < n; i++)
    {
        struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
        scanf_s("%d", &(temp->data));
        temp->next = NULL;
        if (!*head)
            *head = trav = temp;
        else
        {
            trav->next = temp;
            trav = trav->next;
        }
        temp->prev = trav;
    }
}

void printList(struct Node *head)
{
    if (!head)
    {
        printf_s("List is empty.\n");
        return;
    }
    while (head->next)
    {
        printf_s("%d ", head->data);
        head = head->next;
    }
    printf("%d ", head->data);
    printf_s("\nReverse: ");
    while (head)
    {
        printf_s("%d ", head->data);
        head = head->prev;
    }
    printf_s("\n");
}

void insertAtBegin(struct Node **head, int val)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    if (!temp)
    {
        printf_s("Memory full!\n");
        return;
    }
    temp->data = val;
    temp->prev = NULL;
    temp->next = *head;
    if (*head)
        (*head)->prev = temp;
    *head = temp;
}

void insertAtEnd(struct Node **head, int val)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    if (!temp)
    {
        printf_s("Memory full!\n");
        return;
    }
    temp->data = val;
    temp->next = NULL;
    if (!*head)
    {
        temp->prev = NULL;
        *head = temp;
        return;
    }
    struct Node *trav = *head;
    while (trav->next)
        trav = trav->next;
    trav->next = temp;
    temp->prev = trav;
}

void insertAfterk(struct Node **head, int val, int k)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    if (!temp)
    {
        printf_s("Memory full!\n");
        return;
    }
    temp->data = val;
    if (!*head)
    {
        *head = temp;
        temp->next = temp->prev = NULL;
        return;
    }
    struct Node *trav = *head;
    while (trav->next && trav->data != k)
        trav = trav->next;
    temp->prev = trav;
    temp->next = trav->next;
    if (trav->next)
        trav->next->prev = temp;
    trav->next = temp;
}

void insertBeforek(struct Node **head, int val, int k)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    if (!temp)
    {
        printf_s("Memory full!\n");
        return;
    }
    temp->data = val;
    if (!*head)
    {
        temp->next = temp->prev = NULL;
        *head = temp;
        return;
    }
    struct Node *trav = *head;
    while (trav->next)
    {
        if (trav->next->data == k)
        {
            temp->next = trav->next;
            trav->next->prev = temp;
            trav->next = temp;
            temp->prev = trav;
            return;
        }
        trav = trav->next;
    }
    temp->next = *head;
    temp->prev = NULL;
    (*head)->prev = temp;
    *head = temp;
}

void deleteBegin(struct Node **head)
{
    if (!*head)
    {
        printf_s("List already empty!\n");
        return;
    }
    struct Node *temp = *head;
    *head = (*head)->next;
    if (*head)
        (*head)->prev = NULL;
    free(temp);
}

void deleteEnd(struct Node **head)
{
    if (!*head)
    {
        printf_s("List already empty!\n");
        return;
    }
    struct Node *temp;
    if ((*head)->next == NULL)
    {
        temp = *head;
        *head = NULL;
        free(temp);
        return;
    }
    struct Node *trav = *head;
    while (trav->next)
        trav = trav->next;
    temp = trav;
    trav->prev->next = NULL;
    free(temp);
}

void deletek(struct Node **head, int k)
{
    if (!*head)
        return;
    struct Node *temp;
    if ((*head)->data == k)
    {
        temp = *head;
        *head = (*head)->next;
        if (*head)
            (*head)->prev = NULL;
        free(temp);
        return;
    }
    struct Node *trav = *head;
    while (trav && trav->data != k)
        trav = trav->next;
    if (trav)
    {
        temp = trav;
        trav->prev->next = trav->next;
        if (trav->next)
            trav->next->prev = trav->prev;
        free(temp);
    }
}

bool search(struct Node *head, int k)
{
    while (head)
    {
        if (head->data == k)
            return true;
        head = head->next;
    }
    return false;
}

void freeList(struct Node **head)
{
    if ((*head)->next != NULL)
        freeList(&((*head)->next));
    free(*head);
    *head = NULL;
}