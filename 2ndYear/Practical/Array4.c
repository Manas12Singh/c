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
    int min = (m < n) ? m : n;
    int intersect[min];
    int size = 0;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (A[i] == B[j] && notContains(intersect, size, A[i]))
            {
                intersect[size++] = A[i];
                break;
            }
    printf("Intersection is :");
    for (int i = 0; i < size; i++)
        printf("%d ", intersect[i]);
    printf("\n");
    return 0;
}
