#include <stdio.h>

void binToInt(float n)
{
    int n1=(int)n;
    n-=n1;
    int c=1;
    float b=0;
    while (n1!=0)
    {
        b+=(n1%10)*c;
        n1/=10;
        c*=2;
    }
    float d=0.5;
    int a;
    while (n!=0)
    {
        n*=10;
        a=(int)(n);
        b+=(a*d);
        d*=0.5;
        n-=a;
    }
    printf("%.3f",b);
}

int main()
{
    float arr[10] = {0101.110,1010.101,1111.101,1101.011,1010.101,1001.000,0001.011,1010.110,1101.000,1001.100};
    binToInt(arr[0]);
    return 0;
}
