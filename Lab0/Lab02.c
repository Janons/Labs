#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*defining parts*/
#define MAX_ID (4 + 1)

/*strcut*/

typedef struct
{
    char word[MAX_ID];
    float x1, y1, x2, y2;

} rectangles_t;

/*prototypes*/
rectangles_t *rectangleRead(int *numt_ptr, char name1[]);

/*main*/
int main(int argc, char *argv[])
{
    rectangles_t *rectangle;
    int numberofrows;

    if (argc < 2)
    {
        perror("You have entered less arguments that you were supposed to");
        return EXIT_FAILURE;
    }

    printf("%s", argv[1]);

    rectangleRead(&numberofrows, argv[1]);

    free(rectangle);

    return EXIT_SUCCESS;
}

/*putting the values inside our dynamic rectangle structure*/
rectangles_t *rectangleRead(int *numt_ptr, char name1[])
{
    rectangles_t *rectangle;
    FILE *fin;

    char name[MAX_ID];
    float x1, y1, x2, y2;
    int n = 0;

    fin = fopen(name1, "r");
    if (fin == NULL)
    {
        perror("error in parsing the file");
        exit(1);
    }

    rectangles_t tempRect;
    int first_occurrence = 1;

    while (fscanf(fin, "%s %f %f", name, &x1, &y1) != EOF)
    {
        n++;
    }
    /*dynamic memory allocation*/
    rectangle = (rectangles_t *)malloc(n * sizeof(rectangles_t));
    if (rectangle == NULL)
    {
        fprintf(stderr, "Memory Allocation problem");
        exit(1);
    }

    rewind(fin); // Rewind the file to the beginning

    int i = 0;
    while (fscanf(fin, "%s%f%f", name, &x1, &x2) != EOF)
    {
        printf("%s\n", name);
        if (first_occurrence)
        {

            printf("Okkk");

            strcpy(tempRect.word, name);
            tempRect.x1 = x1;
            tempRect.y1 = y1;
            first_occurrence = 0;
        }
        else
        {
            // This is the second occurrence of the same ID
            if (strcmp(tempRect.word, name) == 0)
            {
                printf("yesssss");
                rectangle[i].x1 = tempRect.x1;
                rectangle[i].y1 = tempRect.y1;
                rectangle[i].x2 = x1;
                rectangle[i].y2 = y1;
                i++;
                first_occurrence = 1; // Reset for the next ID
            }
        }
    }

    fclose(fin);

    *numt_ptr = n;
    return rectangle;
}
