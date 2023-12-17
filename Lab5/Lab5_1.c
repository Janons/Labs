#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void matrixPerm(int **matrix, int *mark,
                int dimension, int level, FILE *fout);

int *util_MemoryAllocation(int size);
bool isValid(int **matrix, int dimension);
bool checkMagicSquare(int **matrix, int dimension);

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

    /*file processses*/
    FILE *fout = fopen(argv[2], "w");
    if (fout == NULL)
    {
        fprintf(stderr, "Error in parsing the file");
        exit(-1);
    }

    /*dynamic memory allocation for the matrix and
    mark*/
    // mark
    mark = (int *)calloc(n * n, sizeof(int));
    if (mark == NULL)
    {
        exit(-1);
    }
    // Matrix
    matrix = (int **)util_MemoryAllocation(n * sizeof(int *));
    for (i = 0; i < n; i++)
    {
        matrix[i] = (int *)util_MemoryAllocation(n * sizeof(int));
    }

    /*calling the function*/
    matrixPerm(matrix, mark, n, 0, fout);
    fclose(fout);

    /*freeing the memory*/
    for (i = 0; i < n; i++)
    {
        free(matrix[i]);
    }
    free(matrix);
    free(mark);

    return 0;
}

int *util_MemoryAllocation(int size)
{
    int *mat;

    mat = malloc(size);
    if (mat == NULL)
    {
        fprintf(stdout, "The memory is null");
        exit(-1);
    }

    return mat;
}
// write this code again
bool checkMagicSquare(int **matrix, int n)
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
                count3 += matrix[i][j];
            }
        }

        if (count1 == count2 && count1 == count3 && count2 == count3)
        {
            return true;
        }

        return false;
    }
}

bool isValid(int **matrix, int dimension)
{
    int sum = dimension * (dimension * (dimension + 1)) / 2;

    // row test
    for (int x = 0; x < dimension; x++)
    {
        int sol = 0;
        int consider = 1;
        for (int y = 0; y < dimension; y++)
        {
            sol += matrix[x][y];
            if (matrix[x][y] == 0)
                consider = 0;
        }
        if (consider)
        {
            if (sol != sum)
            {
                return false;
            }
            else
            {
                if (sol > sum)
                    return false;
            }
        }
    }

    // col test
    for (int x = 0; x < dimension; x++)
    {
        int sol = 0;
        int consider = 1;
        for (int y = 0; y < dimension; y++)
        {
            sol += matrix[y][x];
            if (matrix[y][x] == 0)
                consider = 0;
        }
        if (consider)
        {
            if (sol != sum)
                return false;
        }

        else
        {
            if (sol > sum)
            {
                return false;
            }
        }
    }

    return true;
}

void matrixPerm(int **matrix, int *mark,
                int dimension, int level, FILE *fout)
{
    int x, y;
    int i, j;
    /*base case*/
    if (level >= dimension * dimension)
    {
        if (checkMagicSquare(matrix, dimension))
        {
            for (i = 0; i < dimension; i++)
            {
                for (j = 0; j < dimension; j++)
                {
                    fprintf(fout, "%d", matrix[i][j]);
                }
            }
        }
    }

    x = level / dimension;
    y = level % dimension;

    for (i = 0; i < dimension * dimension; i++)
    {
        if (mark[i] == 0)
        {
            mark[i] = 1;

            if (isValid(matrix, dimension))
            {
                matrix[i][j] = i;
                matrixPerm(matrix, mark, dimension, level + 1, fout);
            }

            /*backtracking*/
            mark[i] = 0;
            matrix[i][j] = 0;
        }
    }
}
