

int main()
{
    struct queue *q1 = NULL;
    while (1)
    {
        int opt, k, n;
        printf("Options: \n1. Create a new queue. \n2. Enque. \n3. Deque. \n4. Front. \n5. Print. \n6. Exit.\n");
        printf("Enter your choice (1 to 6): ");
        scanf("%d", &opt);
        switch (opt)
        {
        case 1:
            intialize(&q1);
            break;
        case 2:
            printf("Enter the value: ");
            scanf("%d", &k);
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
            return 0;
        default:
            printf("Wrong Choice!\n");
        }
    }
    return 0;
}