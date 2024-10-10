#include <stdio.h>
#include <stdlib.h>

#define f(x) (x * x * x + 2 * x + 1)

int main()
{
    double *xarr, *yarr;
    int n;
    printf("Enter the number of x values: ");
    scanf("%d", &n);
    xarr = (double *)malloc(n * sizeof(double));
    yarr = (double *)calloc(n * (n + 1), sizeof(double));
    printf("Enter the x values:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%lf", &xarr[i]);
    }
    double x;
    printf("Enter the value of x: ");
    scanf("%lf", &x);
    printf("y:\t");
    for (int i = 0; i < n; i++)
    {
        yarr[i] = f(xarr[i]);
        printf("%10lf ", yarr[i]);
    }
    printf("\n");
    double y = yarr[0], u = (x - xarr[0]) / (xarr[1] - xarr[0]), mf = 1;
    for (int i = 1; i < n; i++)
    {
        printf("d^%d y:\t", i);
        for (int j = 0; j < n - i; j++)
        {
            yarr[j + i * n] = yarr[j + 1 + (i - 1) * n] - yarr[j + (i - 1) * n];
            printf("%10lf ", yarr[j + i * n]);
        }
        printf("\n");
        mf *= u / i;
        u = u - 1;
        y += mf * yarr[i * n];
    }
    printf("The value of y at x = %lf is %lf\n", x, y);
    return 0;
}