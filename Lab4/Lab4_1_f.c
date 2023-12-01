#include <stdio.h>
#include <stdlib.h>

void triangle(int n, int i);

int main()
{
    triangle(5, 1);
    return (EXIT_SUCCESS);
}

void triangle(int n, int i)
{
    int j;
    if (i > n)
        return;

    for (j = 0; j < i; j++)
    {
        fprintf(stdout, "%d", i);
    }
    fprintf(stdout, "\n");

    triangle(n, i+1);

    return;

}
