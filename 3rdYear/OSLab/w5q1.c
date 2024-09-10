#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int id;
    int* maxReq;
    int* allocated;
} Process;

int main()
{
    int p, r;
    printf("Enter number of processes: ");
    scanf("%d", &p);
    printf("Enter number of resources: ");
    scanf("%d", &r);
    int *available = (int *)malloc(r * sizeof(int));
    int *max = (int *)malloc(p * r * sizeof(int));
    int *allocation = (int *)malloc(p * r * sizeof(int));
    int *need = (int *)malloc(p * r * sizeof(int));
    printf("Enter available resources: ");
    for (int i = 0; i < r; i++)
        scanf("%d", &available[i]);
    printf("Enter max resources: ");
    for (int i = 0; i < p; i++)
        for (int j = 0; j < r; j++)
            scanf("%d", &max[i * r + j]);
    printf("Enter allocated resources: ");
    for (int i = 0; i < p; i++)
        for (int j = 0; j < r; j++)
            scanf("%d", &allocation[i * r + j]);
    for (int i = 0; i < p; i++)

        for (int j = 0; j < r; j++)
            need[i * r + j] = max[i * r + j] - allocation[i * r + j];
    int *finish = (int *)malloc(p * sizeof(int));
    for (int i = 0; i < p; i++)
        finish[i] = 0;
    int *safeSeq = (int *)malloc(p * sizeof(int));
    int *work = (int *)malloc(r * sizeof(int));
    for (int i = 0; i < r; i++)
        work[i] = available[i];
    int count = 0;
    while (count < p)
    {
        int found = 0;
        for (int i = 0; i < p; i++)
        {
            if (finish[i] == 0)
            {
                int j;
                for (j = 0; j < r; j++)
                    if (need[i * r + j] > work[j])
                        break;
                if (j == r)
                {
                    for (j = 0; j < r; j++)
                        work[j] += allocation[i * r + j];
                    safeSeq[count++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }
        if (found == 0)
        {
            printf("System is not in safe state\n");
            free(available);
            free(max);
            free(allocation);
            free(need);
            free(finish);
            free(safeSeq);
            free(work);
            return 0;
        }
    }
    printf("System is in safe state\n");
    printf("Safe sequence: ");
    for (int i = 0; i < p; i++)
        printf("%d ", safeSeq[i]);
    printf("\n");
    free(available);
    free(max);
    free(allocation);
    free(need);
    free(finish);
    free(safeSeq);
    free(work);
    return 0;
}