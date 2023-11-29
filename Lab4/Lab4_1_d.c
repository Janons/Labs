#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int countSpaces(char *s);

int main()

{
    int n;
    char str[] = "This is a string with spaces!";

    n = countSpaces(str);

    fprintf(stdout, "The Number of empty Spaces -> %d\n", n);
}

int countSpaces(char *s)
{

    if (*s == '\0')
        return 0;

    else
        return ((isspace(*s) ? 1 : 0) + countSpaces(s+1));
}
