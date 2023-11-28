#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode
{
    int data;
    struct ListNode *next;
} ListNode;

ListNode *createNode(int data)
{
    ListNode *temp = (ListNode *)malloc(sizeof(ListNode));
    if (temp == NULL)
    {
        printf("Memory full!\n");
        return NULL;
    }
    temp->data = data;
    temp->next = NULL;
    return temp;
}

ListNode *createList()
{
    int n;
    printf("Enter the number of node(s): ");
    scanf("%d", &n);
    if (n < 1)
    {
        printf("Invalid number of nodes.\n");
        return NULL;
    }
    ListNode *head = NULL, *trav = NULL;
    printf("Enter the values: ");
    for (int i = 0; i < n; i++)
    {
        int k;
        scanf("%d", &k);
        ListNode *temp = createNode(k);
        if (temp == NULL)
            break;
        if (head == NULL)
            head = trav = temp;
        else
        {
            trav->next = temp;
            trav = temp;
        }
    }
    return head;
}

void partition(ListNode **head, int k)
{
    ListNode *p1 = NULL, *p2 = NULL;
    ListNode *t1 = NULL, *t2 = NULL;
    while (*head != NULL)
    {
        if ((*head)->data < k)
        {
            if (p1 == NULL)
                p1 = t1 = *head;
            else
            {
                t1->next = *head;
                t1 = t1->next;
            }
        }
        else
        {
            if (p2 == NULL)
                p2 = t2 = *head;
            else
            {
                t2->next = *head;
                t2 = t2->next;
            }
        }
        *head = (*head)->next;
    }
    t1->next = t2->next = NULL;
    while (p1 != NULL)
    {
        if (*head == NULL)
            *head = t1 = p1;
        else
        {
            t1->next = p1;
            t1 = t1->next;
        }
        p1 = p1->next;
    }
    while (p2 != NULL)
    {
        if (*head == NULL)
            *head = t1 = p2;
        else
        {
            t1->next = p2;
            t1 = t1->next;
        }
        p2 = p2->next;
    }
}

void printList(ListNode *head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void freeList(ListNode **head)
{
    while (*head != NULL)
    {
        ListNode *temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

int main()
{
    int opt, n;
    ListNode *l1 = NULL;
    while (1)
    {
        printf("Options:\n1. Create List.\n2. Partition.\n3. Print list.\n4. Exit\n");
        printf("Enter your choice (1 to 4): ");
        scanf("%d", &opt);
        switch (opt)
        {
        case 1:
            l1 = createList();
            break;
        case 2:
            printf("Enter the value: ");
            scanf("%d", &n);
            partition(&l1, n);
            break;
        case 3:
            printf("List: ");
            printList(l1);
            break;
        case 4:
            freeList(&l1);
            return 0;
        default:
            printf("Wrong Choice!\n");
        }
    }
    return 0;
}