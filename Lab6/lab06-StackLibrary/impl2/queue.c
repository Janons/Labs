#include <stdio.h>
#include <stdlib.h>
#include "queuePrivate.h"
#include "util.h"

/*create new empty queueu*/

queue_t *queue_init(int size)
{
    queue_t *sp;
    sp = (stack_t *)util_malloc(sizeof(stack_t));
    sp->tail = NULL;
    sp->num = 0;

    return sp;
}

/*return the number of elements form the queue*/
int queue_count(queue_t *sp)
{

    return (sp != NULL) ? sp->num : 0;
}

/*store a new value in queueu (FIFO Policy)*/
int queue_enqueue(queue_t *sp, void *data)
{
    node_t *node;

    if (sp == NULL)
    {
        return 0;
    }
    node = (node_t *)util_malloc(sizeof(node_t));
    node->data = data;
    if (sp->tail == NULL)
    {
        sp->tail = node;
        sp->tail->next = sp->tail;
    }
    node->next = sp->tail->next;
    sp->tail->next = node;
    sp->tail = node;
    sp->num++;

    return 1;
}

int queue_dequeue(queue_t *sp, void **data)
{
    queue_t *old;
    if (sp->tail != NULL)
    {

        if (sp->tail->next = sp->tail)
        {
            data = sp->tail->data;
            free(sp->tail);
        }
        else
        {
            old = sp->tail->next;
            sp->tail->next = old->tail->next;
            free(old);


        }
    }
}
