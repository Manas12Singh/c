#include <stdio.h>

#define fabs(x) ((x) > 0 ? (x) : -(x))

/* #define f(x) (x - exp(-x))
#define g(x) (1 + exp(-x)) */

/* #define f(x) (3 * x - cos(x) - 1)
#define g(x) (3 + sin(x)) */

#define f(x) (pow(x, 2) - 30)
#define g(x) (2 * x)

int main()
{
    double x0, x1, e;
    int step = 0;
    printf("Enter a guess: ");
    scanf("%lf", &x1);
    printf("Enter the error: ");
    scanf("%lf", &e);
    do
    {
        x0 = x1;
        x1 = x0 - f(x0) / g(x0);
        step++;
    } while (abs(x0 - x1) > e);
    printf("The root is: %lf\n", x1);
    printf("Number of steps: %d\n", step);
    return 0;
}
