#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int *array = (int *)malloc(sizeof(int) * n);
    if (!array)
    {
        printf("Memory allocation failed.\n");
        return 0;
    }
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &array[i]);
    printf("Elements stored: ");
    for (int i = 0; i < n; i++)
        printf("%d ", array[i]);
    printf("\n");
    free(array);
    return 0;
}