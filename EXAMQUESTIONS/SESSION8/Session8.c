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

    for (r = 0; r < n; r++)
    {
        for (c = 0; c < n; c++)
        {
            if (matrix[r][c] == 0)
            {

                // upper-left search

                for (r_b = r, c_b = c; c_b >= 0, r_b >= c; r_b--, c_b--)
                {
                    sum += matrix[r_b][c_b];
                }

                // upper-right search

                for (r_b = r, c_b = c; r_b >= 0, c_b <= n; r_b--, c_b++)
                {
                    sum += matrix[r_b][c_b];
                }

                // left-down search
                for (r_b = r, c_b = c; r_b <= n, c_b >= 0; r_b++, c_b--)
                {
                    sum += matrix[r_b][c_b];
                }

                // left-right search
                for (r_b = r, c_b = c; r_b <= n, c_b <= n; r_b++, c_b++)
                {
                    sum += matrix[r_b][c_b];
                }
            }
        }
    }
}
}
