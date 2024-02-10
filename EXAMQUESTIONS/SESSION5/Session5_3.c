#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*we use multiplication principle here*/

/*definitions*/
#define MAX 10

/*prototype*/
int **file_to_array(FILE *fin, int n);
void recursion(int *mark, char **array, int *sol, int n, int pos, FILE *fout);

int main(int argc, char *argv)
{

    if (argc < 2)
    {
        return EXIT_FAILURE;
    }
}

int **file_to_array(FILE *fin, int n)
{
    char **array;
    int i;

    /*allocate memory for the*/
    array = (char **)malloc(n * sizeof(char *));
    if (array == NULL)
    {
        fprintf(stderr, "Memory couldn't be allocated for array");
        exit(EXIT_FAILURE);
    }

    /*getting the value into the array*/
    while (fscanf(fin, "%s", array[i]) != EOF)
    {
        i++;
    }

    return array;
}

void recursion(int *mark, char **array, int *sol, int n, int pos, FILE *fout)
{
    int i,j;

    /*base case*/
    if (pos == n)
        return;

    /*recursion part*/

    for (i = 0; i < n; i++)
    {
     
    }
}