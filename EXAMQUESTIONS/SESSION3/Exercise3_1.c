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
    int i = 0, j, index;
    int flag;

    while (i <= d1 - d2)
    {
        j = 0;
        flag = 1;

        while (j < d2 && flag == 1)
        {
            /*internal check*/
            if ((v1[i + j] != v2[j]))
            {
                flag = 0;
            }
            j++;
        }
        if (flag == 1)
        {
            return i;
        }
        i++;
    }

    return -1;
}