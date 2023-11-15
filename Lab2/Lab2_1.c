#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*defines*/
#define MAXCHAR 100

/*prototypes*/
void createMatrix(char *name, int *, char ***matrix_t);
void sortTheArrray(char **matrix_t, char *name, int num);
void display(char **matrix_t, int number);
void free2d(char **matrix, int n);

int main(int argc, char *argv[])
{
    char **matrix;
    int number;

    if (argc <2){
        perror("Number of arguments is insufficient");
        exit(1);
    }

    createMatrix(argv[1],&number,&matrix);
    sortTheArrray(matrix, argv[1], number);
    free2d(matrix, number);
    display(matrix, number);

    return 0;
}

void createMatrix(char *name, int *number, char ***matrix)
{
    FILE *fin;

    char words[MAXCHAR];
    int numOfwords, i;

    /*openign the file*/
    fin = fopen(name, "r");

    /*reading the number of values in the file*/
    fscanf(fin, "%d", &numOfwords);
    *number = numOfwords;

    /*dynamic memory allocation*/
    (*matrix) = (char **)malloc(numOfwords * sizeof(char *));
    if (matrix == NULL)
    {
        fprintf(stderr, "Memory Allocation Error");
        exit(1);
    }

    /*reading the file
    for loop is the most logical loop to use for this task*/
    for (i = 0; i < numOfwords; i++)
    {
        fscanf(fin, "%s", words);
        (*matrix)[i] = (char *)malloc((strlen(words) + 1) * sizeof(char));
        strcpy((*matrix)[i],words);

        if ((*matrix)[i] == NULL)
        {

            fprintf(stderr, "Memory Allocation error");
            exit(1);
        }
    }
    fclose(fin);
}

/*using insertion sort for the sorting part*/
void sortTheArrray(char **matrix_t, char *name, int num)

{
    FILE *fin;
    int i, j;
    char key[MAXCHAR];

    /*write the insertion sort code*/
    for (i = 1; i < num; i++)
    {
        strcpy(key, matrix_t[i]);
       
        j = i - 1;

        while (j >= 0 && strcmp(matrix_t[i], key) > 0)

        {
            matrix_t[j + 1] = matrix_t[j];
            j = j - 1;
        }
        strcpy(matrix_t[j + 1] , key);
    }
}

void display(char **matrix_t, int number)
{

    int i;

    fprintf(stdout, "Ordererd values");

    for (i = 0; i < number; i++)
    {
        fprintf(stdout, "%s \n", matrix_t[i]);
    }
}

void free2d(char **matrix, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        free(matrix[i]);
    }
    free (matrix);

}