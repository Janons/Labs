#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*definitions*/
#define MAXCHAR 20
#define MAINFILE "../cities.txt"

/*prototypes*/
char ***createTheMatrix(int *rowPOinters, int *collumnPointers, char *name);
char *memory_allocation(int size);
char **matrix_merge(char ***matrix, int R, int C);
FILE *open_file(char *name);

/*main*/

int main(int argc, char *argv[])
{
    char ***mat;
    char **onedarray;
    int r, c, i, j;

    return 0;
}

/*creating the matrix version1*/
char ***createTheMatrix(int *rowPOinters, int *collumnPointers, char *name)
{
    FILE *fin;
    char ***matrix;
    int row, col;

    fin = open_file(name);
    fscanf(fin, "%d %d", &row, &col);

    matrix = (char ***)memory_allocation(row * col * sizeof(char **));
    for (int i = 0; i < row; i++)
    {
        matrix[i] = (char **)memory_allocation(col * sizeof(char *));
    }

    *rowPOinters = row;
    *collumnPointers = col;
    fclose(fin);
}

char **matrix_merge(char ***matrix, int R, int C)
{
    int i, j, min_idx, *idx;
    char **array, *min_word;

    /*memory allocation for the holder*/
    array = (char **)memory_allocation(sizeof(char *));

    /*merging part*/
    i = 0;
    while (i < R * C)
    {
        min_idx = -1;

        /* for loop will be here*/
        if (idx[j] < C)
            return "aaaa";
    }
}