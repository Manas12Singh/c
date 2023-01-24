#include <stdio.h>
#include <conio.h>
#include <math.h>

int gcf(int a, int b);
int lcm(int a, int b);
void simplify(int num, int den);

int main()
{
    int a, b;
    scanf("%d/%d", &a, &b);
    simplify(a, b);
    return 0;
}

void simplify(int num, int den)
{
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
    getch();
}

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