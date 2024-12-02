#include <stdio.h>

#define abs(x) ((x) > 0 ? (x) : -(x))

// #define f(x) (x - exp(-x))
// #define f(x) (3 * x - cos(x) - 1)
#define f(x) (pow(x, 2) - 30)

int main()
{
    double x0, x1, x2, f0, f1, f2, e;
    int step = 0;
up:
    printf("Enter two initial guesses: ");
    scanf("%lf %lf", &x0, &x1);
    printf("Enter the error: ");
    scanf("%lf", &e);
    f0 = f(x0);
    f1 = f(x1);
    if (f0 * f1 > 0)
    {
        printf("The initial guesses are invalid.\n");
        goto up;
    }
    do
    {
        x2 = x0 - (x1 - x0) * f0 / (f1 - f0);
        f2 = f(x2);
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
    } while (
        abs(f2) > e);
    printf("The root is: %lf\n", x2);
    printf("Number of steps: %d\n", step);
    return 0;
}