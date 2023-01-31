#include <stdio.h>

int atoi(const char* string)
{
    int value = 0;
    if(string)
    {
        while(*string && (*string <= '9' && *string >= '0'))
        {
            value = (value * 10)+(*string - '0');
            string++;
        }
    }
    return value;
}