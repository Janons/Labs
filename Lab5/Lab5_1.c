#include <stdio.h>
#include <stdlib.h>

void perm(int *val, int *sol, int *mark,
         int n, int count, int pos);
int checkMagicSquare();
void writeMagicSquare();

int main()
{
    return 0;
}

void perm(int *val, int *sol, int *mark,
         int n, int count, int pos)
{
    int i;

    val = (int *)malloc(n * sizeof(int));
    sol = (int *)malloc(n * sizeof(int));
    mark = (int *)calloc(n, sizeof(int));

    if (pos >= n)
    {
        return count + 1;
    }

    for (i = 0; i < n; i++)
    {
        if (mark[i] == 0)
        {
            mark[i]= 1 //the value is chosen
        }
    }
}