#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = n - 1; j > i; j--)
            printf(" ");
        for (int j = 0; j <= 2 * i; j++)
            if (j == 0 | j == 2 * i | i == n - 1)
                printf("*");
            else
                printf(" ");
        printf("\n");
    }
    return 0;
}