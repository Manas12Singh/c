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
    while (trav->next != NULL)
    {
        if (trav->data == k)
            break;
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

void deleteBegin(struct Node **head)
{
    if (!*head)
    {
        printf("List already empty!\n");
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
        printf("List already empty!\n");
        return;
    }
    struct Node *temp = *head, *trav = *head;
    if ((*head)->next == NULL)
    {
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
        printf("List already empty!\n");
        return;
    }
    struct Node *temp, *trav = *head;
    if ((*head)->next == NULL && (*head)->data != k)
    {
        printf("%d does not exits in list.\n", k);
        return;
    }
    if ((*head)->data == k)
    {
        temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }
    while (trav->next->next != NULL && trav->next->data != k)
        trav = trav->next;
    if (trav->next->data == k)
    {
        temp = trav->next;
        trav->next = trav->next->next;
        free(temp);
        return;
    }
    else
        printf("%d does not exits in list.\n", k);
}

void deleteAllk(struct Node **head, int k)
{
    if (!*head)
    {
        printf("List already empty!\n");
        return;
    }
    struct Node *temp;
    while (*head != NULL && (*head)->data == k)
    {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
    struct Node *trav = *head;
    while (trav != NULL && trav->next != NULL)
    {
        if (trav->next->data == k)
        {
            temp = trav->next;
            trav->next = trav->next->next;
            free(temp);
        }
        else
            trav = trav->next;
    }
}

void freeList(struct Node **head)
{
    if (!*head && (*head)->next != NULL)
        freeList(&((*head)->next));
    free(*head);
    *head = NULL;
}
