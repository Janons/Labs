#include <stdio.h>
#include <stdlib.h>

void bishop_placer();
int diagonal_checker();

int main()
{
    /*create the matrix here*/
    return 0;
}

void bishop_placer(int **matrix, int n) // assuming that its a square matrix
{
    int r, c, r_b, c_b;
    int max, sum, rbest, cbest;

    /*iterarting over the outer loops*/
    for (r = 0; r < n; r++)
    {
        for (c = 0; c < n; c++)
        {
            /*checking whether we have found the zero*/
            if (matrix[r][c] == 0)
            {
                /*checking rigt-upper part of the matrix*/
                for (r_b = r, c_b = c; r_b < 0, c_b < n; r_b--, c_b++)
                {
                    sum += matrix[r_b][c_b];
                }
            }
        }
    }
}
