#include <stdio.h>
#include <stdlib.h>

int mult(int x, int y);

int main()
{

    int x, y, res;
    printf("Please enter the values for x and y");

    scanf("%d %d", &x, &y);

    res = mult(x, y);

    printf("The result is ->  %d \n", res);
}

int mult(int x, int y)
{
    if (x * y == 1)
        return x;

    return x + (x * (y - 1));
}