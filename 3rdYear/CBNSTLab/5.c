#include <stdio.h>
#include <stdlib.h>

int main()
{
    float *xarr, *yarr;
    int n;
    printf("Enter the number of data points: ");
    scanf("%d", &n);
    xarr = (float *)malloc(n * sizeof(float));
    yarr = (float *)malloc(n * sizeof(float));
    printf("Enter the data points:\n");
    for (int i = 0; i < n; i++)
        scanf("%f %f", &xarr[i], &yarr[i]);
    float x;
    printf("Enter the value of x: ");
    scanf("%f", &x);
    float y = yarr[0], u = (x - xarr[0]) / (xarr[1] - xarr[0]), mf = 1;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
            yarr[j] = yarr[j + 1] - yarr[j];
        mf *= u / i;
        u = u - 1;
        y += mf * yarr[0];
    }
    printf("The value of y at x = %f is %f\n", x, y);
    return 0;
}