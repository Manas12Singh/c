#include<stdio.h>

int r;
void cramer_rule(int (*)[r],int,int);

int main()
{
    printf("Enter the number of variables: ");
    scanf("%d",&r);
    float a[r][r],b[r];
    printf("Enter the elements of matrix A:\n");
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; i < r; i++)
        {
            scanf("%f",&a[i][j]);
        }
    }
    printf("Enter the elements of matrix B:\n");
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < r; j++)
        {
            scanf("%f",&b[i]);
        }
    }
    cramer_rule(a[r],r,b);
    return 0;
}

void cramer_rule(int (*a)[r],int r,int b)
{
    int x,y,z,t,swap;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < count; j++)
        {
            /* code */
        }
        
    }
    
}