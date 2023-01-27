#include <stdio.h>

int c;
void trace(int,int,int(*)[c]);
void rank(int,int,int(*)[c]);

int main()
{
    int r,c,i,j,choice;
    printf("No. of row(s) of matrix: ");
    scanf("%d", &r); // takes the no. of rows of matrix
    printf("No. of column(s) of matrix: ");
    scanf("%d", &c); // takes the no. of rows of matrix

    int matrix[r][c];
    printf("Enter elements of the matrix:\n");
    for (i = 0; i < r; i++) // takes row wise elements of matrix like: 12 23 -23
        for (j = 0; j < c; j++)
            scanf("%d", &matrix[i][j]);
    while(1)
    {
        printf("Select one of the following:\n1. Rank\n2. Trace\nEnter the number of your choice:");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            rank(r,c,matrix);
            break;
        
        default:
            break;
        }
    }
    return 0;
}

void rank(int r,int c,int(*m)[c])
{
    printf("Mnaas");
}

void trace(int r,int c,int(*m)[c])
{
    int i,j,sum=0;
    for(i=0;i<r;i++)
     for(j=0;j<c;j++)
        sum+=m[i][j];
    printf("Trace is %d",sum);
}