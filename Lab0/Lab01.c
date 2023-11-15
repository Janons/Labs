#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define NumberOfLines 100
#define NumberOfwords 400

#define filein "words.txt"
#define filesearch "wordsTosearch.txt"

typedef struct
{
    char word[NumberOfLines + 1];
    int occurences;
} index_t;

/*prototypes*/

void readFileIntoTheword(index_t wordsArray);

int main()

{
    index_t wordsArray;
    int i;

    strcpy(wordsArray.word, "");

    for (i = 0; i <= sizeof(wordsArray.occurences); i++)
    {
        wordsArray.occurences[i] = 0;
    }

    readFileIntoTheword(wordsArray);

    return 0;
}

void readFileIntoTheword(index_t wordsArray)
{
    FILE *fin, *fsearch;
    char line[100];
    int i = 0, j;

    fin = fopen(filein, "r");
    if (fin == NULL)
    {
        perror("error in parsing the file");
        exit(1);
    }

    fsearch = fopen(filesearch, "r");
    if (fsearch == NULL)
    {
        perror("error in parsing the file");
        exit(1);
    }

    while (fgets(wordsArray.word, 20, fsearch) != NULL && i <= 100)
    {
        i++;

        while (fgets(line, sizeof(line), fin) != NULL)
        {
            char *token = strtok(line, " ");

            while (token != NULL)
            {
                printf("%s/n", token);

                if (strcmp(token, wordsArray.word) == 0)
                {
                    wordsArray.occurences[i]++;
                }
            }
        }
    }
}

