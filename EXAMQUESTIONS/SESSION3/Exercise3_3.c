#include <stdio.h>
#include <stdlib.h>

/*prototype*/
void menu_create(char ***data, int n);
void menu_recursion(char ***data, int *mark, int n, int l, int *sol);

int main(int argc, char *argv[])
{
}

void menu_create(char ***data, int n)
{
    int i;

    data = (char **)malloc(n * sizeof(char *));
    if (data == NULL)
    {
        return -1;
    }
    for (i = 0; i < n; i++)
    {
        data[i] = (char *)malloc(n * sizeof(char));

        if (data[i] == NULL)
        {
            return -1;
        }
    }
}

void menu_recursion(char ***data, int *mark, int n, int l, int *sol)
{
    int i;
    if (l == n)
    {
        
        return;
    }

    for (i = 0; i < n; i++)
    {
        if (mark[i] == 0)
        {
            mark[i] = 1;
            sol[l] = data[i];
            menu_recursion(data, mark, n, l + 1, sol);
            mark[i] = 0;
        }
    }
}