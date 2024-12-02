#include <stdio.h>

void leastSquareMethod(int n, double x[], double y[])
{
    double sumX = 0, sumY = 0, sumXY = 0, sumX2 = 0;
    for (int i = 0; i < n; i++)
    {
        sumX += x[i];
        sumY += y[i];
        sumXY += x[i] * y[i];
        sumX2 += x[i] * x[i];
    }
    double b = (n * sumXY - sumX * sumY) / (n * sumX2 - sumX * sumX);
    double a = (sumY - b * sumX) / n;
    printf("The line is: y = %.4fx + %.4f\n", b, a);
}

int main()
{
    int n;
    printf("Enter the number of data points: ");
    scanf("%d", &n);
    double x[n], y[n];
    printf("Enter the data points:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Enter x%d: ", i);
        scanf("%lf", &x[i]);
        printf("Enter y%d: ", i);
        scanf("%lf", &y[i]);
    }
    leastSquareMethod(n, x, y);
    return 0;
}