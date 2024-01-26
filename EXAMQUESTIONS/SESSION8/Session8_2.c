#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node_s
{
    char *key;
    struct node_s *right;
    struct node_s *left;
} node_t;

int tree_isomorphism(node_t *t1, node_t *t2);

int main()
{
    return 0;
}

int tree_isomorphism(node_t *t1, node_t *t2)
{
    // Checking whether we have reached the end with success
    if (t1 == NULL || t2 == NULL)
    {
        return 1;
    }

    if (strcmp(t1->key, t2->key) != 0)
    {
        return -1;
    }
    if (strcmp(t1->key, t2->key) == 0)
    {
        return tree_isomorphism(t1->right, t2->right);
    }

    if (strcmp(t1->key, t2->key) == 0)
    {
        return tree_isomorphism(t1->left, t2->left);
    }
}