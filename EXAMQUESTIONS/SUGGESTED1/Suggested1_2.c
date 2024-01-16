#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct element
{
    int key;

    struct element *next;
};
void parse_and_insert(char *s, struct element **p);
void createNode();

int main()
{

    return 0;
}

void parse_and_insert(char *s, struct element **p)
{
    char *token;
    struct element *node;

    /*get the first token*/
    token = strtok(s, " ");

    /*insert the first token*/
    
}