#include <stdio.h>

void transpose()
{
    int i, j,r,c;
    printf("Enter the number of row(s): ");
    scanf("%d",&r);
    printf("Enter the number of column(s): ");
    scanf("%d",&c);
    int matrix[r][c], transpose_matrix[c][r];
    printf("Enter the matrix: \n");
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            transpose_matrix[j][i] = matrix[i][j];
        }
    }
    printf("Transpose matrix is: \n");
    for (i = 0; i < c; i++)
    {
        for (j = 0; j < r; j++)
        {
            printf("%d ", transpose_matrix[i][j]);
        }
        printf("\n");
    }
}

