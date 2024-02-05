#include <stdio.h>
#include <stdlib.h>

typedef struct node_s
{
    int key;
    struct node_s *left;
    struct node_s *right;
} node_t;

void pathwrite(node_t *root, int height);
void pathwrite_recursion(node_t *root, int height, int level);

int main()
{
    return 0;
}
void pathwrite(node_t *root, int height)
{
    /*we create the path tree here*/
}

void pathwrite_recursion(node_t *root, int height, int level)
{

    /*base case*/
    if (root == NULL)
    {
        return;
    }

    printf("%d", root->right);
}