#include <stdio.h>

int main()
{
    int n, i, flag = 1;
    printf("Enter the size of matrix:");
    scanf("%d", &n);
    int m[n][n];
    int sq = n * n, j, k;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            m[i][j] = 0;
    i = 1, j = n - 1, k = n / 2;
    while (i <= sq)
    {
        if (flag)
        {
            if (m[j][k] == 0)
                m[j][k] = i++, j++, k++;
            else
                k--, flag = 0;
        }
        else
        {
            if (m[j][k] == 0)
                m[j][k] = i++, j++, k++, flag = 1;
            else
                j++;
        }
        if (j >= n && k >= n)
            j = 0, k = 0;
        else if (j >= n)
            j = 0;
        else if (k >= n)
            k = 0;
        else if (k < 0)
            k = n - 1;
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            printf("%2d   ", m[i][j]);
        printf("\n");
    }
    return 0;
}
