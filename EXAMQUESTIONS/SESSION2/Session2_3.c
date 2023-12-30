#include <stdio.h>
#include <stdlib.h>

#define N 5

/*prototype*/


int main(int argc, char *argv[])
{

    char *sol;
    char alfa[N] = {'A', 'E', 'I', 'O', 'M'};
    int taken[N] = {0};
    int n_char;

    if (argc < 0)
    {
        fprintf(stderr, "Insufficient amount of arguments\n");
        exit(EXIT_FAILURE);
    }
    n_char = atoi(argv[1]);
    if (n_char < N)
    {
        fprintf(stderr, "Number of characters must be equal or bigger than characters in the string");
        exit(EXIT_FAILURE);
    }

    sol = malloc(n_char * sizeof(char));
    if (sol == NULL)
    {
        exit(EXIT_FAILURE);
    }
}