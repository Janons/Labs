#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*define the variable*/
#define MAXCHAR 50

/*struct for the list*/
typedef struct lists_s
{
    char *name[MAXCHAR];
    char *personalIdentification[16];
    char *arrayofDates[8];
    int salaries;

    struct list_s *left, *right;

} list_t;

/*prototype for the list*/
list_t *createList(char *, list_t *head);
list_t *pushtNodes(list_t *head, int val);
list_t *newNode();
void movebetweennodes(char *command);
void freeList(list_t *head);
void displayResult(list_t *head);

/*main function*/

int main(int argc, char *argv[])
{
    list_t *head = NULL;

    head = createList(argv[1], head);

    return 0;
}
/*creating the list and connecting the nodes with each other*/
list_t *createList(char *File_in_Name, list_t *head)
{
    FILE *fin;

    fin = fopen(File_in_Name, "r");
}

//first our nodes starts as if its surroundings are empty too
list_t *pushNodes(list_t *head, int val)
{
    list_t *newPointer;

    newPointer = new_element();

    newPointer->right = NULL;
    newPointer->left = NULL;
}
list_t *newNode()
{

    list_t *node_ptr;
    node_ptr = (list_t *)malloc(sizeof(list_t));
    if (node_ptr == NULL)
    {
        fprintf(stderr, "Memory allocation error.\n");
        exit(-1);
    }
    return (node_ptr);
}