#include "circularQueue.h"
#include <conio.h>
int main()
{
    struct queue *q1 = NULL;
    while (1)
    {
        int opt, n, k;
        system("cls");
        puts("Options: \n1. Create a new queue. \n2. Push. \n3. Pop. \n4. Front. \n5. Print. \n6. Exit.");
        printf("Enter your choice (1 to 11): ");
        scanf("%d%*c", &opt);
        switch (opt)
        {
        case 1:
            printf("Enter the max size of queue: ");
            scanf("%d%*c", &n);
            intialize(&q1, n);
            break;
        case 2:
            printf("Enter the value: ");
            scanf("%d%*c", &k);
            enque(q1, k);
            break;
        case 3:
            deque(q1);
            break;
        case 4:
            front(q1);
            break;
        case 5:
            print(q1);
            break;
        case 6:
            freeQueue(&q1);
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
