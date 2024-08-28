#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int *arr;
    int capacity, size, front, rear;
};

void intialize(struct queue **q1, int cap)
{
    *q1 = (struct queue *)malloc(sizeof(struct queue));
    (*q1)->capacity = cap;
    (*q1)->size = 0;
    (*q1)->front = (*q1)->rear = -1;
    (*q1)->arr = (int *)malloc(sizeof(int) * cap);
}

void enque(struct queue *q1, int val)
{
    if (((q1->rear + 1) % (q1->capacity)) == q1->front)
    {
        printf("Queue already full!\n");
        return;
    }
    q1->rear = (q1->rear + 1) % (q1->capacity);
    if (q1->front == -1)
        q1->front = 0;
    q1->arr[q1->rear] = val;
    q1->size++;
}

void deque(struct queue *q1)
{
    if (q1->front == -1)
    {
        printf("Queue already empty!\n");
        return;
    }
    q1->front = (q1->front + 1) % (q1->capacity);
    if (q1->front == (q1->rear + 1) % (q1->capacity))
        q1->front = q1->rear = -1;
    q1->size--;
}

void front(struct queue *q1)
{
    if (q1->size == 0)
    {
        printf("Queue is empty!\n");
        return;
    }
    printf("%d\n", q1->arr[q1->front]);
}

void print(struct queue *q1)
{
    if (q1->size == 0)
    {
        printf("Queue is empty!\n");
        return;
    }
    int n = q1->front;
    while (n != q1->rear)
    {
        printf("%d ", q1->arr[n]);
        n = (n + 1) % (q1->capacity);
    }
    printf("%d\n", q1->arr[n]);
    printf("\n");
}

void freeQueue(struct queue **q1)
{
    free((*q1)->arr);
    free(*q1);
    *q1 = NULL;
}

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
            printf("Enter the max size of queue: ");
            scanf("%d", &n);
            intialize(&q1, n);
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
