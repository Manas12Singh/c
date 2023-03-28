#include <stdio.h>
#include <math.h>

void mean_sd(int *, int, float *, float *);

int main()
{
    int n;
    float mean, sd;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    int *a = arr;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    mean_sd(a, n, &mean, &sd);
    printf("Mean is: %.2f.\nStandard Deviation is: %.2f", mean, sd);
}

void mean_sd(int *arr, int n, float *mean, float *sd)
{
    *mean = 0, *sd = 0;
    for (int i = 0; i < n; i++)
    {
        *mean += *(arr + i);
    }
    *mean /= n;
    for (int i = 0; i < n; i++)
    {
        *sd += pow(*(arr + i) - *mean, 2);
    }
    *sd = sqrt(*sd / n);
}