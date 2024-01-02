#include <stdio.h>
#include <stdlib.h>

/*prototype*/
int search(int *v1, int *v2, int d1, int d2);

/*main function*/

int main()
{
    int v1[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int v2[4] = {3, 5, 6, 7};
    int index;

    index = search(&v1, &v2, sizeof(v1), sizeof(v2));
    printf("%d", index);
    return 0;
}

int search(int *v1, int *v2, int d1, int d2)
{
    int i = 0, j = 0, index;
    int flag;

    while (i < d1 - d2)
    {
        if (v1[i] == v2[0])
        {
            flag = 1;
            index = i;
        }

        if (flag)
        {
            while (j < d2)
            {

                if ((v1[i + j] != v2[j]))
                {
                    flag = 0;
                }
                j++;
            }
        }

        i++;
    }

    return (flag == 1) ? index : -1;
}