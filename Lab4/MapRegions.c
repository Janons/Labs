#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define DIM 20

void map_read(char *, int[DIM][DIM], int *, int *);
void expand_r(int[DIM][DIM], int, int, int);
void map_write(char *, int[DIM][DIM], int, int, int);

int main(int argc, char *argv[])
{

    char map[DIM][DIM];
    char line[DIM];
    int nr, nc, i, j, n = 0;

    if (argc < 2)
    {
        return (EXIT_FAILURE);
    }

    map_read(argv[1], map, &nr, &nc);

    for (i = 0; i < nr; i++)
    {
        for (j = 0; j < nc; j++)
        {
            fprintf(stdout, "%d", map[i][j]);
        }
    }

    return 0;

}

void map_read(char *name, int map[DIM][DIM], int *nr, int *nc)
{
    /*the variables*/
    FILE *fin;
    char line[DIM+2];
    int i, j;

    /*opening the file*/
    fin = fopen(name, "r");
    if (fin == NULL)
        perror("ERRRRRORRRR");

    /*Change the numbers of the map values*/
    i = 0;
    while (fgets(line, DIM+2, fin) != NULL)
    {
        j = 0;
        while (j < DIM && (line[j] == '.' || line[j] == '*'))
        {
            map[i][j] = ((line[j] == '.') ? -1 : 0);
            j++;
        }
    }
    *nr = i;
    *nc = j;

    fclose(fin);
}


/*questions to ask
1)Would using memory allocation here be logical?
2)Why do we add 2?*/