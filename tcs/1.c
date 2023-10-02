#include <stdio.h>

int main()
{
    int n, i, j;
    scanf("%d", &n);
    int a[n];
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    int dif = 0;
    for (i = 0, j = n - 1; i < j; i++, j--)
        dif += a[i] - a[j];
    dif += a[i];
    if (dif < 0)
        dif = -dif;
    printf("%d", dif);
    return 0;
}
