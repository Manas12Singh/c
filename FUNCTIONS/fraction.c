#include <stdio.h>
#include <conio.h>
#include <math.h>

void simplify(int num, int den)
{
    if (num==0)
    {
        printf("0");
    }
    int gc = gcf(num, den);
    int s_n = num / gc;
    int s_d = den / gc;
    if (s_d < 0 && s_n > 0)
    {
        printf("-%d/%d", abs(s_n), abs(s_d));
    }
    else if (s_d > 0 && s_n < 0)
    {
        printf("-%d/%d", abs(s_n), abs(s_d));
    }
    else
    {
        printf("%d/%d", abs(s_n), abs(s_d));
    }
}

struct fraction
{
    int num;
    int den;
    int eval=num/den;
};
