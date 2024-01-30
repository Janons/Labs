#include <stdio.h>
#include <stdlib.h>

const int x_offset = {0, 1, 0, -1};
const int y_offset = {-1, 0, 1, 0};

int util_malloc(int size);
int create_matrix(int **matrix); // opens the matrix
void recurBestsum(int **matrix, int matsize, int r, int c, int *marked, int *markedBest, int *pathSumMax, int pathsumCurrent, int *pathLenMax,
int pathLenCurrent);

int main()
{
    return 0;
}
