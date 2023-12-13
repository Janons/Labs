#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void matrixPerm(int **matrix, int *matrixArray, int *val, int *sol, int *mark,
                int n, int count, int pos, int magicnumber);
bool checkMagicSquare(int **matrix, int n, int magicNumber);
void writeMagicSquare();
void freeThematrix();

int main(int argc, char *argv[])
{
    int magicNumber;
    int **matrix, count = 1, i, j;

    if (argc < 3)
    {
        return EXIT_SUCCESS;
    }
    int n = (int)argv[2];
    int *matrixArray;
    magicNumber = n * ((n * n) + 1) / 2;

    /*dynamic memory allocation for the matrix*/
    **matrix = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matrix[i][j] = count;
            count++;
        }
    }

    /*matrix array*/
    *matrixArray = (int *)malloc(n * n * sizeof(int));
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            matrixArray[(n * i) + j] = matrix[i][j];
        }
    }
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

void matrixPerm(int **matrix, int *matrixArray, int *val, int *sol, int *mark,
                int n, int count, int pos, int magicnumber)
{
    int i;

    if (pos >= n * n)
        return;

    *mark = calloc(n * n, sizeof(int));
    *sol = (int *)malloc(n * n * sizeof(int));

    for (i = 0; i < n * n; i++)
    {
        if (mark[i] == 0)
        {
            mark[i] = 1;

            sol[pos] = matrixArray[i];
            
        }
    }
}

/*To-Do
1) Write the same code with calloc
2)Write the same code with lesser lines
3)Go over dynamic memory allocation once again,master the logic*/