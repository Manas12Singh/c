#include<stdio.h>

int main()
{
    int r,x,y,z,t;
    printf("Enter the number of variables: ");
    scanf("%d",&r);
    float m[r][r];
    printf("Enter the elements of matrix A:\n");
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; i < r; i++)
        {
            scanf("%f",&m[i][j]);
        }
    }
    
    return 0;
}
