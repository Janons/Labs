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

    node = new_element();
    head = *headP;

    node -> surname = strdup(surname);
    node -> name = strdup(name);
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