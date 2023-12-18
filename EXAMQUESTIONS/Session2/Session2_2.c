#include "Session_2_2.h"

/*writing the prof solution without looking*/

/*prototypes*/
static *new_Node(float value, int col, node_t *next);
void mat_insert(matr_t *mat, int r, int c, float value);

int main()
{
}

void mat_insert(matr_t *mat, int r, int c, float value)
{

    /*variables*/
    node_t *node, *prev;

    /*error check*/
    if (mat->nr > r || mat->nc > c)
        return;

    if (mat->rows->ne == 0)
    {
        node = new_Node(value, c, NULL); // first ever insertion
    }

    else
    { // sorted insertion
        prev->next = NULL;
        mat->rows[r].next = new_Node(value, c, NULL);

        while (node != NULL && node->col < c)
        {
            prev = node;
            node = node->next;
        }

        /*in the middle*/
        if (node != NULL)
        {

        }
    }
}

// be able to write this function
static *new_Node(float value, int col, node_t *next)
{
    node_t *node;
    node = (node_t *)malloc(sizeof(node_t)); // check this

    if (node == NULL)
    {
        fprintf(stderr, "Memory allocation error");
        exit(EXIT_FAILURE);
        node->f = value;
        node->col = col;

        node->next = next;

        return node;
    }
}
