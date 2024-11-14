#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int *arr;
    int capacity, size, front, rear;
} Queue;

void initialize(Queue *q, int cap)
{
    q->capacity = cap;
    q->size = 0;
    q->front = q->rear = -1;
    q->arr = (int *)malloc(sizeof(int) * cap);
}

void enque(Queue *q, int val)
{
    if (((q->rear + 1) % (q->capacity)) == q->front)
        return;
    q->rear = (q->rear + 1) % (q->capacity);
    if (q->front == -1)
        q->front = 0;
    q->arr[q->rear] = val;
    q->size++;
}

void deque(Queue *q)
{
    if (q->front == -1)
        return;
    if (q->front == q->rear)
        q->front = q->rear = -1;
    else
        q->front = (q->front + 1) % (q->capacity);
    q->size--;
}

int front(Queue *q)
{
    if (q->size == 0)
        return -1;
    return q->arr[q->front];
}

void freeQueue(Queue *q)
{
    free(q->arr);
    q->arr = NULL;
}

void fifo(int n, int *pages, int memorySize)
{
    Queue *memory = (Queue *)malloc(sizeof(Queue));
    initialize(memory, memorySize);
    int pageFaults = 0;
    printf("Page Faults: ");
    for (int i = 0; i < n; i++)
    {
        int page = pages[i];
        int flag = 1;
        for (int j = memory->front; j != (memory->rear + 1) % (memory->capacity); j = (j + 1) % (memory->capacity))
        {
            if (memory->arr[j] == page)
            {
                flag = 0;
                break;
            }
        }
        if (flag)
        {
            pageFaults++;
            if (memory->size == memory->capacity)
            {
                printf("%d ", front(memory));
                deque(memory);
            }
            enque(memory, page);
        }
    }
    freeQueue(memory);
    printf("\nNo of Page Faults: %d\n", pageFaults);
}

int main()
{
    int n, memorySize;
    printf("Enter number of frames available: ");
    scanf("%d", &memorySize);
    printf("Enter number of requests: ");
    scanf("%d", &n);
    int *pages = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        scanf("%d", &pages[i]);
    fifo(n, pages, memorySize);
    free(pages);
    return 0;
}