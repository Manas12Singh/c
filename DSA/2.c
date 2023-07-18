#include "listOfNumber.h"

int main()
{
    struct Node *start = NULL;
    while (1)
    {
        int opt;
        system("cls");
        puts("Options: \n1. Create a new list. \n2. Add element to end of the list. \n3. Add element at an index. \n4. Add element a the starting of the list. \n5. Delete element from the end of the list. \n6. Delete element from the starting of the list. \n7. Delete element from an index. \n8. Search an element in the linked list. \n9. Print the values of the list. \n10. Exit");
        printf("Enter your choice (1 to 10): ");
        scanf("%d%*c", &opt);
        switch (opt)
        {
        case 1:
            start = newList();
            break;
        case 2:
            addToEnd(start);
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
