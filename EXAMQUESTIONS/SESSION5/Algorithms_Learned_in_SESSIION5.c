#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int findElement(int *arr, int n, int key)
{
    int i;
    int flag;
    for (i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            flag = i;
        }
    }
    return flag;
}

void delelement(int *array, int n, int key)
{
    int element_index, i;
    element_index = findElement(array, n, key);

    if (element_index == -1)
    {
        return EXIT_FAILURE;
    }

    // left shift
    for (i = element_index; i < n - 1; i++)
    {
        array[i] = array[i + 1];
    }

    return n - 1;
}