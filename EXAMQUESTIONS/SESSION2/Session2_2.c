#include "Session_2_2.h"

/*writing the prof's solution without looking*/

/*prototypes*/
static *new_Node(float value, int col, node_t *next);
void mat_insert(matr_t *mat, int r, int c, float value);

int main()
{
}

/*normal list insertion*/
void mat_insert(matr_t *mat, int r, int c, float value)
{
    node_t *node, *prev;
    int overwrite = 0;

    /*head insertion*/

    if (mat->rows->ne == 0)
    {
        /*inserting the first element ever*/
        mat->rows[r].next = new_Node(value, c, NULL);
    }
    else
    {
        /*sorted insert*/
        node = mat->rows[r].next;
        prev = NULL;
        while (node != NULL && node->value < value)
        {
            prev = node;
            node = node->next;
        }

        if (prev->value == value)
        {
            overwrite = 1;
            mat->rows[r][
        }
    }
}

static *new_Node(float value, int col, node_t *next)
{
    node_t *node;

    node = (node_t *)malloc(col * sizeof(node_t));
    if (node == NULL)
    {
        fprintf(stdout, "Error in allocating node memory");
        return EXIT_FAILURE;
    }

    node->value = value;
    node->col = col;
    node->next = next;

    return node;
}