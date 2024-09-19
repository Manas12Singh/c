#include <stdio.h>
#include <math.h>

#define fn1(x) (x - exp(-x))
#define fn2(x) (3 * x - cos(x) - 1)
#define fn3(x) (x * x - 30)

#define gn1(x) (1 + exp(-x))
#define gn2(x) (3 + sin(x))
#define gn3(x) (2 * x)

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
        x1 = x0 - fn3(x0) / gn3(x0);
        printf("Iteration %d: %lf\n", ++step, x1);
    } while (fabs(x0 - x1) > e);
    printf("The root is: %lf\n", x1);
    printf("Number of steps: %d\n", step);
}
