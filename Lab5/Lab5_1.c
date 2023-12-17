#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void matrixPerm(int **matrix, int *mark,
                int n, int level);

void *util_MemoryAllocation(int size);
int isValid();
bool checkMagicSquare(int **matrix, int n, int *array);

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
        exit(-1);
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
    /*array*/
    int *array = (int *)malloc(n * n * sizeof(int));
    if (array == NULL)
    {
        fprintf(stdout, "The array pointer is null");
        return -1;
    }

    int row = 0, collumn = 0;

    matrixPerm(matrix, mark, n, magicNumber);
    fclose(fin);

    for (i = 0; i < n; i++)
    {
        free(matrix[i]);
    }
    free(matrix);
    return 0;
}

// write this code again
bool checkMagicSquare(int **matrix, int n, int *array)
{
    int i, j;
    int count1, count2, count3;

    for (i = 0; i < n; i++)
    {
        // row check
        for (j = 0; j < n; j++)
        {
            count1 += matrix[i][j];
        }

        // collumn check
        for (j = 0; j < n; j++)
        {
            count2 += matrix[j][i];
        }

        // diagonal check
        for (j = 0; j < n; j++)
        {
            if (i == j)
            {
                count3 += matrix[i][j]
            }
        }

        if (count1 == count2 && count1 == count3 && count2 == count3)
        {
            return true;
        }

        return false;
    }
}

void matrixPerm(int **matrix, int *mark,
                int n, int level)
{
    
}

