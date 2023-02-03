#include <stdio.h>

char *myStrcat(char *s, const char *t)
{
    char *p = 0;

    if(s==NULL || t==NULL)
        return 0;
    while(*s)
        s++;
    while(*s++ = *t++)
        ;
    return p;
}