#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int id;
    int arrivalTime;
    int burstTime;
    int remainingTime;
} Process;
int compareArrival(const void *a, const void *b){
    Process *processA = (Process *)a;
    Process *processB = (Process *)b;
    return processA->arrivalTime - processB->arrivalTime;
}
#define min(a, b) ((a) < (b) ? (a) : (b))
void roundRobin(int n, Process *processes, double *avgWaitTime, double *avgTurnAroundTime, int timeQuantum){
    for(int i = 0; i < n; i++)
        processes[i].remainingTime = processes[i].burstTime;
    qsort(processes, n, sizeof(Process), compareArrival);
    *avgWaitTime = 0;
    *avgTurnAroundTime = 0;
    int currentTime = processes[0].arrivalTime;
    int i = 0;
    int prev = -1;
    printf("Round Robin Gantt Chart: ");
    while (i < n)
    {
        for (int j = i; j < n && processes[j].arrivalTime <= currentTime; j++)
        {
            if (prev != processes[j].id)
            {
                printf("P%d ", processes[j].id);
                prev = processes[j].id;
            }
            int runTime = min(processes[j].remainingTime, timeQuantum);
            processes[j].remainingTime -= runTime;
            currentTime += runTime;
            if (processes[j].remainingTime == 0)
            {
                *avgWaitTime += currentTime - processes[j].arrivalTime - processes[j].burstTime;
                *avgTurnAroundTime += currentTime - processes[j].arrivalTime;
                if (j != i)
                {
                    Process temp = processes[j];
                    processes[j] = processes[i];
                    processes[i] = temp;
                }
                i++;
            }
        }
    }
    printf("\n");
    *avgWaitTime /= n;
    *avgTurnAroundTime /= n;
}
int main(){
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
    printf("Enter time quantum: ");
    scanf("%d", &timeQuantum);
    double avgWaitTime, avgTurnAroundTime;
    roundRobin(n, processes, &avgWaitTime, &avgTurnAroundTime, timeQuantum);
    printf("Average Waiting Time: %.2lf\n", avgWaitTime);
    printf("Average Turnaround Time: %.2lf\n", avgTurnAroundTime);
    free(processes);
    return 0;
}