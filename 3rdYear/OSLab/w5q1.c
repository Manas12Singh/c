#include <stdio.h>
#include <stdlib.h>

typedef struct
{
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
        for (int i = 0; i < r; i++)
            printf("%d ", available[i]);
        printf("\n");
        int canFinish = i;
        while (canFinish < p)
        {
            int j = 0;
            while (j < r)
            {
                if (processes[canFinish].maxReq[j] - processes[canFinish].allocated[j] > available[j])
                    break;
                j++;
            }
            if (j == r)
                break;
            canFinish++;
        }
        if (canFinish == p)
        {
            printf("Request cannot be fulfilled\n");
            return 0;
        }
        Process temp = processes[i];
        processes[i] = processes[canFinish];
        processes[canFinish] = temp;
        for (int j = 0; j < r; j++)
            available[j] += processes[i].allocated[j];
    }
    printf("Request can be fulfilled\n");
    printf("Safe sequence: ");
    for (int i = 0; i < p; i++)
        printf("P%d ", processes[i].id);
    for (int i = 0; i < p; i++)
    {
        free(processes[i].maxReq);
        free(processes[i].allocated);
    }
    printf("\n");
    return 0;
}