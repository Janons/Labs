#include <stdio.h>
#include <stdlib.h>

char  backtrack(int *stringArray, int *mark, int *sol,int n, int l, int r);
void swap(char *x, char *y);

int main(int argc, char *argv[])
{
    if (argc < 6)
    {
        fprintf(stdout, "Insufficient amount of arguments");
        return EXIT_FAILURE;
    }

    char arr[5] = {argv[1], argv[2], argv[3], argv[4], argv[5]};

    return 0;
}

void swap(char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

char backtrack(int *stringArray, int *mark, int *sol,int n, int l, int r,
int pos)
{
    int i;
    if (pos >= n)
    {
        return;
    }

    for (i = l; i < r; i++)
    {
        if (mark[i] == 0)
        {
            swap(string[i+l][i+r])
        }
    }
    return;
}