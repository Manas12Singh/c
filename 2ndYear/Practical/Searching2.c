#include <stdio.h>

int binarySearch(int *arr, int n, int k)
{
    int l = 0, r = n - 1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (arr[mid] == k)
            return mid;
        if (arr[mid] > k)
            r = mid - 1;
        else
            l = mid + 1;
    }
    return -1;
}

int main()
{
    int n, k;
    
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    scanf("%d", &k);
    int i = binarySearch(arr, n, k);
    if (i == -1)
        printf("Value not found.\n");
    else
        printf("Value found at index %d.\n", i);
    return 0;
}