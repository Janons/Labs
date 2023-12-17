#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void matrixPerm(int **matrix, int *mark, int dimension, int level);
int *util_MemoryAllocation(int size);
bool isValid(int **matrix, int dimension);
bool checkMagicSquare(int **matrix, int dimension);

int main(int argc, char *argv[])
{
    int i, j;
    int n;
    int **matrix;
    int *mark;

    if (argc <= 2)
    {
        fprintf(stderr, "Usage: %s <dimension> <output_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    n = atoi(argv[1]);
    mark = (int *)calloc(n * n, sizeof(int));
    if (mark == NULL)
    {
        fprintf(stderr, "Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    matrix = (int **)util_MemoryAllocation(n * sizeof(int *));
    for (i = 0; i < n; i++)
    {
        matrix[i] = (int *)util_MemoryAllocation(n * sizeof(int));
    }

    matrixPerm(matrix, mark, n, 0);


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
    int *mat = (int *)malloc(size);
    if (mat == NULL)
    {
        fprintf(stderr, "Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    return mat;
}

bool checkMagicSquare(int **matrix, int n)
{
    int i, j;
    int count1 = 0, count2 = 0, count3 = 0;

    for (i = 0; i < n; i++)
    {
        count1 = count2 = 0; // Initialize counts for each iteration

        // row check
        for (j = 0; j < n; j++)
        {
            count1 += matrix[i][j];
        }

        // column check
        for (j = 0; j < n; j++)
        {
            count2 += matrix[j][i];
        }

        // diagonal check
        count3 += matrix[i][i];
    }

    return (count1 == count2 && count1 == count3 && count2 == count3);
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

void matrixPerm(int **matrix, int *mark, int dimension, int level)
{
    int x, y;
    int i, j;

    if (level >= dimension * dimension)
    {
        if (checkMagicSquare(matrix, dimension))
        {
            for (i = 0; i < dimension; i++)
            {
                for (j = 0; j < dimension; j++)
                {
                    printf("%2d ", matrix[i][j]);
                }
                printf("\n");
            }
        }
        return;
    }

    x = level / dimension;
    y = level % dimension;

    for (i = 1; i <= dimension * dimension; i++)
    {
        if (mark[i - 1] == 0)
        {
            mark[i - 1] = 1;
            matrix[x][y] = i;

            if (isValid(matrix, dimension))
            {
                matrixPerm(matrix, mark, dimension, level + 1);
            }

            mark[i] = 0;
            matrix[x][y] = 0;
        }
    }
}
