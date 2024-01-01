#include <stdio.h>
#include <stdlib.h>

/*prototype*/
void menu_create(char **data[], int n);
void menu_recursion(char **data[], int n, int pos, int *sol, int mark[], int num_courses);

int main()
{
}

void menu_create(char **data[], int n)
{
}

void menu_recursion(char **data[], int n, int pos, int *sol, int mark[], int num_courses)
{

    if (pos == n)
    {
        for (int i = 0; i < num_courses; i++)
        {
            fprintf(stdout, "%d", sol[i]);
        }
        fprintf(stdout, "\n");
    }

    /*recursion part*/
    for (int i = 0; i < n;l, i++)
    {
        if (mark[i] = 0)
        {
            mark[i] = 1;
            sol[pos] = *data[i];
            menu_recursion(data, n, pos + 1, sol, mark, num_courses);
            mark[i] = 0;
        }
    }
}