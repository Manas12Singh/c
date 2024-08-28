#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
struct ListNode
{
    int val;
    struct ListNode *next;
};

void insert(struct ListNode **top, int a)
{
    struct ListNode *temp = (struct ListNode *)malloc(sizeof(struct ListNode));
    temp->val = a;
    if (*top == NULL)
    {
        *top = temp;
        temp->next = NULL;
    }
    else
    {
        temp->next = *top;
        *top = temp;
    }
}
void delete1(struct ListNode **top)
{
    struct ListNode *temp = *top;
    if (temp->next == NULL)
    {
        (*top) = NULL;
        free(temp);
    }
    else
    {
        *top = temp->next;
        free(temp);
    }
}
bool isPalindrome(struct ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return 1;
    struct ListNode *top = NULL;
    int count = 1;
    struct ListNode *temp = head;
    while (temp->next)
    {
        count++;
        temp = temp->next;
    }
    temp = head;
    for (int i = 1; i <= count; i++)
    {
        if (count % 2 != 0)
        {
            if ((count / 2) + 1 == i)
            {
                temp = temp->next;
                if (temp == NULL)
                    break;
            }
            else
            {
                if (top != NULL && (top->val == temp->val))
                {
                    delete1(&top);
                }
                else
                {
                    insert(&top, temp->val);
                }
            }
        }
        else
        {
            if (top != NULL && top->val == temp->val)
            {
                delete1(&top);
            }
            else
            {
                insert(&top, temp->val);
            }
        }
        temp = temp->next;
        if (temp == NULL)
            break;
    }
    if (top == NULL)
        return 1;
    else
        return 0;
}