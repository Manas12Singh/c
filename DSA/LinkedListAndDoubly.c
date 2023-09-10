#include "LinkedList.h"
// #include "doublyLinkedList.h"
#include <conio.h>

int main()
{
    struct Node *head = NULL;
    while (1)
    {
        int opt, n, k;
        system("cls");
        puts("Options: \n1. Create a new list. \n2. Insert at the Beginning. \n3. Insert at the End. \n4. Insert after k.\n5. Insert before k. \n6. Delete from the Beginning. \n7. Delete from the End. \n8. Delete k.\n9. Delete all k.\n10. Print the Linked List. \n11. Exit.");
        printf("Enter your choice (1 to 11): ");
        scanf("%d%*c", &opt);
        switch (opt)
        {
        case 1:
            createList(&head);
            break;
        case 2:
            printf("Enter the value: ");
            scanf("%d%*c", &n);
            insertAtBegin(&head, n);
            break;
        case 3:
            printf("Enter the value: ");
            scanf("%d%*c", &n);
            insertAtEnd(&head, n);
            break;
        case 4:
            printf("Enter the value: ");
            scanf("%d%*c", &n);
            printf("Enter k: ");
            scanf("%d%*c", &k);
            insertAfterk(&head, n, k);
            break;
        case 5:
            printf("Enter the value: ");
            scanf("%d%*c", &n);
            printf("Enter k: ");
            scanf("%d%*c", &k);
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
            scanf("%d%*c", &k);
            deletek(&head, k);
            break;
        case 9:
            printf("Enter k: ");
            scanf("%d%*c", &k);
            deleteAllk(&head, k);
            break;
        case 10:
            printf("Linked List: ");
            printList(head);
            break;
        case 11:
            freeList(&head);
            exit(1);
        default:
            puts("Wrong Choice!");
            break;
        }
        puts("Press any key to continue... ");
        getch();
    }
    return 0;
}
