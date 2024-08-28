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