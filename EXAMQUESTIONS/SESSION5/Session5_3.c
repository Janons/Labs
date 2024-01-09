#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*definitions*/
#define MAX 10

/*prototype*/
int *file_to_array(FILE *fin, int n);
void recursion(int *mark, int *sol, int n, int pos);

int main(int argc, char *argv)
{

    if (argc < 2)
    {
        return EXIT_FAILURE;
    }
}

int *file_to_array(FILE *fin, int n)
{
    int *array, i = 0;
    array = malloc(sizeof(int));

    while (fgets(array[i], MAX, fin) != EOF || i <= 3)
    {
        array[i] = malloc(MAX * sizeof(int));
        i++;
    }

    return array;
}

void recursion(int *mark, int *sol, int n, int pos, FILE *fout)
{
    int i, j;

    if (pos >= n)
    {
        for (i = 0; i < n; i++)
        {
            fprintf(fout, "%c", sol[i]);
        }
        fprintf(fout, "\n");
    }

    i = 0;
    while (i <= n)
    {
        while (array[i][j] != ' ')
        {
            if (mark[i] == 0)
            {
                mark[i] == 1;
                sol[i] = array[i][j];
                recursion(mark, sol, n, pos + 1, fout);
                mark[i] = 0;
            }
            j++;
        }
        i++;
    }
}