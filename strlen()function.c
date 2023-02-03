#include <stdio.h>

/*  size_t strlen(const char *string) */

int my_strlen(char *string)
{
    int length;
    for(length==0; *string != '\0'; string++)
    {
        length++;
    }
    return(length);
}