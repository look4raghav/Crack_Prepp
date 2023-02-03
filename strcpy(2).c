#include <stdio.h>

char *my_strspy(char dest[], const char src[])
{
    int i = 0;
    while (source[i] != '\0')
    {
        dest[i] = source[i];
        i++;
    }
    dest[i] = source[i];
    return(dest);
}