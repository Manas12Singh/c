#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    void *queue;
    size_t maxSize;
    size_t elementSize;
    size_t currentSize;
    int (*compare)(const void *, const void *);
} Priority_Queue;

int defaultCompare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

/*
Creates a Priority Queue with maxSize elements of elementSize bytes each.
compare function to compare elements (default is integer comparison).
*/
Priority_Queue *createPriorityQueue(size_t maxSize, size_t elementSize, int (*compare)(const void *, const void *))
{
    Priority_Queue *pq = (Priority_Queue *)malloc(sizeof(Priority_Queue));
    if (!pq)
    {
        perror("Failed to allocate memory for Priority Queue");
        exit(EXIT_FAILURE);
    }
    pq->queue = malloc(maxSize * elementSize);
    if (!pq->queue)
    {
        free(pq);
        perror("Failed to allocate memory for queue elements");
        exit(EXIT_FAILURE);
    }
    pq->maxSize = maxSize;
    pq->currentSize = 0;
    pq->elementSize = elementSize;
    pq->compare = compare == NULL ? &defaultCompare : compare;
    return pq;
}

void push(Priority_Queue *pq, void *element)
{
    if (pq->currentSize == pq->maxSize)
    {
        perror("Queue is full");
        return;
    }
    size_t i = pq->currentSize++;
    while (i > 0)
    {
        size_t parent = (i - 1) / 2;
        if (pq->compare(element, (char *)pq->queue + parent * pq->elementSize) >= 0)
            break;
        memcpy((char *)pq->queue + i * pq->elementSize, (char *)pq->queue + parent * pq->elementSize, pq->elementSize);
        i = parent;
    }
    memcpy((char *)pq->queue + i * pq->elementSize, element, pq->elementSize);
}

void pop(Priority_Queue *pq)
{
    if (pq->currentSize == 0)
    {
        perror("Queue is empty");
        return;
    }

    pq->currentSize--;
    void *lastElement = (char *)pq->queue + pq->currentSize * pq->elementSize;
    memcpy(pq->queue, lastElement, pq->elementSize);

    size_t i = 0;
    while (i < pq->currentSize / 2)
    {
        size_t left = 2 * i + 1;
        size_t right = 2 * i + 2;
        size_t smallest = left;

        if (right < pq->currentSize && pq->compare((char *)pq->queue + right * pq->elementSize, (char *)pq->queue + left * pq->elementSize) < 0)
            smallest = right;
        if (pq->compare((char *)pq->queue + i * pq->elementSize, (char *)pq->queue + smallest * pq->elementSize) <= 0)
            break;

        char *temp = (char *)malloc(pq->elementSize);
        if (!temp)
        {
            perror("Failed to allocate temporary memory");
            exit(EXIT_FAILURE);
        }
        memcpy(temp, (char *)pq->queue + i * pq->elementSize, pq->elementSize);
        memcpy((char *)pq->queue + i * pq->elementSize, (char *)pq->queue + smallest * pq->elementSize, pq->elementSize);
        memcpy((char *)pq->queue + smallest * pq->elementSize, temp, pq->elementSize);
        free(temp);

        i = smallest;
    }
}

void *top(Priority_Queue *pq)
{
    if (pq->currentSize == 0)
    {
        perror("Queue is empty");
        return NULL;
    }
    void *topElement = malloc(pq->elementSize);
    if (!topElement)
    {
        perror("Failed to allocate memory for top element");
        exit(EXIT_FAILURE);
    }
    memcpy(topElement, pq->queue, pq->elementSize);
    return topElement;
}

void freePriorityQueue(Priority_Queue *pq)
{
    free(pq->queue);
    free(pq);
}
