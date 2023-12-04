#include <stdio.h>
#include <stdlib.h>

void swap(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

int partition(char *arr, int left, int right)
{
    int i = left - 1;
    for (int j = left; j <= right; j++)
        if (arr[j] < arr[right])
            swap(&arr[++i], &arr[j]);
    swap(&arr[++i], &arr[right]);
    return i;
}

void quickSort(char *arr, int left, int right)
{
    if (left < right)
    {
        int p = partition(arr, left, right);
        quickSort(arr, left, p - 1);
        quickSort(arr, p + 1, right);
    }
}

void printArray(char *arr, int n)
{
    for (int i = 0; i < n; i++)
        printf("%c ", arr[i]);
    printf("\n");
}

int main()
{
    int n, opt;
    char *arr = NULL;
    do
    {
        printf("1. Create array\n2. Sort array\n3. Print array\n4. Exit\nEnter option: ");
        scanf("%d", &opt);
        switch (opt)
        {
        case 1:
            if (arr != NULL)
                free(arr);
            arr = NULL;
            printf("Enter the number of elements: ");
            scanf("%d", &n);
            arr = (char *)malloc(n * sizeof(char));
            printf("Enter the elements: ");
            for (int i = 0; i < n; i++)
                scanf(" %c", &arr[i]);
            break;
        case 2:
            quickSort(arr, 0, n - 1);
            break;
        case 3:
            printf("Sorted array: ");
            for (int i = 0; i < n; i++)
                printf("%c ", arr[i]);
            printf("\n");
            break;
        case 4:
            break;
        default:
            printf("Invalid option.\n");
        }
    } while (opt != 4);
    if (arr != NULL)
        free(arr);
    return 0;
}