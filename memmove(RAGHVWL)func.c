#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *mymemmove(void *dest, const void *src, size_t count);

int main(int argc, char* agrv[])
{
    char *p1, *p2;
    char *p3, *p4;
    int size;

    printf("\n----------\n");
    p1 = (char *) malloc(12);
    size=10;
    strcpy(p1,"RAGHVWL");
    p2 = p1 + 2;
    printf("\n----------\n");
    printf("\nFrom (before) = [%s]", p1);
    printf("\nTo (before) = [%s]", p2);
    
    mymemmove(p2,p1,size);

    printf("\n\nFrom (after) = [%s]", p1);
    printf("\nTo (before) = [%s]", p2);
    printf("\n----------\n");

    p3 = (char *) malloc(12);
    memset(p3,12,'\0');
    p4 = p3+2;

    strcpy(p4, "RAGHVWL");
    printf("\nFrom (before) = [%s]", p4);
    printf("\nTo (before) = [%s]", p3);

    mymemmove(p3,p4,size);

    printf("\n\nFrom (after) = [%s]", p4);
    printf("\nTo (after) = [%s]", p3);
    printf("\n-------------\n");

    p1 = (char *) malloc(30);
    memset(p1,30,'\0');
    size = 10;

    strcpy(p1, "RAGHVWL");
    p2 = p1+15;
    printf("\n--------------------\n");
    printf("\nFrom (before) = [%s]", p1);
    printf("\nTo (before) = [%s]", p2);
    mymemmove(p2,p1,size);
    printf("\n\nFrom (after) = [%s]", p1);
    printf("\nTo (after) = [%s]", p2);
    printf("\n---------------\n");
    printf("\n\n");
    return 0;
}

void *mymemmove(void *to, const void *from, size_t size)
{
    unsigned char *p1;
    const unsigned char *p2;

    p1 = (unsigned char *) to;
    p2 = (const unsigned char *) from;

    p2 = p2+size;
    while (p2 != from && --p2 != to);

    if(p2!=from)
    {
        p2 = (const unsigned char *) from;
        p2 = p2 + size;
        p1 = p1 + size;

        while (size-- != 0)
        {
            *--p1 = *--p2;
        }
    }
    else
    {
        while (size-- != 0)
        {
            *p1++ = *p2++;
        }
    }
    return(to);
}