#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef PRIORITY_QUEUE_H

#define PRIORITY_QUEUE_H

typedef struct
{
    void *queue;
    size_t maxSize;
    size_t elementSize;
    size_t currentSize;
    int (*compare)(const void *, const void *);
} Priority_Queue;

int defaultCompare(const void *a, const void *b);

/*
Creates a Priority Queue with maxSize elements of elementSize bytes each.
compare function to compare elements (default is integer comparison).
*/
Priority_Queue *createPriorityQueue(size_t maxSize, size_t elementSize, int (*compare)(const void *, const void *));

void push(Priority_Queue *pq, void *element);

void pop(Priority_Queue *pq);

void *top(Priority_Queue *pq);

void freePriorityQueue(Priority_Queue *pq);

#endif // PRIORITY_QUEUE_H