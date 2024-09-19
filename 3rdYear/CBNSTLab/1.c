#include <stdio.h>
#include <math.h>

#define fn1(x) pow(x, 3) - 20
#define fn2(x) (pow(x, 3) - 4 * (x) - 9)
#define fn3(x) ((x) * (x) - 30)
#define fn4(x) ((x) - cos(x))
#define fn5(x) (exp(x) - 10)

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
        printf("Iteration no. %d: %lf\n", step, x2);
    } while (fabs(f2) > e);
    printf("The root is: %lf\n", x2);
    printf("Number of steps: %d\n", step);
    return 0;
}