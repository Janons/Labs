#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    node_t *newNode, *top;

    int starting_index, ending_index;

    int lenghtOftheString = (sizeof(str) % sizeof(str[0]));
    char *strHolder;

    while (starting_index < lenghtOftheString || ending_index < lenghtOftheString)
    {

        while (str[ending_index] != '.' && str[ending_index] == str[starting_index])
        {
            ending_index++;
        }

        strHolder = (char *)malloc((ending_index - starting_index) * sizeof(char));

       
    }
}

/*creating the node part*/
node_t *createNode(int size)
{
    node_t *newNode;
    newNode = (node_t *)malloc(size * sizeof(node_t));
    if (newNode == NULL)
    {
        fprintf(stdout, "The memory couldn't be allocated");
        return EXIT_FAILURE;
    }

    return newNode;
}