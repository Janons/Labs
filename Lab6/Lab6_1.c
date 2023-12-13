#include <stdio.h>
#include <stdlib.h>

/*prototypes*/

void **matrixCreate(int **matrix, int *nr, int *nc, char *name);
void my_memoryAllocation(int **matrix, int r);
int recursion();

int main()
{
    return 0;
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