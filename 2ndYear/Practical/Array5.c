#include <stdio.h>

int main()
{
    int m;
    printf("Enter the number of elements: ");
    scanf("%d", &m);
    int A[m];
    printf("Enter the elements: ");
    for (int i = 0; i < m; i++)
        scanf("%d", &A[i]);
    for (int i = 0, j = m - 1; i < j; i++, j--)
    {
        int temp = A[i];
        A[i] = A[j];
        A[j] = temp;
    }
    printf("Reversed array is: ");
    for (int i = 0; i < m; i++)
        printf("%d ", A[i]);
    printf("\n");
    return 0;
}
