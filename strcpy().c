#include <stdio.h>

char *mystrspy(char *dst, const char *src)
{
    char *ptr;
    ptr = dst;
    while(*dst++=*src++);
    return(ptr);
}