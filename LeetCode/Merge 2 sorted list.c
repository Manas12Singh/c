#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *mergeTwoLists(struct ListNode *list1, struct ListNode *list2)
{
    if (list1 == NULL)
        return list2;
    else if (list2 == NULL)
        return list1;
    struct ListNode *head, *cur;
    if (list1->val <= list2->val)
    {
        cur = head = (struct ListNode *)calloc(1, sizeof(struct ListNode));
        head->val = list1->val;
        list1 = list1->next;
    }
    else
    {
        cur = head = (struct ListNode *)calloc(1, sizeof(struct ListNode));
        head->val = list2->val;
        list2 = list2->next;
    }
    while (list1 != NULL && list2 != NULL)
    {
        if (list1->val <= list2->val)
        {
            cur->next = (struct ListNode *)calloc(1, sizeof(struct ListNode));
            cur = cur->next;
            cur->val = list1->val;
            list1 = list1->next;
        }
        else
        {
            cur->next = (struct ListNode *)calloc(1, sizeof(struct ListNode));
            cur = cur->next;
            cur->val = list2->val;
            list2 = list2->next;
        }
    }
    while (list1 != NULL)
    {
        cur->next = (struct ListNode *)calloc(1, sizeof(struct ListNode));
        cur = cur->next;
        list1 = list1->val;
    }
    while (list2 != NULL)
    {
        cur->next = (struct ListNode *)calloc(1, sizeof(struct ListNode));
        cur = cur->next;
        list2 = list2->val;
    }
    return head;
}