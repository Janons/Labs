#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void matrixPerm(int *val, int *sol, int *mark,
                int n, int count, int pos);
bool checkMagicSquare(int **matrix, int n, int magicNumber);
void writeMagicSquare();

int main(int argc, char *argv[])
{
    int magicNumber;
    int **matrix;
    
    if (argc < 3)
    {
        return EXIT_SUCCESS;
    }
    int n = (int)argv[2];
    magicNumber = n*((n * n) + 1)/ 2;

    /*creating the default matrix with zeroes*/

    return 0;
}

// checking for the square matrix
bool checkMagicSquare(int **matrix, int n, int magicNumber)
{
    int i, j;
    int flag1, flag2, flag3, count = 0;

    // check rows
    for (i = 0; i < n; i++)
    {
        flag1 = 0;
        count = 0;

        for (j = 0; j < n; j++)
        {
            count += matrix[i][j];

            if (count == magicNumber)
                flag1 = 1;
        }
        flag2 = 0;
        count = 0;
        for (j = 0; j < n; j++)
        {
            count += matrix[j][i];
            if (count == magicNumber)
            {
                flag2 = 1;
            }
        }
        // Check Diagonal
        flag3 = 0;
        count = 0;
        for (j = 0; j < n; j++)
        {
            if (j == i)
            {
                count += matrix[i][j];
            }
        }
    }

    if (flag1 && flag2 && flag3)
    {
        return true;
    }

    return false;
}

void matrixPerm(int *val, int *sol, int *mark,
                int n, int count, int pos)
{
    int i;

    val = (int *)malloc(n * sizeof(int));
    sol = (int *)malloc(n * sizeof(int));
    mark = (int *)calloc(n, sizeof(int));

    if ()
}