#include <stdio.h>

int toUpper(int ch)
{
    if(ch>='a' && ch<='z')
    return('A' + ch - 'a');
    else
    return(ch);
}

/**/