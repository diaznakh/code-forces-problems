/*You've got a 5 × 5 matrix, consisting of 24 zeroes and a single number one. Let's index the matrix rows by numbers from 1 to 5 from top to bottom, let's index the matrix columns by numbers from 1 to 5 from left to right. In one move, you are allowed to apply one of the two following transformations to the matrix:

Swap two neighboring matrix rows, that is, rows with indexes i and i + 1 for some integer i (1 ≤ i < 5).
Swap two neighboring matrix columns, that is, columns with indexes j and j + 1 for some integer j (1 ≤ j < 5).
You think that a matrix looks beautiful, if the single number one of the matrix is located in its middle (in the cell that is on the intersection of the third row and the third column). Count the minimum number of moves needed to make the matrix beautiful.

Input
The input consists of five lines, each line contains five integers: the j-th integer in the i-th line of the input represents the element of the matrix that is located on the intersection of the i-th row and the j-th column. It is guaranteed that the matrix consists of 24 zeroes and a single number one.

Output
Print a single integer — the minimum number of moves needed to make the matrix beautiful.*/
#include <stdio.h>
#include <stdlib.h>
int matrix[5][5];
int i, j, k, l, mov;
void swap_rows(int matrix[5][5], int rowA, int rowB)
{
    int temp = 0;
    for (int n = 0; n < 5; n++)
    {
        temp = matrix[rowA][n];
        matrix[rowA][n] = matrix[rowB][n];
        matrix[rowB][n] = temp;
    }
}
void swap_col(int matrix[5][5], int colA, int colB)
{
    int temp1 = 0;
    for (int m = 0; m < 5; m++)
    {
        temp1 = matrix[m][colA];
        matrix[m][colA] = matrix[m][colB];
        matrix[m][colB] = temp1;
    }
}
void check()
{
    if (matrix[2][2] == 1)
    {
        printf("%d", mov);
        exit(0);
    }
}
void ladder_rows()
{
    if (matrix[0][0] || matrix[0][1] || matrix[0][3] || matrix[0][4] == 1)
    {
        swap_rows(matrix, 0, 1);
        mov++;
    }
    if (matrix[1][0] || matrix[1][1] || matrix[1][3] || matrix[1][4] == 1)
    {
        swap_rows(matrix, 1, 2);
        mov++;
    }
    if (matrix[3][0] || matrix[3][1] || matrix[3][3] || matrix[3][4] == 1)
    {
        swap_rows(matrix, 3, 2);
        mov++;
    }
    if (matrix[4][0] || matrix[4][1] || matrix[4][3] || matrix[4][4] == 1)
    {
        swap_rows(matrix, 4, 3);
        mov++;
    }
    check();
}
void ladder_col()
{
    if (matrix[0][0] || matrix[1][0] || matrix[3][0] || matrix[4][0] == 1)
    {
        swap_col(matrix, 0, 1);
        mov++;
    }
    if (matrix[0][1] || matrix[1][1] || matrix[3][1] || matrix[4][1] == 1)
    {
        swap_col(matrix, 1, 2);
        mov++;
    }
    if (matrix[0][3] || matrix[1][3] || matrix[3][3] || matrix[4][3] == 1)
    {
        swap_col(matrix, 3, 2);
        mov++;
    }
    if (matrix[0][4] || matrix[1][4] || matrix[3][4] || matrix[4][4] == 1)
    {
        swap_col(matrix, 4, 3);
        mov++;
    }
    check();
}
void lh()
{
    if (matrix[0][2] == 1)
    {
        swap_rows(matrix, 0, 1);
        mov++;
    }
    if (matrix[1][2] == 1)
    {
        swap_rows(matrix, 1, 2);
        mov++;
    }
    if (matrix[3][2] == 1)
    {
        swap_rows(matrix, 3, 2);
        mov++;
    }
    if (matrix[4][2] == 1)
    {
        swap_rows(matrix, 4, 3);
        mov++;
    }
    check();
}
void lv()
{
    if (matrix[2][0] == 1)
    {
        swap_col(matrix, 0, 1);
        mov++;
    }
    if (matrix[2][1] == 1)
    {
        swap_col(matrix, 1, 2);
        mov++;
    }
    if (matrix[2][3] == 1)
    {
        swap_col(matrix, 3, 2);
        mov++;
    }
    if (matrix[2][4] == 1)
    {
        swap_col(matrix, 4, 3);
        mov++;
    }
    check();
}
void loop()
{
    ladder_rows();
    ladder_col();
    lh();
    lv();
    loop();
}
int main()
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            matrix[i][j] = 0;
        }
    }
    for (int k = 0; k < 5; k++)
    {
        for (int l = 0; l < 5; l++)
        {
            scanf("%d", &matrix[k][l]);
        }
    }
    loop();
    return 0;
}