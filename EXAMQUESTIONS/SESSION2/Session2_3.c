#include <stdio.h>
#include <stdlib.h>

#define N 5

/*prototype*/
void arr(char *, char[], int[], int, int, int);

int main(int argc, char *argv[])
{

    char *sol;
    char alfa[N] = {'A', 'E', 'I', 'O', 'M'};
    int taken[N] = {0};
    int n_char;

    if (argc < 2)
    {
        fprintf(stderr, "Insufficient amount of arguments\n");
        exit(EXIT_FAILURE);
    }
    n_char = atoi(argv[1]);

    fprintf(stdout, "%d", n_char);
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

    arr(sol, alfa, taken, 0, n_char - N, n_char);
    free(sol);
}

void arr(char *sol, char alfa[], int taken[], int position, int reps_allowed, int n_char)
{
    int i;

    if (position == n_char)
    {

        for (i = 0; i < n_char; i++)
        {
            fprintf(stdout, "%c", sol[i]);
        }
        fprintf(stdout, "\n");
        return;
    }

    for (i = 0; i < N; i++)
    {
        if (!taken[i])
        {
            taken[i] = 1;
            sol[position] = alfa[i];
            arr(sol, alfa, taken, position + 1, reps_allowed, n_char);
            taken[i] = 0;
        }
        else
        {
            if (taken[i] && reps_allowed > 0)
            {
                sol[position] = alfa[i];
                arr(sol, alfa, taken, position + 1, reps_allowed - 1, n_char);
            }
        }
    }
}
