#include<stdio.h>

int main()
{
    int n,i,j,r_sum,sum;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements: ");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    printf("Enter the required sum: ");
    scanf("%d",&r_sum);
    for(i=0;i<n;i++)
    {
        sum=0;
        for(j=i;j<n;j++)
        {
            sum+=arr[j];
            if(sum==r_sum)
            {
                printf("Requred indices are %d and %d",i,j);
                return 0;
            }
        }
    }
    printf("Doesn't exist");
    return 0;
}