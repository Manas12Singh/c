#include <stdio.h>

int *plus(int arr[], int n)
{
    int count = 0;
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        count++;
    }
    arr[count - 1] = arr[count - 1] + 1;
    if (arr[count - 1] > 9)
    {
        arr[j] = arr[count - 1] / 10;
        j++;
        arr[j] = arr[count - 1] % 10;
    }
    return arr;
}

int main()
{
    int n, arr[100];
    int *a;
    printf("enter total numbers\n");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    a = plus(arr, n);
    for (int i = 0; i <= n; i++)
    {
        printf("%d", a[i]);
    }
    return 0;
}