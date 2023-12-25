#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX 20

/*struct*/

typedef struct list_s
{
    char *name;
    char *surname;
    struct list_s *next;
} list_t;

/*prototype*/
int list_insert_in_oder(list_t **headp, char *name, char *surname);

int main()
{
    return 0;
}

int list_insert_in_oder(list_t **headp, char *name, char *surname)
{
    list_t *node, *head, *ptr;

    /*initial search*/

    head = *headp;

    for (node = head; node != NULL; node = node->next)
    {
        if (strcmp(node->surname, surname) == 0 && strcmp(node->name, name) == 0)
        {
            return EXIT_FAILURE;
        }
    }

    /*since the search didnt find a match, allocate memory for the node*/
    node = (list_t *)malloc(sizeof(list_t));
    if (node == NULL)
    {
        fprintf(stderr, "Error in allocating memory\n");
        return EXIT_FAILURE;
    }

    /*head check*/
    if (node->next = NULL || strcmp(surname, head->surname) < 0 || (strcmp(surname, head->surname) == 0 && strcmp(name, head->name) < 0))
    {
        node->next = head;
        *headp = node;

        return 1;
    }
}