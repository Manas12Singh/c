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

int length(ListNode *n1)
{
    int len = 0;
    while (n1 != NULL)
        len++, n1 = n1->next;
    return len;
}

void rearrange(ListNode **head)
{
    int len = length(*head);
    if (len <= 2)
        return;
    ListNode *temp = NULL, *trav = *head;
    len /= 2;
    while (len-- > 0)
        trav = trav->next;
    while (trav->next != NULL)
    {
        ListNode *t = trav->next;
        trav->next = trav->next->next;
        t->next = temp;
        temp = t;
    }
    ListNode *merge = *head;
    trav = *head;
    *head = (*head)->next;
    while (temp != NULL)
    {
        trav->next = temp;
        temp = temp->next;
        trav = trav->next;
        trav->next = *head;
        (*head) = (*head)->next;
        trav = trav->next;
    }
    *head = merge;
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
        printf("Options:\n1. Create List.\n2. Rearrange.\n3. Print list.\n4. Exit\n");
        printf("Enter your choice (1 to 4): ");
        scanf("%d", &opt);
        switch (opt)
        {
        case 1:
            l1 = createList();
            break;
        case 2:
            rearrange(&l1);
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