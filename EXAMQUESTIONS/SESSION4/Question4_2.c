#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*definitions*/
#define USESTRCPY 1

/*struct*/

typedef struct node
{
    char *str;
    struct node *next;

} node_t;
/*prototypes*/
node_t *string_split(char *str);
char *split_string(char *str);
node_t *createNode();

int main()
{
    return 0;
}

node_t *string_split(char *str)
{
    node_t *strHolder, *top;

    int starting_index, ending_index;

    while (ending_index < strlen(str))
    {

        while (ending_index < strlen(str) && str[ending_index] != '.')
        {
            ending_index++;
        }

        strHolder = (node_t *)malloc(sizeof(node_t));
        if (strHolder == NULL)
        {
            fprintf(stdout, "Error in allocating memory for the string holder");
            return EXIT_FAILURE;
        }
        strHolder->str = malloc((ending_index - starting_index + 1) * sizeof(char));
    }

#if USESTRCPY
    strncpy(strHolder->str, &str[starting_index], (ending_index - starting_index));

#endif

    strHolder->next = top;
    top = strHolder;

    return top;
}
