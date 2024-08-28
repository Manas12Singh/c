#include<stdio.h>
int main()
{
    int n,i,j,k,c,t,count=0;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements: ");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    for(i=0;i<n-1;i++)
        for(j=i;j<n-1;j++)
            if (arr[j]>arr[j+1])
                k=arr[j],
                arr[j]=arr[j+1],
                arr[j+1]=k;
    for(i=0;i<n;i++)
    {
        c=0;
        t=arr[i];
        for(j=i+1;j<n;j++)
            if(t==arr[j])
                c++,
                i++;
        if(c!=0)
            count++;
    }   
    printf("%d",count);
}