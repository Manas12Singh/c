#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int compare(void *arr2, const void *a, const void *b)
{
    return ((int *)arr2)[*(int *)a] c- ((int *)arr2)[*(int *)b];
}
// int (*_PtFuncCompare)(void *, const void *, const void *), void *_Context)
void fcfs(int n, int *processes, int *arrivalTime, double *avgWaitTime, double *avgTurnAroundTime)
{
    int index[n];
    for (int i = 0; i < n; i++)
        index[i] = i;
    qsort_s(index, n, sizeof(int), &compare, arrivalTime);
    for (int i = 0; i < n; i++)
        printf("%d ", index[i]);
    *avgWaitTime = 0;
    *avgTurnAroundTime = 0;
    int pSum = 0;
    for (int i = 0; i < n; i++)
    {
        *avgWaitTime += fmax(0, pSum - arrivalTime[index[i]]);
        pSum += processes[index[i]];
        *avgTurnAroundTime += fmax(0, pSum - arrivalTime[index[i]]);
    }
    *avgWaitTime /= n;
    *avgTurnAroundTime /= n;
}

int main()
{
    int processes[] = {5, 3, 8, 6};
    int arrivalTime[] = {0, 1, 2, 3};
    double avgWaitTime, avgTurnAroundTime;
    fcfs(4, processes, arrivalTime, &avgWaitTime, &avgTurnAroundTime);
    printf("%lf %lf", avgWaitTime, avgTurnAroundTime);
}