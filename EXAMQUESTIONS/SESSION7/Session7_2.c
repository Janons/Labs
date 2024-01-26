#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct node_s
{

    int key;
    struct node_s *right;
    struct node_s *left
} node_t;

void tree_dup(node_t *root);

int main()
{
    return 0;
}

void tree_dup(node_t *root)
{
    if (root == NULL)
        return;
}
