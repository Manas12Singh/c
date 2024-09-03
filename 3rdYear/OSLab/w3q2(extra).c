#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "structure.h"
typedef struct
{
    int id;
    int arrivalTime;
    int burstTime;
} Process;

int compareArrival(const void *a, const void *b)
{
    Process *processA = (Process *)a;
    Process *processB = (Process *)b;
    return processA->arrivalTime - processB->arrivalTime;
}

int compareBurst(const void *a, const void *b)
{
    Process *processA = (Process *)a;
    Process *processB = (Process *)b;
    if (processA->burstTime == processB->burstTime)
        return processA->arrivalTime - processB->arrivalTime;
    return processA->burstTime - processB->burstTime;
}

void sjf(int n, Process *processes, double *avgWaitTime, double *avgTurnAroundTime)
{
    qsort(processes, n, sizeof(Process), compareArrival);
    *avgWaitTime = 0;
    *avgTurnAroundTime = 0;
    int currentTime = processes[0].arrivalTime;
    int j = 0;
    Priority_Queue *pq = createPriorityQueue(n, sizeof(Process), compareBurst);
    printf("Gantt Chart: ");
    for (int i = 0; i < n; i++)
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
    }
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
