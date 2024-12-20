#include <stdio.h>
#include <stdlib.h>

#define MAXTRACKS 200

int scan(int n, int *requests, int currHead)
{
    int totalSeek = 0;
    int direction = 1;
    int reqCompleted[n];
    int completed = 0;
    for (int i = 0; i < n; i++)
        reqCompleted[i] = 0;
    printf("Seek sequence: ");
    while (completed < n)
    {
        int nextReq = -1;
        for (int j = 0; j < n; j++)
        {
            if (reqCompleted[j] == 0 && direction * requests[j] >= direction * currHead)
            {
                if (nextReq == -1 || direction * requests[j] <= direction * requests[nextReq])
                    nextReq = j;
            }
        }
        if (nextReq == -1)
        {
            if (direction == 1)
            {
                totalSeek += MAXTRACKS - 1 - currHead;
                currHead = MAXTRACKS - 1;
            }
            else
            {
                totalSeek += currHead;
                currHead = 0;
            }
            direction *= -1;
        }
        else
        {
            totalSeek += abs(requests[nextReq] - currHead);
            currHead = requests[nextReq];
            reqCompleted[nextReq] = 1;
            completed++;
            printf("%d ", currHead);
        }
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
    printf("Total seek movement: %d\n", scan(n, requests, currHead));
    return 0;
}
