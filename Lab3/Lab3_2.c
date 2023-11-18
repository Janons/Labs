#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*define the variable*/
#define MAXCHAR 50
#define MAXARRAY 8
#define IDENTIFICATION 16

/*struct for the list*/
typedef struct Node_t_movement
{
    char *name;
    char personalidentification[IDENTIFICATION];
    char arrayofdates[MAXARRAY];
    int salary;
    struct Node_Movement *next;
    struct Node_Movement *prev;

} Node_t;

/*prototype for the list*/
Node_t *createNode(char name, char identification, char arrayofdate, int salary);
Node_t *createList(char *File_in_Name, Node_t *head);
void *InsertNodeAtHead(Node_t *head, Node_t *newNode);

/*main function*/

int main(int argc, char *argv[])
{
    Node_t *head = NULL;

    // Memory allocation for the head

    head = createList(argv[1], head);

    Node_t *temp = head;

    return 0;
}
/*creating the list and connecting the Node_ts with each other*/
Node_t *createList(char *File_in_Name, Node_t *head)
{
    FILE *fin;
    Node_t *new;

    char name[MAXCHAR];
    char personalIdentification[IDENTIFICATION];
    char arrayofDate[MAXARRAY];
    int salaries;
    int i=0;

    fin = fopen(File_in_Name, "r");

    if (fin == NULL)
    {
        perror("Error in parsing the file");
        return NULL;
    }

    while (fscanf(fin, "%s %s %s %d", name, personalIdentification, arrayofDate, &salaries))
    {
        i++;
    }
}

Node_t *createNode(char name, char identification, char arrayofdate, int salary)
{

    Node_t *Node_t_ptr;
    Node_t_ptr = (Node_t *)malloc(sizeof(Node_t));
    if (Node_t_ptr == NULL)
    {
        fprintf(stderr, "Memory allocation error.\n");
        exit(-1);
    }

    strcpy(*Node_t_ptr, name);
    strcpy(*Node_t_ptr, identification);
    strcpy(*Node_t_ptr, arrayofdate);
    Node_t_ptr->salary = salary;

    Node_t_ptr->prev = NULL;
    Node_t_ptr->next = NULL;

    return (Node_t_ptr);
}
