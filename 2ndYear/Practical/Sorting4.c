#include <stdio.h>

void merge(int *arr, int left, int mid, int right)
{
    int llen = mid - left + 1, rlen = right - mid;
    int larr[llen];
    int rarr[rlen];
    int j = left;
    for (int i = 0; i < llen; i++)
        larr[i] = arr[j++];
    for (int i = 0; i < rlen; i++)
        rarr[i] = arr[j++];
    int i = 0, k = 0;
    while (i < llen && k < rlen)
    {
        if (larr[i] < rarr[k])
            arr[left++] = larr[i++];
        else
            arr[left++] = rarr[k++];
    }
    while (i < llen)
        arr[left++] = larr[i++];
    while (k < rlen)
        arr[left++] = rarr[k++];
}

void mergeSort(int *arr, int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
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
    mergeSort(arr, 0, n);
    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}
