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
/*write this code again*/
void list_insert(node_t **left, node_t **right, int key, int leftright)
{
    node_t *node, *left_, *right_;
    left_ = *left;
    right_ = *right;

    int val = (leftright == 1) ? 1 : 0;
    node = createNode(right_, left_, key);

    if (val)
    {
        /*right extreme insertion*/
        while (left_ != NULL)
        {
            left_ = left_->left;
        }
        if (left != NULL)
        {
            return EXIT_FAILURE;
        }

        else
        {
            left_->left = node;
            node->right = left_;
            node->left = NULL;
        }
    }

    else
    {
    }
}
node_t *createNode(node_t *right, node_t *left, int key)
{
    node_t *newNode;

    newNode = (node_t *)malloc(sizeof(node_t));
    if (newNode == NULL)
    {
        fprintf(stdout, "Problem in allocatig memory for newNode");
        return EXIT_FAILURE;
    }

    newNode->left = left;
    newNode->right = right;
    newNode->key = key;
}

void list_write(node_t *left, node_t *right, int leftright)
{
    node_t *node;

    if (leftright == 1)
    {
        while (right != NULL)
        {
            right = right->right;
            fprintf(stdout, "%d", right->key);
        }
    }
}