#include <stdio.h>
#include <stdlib.h>

#define N 15

typedef struct node_s
{
    int key;
    struct node_s *child[15];
} node_t;

void levelByLevel_visit_r(node_t *root, int l1, int l2);

int main()
{
    return 0;
}

void levelByLevel_visit_r(node_t *root, int l1, int l2)
{
    /*base case*/
    if (root == NULL)
    {
        return;
    }

    if (l1 > l2)
    {
        fprintf(stderr, "level1 cant be greater than l2");
        exit(EXIT_FAILURE);
    }
}