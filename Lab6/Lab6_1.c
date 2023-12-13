#include <stdio.h>
#include <stdlib.h>

/*prototypes*/

void **matrixCreate(int **matrix, int *nr, int *nc, char *name);
int *my_memoryAllocation(int size, int typesize);
int recursion();

int main()
{
    int **matrix;
    

    return 0;
}

int *my_memoryAllocation(int size, int typesize)
{
    int *mem = malloc(size * sizeof(typesize));
    if (mem == NULL)
    {
        exit(-1);
    }
    return mem;
}

void **matrixCreate(int **matrix, int *nr, int *nc, char *name)
{
    /*variable*/
    FILE *fmaze;
    int i, j;
    int r, c;

    /*open the file*/
    fmaze = fopen(name, "r");
    if (fmaze == NULL)
    {
        fprintf(stderr, "Error in parsing the file");
    }

    fscanf(fmaze, "%d %d", &r, &c);
    char line[c];

    /*memory allocation for the matrix*/
    matrix = (int **)my_memoryAllocation(r, sizeof(int *));
    for (i = 0; i < r; i++)
    {
        matrix[i] = (int *)my_memoryAllocation(c, sizeof(int));
    }

    /*matrix creation*/
    while (fgets(line, c, fmaze) == NULL)
    {
        j = 0;
        while (j < c && (line[j] == ' ' || line[j] == '*' || line[j] == '#'))
        {
            if (matrix[i][j] == '*')
                matrix[i][j] = 1;
            j++;
        }
        i++;
    }
    fclose(fmaze);

    *nr = r;
    *nc = c;
}