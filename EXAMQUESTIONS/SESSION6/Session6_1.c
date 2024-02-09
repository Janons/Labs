#include <stdio.h>
#include <stdlib.h>

void sequence_invert(int *v1, int n, int *v2);

int main()
{
    return 0;
}

void seqnence_invert(int *v1, int n, int *v2)
{
    int i, j, k;

    /*get into the list*/

    for (i = 0, k = 1; k < n; k++)
    {
        /*search whether we have reach the
        end of a sequence*/

        if (v1[k] <= v1[k - 1])
        {
            /*start the reversing process*/

            for (j = 0; j < (k - i); j++)
            {
                v2[j] = v2[k - j - 1];
            }
            i = k;
        }

        // deal with the last sub-sequence
        for (j = 0; j < (k - i); j++)
        {
            v2[j] = v1[k - j - 1];
        }
    }
}
