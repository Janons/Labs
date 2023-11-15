#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*definitions*/
#define MAXCHAR 20
#define MAINFILE "../cities.txt"

/*prototypes*/
char ***createTheMatrix(int *rowPOinters, int *collumnPointers, char *name);
char **matrix_merge(char ***matrix, int R, int C);
void free3d(char ***matrix, char **array, int R, int C);

/*main*/

int main(int argc, char *argv[])
{
    char ***mat;
    char **onedarray;
    int r, c, i, j;

    return 0;
}

/*loading the string matrix*/
char ***createTheMatrix(int *rowPOinters, int *collumnPointers, char *name)
{
    char word[MAXCHAR], ***matrix;
    int r, c, i, j;

    FILE *fin;

    /*open the file*/
    fin = fopen(name, "r");
    if (fin == NULL)
    {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    /*read the row and collumn of the file*/
    fscanf(fin, "%d %d", &r, &c);
    *rowPOinters = r;
    *collumnPointers = c;

    /*dynamic memory allocation for the values*/
    matrix = (char ***)malloc(r * sizeof(char **));
    if (matrix == NULL)
    {
        perror("The pointer is null");
        exit(EXIT_FAILURE);
    }
    for (i = 0; i < r; i++)
    {
        matrix[i] = (char **)malloc(c * sizeof(char *));
        if (matrix[i] == NULL)
        {
            perror("The pointer is null");
            exit(EXIT_FAILURE);
        }
    }

    /*dynamicaaly alocating strings and parsing the file
    content*/

    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            fscanf(fin, "%s", word);

            matrix[i][j] = strdup(word);
        }
    }

    /*close the file*/
    fclose(fin);
    *rowPOinters = r;
    *collumnPointers = c;

    return matrix;
}

char **matrix_merge(char ***matrix, int R, int C)

{
    int i, j;
    char **array, *min_word;
    int *aux;

    /*allocating a final array + an auxliray one*/
    array = (char **)malloc(R * C * sizeof(char *));
    aux = (int *)calloc(R, sizeof(int));

    /*merging the matrix in a sorted way*/
    i = 0;
    while (i < sizeof(array))

    {
        int min_index = -1;
        for (j = 0; j < R; j++)
        {
            if (aux[j] < C) /*comparing that rows dont have more than C values*/
            {
                if (min_index == -1 || strcmp(matrix[j][aux[j]], min_word) < 0)
                {
                    min_index = j;
                    min_word = matrix[min_index][aux[min_index]];
                }
            }
        }

        array[i] = matrix[j][aux[min_index]++];
        i++;
    }
}