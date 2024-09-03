#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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
    int nextTime = 0;
    int i = 0, j = 1;
    printf("Gantt Chart: ");
    while (i < n)
    {
        int m=i;
        while(j<n && processes[j].arrivalTime<=currentTime)
            j++;
        for(int k=i;k<j;k++)
        {
        }
        printf("P%d ", p->id);
        currentTime = fmax(currentTime, p->arrivalTime);
        *avgWaitTime += currentTime - p->arrivalTime;
        *avgTurnAroundTime += currentTime - p->arrivalTime + p->burstTime;
        currentTime += p->burstTime;
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
    sjf(n, processes, &avgWaitTime, &avgTurnAroundTime);

    printf("Average Waiting Time: %.2lf\n", avgWaitTime);
    printf("Average Turnaround Time: %.2lf\n", avgTurnAroundTime);

    free(processes);

    return 0;
}

// sum(bursttimes)n2logn