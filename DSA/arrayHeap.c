#include <stdio.h>

void swap(int *n1, int *n2)
{
    int temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}

void minheapify(int *arr, int n, int i)
{
    int c1 = 2 * i + 1, c2 = 2 * i + 2, max = i;
    if (c1 < n && arr[c1] < arr[max])
        max = c1;
    if (c2 < n && arr[c2] < arr[max])
        max = c2;
    if (i != max)
    {
        swap(arr + i, arr + max);
        minheapify(arr, n, max);
    }
}

void maxheapify(int *arr, int n, int i)
{
    int c1 = 2 * i + 1, c2 = 2 * i + 2, max = i;
    if (c1 < n && arr[c1] > arr[max])
        max = c1;
    if (c2 < n && arr[c2] > arr[max])
        max = c2;
    if (i != max)
    {
        swap(arr + i, arr + max);
        maxheapify(arr, n, max);
    }
}

void buildHeap(int *arr, int n, int opt)
{
    if (opt == 0)
        for (int i = n / 2; i >= 0; i--)
            minheapify(arr, n, i);
    else if (opt == 1)
        for (int i = n / 2; i >= 0; i--)
            maxheapify(arr, n, i);
}

void main()
{
    int arr[] = {3, 9, 4, 5, 1, 2};
    int n = sizeof(arr) / sizeof(int);
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    buildHeap(arr, n, 0);
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
}