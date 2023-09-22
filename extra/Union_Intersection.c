#include <stdio.h>

int main()
{
    int m,n,k;
    
    printf("Enter the length of first array: ");
    scanf("%d",&m);
    printf("Enter the length of second array: ");
    scanf("%d",&n);
    
    int a1[m] , a2[n];
    
    printf("Enter the elements of first array: ");
    for(int i=0;i<m;i++)
        scanf("%d",&a1[i]);
    printf("Enter the elements of second array: ");
    for(int i=0;i<n;i++)
        scanf("%d",&a2[i]);
    
    printf("Intersectin is: ");
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(a1[i]==a2[j])            //Checking if an element in a1 is equal to an element in a2.
            {
                printf("%d ",a1[i]);
            }
        }
    }
    
    printf("Union is: ");
    for (int i = 0; i < m; i++)
    {
        printf("%d ",a1[i]);            //Printing all elements of a1.
    }
    for (int i=0;i<n;i++)
    {
        k=0;
        for(int j=0;j<m;j++)
        {
            if (a2[i]==a1[j])           //Checking if an element in a2 is equal to an element in a1.
            {
                k++;                    //If yes, then changing the value of k and ending the inner loop 
                break;
            }
        }
        if(k==0)                        //If k==0, it means it's value is not changed and the element doesn't exist in a1
        {
            printf("%d ",a2[i]);
        }
    }
    return 0;
}