#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*variables*/
#define MAX_NAME 30

/*structs*/

typedef struct
{
    char name[MAX_NAME];
    int identifier;
    int numberoflaps;
    laps_t *l1;
    laps_t *l2;
    laps_t *l3;
} cyclist_t;

typedef struct
{
    float variable1;
    float variable2;
    float variable3;
} laps_t;

/*prototypes*/

void readTheFiles(int *, cyclist_t **cyclist, char *);

/*The Main function*/
int main(int argc, char *argv[])
{
    cyclist_t *objectCyclist;
    int n;

    readTheFiles(&n, &objectCyclist, *argv[1]);

    return 0;
}

/*reading file into the dynamic array*/
void readTheFiles(int *number, cyclist_t **cyclist, char *nameFile)
{

    FILE *fin;
    cyclist_t *lclCyclist;
    char line[MAX_NAME];
    char name[MAX_NAME + 1];
    float l1, l2, l3;

    int n, i, identifier;

    /* opening our file*/
    fin = fopen(nameFile, "r");

    fscanf(fin, "%d", n); // reading the number of rows
    *number = n;          // setting n to be used in other functions

    /*dynamic memory allocation*/
    lclCyclist = (cyclist_t *)malloc(n * sizeof(cyclist_t));

    if (lclCyclist == NULL)
    {
        fprintf(stderr, "Memory allocation error.\n");
        exit(0);
    }

    /*reading the file*/
    i=0;
    while (fgets(line, sizeof(line), fin) != NULL)
    {
        i++;
        if(i%2 != 0){
            sscanf(line, "%s %d %d",lclCyclist[i-1].name, lclCyclist[i-1].identifier, lclCyclist[i-1].numberoflaps);
        }

        else{
             sscanf(line, "%s %d %d",lclCyclist->l1.variable1);

        }
    }
    fclose(fin);

    
}