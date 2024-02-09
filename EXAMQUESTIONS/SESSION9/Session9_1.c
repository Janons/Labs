#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *char_erase(char *str, int *pos);
void *allocateMemory(int size);

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        fprintf(stderr, "The number of arguments is insufficient");
        exit(EXIT_FAILURE);
    }
    char *new_Array;
    char *str = argv[1];
    int *pos = {7, 4, 2, 0, 11, -1};

    /*memory allocation for the new array*/
    int size = strlen(str) - strlen(pos);
    new_Array = (char *)allocateMemory(size);

    /*test the function*/
    new_Array = char_erase(str, pos);

    for (int i = 0; i < size; i++)
    {
        fprintf(stdout, "%c", new_Array[i]);
    }

    return 0;
}

char *char_erase(char *str, int *pos)
{
    int i, j, index;

    int size_of_pos = strlen(pos);
    int size_of_str = strlen(str);

    /*search pos index in string*/

    for (i = 0; i < size_of_pos; i++)
    {
        index = pos[i];

        for (j = index; j < size_of_str - 1; j++)
        {
            str[j] = str[j + 1];
        }
    }

    return str;
}

void *allocateMemory(int size)
{
    void *ptr = malloc(size);
    if (ptr == NULL)
    {
        fprintf(stderr, "Error in allocating memory");
        exit(EXIT_FAILURE);
    }

    return ptr;
}