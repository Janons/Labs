#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*prototype*/
void duplicate_erase(char *str);

int main()
{
}

void duplicate_erase(char *str)
{
    int i, j;
    i = 0;
    while (i < strlen(str))
    {

        while (j < strlen(str) && str[j + 1] == str[i])
        {
            j++;
            free(str[j + 1]);
        }
        i++;
    }
}