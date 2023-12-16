#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*prototypes*/

void **matrixCreate(int **matrix, int *nr, int *nc, char *name);
int *my_memoryAllocation(int size, int typesize);
bool isValid(int **matrix, int r, int c, int x, int y);

void recursion(int **matrix, int x, int y);

int main()
{
    int **matrix;

    return 0;
}

int *my_memoryAllocation(int size, int typesize)
{
    int mem = malloc(size * sizeof(typesize));
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
            if (matrix[i][j] == ' ')
                matrix[i][j] = -1;
            j++;
        }
        i++;
    }
    fclose(fmaze);

    *nr = r;
    *nc = c;
}

bool isValid(int **matrix, int r, int c, int x, int y)
{
    /*row,col check*/

    bool row = (x <= c && y <= c) ? true : false;
    bool result = (matrix[x][y] != "*") ? true : false;

    if (row && result)
        return true;

    return false;
}

/*finding a general solution*/
void recursion(int **matrix, int x, int y);
{

    int xoffset = {0, 1, 0, -1};
    int yoffset = {1, 0, -1, 0};
    int xx, yy;

    if (map[x][y] == "#")
    {
        return;
    }

    /*mark the position*/
    map[x][y] = '.';

    /*look for a path to escape*/
    for (i = 0; i < 4; i++)
    {
        xx = x + xoff[i];
        yy = y + yoff[i];
        recursion(matrix, xx, yy);
    }
}