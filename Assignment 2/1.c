#include <stdio.h>
#include <math.h>

void mean_sd(float [], int, float *, float *);

int main()
{
    int n;
    float mean, sd;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    float arr[n];
    printf("Enter the numbers: ");
    for (int i = 0; i < n; i++)
        scanf("%f", &arr[i]);
    mean_sd(arr, n, &mean, &sd);
    printf("Mean: %.2f\nStandard Deviation: %.2f", mean, sd);
    return 0;
}

void mean_sd(float arr[], int n, float *mean, float *sd)
{
    *mean = 0, *sd = 0;
    for (int i = 0; i < n; i++)
        *mean += arr[i];
    *mean /= n;
    for (int i = 0; i < n; i++)
        *sd += pow(arr[i] - *mean, 2);
    *sd = sqrt(*sd / n);
}