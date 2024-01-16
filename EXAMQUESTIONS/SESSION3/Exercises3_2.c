#include <stdio.h>
#include <stdlib.h>

/*structure for our node*/
typedef struct node
{
    int key;
    struct node *left;
    struct node *right;
} node_t;

/*prototypes*/
node_t *createNode(node_t *right, node_t *left, int key);
void list_insert(node_t **left, node_t **right, int key, int leftright);
void list_write(node_t *left, node_t *right, int leftright);

int main()
{
    return 0;
}

void list_insert(node_t **left, node_t **right, int key, int leftright)
{
    node_t *node;
    node = createNode(right, left, key);
    if (leftright == 0)
    {
        while (node != NULL)
        {
            node = node->left;
        }

        node->left = NULL;
        node->right = left;
    }
}

void list_write(node_t *left, node_t *right, int leftright)
{
    node_t *p;
    if (leftright == 0)
    {
        p = left;
        while (p != NULL)
        {
            fprintf(stdout, "Values : %f", p->key);
            p = p->right;
        }
    }
}

node_t *createNode(node_t *right, node_t *left, int key)
{
    node_t *node;

    node = (node_t *)malloc(sizeof(node_t));
    if (node == NULL)
    {
        return EXIT_FAILURE;
    }

    node->right = right;
    node->left = left;
    node->key = key;
}