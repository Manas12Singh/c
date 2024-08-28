#include <stdio.h>

int *sort(int *arr,int n)
{
    int temp;
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i;j++)
        {
            if(*(arr+j)>*(arr+j+1))
            {
                temp=*(arr+j);
                *(arr+j)=*(arr+j+1);
                *(arr+j+1)=temp;
            }
        }
    }
    return arr;
}

char *sort(char *arr,int n)
{
    char temp;
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i;j++)
        {
            if(*(arr+j)>*(arr+j+1))
            {
                temp=*(arr+j);
                *(arr+j)=*(arr+j+1);
                *(arr+j+1)=temp;
            }
        }
    }
    return arr;
}

int main()
{
    char arr[]={'d','c','b','a'};
    char*arr1=sort(arr,4);
    for (int i = 0; i < 4; i++)
    {
        printf("%d %d\n",arr[i],arr1[i]);
    }
    return 0;
}
