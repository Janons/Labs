#include <stdio.h>
#include <stdlib.h>

const int x_offset = {-1, -1, -1, 0, 0, 1, 1, 1};
const int y_offset = {-1, 0, 1, -1, 1, -1, 0, 1};

int util_malloc(int size);
int create_matrix(int **matrix); // opens the matrix
void recurBestsum(int **matrix, int matsize, int r, int c, int **marked, int *markedBest, int *pathSumMax, int pathsumCurrent, int *pathLenMax,
                  int pathLenCurrent);

int main()
{
    return 0;
}

void recurBestsum(int **matrix, int matsize, int r, int c, int **marked, int *markedBest, int *pathSumMax, int pathsumCurrent, int *pathLenMax,
                  int pathLenCurrent)

{
    int sumtracker, lentracker, i;
    /*base cases*/

    if (r == (matsize - 1) && c == (matsize - 1))
    {
    }

    /*marked check*/
    if (marked[r][c] > 0)
    {
        return;
    }

    sumtracker = pathsumCurrent + matrix[r][c];
    lentracker = pathLenCurrent + 1;

    /*recursion*/
    for (i = 0; i < 8; i++)
    {
    }

    /*backtrack*/
}
