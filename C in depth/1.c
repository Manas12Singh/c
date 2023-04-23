#include <stdio.h>

int main()
{
    int n, sum = 0;
    scanf("%d", &n);
    while (1)
    {
        if (n == 0)
        {
            if (sum < 10)
                break;
            else
                n = sum;
            sum = 0;
        }
        sum += n % 10;
        n /= 10;
    }
    printf("%d", sum);
    return 0;
}
