#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define min(a, b) ((a) < (b) ? (a) : (b))
typedef struct
{
    int id;
    int arrivalTime;
    int burstTime;
    int priority;
} Process;
int compareArrival(const void *a, const void *b)
{
    Process *processA = (Process *)a;
    Process *processB = (Process *)b;
    return processA->arrivalTime - processB->arrivalTime;
}



int main()
{
    int n, timeQuantum;
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
    {
        scanf("%d", &processes[i].arrivalTime);
    }
    double avgWaitTime, avgTurnAroundTime;
    printf("Average Waiting Time: %.2lf\n", avgWaitTime);
    printf("Average Turnaround Time: %.2lf\n", avgTurnAroundTime);
    free(processes);
    return 0;
}
