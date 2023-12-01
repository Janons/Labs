// solve this again

#include <stdio.h>
#include <stdlib.h>

void d2b(int d, int *b, int *n);

int main()
{
    int i, b[10], d = 35, n = 0;

    d2b(d, b, &n);
    fprintf(stdout, "-- Decimal to Binary Conversion: (base 10) %d = (base 2) ", d);
    for (i = n - 1; i >= 0; i--)
        fprintf(stdout, "%d", b[i]);
    fprintf(stdout, "\n");

    return 1;
}

void d2b(int d, int *b, int *n)
{

    if (d == 0) // the termination condition
        return;

    b[*n] = d % 2;
    d = d / 2;
    *n = *n + 1;
    d2b(d, b, n);

    return;
}