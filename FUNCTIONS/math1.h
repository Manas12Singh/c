#include <stdio.h>
#include <math.h>

int lcm(int , int);
int gcf(int , int);

int gcf(int a, int b)
{
    a = abs(a);
    b = abs(b);
    if (a != b)
    {
        if (a < b)
        {
            int t = a;
            a = b;
            b = t;
        }
        if (a % b == 0)
            return b;
        else
            return gcf(b, a % b);
    }
    else
        return a;
}

int lcm(int a, int b)
{
    return a * b / gcf(a, b);
}