#include<stdio.h>
int main()
{
    int n,i,j,k,count=0,c=0;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements: ");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    for(i=0;i<n-1;i++)
    {
        for (j = i+1; j < n; j++)
        {
            if(arr[i]==arr[j])
            {
                for(k=j;k<n-1;k++)
                {
                    arr[k]=arr[k+1];
                }
                c++;
                n--;
            }
        }
        if(c!=0)
            count++;
    }
    printf("%d",count);
}