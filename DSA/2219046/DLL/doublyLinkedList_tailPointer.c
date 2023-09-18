#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev, *next;
};

void createList(struct Node **head, struct Node **tail)
{
    if (*head)
    {
        printf_s("The list already exists!\n");
        return;
    }
    int n;
    printf_s("Enter the number of intialising nodes: ");
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
        {
            *head = trav = temp;
            temp->prev = NULL;
        }
        else
        {
            trav->next = temp;
            temp->prev = trav;
            trav = trav->next;
        }
    }
    *tail = trav;
}

void printList(struct Node *head, struct Node *tail)
{
    if (!head)
    {
        printf_s("List is empty.\n");
        return;
    }
    while (head)
    {
        printf_s("%d ", head->data);
        head = head->next;
    }
    printf_s("\nReverse: ");
    while (tail)
    {
        printf_s("%d ", tail->data);
        tail = tail->prev;
    }
    printf_s("\n");
}

void insertAtBegin(struct Node **head, struct Node **tail, int val)
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
    else
        *tail = temp;
    *head = temp;
}

void insertAtEnd(struct Node **head, struct Node **tail, int val)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    if (!temp)
    {
        printf_s("Memory full!\n");
        return;
    }
    temp->data = val;
    temp->next = NULL;
    temp->prev = *tail;
    if (*head)
        (*tail)->next = temp;
    else
        *head = temp;
    *tail = temp;
}

void insertAfterk(struct Node **head, struct Node **tail, int val, int k)
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
        *head = *tail = temp;
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
    else
        *tail = temp;
    trav->next = temp;
}

void insertBeforek(struct Node **head, struct Node **tail, int val, int k)
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
        *head = *tail = temp;
        temp->next = temp->prev = NULL;
        return;
    }
    struct Node *trav = *tail;
    while (trav->prev && trav->data != k)
        trav = trav->prev;
    temp->next = trav;
    temp->prev = trav->prev;
    if (trav->prev)
        trav->prev->next = temp;
    else
        *head = temp;
    trav->prev = temp;
}

void deleteBegin(struct Node **head, struct Node **tail)
{
    if (!*head)
    {
        printf_s("List is empty.\n");
        return;
    }
    struct Node *temp = *head;
    *head = (*head)->next;
    if (*head)
        (*head)->prev = NULL;
    else
        *tail = NULL;
    free(temp);
}

void deleteEnd(struct Node **head, struct Node **tail)
{
    if (!*head)
    {
        printf_s("List is empty.\n");
        return;
    }
    struct Node *temp = *tail;
    *tail = (*tail)->prev;
    if (*tail)
        (*tail)->next = NULL;
    else
        *head = NULL;
    free(temp);
}

void deletek(struct Node **head, struct Node **tail, int k)
{
    if (!*head)
        return;
    struct Node *trav = *head;
    while (trav && trav->data != k)
        trav = trav->next;
    if (trav)
    {
        if (trav->prev)
            trav->prev->next = trav->next;
        else
            *head = trav->next;
        if (trav->next)
            trav->next->prev = trav->prev;
        else
            *tail = trav->prev;
        free(trav);
    }
}

void freeList(struct Node **head, struct Node **tail)
{
    if ((*head) == (*tail))
    {
        free(*head);
        *head = *tail = NULL;
        return;
    }
    else
        freeList(&(*head)->next, &(*tail)->prev);
    free(*head);
    free(*tail);
    *tail = *head = NULL;
}

int main()
{
    struct Node *head = NULL, *tail = NULL;
    while (1)
    {
        int opt, n, k;
        printf("Options: \n1. Create a new list. \n2. Insert at the Beginning. \n3. Insert at the End. \n4. Insert after k.\n5. Insert before k. \n6. Delete from the Beginning. \n7. Delete from the End. \n8. Delete k.\n9. Print the Linked List. \n10. Exit.\n");
        printf("Enter your choice (1 to 10): ");
        scanf("%d", &opt);
        switch (opt)
        {
        case 1:
            createList(&head, &tail);
            break;
        case 2:
            printf("Enter the value: ");
            scanf("%d", &n);
            insertAtBegin(&head, &tail, n);
            break;
        case 3:
            printf("Enter the value: ");
            scanf("%d", &n);
            insertAtEnd(&head, &tail, n);
            break;
        case 4:
            printf("Enter the value: ");
            scanf("%d", &n);
            printf("Enter k: ");
            scanf("%d", &k);
            insertAfterk(&head, &tail, n, k);
            break;
        case 5:
            printf("Enter the value: ");
            scanf("%d", &n);
            printf("Enter k: ");
            scanf("%d", &k);
            insertBeforek(&head, &tail, n, k);
            break;
        case 6:
            deleteBegin(&head, &tail);
            break;
        case 7:
            deleteEnd(&head, &tail);
            break;
        case 8:
            printf("Enter k: ");
            scanf("%d", &k);
            deletek(&head, &tail, k);
            break;
        case 9:
            printf("Linked List: ");
            printList(head, tail);
            break;
        case 10:
            freeList(&head, &tail);
            return 0;
        default:
            printf("Wrong Choice!\n");
        }
    }
    return 0;
}
