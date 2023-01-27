#include <stdio.h>

int c;
void rank(int,int, int (*)[c]);

int main()
{
    int r,c,i,j;
    printf("No. of row(s) of matrix: ");
    scanf("%d", &r); // takes the no. of rows of matrix
    printf("No. of column(s) of matrix: ");
    scanf("%d", &c); // takes the no. of rows of matrix

    int matrix[r][c];
    printf("Enter elements of the matrix:\n");
    for (i = 0; i < r; i++) // takes row wise elements of matrix like: 12 23 -23
        for (j = 0; j < c; j++)
            scanf("%d", &matrix[i][j]);

    return 0;
}

void rank(int r,int c,int (*m)[c])
{
    printf("Mnaas");
}