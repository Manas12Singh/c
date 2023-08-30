#include <stdio.h>
#include "LinkedList.h"
int main()
{
    struct Node *head = NULL;
    createList(&head);
    printList(head);
    //insertInBegin(&head, 10);
    //printList(head);
    insertAtEnd(&head, 5);
    printList(head);
    insertAfterk(&head, 5, 3);
    printList(head);
    insertBeforek(&head, 5, 3);
    printList(head);

    freeList(&head);
    printList(head);
}
