#include <stdio.h>
#include <stdlib.h>

/*prototype*/
void menu_create(char **data[], int n);
void menu_recursion(char **data[], int n, int pos, int *sol, int mark[]);

int main()
{
}

void menu_create(char **data[], int n)
{
}

void menu_recursion(char **data[], int n, int pos, int *sol, int mark[])
{

    if (pos == n)
    {
        for (int i = 0; i < n; i++)
        {
            fprintf(stdout, "%d", sol[i]);
        }
        fprintf(stdout, "\n");
    }

    /*recursion part*/
    for (int i = 0; i < n; i++)
    {
        if (mark[i] = 0)
        {
            mark[i] = 1;
            sol[pos] = *data[i];

        }
    }
}