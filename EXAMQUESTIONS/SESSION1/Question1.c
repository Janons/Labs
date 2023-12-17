#include <stdio.h>
#include <stdlib.h>

int *merge3(int *a, int *b, int *c, int na, int nb, int nc);
int main()
{

}

int *merge3(int *a, int *b, int *c, int na, int nb, int nc)
{
    int *d;
    int *m[3], len[3];

    m[0] = a;
    m[1] = b;
    m[2] = c;

    len[0] = na;
    len[1] = nb;
    len[2] = nc;

    int sum = na + nb + nc;

    d = (int *)malloc(sum * sizeof(int));
    if (d == NULL)
    {
        perror("Error in memory allocating");
        return EXIT_FAILURE;
    }

    for (int i; i < sum; i++)
    {
        int min_index = -1;
        for (int j = 0; j < 3; j++)
        {
            if (len[j] != 0 || (min_index == -1 || *m[min_index] > *m[j]))
            {
                min_index = j;
            }
        }

        d[i] = *m[min_index]; // we access the value with the pointers
        m[min_index]++;
        len[min_index]--;
    }

    return d;
}