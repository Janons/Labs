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

    index = search(&v1, &v2, sizeof(v1), sizeof(v2));
    printf("%d", index);
    return 0;
}

/*solve again*/
int search(int *v1, int *v2, int d1, int d2)
{
    char *p1, *p2;
    int index;

    for (int i = 0; i < d1; i++)
    {
        printf("%d", v1[i]);
        if (v1[i] == v2[0])
        {
            index = i;
            break;
        }
    }

    return index;
}