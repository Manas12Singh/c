#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int k = n;
    for (int i = 1; i < 2 * n; i++)
    {
        int l = n;
        for (int j = 1; j < 2 * n; j++)
        {
            printf("%d", (l > k) ? l : k);
            if (j < n)
                l--;
            else
                l++;
        }
        if (i < n)
            k--;
        else
            k++;
        printf("\n");
    }
    return 0;
}