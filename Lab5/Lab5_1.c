#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void matrixPerm(int **matrix, int *sol, int *mark,
                int n, int pos, int magicnumber, FILE *fin);
bool checkMagicSquare(int **matrix, int n, int magicNumber);

int main(int argc, char *argv[])
{
    int magicNumber;
    int **matrix, count = 1, i, j;

    if (argc < 3)
    {
        return EXIT_SUCCESS;
    }
    int n = atoi(argv[2]);
    int *matrixArray;
    magicNumber = n * ((n * n) + 1) / 2;

    /*open the file*/
    FILE *fin = fopen(argv[3], "r");

    /*dynamic memory allocation for the matrix*/
    matrix = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
    {
        matrix[i] = (int *)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++)
        {
            matrix[i][j] = count;
            count++;
        }
    }

    int *mark = calloc(n * n, sizeof(int));
    int *sol = (int *)malloc(n * n * sizeof(int));
    int pos;

    matrixPerm(matrix, sol, mark, n, pos + 1, magicNumber, fin);
    fclose(fin);

    for (i = 0; i < n; i++)
    {
        free(matrix[i]);
    }
    free(matrix);
    free(sol);
    return 0;
}

// checking for the square matrix
bool checkMagicSquare(int **matrix, int n, int magicNumber)
{
    int i, j;
    int flag1, flag2, flag3, count = 0;

    // check rows
    flag1 = 0;
    flag2 = 0;
    flag3 = 0;
    count = 0;
    for (i = 0; i < n; i++)
    {

        for (j = 0; j < n; j++)
        {
            count += matrix[i][j];

            if (count == magicNumber)
                flag1 = 1;
        }
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

void matrixPerm(int **matrix, int *sol, int *mark,
                int n, int pos, int magicnumber, FILE *fin)
{
    int i, j;

    if (pos >= n * n)
    {
        if (checkMagicSquare(matrix, n, magicnumber))
        {
            for (i = 0; i < n; i++)
            {
                for (j = 0; j < n; j++)
                {
                    fprintf(fin, "%d", matrix[i][j]);
                }
                fprintf(fin, "\n");
            }
        }
    }

    return;

    for (i = 0; i < n * n; i++)
    {
        for (j = 0; j < n; j++)
        {
            pos = (n * i) + j;
            if (mark[i] == 0)
            {

                mark[i] = 1;
                sol[pos] = matrix[i][j];
                matrixPerm(matrix, sol, mark, n, pos++, magicnumber, fin);
                mark[i] = 0;
            }
        }
    }
    free(mark);
    return;
}

/*To-Do
1) Write the same code with calloc
2)Write the same code with lesser lines
3)Go over dynamic memory allocation once again,master the logic*/