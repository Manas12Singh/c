#include <stdio.h>

int main()
{
    int arr[5];
    int *a = arr;
    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < 5; i++)
    {
        *(a + i) = (*(a + i) * 2) / 3;
    }
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}
