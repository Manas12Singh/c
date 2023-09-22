#include <stdio.h>

int notContains(int arr[], int n, int k)
{
    for (int i = 0; i < n; i++)
        if (arr[i] == k)
            return 0;
    return 1;
}

int main()
{
    int m, n;
    printf("Enter the number of elements in array A: ");
    scanf("%d", &m);
    int A[m];
    printf("Enter the elements: ");
    for (int i = 0; i < m; i++)
        scanf("%d", &A[i]);
    printf("Enter the number of elements in array B: ");
    scanf("%d", &n);
    int B[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &B[i]);
    int Union[m + n];
    int max = (m > n) ? m : n;
    int size = 0;
    for (int i = 0; i < max; i++)
    {
        if (i < m && notContains(Union, size, A[i]))
            Union[size++] = A[i];
        if (i < n && notContains(Union, size, B[i]))
            Union[size++] = B[i];
    }
    printf("Union is: ");
    for (int i = 0; i < size; i++)
        printf("%d ", Union[i]);
    printf("\n");
    return 0;
}
