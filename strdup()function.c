#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *mystrdup(char *s)
{
    char *result = (char*)malloc(strlen(s)+1);
    if(result == (char*)0)
    {
        return (char*)0;
    }
    strcpy(result, s);
    return result;
}
