#include <stdio.h>
#include <stdlib.h>

// #define insert(head,trav,temp) {if(head==NULL) head=trav=temp; else {trav->next=temp;trav=trav->next;}}

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
    if (*head == NULL || (*head)->next == NULL)
        return;
    ListNode *trav = *head;
    ListNode *later = NULL, *ltrav = NULL;
    while (trav->next != NULL)
    {
        if (trav->next->data >= k)
        {
            if (later == NULL)
                later = ltrav = trav->next;
            else
            {
                ltrav->next = trav->next;
                ltrav = ltrav->next;
            }
            trav->next = trav->next->next;
        }
        else
            trav = trav->next;
    }
    if ((*head)->data >= k)
    {
        ListNode *temp = *head;
        *head = (*head)->next;
        temp->next = later;
        later = temp;
    }
    if (ltrav != NULL)
        ltrav->next = NULL;
    if (*head == NULL)
        *head = later;
    else
        trav->next = later;
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
    do
    {
        printf("Options:\n1. Create List.\n2. Partition.\n3. Print list.\n4. Exit\n");
        printf("Enter your choice (1 to 4): ");
        scanf("%d", &opt);
        switch (opt)
        {
        case 1:
            if (l1 != NULL)
                freeList(&l1);
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
            break;
        default:
            printf("Wrong Choice!\n");
        }
    } while (opt != 4);
    freeList(&l1);
    return 0;
}