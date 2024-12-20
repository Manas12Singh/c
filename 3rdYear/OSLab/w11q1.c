#include <stdio.h>
#include <stdlib.h>

#define MAXTRACKS 200

int fcfs(int n, int *requests, int currHead)
{
    int totalSeek = 0;
    printf("Seek sequence: ");
    for (int i = 0; i < n; i++)
    {
        totalSeek += abs(requests[i] - currHead);
        currHead = requests[i];
        printf("%d ", currHead);
    }
    printf("\n");
    return totalSeek;
}

int main()
{
    int n;
    printf("Enter the number of disk requests: ");
    scanf("%d", &n);
    int requests[n];
    printf("Enter the disk requests: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &requests[i]);
        if (requests[i] >= MAXTRACKS || requests[i] < 0)
        {
            printf("Error: Requested track is out of range.\n");
            return 1;
        }
    }
    int currHead;
    printf("Enter the current head position: ");
    scanf("%d", &currHead);
    printf("Total seek movement: %d\n", fcfs(n, requests, currHead));
    return 0;
}
