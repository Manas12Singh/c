#include <stdio.h>
#include "LinkedList.h"

int main()
{
    struct Node* head =NULL;
    createList(&head);
    printList(head);
}
