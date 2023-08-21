#include "listOfNumber.h"

int main()
{
    struct Node *start = NULL;
    while (1)
    {
        int opt;
        system("cls");
        puts("Options: \n1. Create a new list. \n2. Insert at the Beginning. \n3. Insert at the End. \n4. Insert at a Specific Index. \n5. Delete from the Beginning. \n6. Delete from the End. \n7. Delete from a Specific Index. \n8. Search. \n9. Get the Length. \n10. Print the Linked List. \n11. Exit.");
        printf("Enter your choice (1 to 10): ");
        scanf("%d%*c", &opt);
        switch (opt)
        {
        case 1:
            start = newList();
            break;
        case 2:
            start = insertToStart(start);
            break;
        case 3:
            // addToIndex(start);
            break;
        case 4:
            // start = addToStart(start);
            break;
        case 5:
            // deleteFromEnd(start);
            break;
        case 6:
            // start = deleteFromStart(start);
            break;
        case 7:
            // deleteFromIndex(start);
            break;
        case 8:
            // searchElement(start);
            break;
        case 9:
            printList(start);
            break;
        case 10:
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
