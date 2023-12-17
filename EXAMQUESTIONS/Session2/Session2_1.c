#include <stdio.h>
#include <stdlib.h>

/*prototype*/

int *rotate(int *array, int size, int command);

int main()
{
    int command;
    int *array;

    array = (int *)malloc(10 * sizeof(int));
    for (int i = 0; i < 10; i++)
    {
        array[i] = i;
    }

    printf("Enter the rotation command please \n");
    scanf("%d", &command);

    array = rotate(array, sizeof(array), command);

    for (int i = 0; i < sizeof(array); i++)
    {
        fprintf(stdout, "%d \n", array[i]);
    }


    free(array);

    return 1;
}

int *rotate(int *array, int size, int command)
{
    int *aux;

    aux = (int *)malloc(size * sizeof(int));

    for (int i = 0; i < size; i++)
    {
        aux[i - command] = array[i]; 
    }

    return aux;
}