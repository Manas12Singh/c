#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev, *next;
};

void createList(struct Node **head)
{
    if (*head)
    {
        printf("The list already exists!\n");
        return;
    }
    int n;
    printf("Enter the number of initialising nodes: ");
    scanf("%d", &n);
    if (n < 1)
    {
        printf("Invalid number of node.\n");
        return;
    }
    printf("Enter the elements:\n");
    struct Node *trav = NULL;
    for (int i = 0; i < n; i++)
    {
        struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
        scanf("%d", &(temp->data));
        temp->next = NULL;
        temp->prev = trav;
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
    {
        printf("List is empty.\n");
        return;
    }
    while (head->next)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("%d ", head->data);
    printf("\nReverse: ");
    while (head)
    {
        printf("%d ", head->data);
        head = head->prev;
    }
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
        printf("Memory full!\n");
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
        printf("Memory full!\n");
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
        printf("Memory full!\n");
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
    while (trav && trav->data != k)
        trav = trav->next;
    if (trav)
    {
        temp->next = trav;
        temp->prev = trav->prev;
        if (trav->prev)
            trav->prev->next = temp;
        else
            *head = temp;
        trav->prev = temp;
    }
    else
    {
        temp->next = *head;
        temp->prev = NULL;
        (*head)->prev = temp;
        *head = temp;
    }
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
    if (*head)
        (*head)->prev = NULL;
    free(temp);
}

void deleteEnd(struct Node **head)
{
    if (!*head)
    {
        printf("List already empty!\n");
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

void freeList(struct Node **head)
{
    if ((*head)->next != NULL)
        freeList(&((*head)->next));
    free(*head);
    *head = NULL;
}

int main()
{
    struct Node *head = NULL;
    while (1)
    {
        int opt, n, k;
        printf("Options: \n1. Create a new list. \n2. Insert at the Beginning. \n3. Insert at the End. \n4. Insert after k.\n5. Insert before k. \n6. Delete from the Beginning. \n7. Delete from the End. \n8. Delete k.\n9. Print the Linked List. \n10. Exit.\n");
        printf("Enter your choice (1 to 10): ");
        scanf("%d", &opt);
        switch (opt)
        {
        case 1:
            createList(&head);
            break;
        case 2:
            printf("Enter the value: ");
            scanf("%d", &n);
            insertAtBegin(&head, n);
            break;
        case 3:
            printf("Enter the value: ");
            scanf("%d", &n);
            insertAtEnd(&head, n);
            break;
        case 4:
            printf("Enter the value: ");
            scanf("%d", &n);
            printf("Enter k: ");
            scanf("%d", &k);
            insertAfterk(&head, n, k);
            break;
        case 5:
            printf("Enter the value: ");
            scanf("%d", &n);
            printf("Enter k: ");
            scanf("%d", &k);
            insertBeforek(&head, n, k);
            break;
        case 6:
            deleteBegin(&head);
            break;
        case 7:
            deleteEnd(&head);
            break;
        case 8:
            printf("Enter k: ");
            scanf("%d", &k);
            deletek(&head, k);
            break;
        case 9:
            printf("Linked List: ");
            printList(head);
            break;
        case 10:
            freeList(&head);
            return 0;
        default:
            printf("Wrong Choice!\n");
        }
    }
    return 0;
}
