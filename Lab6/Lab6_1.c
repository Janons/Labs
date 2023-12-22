#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

#define EMPTY ' '
#define START '@'
#define STOP '#'
#define PATH '$'

const int xOff[4] = {0, 1, 0, -1};
const int yOff[4] = {-1, 0, 1, 0};

/* function prototypes */
void display(char **maze, int nr);
int move_recur(char **mazeCurr, int stepCurr, char **mazeBest, int stepBest,
               int nr, int nc, int row, int col);
FILE *util_fopen(char *name, char *mode);
void *util_malloc(int size);
char *util_strdup(char *src);

int main(int argc, char *argv[])
{
    int r = -1, c = -1, i, j, nr, nc, step;
    int **mazeCurr, **mazeBest;
    char line[MAX]; // maximum number of characters for our maze;
    FILE *fin;

    if (argc < 2)
    {
        printf("Error: missing parameter.\n");
        printf("Run as: %s <maze_file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    fin = util_fopen(argv[1], "r");
    fgets(line, MAX, fin);
    sscanf(line, "%d %d", &nr, &nc);

    mazeCurr = (char **)(util_malloc(nr * sizeof(char *)));
    mazeBest = (char **)(util_malloc(nr * sizeof(char *)));

    for (i = 0; i < nr; i++)
    {
        fgets(line, MAX, fin);
        mazeCurr[i] = util_strdup(line);
        mazeBest[i] = util_strdup(line);

        for (j = 0; j < nc; j++)
        {
            if (mazeCurr[i][j] == START)
            {
                mazeCurr[i][j] = ' ';
                r = i;
                c = j;
            }
        }
    }

    if (r < 0 || c < 0)
    {
        exit(EXIT_FAILURE);
    }

    step = move_recur(mazeCurr, 0, mazeBest, nr * nc, nr, nc, r, c);

    /*freeing part*/
    for (r = 0; r < nr; r++)
    {
        free(mazeCurr[r]);
        free(mazeBest[r]);
    }
    free(mazeCurr[r]);
    free(mazeBest[r]);

    return EXIT_SUCCESS;
}

void *util_malloc(int size)
{
    void *mem;
    mem = malloc(size);

    if (mem == NULL)
    {
        fprintf(stderr, "Error in memory allocation 1");
        exit(EXIT_FAILURE);
    }

    return mem;
}

char *util_strdup(char *src)
{
    char *strr = strdup(src);
    if (src == NULL)
    {
        fprintf(stderr, "Error in memory allocation 2");
        exit(EXIT_FAILURE);
    }

    return strr;
}

FILE *util_fopen(char *name, char *mode)
{
    FILE *fin;
    fin = fopen(name, mode);

    if (fin == NULL)
    {
        fprintf(stderr, "Error in file parsing");
        exit(EXIT_FAILURE);
    }
}

int move_recur(char **mazeCurr, int stepCurr, char **mazeBest, int stepBest,
               int nr, int nc, int row, int col)
{
    int k, r, c;
    // first check
    if (stepCurr >= stepBest)
    {
        return stepBest;
    }

    // second check
    if (mazeCurr[row][col] == STOP)
    {
        if (stepCurr < stepBest)
        {
            for (r = 0; r < row; r++)
            {
                for (c = 0; c < col; c++)
                {
                    mazeBest[r][c] = mazeCurr[r][c];
                }
            }
        }
        return stepBest;
    }

    // third base case
    if (mazeCurr[r][c] != EMPTY)
    {
        return stepBest;
    }

    // Recursion
    mazeCurr[r][c] = PATH;
    for (k = 0; k < 4; k++)
    {
        r = row + xOff[k]; // we update the values for the r and c constantly here
        c = col + yOff[k];

        if (r <= nr && c <= nc && mazeCurr[r][c])
        {
            stepBest = move_recur(mazeCurr, stepCurr + 1, mazeBest, stepBest, nr, nc, r, c);
        }
    }
}

/*Writing the professors solution once again on my own*/
/*Key goal => Solve all recursion questions once again*/