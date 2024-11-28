#include <stdio.h>

#define f(x, y) (x + y * y)

double rk4Method(double x0, double y0, double target, double h)
{
    int n = (target - x0) / h;
    for (int i = 1; i <= n; i++)
    {
        double k1 = h * f(x0, y0);
        double k2 = h * f(x0 + h / 2, y0 + k1 / 2);
        double k3 = h * f(x0 + h / 2, y0 + k2 / 2);
        double k4 = h * f(x0 + h, y0 + k3);
        double k = (k1 + 2 * (k2 + k3) + k4) / 6;
        y0 = y0 + k;
        x0 = x0 + h;
        printf("\nAt approximation: %d\n", i);
        printf("k1\tk2\tk3\tk4\tk\n");
        printf("%.4f\t%.4f\t%.4f\t%.4f\t%.4f\n", k1, k2, k3, k4, k);
        printf("\nValue at y(%.4f): %.6f\n", x0, y0);
        printf("-------------------------------------------\n");
    }
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
    double result = rk4Method(x0, y0, target, h);
    printf("\nApproximate value is: %.6f\n", result);
    return 0;
}