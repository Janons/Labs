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

int main(int argc, char *argv)
{
    int **matrix;
}

void *util_malloc(int size)
{
    int *mem;
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
    src = strdup(src);
    if (src == NULL)
    {
        fprintf(stderr, "Error in memory allocation 2");
        exit(EXIT_FAILURE);
    }
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

}




/*Writing the professors solution once again on my own*/