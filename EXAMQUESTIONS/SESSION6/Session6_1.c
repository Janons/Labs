#include <stdio.h>
#include <stdlib.h>

void sequence_invert(int *v1, int n, int *v2);

int main()
{
    return 0;
}

void sequence_invert(int *v1, int n, int *v2)
{
    int i, j, k;

    // we track everything with k

    for (i = 0, k = 1; k < n; k++)
    {
        /*checking end of the subsequence*/
        if (v1[k] <= v1[k - 1])
        {
            for (j = 0; j < (k - i); j++)
            {

                v2[i + j] = v1[k - i - j];
            }
        }
        i = k;
    }
    
}
}
