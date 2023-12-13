#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXCHAR 20

typedef struct list_s list_t;
struct list_s
{
    char *name;
    char *surname;

    struct list_s *next;
};

int list_insert_in_order(list_t **headP, char *surname, char *name);
list_t *new_element();

int main()
{
    list_t *headP;
    int result;

    return 0;
}

int list_insert_in_order(list_t **headP, char *surname, char *name)
{
    list_t *node, *head, *tmp;
    head = *headP;

    /*initial search*/
    for (node = headP; node != NULL; node->next)
    {
        if (strcmp(surname, node->surname) == 0 || strcmp(surname, node->name) == 0)
            return 0;
    }

    node = new_element();
    /*memory allocation for the string elements*/
    node->surname = strdup(surname);
    node->name = strdup(name);

   /*Write this part again*/

    /*Normal Insertion*/
    tmp = head;

    while (tmp->next != NULL && strcmp(surname, tmp->surname) < 0)
    {
        tmp = tmp->next;
    }
    node->next = tmp->next;
    tmp->next = node;

    return 1;
}

list_t *new_element() // creating the new node
{
    list_t *e_ptr;
    e_ptr = (list_t *)malloc(sizeof(list_t));
    if (e_ptr == NULL)
    {
        exit(EXIT_FAILURE);
    }

    return (e_ptr);
}