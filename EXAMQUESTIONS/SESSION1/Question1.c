#include <stdio.h>
#include <stdlib.h>

int *merge3(int *a, int *b, int *c, int na,
            int nb, int nc, int *n);
int main()
{

    int *finalArray;
    int n;
    int a[] = {1, 4, 10, 11};
    int b[] = {2, 5, 6, 12, 24};
    int c[] = {0, 7, 8};

    finalArray = merge3(a, b, c, sizeof(a), sizeof(b),
                        sizeof(c), &n);

    for (int i = 0; i < sizeof(finalArray); i++)
    {
        fprintf(stdout, "%i \n", finalArray[i]);
        }

    fprintf(stdout, "%ld", sizeof(finalArray));

    return 0;
}

int *merge3(int *a, int *b, int *c, int na,
            int nb, int nc, int *n)
{
    int *d, *m[3], len[3];
    int tot = na + nb + nc;
    int i, j;



    m[0] = a;
    m[1] = b;
    m[2] = c;
    len[0] = na;
    len[1] = nb;
    len[2] = nc;

    /*dynamic memory allocation*/
    d = (int *)malloc(tot * sizeof(int));
    if (d == NULL)
    {
        exit(EXIT_FAILURE);
    }
    for (i = 0; i < tot; i++)
    {
        int min_index = -1;
        for (j = 0; j < 3; j++)
        {
            if (len[j] != 0 && (min_index == -1 || *m[min_index] > *m[j]))
            {
                min_index = j;
            }
        }
        d[i] = *m[min_index];
        m[min_index]++;
        len[min_index]--;
    }

    *n = tot;

    return d;
}