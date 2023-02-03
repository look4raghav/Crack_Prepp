#include <stdio.h>

/*  size_t strlen(const char *string) */

int my_strlen(char *s)
{
    char *p=s;

    while(*p!='\0')
    p++;

    return 0;
}