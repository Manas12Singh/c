#include <stdio.h>
#include <math.h>

/* #define f(x) (cos(x) - 3 * x + 1)
#define g(x) ((cos(x) + 1) / 3)
#define dg(x) (-sin(x) / 3) */

/* #define f(x) (2 * x - log10(x) - 7)
#define g(x) ((7 + log10(x)) / 2)
#define dg(x) (1 / (2 * x)) */

#define f(x) (x * x * x + x - 1.0)
#define g(x) pow(1.0 - x, 0.33)
#define dg(x) -0.33 * pow(1 - x, -0.67)

int main()
{
    double x0, x1, e;
up:
    int step = 0, maxStep;
    printf("Enter a guess: ");
    scanf("%lf", &x0);
    printf("Enter the error: ");
    scanf("%lf", &e);
    printf("Enter the maximum number of steps: ");
    scanf("%d", &maxStep);
    if (dg(x0) >= 1)
    {
        printf("Intital guess is invalid\n");
        goto up;
    }
    do
    {
        x1 = g(x0);
        step++;
        if (step > maxStep)
        {
            printf("Not Convergent\n");
            return 0;
        }
        x0 = x1;
    } while (fabs(f(x1)) > e);
    printf("The root is: %lf\n", x1);
    printf("Number of steps: %d\n", step);
    return 0;
}