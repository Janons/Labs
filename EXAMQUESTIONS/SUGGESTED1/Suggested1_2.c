#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct element
{
    char data[20];

    struct element *next;
} element;
void parse_and_insert(char *s, struct element **p);
void createNode();

int main()
{
    char input[] = "Split me okey";

   
    /*insert the values to the linked list*/

    return 0;
}

void parse_and_insert(char *s, struct element **p)
{
     /*split the string using strtok*/
    char *token = strtok(s, " ");

    struct element *head;

    head = NULL;


    /*get the first token*/
    token = strtok(s, " ");

    /*insert the first token*/
}