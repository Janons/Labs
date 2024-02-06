#include <stdio.h>
#include <stdlib.h>

int util_malloc(int size);
int create_matrix(int **matrix); // opens the matrix
void recurBestsum(int **matrix, int **bestMatrix, int matsize, int r, int c, int **marked, int *markedBest, int *pathSumMax, int pathsumCurrent, int *pathLenMax,
                  int pathLenCurrent);

void copyPath(int **matrix, int *copyMatrix);

int main()
{
    return 0;
}

void recurBestsum(int **matrix, int **bestMatrix, int matsize, int r, int c, int **marked, int *markedBest, int *pathSumMax, int pathsumCurrent, int *pathLenMax,
                  int pathLenCurrent)

{
    int i, j, v1, v2;
    int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

    /*base cases*/

    if (r > matsize || c > matsize)
    {
        return;
    }

    if (marked[r][c] > 0)
    {
        return;
    }

    /*The thing we have missed , and the thing we need to recap again*/
    v1 = pathsumCurrent + matrix[r][c];
    v2 = pathLenCurrent + 1;

    if (matrix[r][c] == matrix[matsize][matsize])

    {
        fprintf(stdout, "We are at the last index");
        copyPath(matrix, bestMatrix);

        marked[r][c] = v2; // so basically we make it bigger than zero

        /*recursion*/
        for (i = 0; i < 8; i++)
        {
            r = r + dx[i];
            c = c + dy[i];
            recurBestsum(matrix, bestMatrix, matsize, r, c, marked, markedBest, pathSumMax, pathsumCurrent, pathLenMax,
                         pathLenCurrent);
        }

        marked[r][c] = 0; // backtracking part
    }
