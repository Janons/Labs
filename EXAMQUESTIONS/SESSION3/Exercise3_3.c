#include <stdio.h>
#include <stdlib.h>

/*prototype*/
void menu_create(char ***data, int n);
void menu_recursion(char ***data, int n, int l, int **sol);

int main(int argc, char *argv[])
{
}

void menu_create(char ***data, int n)
{
    char **v;
    v = (char **)malloc(n * sizeof(char));
    if (v == NULL)
    {
        fprintf(stdout, "The malloc is null");
        return;
    }
    menu_recursion(***data, n, 0, v);
}

void menu_recursion(char ***data, int n, int pos, int **sol)
{

    int i;

    /*we are dealing with a matrix*/
    if (pos == n)
    {
        for (i = 0; i < n; i++)
        {
            fprintf(stdout, "%d", sol[i]);
        }
        fprintf(stdout, "\n");

        return;
    }

    /*recursion part*/

    while (data[pos][i] != NULL)
    {
        sol[pos] = data[pos][i];
        menu_recursion(data, n, pos + 1, sol);
        i++;
    }
    return;
}