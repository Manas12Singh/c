#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// #define f(x) (x + 4)

// #define f(x) (1 / (1 + x * x))

// #define f(x) (exp(x * x))

double simpson1_3(double x[], double y[], int n)
{
    y[0] = f(x[0]);
    y[n] = f(x[n]);
    double h = (x[n] - x[0]) / n;
    double sum1 = 0, sum2 = 0;
    for (int i = 1; i < n; i++)
    {
        x[i] = x[i - 1] + h;
        y[i] = f(x[i]);
        if (i % 2 == 0)
            sum1 += y[i];
        else
            sum2 += y[i];
    }
    return h * (y[0] + 2 * sum1 + 4 * sum2 + y[n]) / 3;
}

int main()
{
    int n;
    do
    {
        printf("Enter the number of sub interals: ");
        scanf("%d", &n);
        if (n % 2 != 0)
            printf("Please enter an even number\n");
    } while (n % 2 != 0);
    double x[n + 1], y[n + 1];
    printf("Enter the lower limit of x: ");
    scanf("%lf", &x[0]);
    printf("Enter the upper limit of x: ");
    scanf("%lf", &x[n]);
    double yp = simpson1_3(x, y, n);
    printf("Area = %lf\n", yp);
    return 0;
}