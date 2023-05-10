#include <stdio.h>
#include <stdlib.h>

int fib(int *a,int n)
{
    FILE *fp=fopen("fib.txt","r+");
    if(fp=NULL)
    {
        FILE *fp=fopen("fib.txt","w");
        for (int i=0;i<n;i++)
        {
            
        }
    }
}

int main(){
    int n;
    scanf("%d",&n);
    printf("%d",fib())
    return 0;
}
