#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*definition*/
#define EMPTY ' '
#define START '@'
#define STOP '#'
#define PATH '$'

const int xOff = {0, 1, 0, -1};
const int yOff = {-1, 0, 1, 0};

/*prototypes*/

void **matrixCreate(int **matrix, int *nr, int *nc, char *name);
int *my_memoryAllocation(int size, int typesize);
bool isValid(int **matrix, int r, int c, int x, int y);

void recursion(int **matrix, int x, int y, int *path);

int main(int argc, char *argv)
{
    int **matrix;
    int nr, nc;

    matrixCreate(matrix, nr, nc, argv[1]);

    int *path;

    path = (int *)malloc(nr * nc * sizeof(int));
    if (path == NULL)
    {
        return EXIT_FAILURE;
    }

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
void recursion(int **matrix, int x, int y, int *path);
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

        if (isValid(xx, yy, matrix))
        {
        }
    }
}