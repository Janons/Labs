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
list_t *pushNode(list_t *head, list_t *newNode);
list_t *createNode();

/*main function*/

int main(int argc, char *argv[])
{
    list_t *head = NULL;

    // Memory allocation for the head

    head = createList(argv[1], head);

    list_t *temp = head;

    while (temp != NULL)
    {
        printf("%s->", temp->name);
        temp = temp->right;
    }

    // Free allocated memory
    temp = head;
    while (temp != NULL)
    {
        list_t *next = temp->right;
        free(temp);
        temp = next;
    }

    return 0;
}
/*creating the list and connecting the nodes with each other*/
list_t *createList(char *File_in_Name, list_t *head)
{
    FILE *fin;
    list_t *new;

    char name[MAXCHAR];
    char personalIdentification[16];
    char arrayofDate[8];
    int salaries;

    fin = fopen(File_in_Name, "r");

    if (fin == NULL)
    {
        perror("Error in parsing the file");
        return NULL;
    }

    while (fscanf(fin, "%s %s %s %i", name, personalIdentification, arrayofDate, &salaries) != EOF)
    {
        new = createNode();
        strcpy(*new->name, name);
        strcpy(*new->personalIdentification, personalIdentification);
        strcpy(*new->arrayofDates, arrayofDate);
        new->salaries = salaries;

        head = pushNode(head, new);
    }
    fclose(fin);
    return head;
}

list_t *pushNode(list_t *head, list_t *newNode)
{

    if (head == NULL)
    {
        newNode->left = NULL;
        newNode->right = NULL;
    }

    newNode->right = head->right;
    newNode->left = NULL;


    return head;
}

list_t *createNode()
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