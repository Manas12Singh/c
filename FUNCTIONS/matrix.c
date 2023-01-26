#include <stdio.h>

int c;
void rank(int,int, int (*)[]);
void j;

int main()
{
    int r,c;
    printf("No. of row(s) of matrix: ");
    scanf("%d", &r); // takes the no. of rows of matrix
    printf("No. of column(s) of matrix: ");
    scanf("%d", &c); // takes the no. of rows of matrix

    int matrix[r][c];
    for (int i = 0; i < r; i++) // takes row wise elements of matrix like: 12 23 -23
    {
        printf("Enter elements of row %d:\n", i + 1);
        for (int j = 0; j < c; j++)
            scanf("%d", &matrix[i][j]);
    }

    return 0;
}

void rank(int r,int c,int (*m)[c])
{

}