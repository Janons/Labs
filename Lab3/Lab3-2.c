#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXCHAR 50
#define MAXARRAY 8
#define IDENTIFICATION 16 + 1

typedef struct Node_t_movement
{
    char *name;
    char personalidentification[IDENTIFICATION];
    char arrayofdates[MAXARRAY];
    int salary;
    struct Node_t_movement *next;
    struct Node_t_movement *prev;
} Node_t;

Node_t *createList(char *File_in_Name, Node_t *head);
Node_t *InsertNodeAtHead(Node_t *head, Node_t *node);

int main(int argc, char *argv[])
{
    Node_t *head = NULL;

    head = createList(argv[1], &head);

    Node_t *temp = head;
    while (temp != NULL)
    {
        printf("%s ->", temp->personalidentification);
        temp = temp->next;
    }

    return 0;
}

Node_t *createList(char *File_in_Name, Node_t *head)
{
    FILE *fin;
    Node_t *tmpPnt;

    char name[MAXCHAR];
    char personalIdentification[IDENTIFICATION];
    char arrayofDate[MAXARRAY];
    int salaries;

    fin = fopen(File_in_Name, "r");
    if (fin == NULL)
    {
        perror("Error in parsing the file");
        return NULL;
    }

    while (fscanf(fin, "%s %s %s %d", name, personalIdentification, arrayofDate, &salaries) != EOF)
    {

        Node_t *Node_t_ptr = (Node_t *)malloc(sizeof(Node_t));
        if (Node_t_ptr == NULL)
        {
            fprintf(stderr, "Memory allocation error.\n");
            exit(EXIT_FAILURE);
        }
        Node_t_ptr->name = strdup(name);
        strcpy(Node_t_ptr->personalidentification, personalIdentification);
        strcpy(Node_t_ptr->arrayofdates, arrayofDate);
        Node_t_ptr->salary = salaries;

        head = InsertNodeAtHead(head, Node_t_ptr);
    }

    fclose(fin);

    return head;
}

// function used to insert the nodes at the head
Node_t *InsertNodeAtHead(Node_t *head, Node_t *newNode)
{

    newNode->prev = NULL;

    if (head == NULL)
    {
        newNode->next = NULL;
        head = newNode;
    }

    else
    {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    return head;
}
