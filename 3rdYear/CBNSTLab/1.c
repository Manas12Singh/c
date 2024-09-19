#include <stdio.h>
#include <math.h>

double fn1(double x)
{
    return pow(x, 3) - 20;
}

double fn2(double x)
{
    return pow(x, 3) - 4 * x - 9;
}

double fn3(double x)
{
    return x * x - 30;
}

double fn4(double x)
{
    return x - cos(x);
}

double fn5(double x)
{
    return exp(x) - 10;
}

int main()
{
    double x0, x1, x2, f0, f1, f2, e;
    int step = 0;
up:
    printf("Enter two initial guesses: ");
    scanf("%lf %lf", &x0, &x1);
    printf("Enter the error: ");
    scanf("%lf", &e);
    f0 = fn1(x0);
    f1 = fn1(x1);
    if (f0 * f1 > 0)
    {
        printf("The initial guesses are invalid.\n");
        goto up;
    }
    do
    {
        x2 = (x1 + x0) / 2;
        f2 = fn1(x2);
        if (f2 * f0 < 0)
        {
            x1 = x2;
            f1 = f2;
        }
        else
        {
            x0 = x2;
            f0 = f2;
        }
        step++;
        printf("%d: %lf\n", step, x2);
    } while (fabs(f2) > e);
    printf("The root is: %lf\n", x2);
    printf("Number of steps: %d\n", step);
    return 0;
}