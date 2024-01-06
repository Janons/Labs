#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*CORRECT IN FIRST TRY ✅*/

/*tree structure*/
typedef struct node
{
    int key;
    char *name;
    char *surname;
    struct node *l, *r;
} node_t;

void pre_order(node_t *);
void in_order(node_t *);
void post_order(node_t *);

int main()
{
    return 0;
}

/*pre_order solution*/

void pre_order(node_t *root)
{

    if (root == NULL)
    {
        return;
    }

    printf("%d %s %s", root->key, root->name, root->surname);
    pre_order(root->l);
    pre_order(root->r);
}

/*In-Order Solution*/
void in_order(node_t *root)
{
    if (root == NULL)
        return;

    pre_order(root->l);
    printf("%d %s %s", root->key, root->name, root->surname);
    pre_order(root->r);
}

void post_order(node_t *root)
{
    if (root == NULL)
        return;

    pre_order(root->l);
    pre_order(root->r);
    printf("%d %s %s", root->key, root->name, root->surname);
}