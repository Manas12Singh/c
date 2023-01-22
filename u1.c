#include <stdio.h>

int main()
{
    float n, bill;
    scanf("%f", &n);
    if (n > 3000)
    {
        bill = n - n * 12 / 100;
    }
    else if (n > 2000)
    {
        bill = n - n * 10 / 100;
    }
    else if (n > 1000)
    {
        bill = n - n * 5 / 100;
    }
    else
    {
        bill = n;
    }

    printf("%f", bill);
}
