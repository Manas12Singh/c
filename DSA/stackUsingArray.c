#include "stackUsingArray.h"
#include <conio.h>
int main()
{
    struct stack *s1 = NULL;
    while (1)
    {
        int opt, n, k;
        system("cls");
        puts("Options: \n1. Create a new stack. \n2. Push. \n3. Pop. \n4. Top. \n5. Print. \n6. Exit.");
        printf("Enter your choice (1 to 11): ");
        scanf("%d%*c", &opt);
        switch (opt)
        {
        case 1:
            printf("Enter the max size of stack: ");
            scanf("%d%*c", &n);
            intialize(&s1, n);
            break;
        case 2:
            printf("Enter the value: ");
            scanf("%d%*c", &k);
            push(s1, k);
            break;
        case 3:
            pop(s1);
            break;
        case 4:
            top(s1);
            break;
        case 5:
            print(s1);
            break;
        case 6:
            freeStack(&s1);
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
