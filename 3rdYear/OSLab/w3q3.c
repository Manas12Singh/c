#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define min(a, b) ((a) < (b) ? (a) : (b))

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

void srt(int n, Process *processes, double *avgWaitTime, double *avgTurnAroundTime)
{
    qsort(processes, n, sizeof(Process), compareArrival);
    *avgWaitTime = 0;
    *avgTurnAroundTime = 0;
    int currentTime = processes[0].arrivalTime;
    int i = 0, j = 0, prev = -1;
    printf("Gantt Chart: ");
    while (i < n)
    {
        while (j < n && processes[j].arrivalTime <= currentTime)
            j++;
        int minIndex = i;
        for (int k = i + 1; k < j; k++)
            if (processes[k].remainingTime < processes[minIndex].remainingTime)
                minIndex = k;
        if (minIndex != i)
        {
            Process temp = processes[i];
            processes[i] = processes[minIndex];
            processes[minIndex] = temp;
        }
        if (prev != processes[i].id)
        {
            printf("P%d ", processes[i].id);
            prev = processes[i].id;
        }
        int runTime = processes[i].remainingTime;
        if (j < n)
            runTime = min(processes[minIndex].remainingTime, processes[j].arrivalTime - currentTime);
        processes[i].remainingTime -= runTime;
        currentTime += runTime;
        if (processes[i].remainingTime == 0)
        {
            *avgWaitTime += currentTime - processes[i].arrivalTime - processes[i].burstTime;
            *avgTurnAroundTime += currentTime - processes[i].arrivalTime;
            i++;
        }
    }
    printf("\n");
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
    srt(n, processes, &avgWaitTime, &avgTurnAroundTime);

    printf("Average Waiting Time: %.2lf\n", avgWaitTime);
    printf("Average Turnaround Time: %.2lf\n", avgTurnAroundTime);

    free(processes);

    return 0;
}