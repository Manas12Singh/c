#include<stdio.h>
int main()
{
    int n,i,max;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements of the array: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Peak are at: ");
    if (arr[0]>arr[1])
    {
        printf("%d ",arr[0]);
    }
    
    for(i=1;i<n-1;i++)
    {
        if(arr[i]>arr[i+1] && arr[i]>arr[i-1])
        {
            printf("%d ",arr[i]);
        }
    }

    if (arr[n-1]>arr[n-2])
    {
        printf("%d ",arr[n-1]);
    }
    return 0;
}