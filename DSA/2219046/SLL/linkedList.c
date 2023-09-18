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
    printf("Enter the number of initializing nodes: ");
    scanf("%d", &n);
    if (n < 1)
    {
        printf("Invalid number of node.\n");
        return NULL;
    }
    struct Node *trav = NULL;
    printf("Enter the elements:\n");
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
}

void printList(struct Node *head)
{
    if (!head)
        printf("List is empty.");
    while (head)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void insertAtBegin(struct Node **head, int value)
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
        printf("Memory full!\n");
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
        printf("List already empty!\n");
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

void freeList(struct Node **head)
{
    if ((*head)->next != NULL)
    {
        freeList(&((*head)->next));
    }
    free(*head);
    *head = NULL;
}

int main()
{
    struct Node *head = NULL;
    while (1)
    {
        int opt, n, k;
        printf("Options: \n1. Create a new list. \n2. Insert at the Beginning. \n3. Insert at the End. \n4. Insert after k.\n5. Insert before k. \n6. Delete from the Beginning. \n7. Delete from the End. \n8. Delete k.\n9 Print the Linked List. \n10. Exit.\n");
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
            break;
        }
    }
    return 0;
}
