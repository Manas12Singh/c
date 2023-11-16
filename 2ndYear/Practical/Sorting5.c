#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *arr, int left, int right)
{
    int i = left - 1;
    for (int j = left; j <= right; j++)
        if (arr[j] < arr[right])
            swap(&arr[++i], &arr[j]);
    swap(&arr[++i], &arr[right]);
    return i;
}

void quickSort(int *arr, int left, int right)
{
    if (left < right)
    {
        int p = partition(arr, left, right);
        quickSort(arr, left, p - 1);
        quickSort(arr, p + 1, right);
    }
}

int main()
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    quickSort(arr, 0,   n);
    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}