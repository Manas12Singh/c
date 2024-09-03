#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct
{
    int id;
    int arrivalTime;
    int burstTime;
} Process;

int compare(const void *a, const void *b)
{
    Process *processA = (Process *)a;
    Process *processB = (Process *)b;
    return processA->arrivalTime - processB->arrivalTime;
}

void sjf(int n, Process *processes, double *avgWaitTime, double *avgTurnAroundTime)
{
    qsort(processes, n, sizeof(Process), compare);
    *avgWaitTime = 0;
    *avgTurnAroundTime = 0;
    int currentTime = processes[0].arrivalTime;
    int j = 0;
    printf("Gantt Chart: ");
    for (int i = 0; i < n; i++)
    {
        int m = i;
        for (int j = i + 1; j < n; j++)
        {
            if (processes[j].arrivalTime <= currentTime)
            {
                if (processes[j].burstTime < processes[m].burstTime)
                    m = j;
            }
            else
                break;
        }
        if (m != i)
        {
            Process temp = processes[i];
            processes[i] = processes[m];
            processes[m] = temp;
        }
        currentTime = fmax(currentTime, processes[i].arrivalTime);
        *avgWaitTime += currentTime - processes[i].arrivalTime;
        *avgTurnAroundTime += currentTime - processes[i].arrivalTime + processes[i].burstTime;
        currentTime += processes[i].burstTime;
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
