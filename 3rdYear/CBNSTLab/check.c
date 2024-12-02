#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define f(x) (x * x * x + x - 1) // Original function
#define g(x) (pow(1 - x, 0.33))    // Rearranged function for Fixed Point Iteration

int main()
{
    float x0, x1, e;
    int step = 1, N;

    printf("Enter the initial guess: ");
    scanf("%f", &x0);

    printf("Enter tolerable error: ");
    scanf("%f", &e);

    printf("Enter maximum iteration: ");
    scanf("%d", &N);

    printf("\nStep \t\t x0 \t\t f(x0) \t\t x1 \t\t f(x1)\n");

    do
    {
        x1 = g(x0); // Apply the new g(x) function
        printf("\n%d \t\t %f \t %f \t %f \t %f ", step, x0, f(x0), x1, f(x1));
        step++;

        if (step > N)
        {
            printf("\nNot Convergent.");
            exit(0);
        }

        x0 = x1; // Update x0 for the next iteration

    } while (fabs(f(x1)) > e); // Continue until convergence condition is met

    printf("\n\nThe Root is: %f\n", x1);

    return 0;
}