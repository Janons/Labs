#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*variable definitions*/
#define MAXROWS 1000

/*struct for list*/
typedef struct lists_s
{
    char *word;
    int count;

    struct list_s *next;
} list_t;

/*prototypes*/
list_t *readInputFIle(char *name, list_t *head);
list_t *newElement();
list_t *push(list_t *head, char *);
list_t *incrementTheOccurencies(list_t *head, char *string);
void displayTheResults();

/*main function*/

int main(int argc, char *argv[])
{
    list_t *head = NULL;

    return 0;
}

/*functions*/
list_t *readInputFIle(char *name, list_t *head)
{
    FILE *fin;
    list_t *temp;
    char maxstring[MAXROWS];
    int counter, i;

    fin = fopen(name, 'r');
    if (fin == NULL)
    {
        perror("Error in opening the file");
    }

    while (fscanf(fin, "%s", maxstring) != EOF)
    {
        temp = incrementTheOccurencies(head, maxstring);

        if (temp != NULL)
        {
            temp->count++;
        }
        else
        {
            head = push(head, maxstring); // creating the nodes with the
        }
    }
}

list_t *push(list_t *head, char *word)
{
    list_t *list_Pointer;

    list_Pointer = newElement();
    strcpy(list_Pointer->word, word);
    list_Pointer->count = 1;

    // doing the pushing part for the head
    list_Pointer->next = head;
    head = list_Pointer;

    return head;
}

list_t *incrementTheOccurencies(list_t *head, char *word)
{
    list_t *tmpP;
    int found = 0;

    tmpP = head;

    while (tmpP != NULL)
    {
        found = strcmp(tmpP->word, word) == 1;
        if (found == 1)
            break;
        tmpP = tmpP->next;
    }

    if (found == 0)
    {
        tmpP = NULL;
    }

    return (tmpP);
}

list_t *newElement()
{

    list_t *e_ptr;
    e_ptr = (list_t *)malloc(sizeof(list_t));
    if (e_ptr == NULL)
    {
        fprintf(stderr, "Memory allocation error.\n");
        exit(-1);
    }
    return (e_ptr);
}