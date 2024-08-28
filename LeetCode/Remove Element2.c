#include <stdio.h>
#include <stdlib.h>

int* removeElement(int* nums, int* numsSize, int val)
{
    // static int arr[1000];
    int *arr;
    arr=(int*)malloc(*numsSize*sizeof(int));
    int i=0,j=0;
    while(i+j<*numsSize)
    {
        if(*(nums+i+j)==val)
            j++;
        else
        {
            *(arr+i)=*(nums+i+j);
            i++;
        }
    }
    *numsSize-=j;
    return arr;
}

int main()
{
    int n,l;
    scanf("%d",&n);
    int arr[n];
    int *p=arr;
    int *numSize=&n;
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
        // scanf("%d",p+i);
    }
    scanf("%d",&l);
    int *p1=removeElement(p,numSize,l);
    //reverse(arr,n);

    for (int i = 0; i < n; i++)
    {
        //scanf("%d",arr[i]);
        printf("%d %d\n",*(p1+i),arr[i]);
    }
    free(p);
    for (int i = 0; i < n; i++)
    {
        //scanf("%d",arr[i]);
        printf("%d %d\n",*(p1+i),arr[i]);
    }
    return 0;
}