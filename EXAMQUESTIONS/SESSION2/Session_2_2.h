#ifndef _SESSION_2_2
#define _SESSION_2_2

#include <stdlib.h>
#include <stdio.h>

typedef struct node_s
{
    int col;
    float value;
    struct node_s *next;
} node_t;

typedef struct list_s
{
    int ne;
    node_t *next;
} list_t;

typedef struct matr_s
{
    int nr;
    int nc;
    list_t *rows;
} matr_t;

#endif