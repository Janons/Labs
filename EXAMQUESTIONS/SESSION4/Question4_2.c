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
    node_t *newNode, *head;
    newNode = createNode();

    if (head->next == NULL)
    {
        
    }
}

char *split_string(char *str)
{
    int lenght = sizeof(str) % (sizeof(str[0]));
    int i, j;

    while (i < sizeof(str) - 1)
    {
        j = i + 1;
        while (j < lenght && str[j] == str[i])
        {
            j++;
        }
    }
}

node_t *createNode()
{
    node_t *newNode;
    newNode = (node_t *)malloc(sizeof(node_t));
    if (newNode == NULL)
    {
        fprintf(stdout, "The memory couldn't be allocated");
        return EXIT_FAILURE;
    }

    return newNode;
}