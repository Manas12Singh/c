#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int *arr;
    int capacity, size, rear;
} Queue;

void intialize(Queue **q1, int cap)
{
    *q1 = (Queue *)malloc(sizeof(Queue));
    (*q1)->capacity = cap;
    (*q1)->size = 0;
    (*q1)->rear = -1;
    (*q1)->arr = (int *)malloc(sizeof(int) * cap);
}

void enqueue(Queue *q1, int val)
{
    if (q1->rear + 1 == q1->capacity)
    {
        printf("Queue already full!\n");
        return;
    }
    q1->rear = q1->rear + 1;
    q1->arr[q1->rear] = val;
    q1->size++;
}

void dequeue(Queue *q1)
{
    if (q1->rear == -1)
    {
        printf("Queue already empty!\n");
        return;
    }
    int n = 0;
    printf("Dequeued value: %d\n", q1->arr[0]);
    while (n < q1->rear)
    {
        q1->arr[n] = q1->arr[n + 1];
        n++;
    }
    q1->rear--;
    q1->size--;
}

void front(Queue *q1)
{
    if (q1->size == 0)
    {
        printf("Queue is empty!\n");
        return;
    }
    printf("%d\n", q1->arr[0]);
}

void print(Queue *q1)
{
    if (q1->size == 0)
    {
        printf("Queue is empty!\n");
        return;
    }
    int n = 0;
    printf("Queue: ");
    while (n <= q1->rear)
    {
        printf("%d ", q1->arr[n]);
        n++;
    }
    printf("\n");
}

void freeQueue(Queue **q1)
{
    free((*q1)->arr);
    free(*q1);
    *q1 = NULL;
}

int main()
{
    Queue *q1 = NULL;
    while (1)
    {
        int opt, k, n;
        printf("Options: \n1. Create a new queue. \n2. Enque. \n3. Deque. \n4. Front. \n5. Print. \n6. Exit.\n");
        printf("Enter your choice (1 to 6): ");
        scanf("%d", &opt);
        if (opt == 1)
        {
            if (q1)
            {
                printf("Queue already exists.\n");
                continue;
            }
            printf("Enter the max size of queue: ");
            scanf("%d", &n);
            intialize(&q1, n);
        }
        else if (opt >= 2 && opt <= 6)
        {
            if (q1 == NULL)
            {
                printf("Please create a queue first.\n");
                continue;
            }
            switch (opt)
            {
            case 2:
                printf("Enter the value: ");
                scanf("%d", &k);
                enqueue(q1, k);
                break;
            case 3:
                dequeue(q1);
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
            }
        }
        else
            printf("Wrong Choice!\n");
        printf("\n");
    }
    return 0;
}
