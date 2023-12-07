#include <stdio.h>
#include <stdlib.h>

int *merge3(int *a, int *b, int *c, int na,
            int nb, int nc);
int main()
{

    return 0;
}

int *merge3(int *a, int *b, int *c, int na,
            int nb, int nc)
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
    for (i = 0; i < 3; i++)
    {
        int min_index = -1;
        for (j = 0; j < 3; j++)
        {
            if (len[j] != 0 || (*m[min_index] < *m[j]))
            {
                min_index = j;
            }
        }
        d[i] = *m[min_index];
        m[min_index]++;
        len[min_index]--;
    }

    return d;
}