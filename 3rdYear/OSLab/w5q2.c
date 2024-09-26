#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    short finish;
    int id;
    int *maxReq;
    int *allocated;
} Process;

int main()
{
    int p, r;
    printf("Enter number of processes: ");
    scanf("%d", &p);
    printf("Enter number of resources: ");
    scanf("%d", &r);
    int resource[r];
    int available[r];
    for (int i = 0; i < r; i++)
        available[i] = 0;
    Process processes[p];
    for (int i = 0; i < p; i++)
    {
        processes[i].maxReq = (int *)malloc(r * sizeof(int));
        processes[i].allocated = (int *)malloc(r * sizeof(int));
        processes[i].id = i;
        processes[i].finish = 0;
    }
    printf("Enter maximum requirement: ");
    for (int i = 0; i < p; i++)
        for (int j = 0; j < r; j++)
            scanf("%d", &processes[i].maxReq[j]);
    printf("Enter allocated matrix: ");
    for (int i = 0; i < p; i++)
        for (int j = 0; j < r; j++)
        {
            scanf("%d", &processes[i].allocated[j]);
            available[j] -= processes[i].allocated[j];
        }
    printf("Enter resource vector: ");
    for (int i = 0; i < r; i++)
    {
        scanf("%d", &resource[i]);
        available[i] = resource[i] + available[i];
    }
    for (int i = 0; i < p; i++)
    {
        int j=0;
        while(j<p)
        {
            
        }
    }
    return 0;
}