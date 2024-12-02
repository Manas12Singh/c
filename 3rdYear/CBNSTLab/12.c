#include <stdio.h>

#define f(x, y) (y - x) / (y + x)

double eulerMethod(double x0, double y0, double target, double h)
{
    int n = (target - x0) / h;
    printf("\nx\t\ty\t\t(dy/dx)\t\tnew_y\n");
    for (int i = 0; i < n; i++)
    {
        double f = f(x0, y0);
        double y1 = y0 + h * f;
        printf("%.4f\t\t%.4f\t\t%.4f\t\t%.4f\n", x0, y0, f, y1);
        x0 = x0 + h;
        y0 = y1;
    }
    printf("\n");
    printf("%.4f\t%.4f\n\n", x0, y0);
    return y0;
}

int main()
{
    double x0, y0, h, target;
    printf("Enter x0: ");
    scanf("%lf", &x0);
    printf("Enter y0: ");
    scanf("%lf", &y0);
    printf("Enter h: ");
    scanf("%lf", &h);
    printf("Enter the value of x for which corresponding y to be found: ");
    scanf("%lf", &target);
    double result = eulerMethod(x0, y0, target, h);
    printf("Approximate value is: %.6f\n", result);
    return 0;
}