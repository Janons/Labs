#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define DIM 20

void map_read(char *, int[DIM][DIM], int *, int *);
void expand_r(int[DIM][DIM], int, int, int);
void map_write(char *, int[DIM][DIM], int, int, int);

int main(int argc, char *argv[])
{

    char mat[DIM][DIM];
    int nr, nc, i, j;

    map_read(argv[1], mat, nr, nc);
    for (i = 0; i < nr; i++)
    {
        for (j = 0; j < nc; j++)
        {
            if (mat[i][j] == -1)
            {
                expand_r(); // dropping the water drop
            }
        }
    }
}

void map_read(char *name, int map[DIM][DIM], int *nr, int *nc)
{
    /*the variables*/

    /*open the file*/

    /*Change the numbers of the map values*/
    while()
}