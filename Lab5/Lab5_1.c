#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void matrixPerm(int **matrix, int *mark,
                int n, int row, int collumn, int magicnumber, FILE *fin);
bool checkMagicSquare(int **matrix, int n, int magicNumber);

int main(int argc, char *argv[])
{
    int magicNumber;
    int i, j;
    int n;
    int **matrix, count = 1;
    int *mark;

    if (argc != 3)
    {
        return (EXIT_FAILURE);
    }
    // Important int variables

    n = atoi(argv[1]);
    magicNumber = n * ((n * n) + 1) / 2;

    /*file processses*/
    FILE *fin = fopen(argv[2], "w");
    if (fin == NULL)
    {
        fprint(stderr, "Error in parsing the file");
    }

    if (fin == NULL)
    {
        exit(EXIT_FAILURE);
    }

    /*dynamic memory allocation for the matrix and
    mark*/
    // mark
    int mark = (int *)calloc(n * n, sizeof(int));
    if (mark == NULL)
    {
        exit(-1);
    }
    // Matrix
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

    int row = 0, collumn = 0;

    matrixPerm(matrix, mark, n, row, collumn, magicNumber, fin);
    fclose(fin);

    for (i = 0; i < n; i++)
    {
        free(matrix[i]);
    }
    free(matrix);
    return 0;
}

// checking for the square matrix
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
    }

    // Check Diagonal
    count = 0;
    for (i = 0; i < n; i++)
    {
        count += matrix[i][i];
    }
    if (count == magicNumber)
    {
        flag3 = 1;
    }

    if (flag1 && flag2 && flag3)
    {
        return true;
    }

    return false;
}

void matrixPerm(int **matrix, int *mark,
                int n, int row, int collumn, int magicnumber, FILE *fin)
{
    int i, j;

    if (row == n)
    {
        if (checkMagicSquare(matrix, n, magicnumber))
        {
            for (i = 0; i < n; i++)
            {
                for (j = 0; j < n; j++)
                {
                    fprintf(fin, "%d ", matrix[i][j]);
                }
                fprintf(fin, "\n");
            }
            fprintf(fin, "\n");
        }
        return;
    }

    for (i = 1; i < n * n; i++)
    {
        if (mark[i] == 0)
        {
            mark[i] = 1;
            matrix[row][collumn] = i;

            int nextcol = (collumn + 1) % n;
            int nextrow = row + (nextcol == 0);

            matrixPerm(matrix, mark, n, nextrow, nextcol, magicnumber, fin);

            mark[i] = 0;
        }
    }
    return;
}


/*the coder was later on changed with Professors
Solution*/