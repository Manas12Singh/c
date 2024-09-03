#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "structure.h"
typedef struct
{
    int id;
    int arrivalTime;
    int burstTime;
    int remainingTime;
} Process;

int compareArrival(const void *a, const void *b)
{
    Process *processA = (Process *)a;
    Process *processB = (Process *)b;
    return processA->arrivalTime - processB->arrivalTime;
}

int compareRemaining(const void *a, const void *b)
{
    Process *processA = (Process *)a;
    Process *processB = (Process *)b;
    if (processA->remainingTime == processB->remainingTime)
        return processA->arrivalTime - processB->arrivalTime;
    return processA->remainingTime - processB->remainingTime;
}

void srt(int n, Process *processes, double *avgWaitTime, double *avgTurnAroundTime)
{
    qsort(processes, n, sizeof(Process), compareArrival);
    *avgWaitTime = 0;
    *avgTurnAroundTime = 0;
    int currentTime = processes[0].arrivalTime;
    int nextTime = 0;
    int j = 0;
    Priority_Queue *pq = createPriorityQueue(n, sizeof(Process), compareRemaining);
    printf("Gantt Chart: ");
    do
    {
        while (j < n && processes[j].arrivalTime <= currentTime)
            push(pq, &processes[j++]);
        Process *p = (Process *)top(pq);
        pop(pq);
        printf("P%d ", p->id);
        currentTime = fmax(currentTime, p->arrivalTime);
        *avgWaitTime += currentTime - p->arrivalTime;
        *avgTurnAroundTime += currentTime - p->arrivalTime + p->burstTime;
        currentTime += p->burstTime;
    } while (pq->currentSize > 0);
    printf("\n");
    freePriorityQueue(pq);
    *avgWaitTime /= n;
    *avgTurnAroundTime /= n;
}

int main()
{
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    Process *processes = (Process *)malloc(n * sizeof(Process));

    printf("Enter burst times: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &processes[i].burstTime);
        processes[i].remainingTime = processes[i].burstTime;
        processes[i].id = i;
    }

    printf("Enter arrival times: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &processes[i].arrivalTime);

    double avgWaitTime, avgTurnAroundTime;
    sjf(n, processes, &avgWaitTime, &avgTurnAroundTime);

    printf("Average Waiting Time: %.2lf\n", avgWaitTime);
    printf("Average Turnaround Time: %.2lf\n", avgTurnAroundTime);

    free(processes);

    return 0;
}

// sum(bursttimes)n2logn