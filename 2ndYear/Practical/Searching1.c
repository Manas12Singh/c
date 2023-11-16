#include <stdio.h>

int linearSearch(int *arr, int n, int k)
{
    for (int i = 0; i < n; i++)
        if (arr[i] == k)
            return i;
    return -1;
}

int main()
{
    int n, k;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    printf("Enter the value to be searched: ");
    scanf("%d", &k);
    int i = linearSearch(arr, n, k);
    if (i == -1)
        printf("Value not found.\n");
    else
        printf("Value found at index %d.\n", i);
    return 0;
}
