#include <stdio.h>

int main()
{
    long unsigned n, sum = 0;
    scanf("%lu", &n);
    while (1)
    {
        if (n == 0)
        {
            if (sum < 10)
                break;
            n = sum;
            sum = 0;
        }
        sum += n % 10;
        n /= 10;
    }
    printf("%d", sum);
    return 0;
}
