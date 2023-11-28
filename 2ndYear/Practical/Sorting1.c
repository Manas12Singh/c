#include <stdio.h>
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void bubbleSort(int *arr, int n)
{
    int s;
    for (int i = 1; i < n; i++)
    {
        s = 0;
        for (int j = 0; j < n - i; j++)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]), s = 1;
        if (s == 0)
            break;
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
    bubbleSort(arr, n);
    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}
