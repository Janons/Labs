#include <stdio.h>
#include <stdlib.h>

/*prototype*/
int search(int *v1, int *v2, int d1, int d2);

/*main function*/

int main()
{
    int v1[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int v2[4] = {4, 5, 6, 7};
    int index;

    index = search(v1, v2, sizeof(v1) / sizeof(v1[0]), sizeof(v2) / sizeof(v2[0]));
    printf("%d", index);
    return 0;
}

int search(int *v1, int *v2, int d1, int d2)
{
    int i, j, flag, index;

    i = 0;
    while (i < d1 - d2)
    {
        if (v1[i] = v2[0])
        {
            index = i;
            for (j = 0; j < d2; j++)
            {

                if (v1[i + j] == v2[j])
                {
                    flag = 1;
                }

                else
                {
                    flag = 0;
                }
            }
        }
        i++;
    }

    if (flag == 1)
    {
        return index;
    }

    return -1;
}