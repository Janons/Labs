#ifndef _QUEUEUPUBLIC
#define _QUEUEUPUBLIC

#include <stdio.h>

/*Macro Definition*/
#define queue_empty_m(sp) (stack_count(sp) == 0)

/*type declarations*/
typedef struct queue queue_t;

/*extern function prototypes*/
extern queue_t *queue_init(int size);
extern int queue_enqueue(queue_t *sp, void *data);
extern int queue_dequeue(queue_t *sp, void *data_ptr);
extern int queue_count(queue_t *sp);
extern void queue_dispode(queue_t*tail, void(*quit)(void*));

#endif