#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int id;
    int arrivalTime;
    int priority;
    int burstTime;
    int remainingTime;
    int isCompleted;
} Process;
int compareArrival(const void *a, const void *b)
{
    Process *processA = (Process *)a;
    Process *processB = (Process *)b;
    return processA->arrivalTime - processB->arrivalTime;
}
#define min(a, b) ((a) < (b) ? (a) : (b))
void priority(int n, Process *processes, double *avgWaitTime, double *avgTurnAroundTime)
{
    for (int i = 0; i < n; i++)
    {
        processes[i].remainingTime = processes[i].burstTime;
        processes[i].isCompleted = 0;
    }
    qsort(processes, n, sizeof(Process), compareArrival);
    *avgWaitTime = 0;
    *avgTurnAroundTime = 0;
    int currentTime = processes[0].arrivalTime;
    int completed = 0;
    int prev = -1;
    int j = 0;
    printf("Priority Scheduling Gantt Chart: ");
    while (completed < n)
    {
        while (j < n && processes[j].arrivalTime <= currentTime)
            j++;
        int m = -1;
        for (int k = 0; k < j; k++)
            if (processes[k].isCompleted == 0 && (m == -1 || processes[k].priority < processes[m].priority))
                m = k;
        if (m == -1)
        {
            currentTime = processes[j].arrivalTime;
            continue;
        }
        if (prev != processes[m].id)
        {
            printf("P%d ", processes[m].id);
            prev = processes[m].id;
        }
        int runTime = processes[m].remainingTime;
        if (j < n)
            runTime = min(runTime, processes[j].arrivalTime - currentTime);
        processes[m].remainingTime -= runTime;
        currentTime += runTime;
        if (processes[m].remainingTime == 0)
        {
            processes[m].isCompleted = 1;
            *avgWaitTime += currentTime - processes[m].arrivalTime - processes[m].burstTime;
            *avgTurnAroundTime += currentTime - processes[m].arrivalTime;
            completed++;
        }
    }
    printf("\n");
    *avgWaitTime /= n;
    *avgTurnAroundTime /= n;
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
        scanf("%d", &processes[i].arrivalTime);
    printf("Enter priorities: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &processes[i].priority);
    double avgWaitTime, avgTurnAroundTime;
    priority(n, processes, &avgWaitTime, &avgTurnAroundTime);
    printf("Average Waiting Time: %.2lf\n", avgWaitTime);
    printf("Average Turnaround Time: %.2lf\n", avgTurnAroundTime);
    free(processes);
    return 0;
}
