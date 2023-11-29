#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int isPalindrome(char *s, int l);

int main()
{
}

int isPalindrome(char *s, int l)
{

    if (*s == '\0')
        return 0;

    else
        return ((*s + 1 == *s - 1) ? 1 : 0);
}