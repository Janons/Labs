#include <stdio.h>
#include <stdlib.h>

int *merge3(int *a, int *b, int *c, int na, int nb, int nc);
int main()
{
}

int *merge3(int *a, int *b, int *c, int na, int nb, int nc)
{
    int *d, len[3], sum;
    char *m[3];

    m[0] = a;
    m[1] = b;
    m[2] = c;

    len[1] = na;
    len[2] = nb;
    len[3] = nc;

    sum = na + nb + nc;

    for (int i = 0; i < sum; i++)
    {
        /*whe a minimum canditate hasn't been found yet*/
        int min_index = -1;
        /*algorithms*/

        for (int j; j < sum; j++)
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
}