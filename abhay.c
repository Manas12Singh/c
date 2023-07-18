#include <stdio.h>

int bin(int arr[], int element, int size)
{
    int low = 0, mid, high;
    high = size - 1;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (arr[mid] == element)
            return 1;
        if (arr[mid] > element)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return 0;
}

void main()
{
    int arr[] = {1, 2, 3, 4, 5, 6};
    int n = bin(arr, 1, 6);
    printf("%d", n);
}