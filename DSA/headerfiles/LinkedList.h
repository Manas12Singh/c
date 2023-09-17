#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int data;
    struct Node *next;
};

void createList(struct Node **head)
{
    if (*head)
    {
        printf_s("The list already exists!\n");
        return;
    }
    int n;
    printf_s("Enter the number of initializing nodes: ");
    scanf_s("%d", &n);
    if (n < 1)
    {
        printf_s("Invalid number of node.\n");
        return NULL;
    }
    struct Node *trav = NULL;
    printf_s("Enter the elements:\n");
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
    }
}

void printList(struct Node *head)
{
    if (!head)
        printf_s("List is empty.");
    while (head)
    {
        printf_s("%d ", head->data);
        head = head->next;
    }
    printf_s("\n");
}

void insertAtBegin(struct Node **head, int value)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    if (!temp)
    {
        printf_s("Memory full!\n");
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
        printf_s("Memory full!\n");
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
        printf_s("Memory full!\n");
        return;
    }
    temp->data = value;
    if (!*head)
    {
        *head = temp;
        temp->next = NULL;
        return;
    }
    while (trav->next != NULL && trav->data != k)
        trav = trav->next;
    temp->next = trav->next;
    trav->next = temp;
}

void insertBeforek(struct Node **head, int value, int k)
{
    struct Node *trav = *head, *temp = (struct Node *)malloc(sizeof(struct Node));
    if (!temp)
    {
        printf_s("Memory full!\n");
        return;
    }
    temp->data = value;
    if (!*head || (*head)->data == k)
    {
        temp->next = *head;
        *head = temp;
        return;
    }
    while (trav->next)
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

void deleteBegin(struct Node **head)
{
    if (!*head)
    {
        printf_s("List already empty!\n");
        return;
    }
    struct Node *temp = *head;
    *head = (*head)->next;
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
    if ((*head)->next == NULL)
    {
        temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }
    while (trav->next->next != NULL)
        trav = trav->next;
    temp = trav->next;
    trav->next = NULL;
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
        *head = (*head)->next;
        free(temp);
        return;
    }
    while (trav->next != NULL && trav->next->data != k)
        trav = trav->next;
    if (trav->next != NULL)
    {
        temp = trav->next;
        trav->next = trav->next->next;
        free(temp);
    }
}

bool search(struct Node *head, int k)
{
    while (head != NULL)
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
    {
        freeList(&((*head)->next));
    }
    free(*head);
    *head = NULL;
}