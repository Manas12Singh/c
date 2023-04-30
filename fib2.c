#include <stdio.h>

int fib(int n)
{
    FILE *f1;
    int arr[n],f;
    f1=fopen("fib.txt","w+");
    fread(arr,sizeof(arr),1,f1);
    if(arr[n-1]!=0)
        return arr[n-1]; 
    if(n<=2)
        f=1;
    else
        f=fib(n-1)+fib(n-2);
    arr[n-1]=f;
    fwrite(arr,sizeof(arr),1,f1);
    fclose(f1);
    return f;
}

int main(){
    printf("%d",fib(5));
    return 0;
}
