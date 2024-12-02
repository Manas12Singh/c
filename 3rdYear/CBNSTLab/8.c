#include <stdio.h>

double lagrangeInterpolation(double x[], double y[], int n, double xp)
{
    double yp = 0;
    for (int i = 0; i < n; i++)
    {
        double p = 1;
        for (int j = 0; j < n; j++)
            if (i != j)
                p *= (xp - x[j]) / (x[i] - x[j]);
        yp += p * y[i];
    }
    return yp;
}

int main()
{
    int n;
    printf("Enter the number of data points: ");
    scanf("%d", &n);    

    double x[n], y[n];
    printf("Enter the data points (x y):\n");
    for (int i = 0; i < n; i++)
        scanf("%lf %lf", &x[i], &y[i]);

    double xp;  
    printf("Enter the interpolation point: ");
    scanf("%lf", &xp);

    double yp = lagrangeInterpolation(x, y, n, xp);
    printf("The interpolated value at x = %lf is y = %lf\n", xp, yp);

    return 0;
}