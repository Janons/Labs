#ifndef _QUEUEPRIVATE
#define QUEUEPRIVATE

#include <stdio.h>
#include "queuePublic.h"
#include "util.h"

/*structure declarations*/

typedef struct node
{
    void *data;
    struct node *next;
} node_t;

struct queue
{
    node_t *tail;
    int num;
};

#endif