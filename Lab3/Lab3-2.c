#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_R 255 + 1
#define MAXARRAY 8
#define IDENTIFICATION 16 + 1
#define MAX 21

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

    char line[MAX_R], name[MAX];

    fin = fopen(File_in_Name, "r");
    if (fin == NULL)
    {
        perror("Error in parsing the file");
        return NULL;
    }

    while (fgets(line, MAX_R, fin) != NULL)
    {
        tmpPnt = (Node_t *)malloc(sizeof(Node_t));
        if (tmpPnt == NULL)
        {
            printf("Allocation Error.\n");
            exit(EXIT_FAILURE);
        }
        sscanf(line, "%s %s %s %d",
               name, tmpPnt->personalidentification, tmpPnt->arrayofdates, &tmpPnt->salary);
        tmpPnt->name = strdup(name);
        head = InsertNodeAtHead(head, tmpPnt);
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
