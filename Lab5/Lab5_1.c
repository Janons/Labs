#include <stdio.h>
#include <stdlib.h>

int perm(int *val, int *sol, int *mark,
         int n, int count, int pos);
int magicsquare();
void writeMagicSquare();

int main()
{
    return 0;
}

int perm(int *val, int *sol, int *mark,
         int n, int count, int pos)
{
    int i;

    val = malloc(n * sizeof(int));
    sol = malloc(n * sizeof(int));
    mark = malloc(n * sizeof(int));
    
    if (pos >= n)
    {
        return count + 1;
    }
}