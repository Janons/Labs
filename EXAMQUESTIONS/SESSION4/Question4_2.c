#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*definitions*/
#define USESTRCPY 1

/*struct*/

typedef struct node
{
    char *str1;
    struct node *next;

} node_t;

/*prototypes*/
node_t *string_split(char *str);

int main()
{

    return 0;
}

node_t *string_split(char *str)
{
    node_t *top, *node;

    int starting_index, ending_index;

    starting_index = 0, ending_index = 0;
    while (starting_index < strlen(str))
    {

        while (ending_index < strlen(str) && str[ending_index] != '.')
        {
            ending_index++;
        }

        /*memory allocation for the new node*/
        node = (node_t *)malloc(1 * sizeof(node_t)); // include the one
        if (node == NULL)
        {
            fprintf(stdout, "Error in allocating memory for the node");
            return EXIT_FAILURE;
        }
        node->str1 = malloc((ending_index - starting_index) * sizeof(node_t));
    }
#if USESTRCPY

    strncpy(node->str1, &str[starting_index], (ending_index - starting_index));

#endif

    /*insertion to top*/
    node->next = top;
    top = node;

    return top;
}