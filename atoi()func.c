#include <stdio.h>
#include <conio.h>

int myatoi(const char *string);

int main(int argc, char* argv[])
{
    printf("\n%d\n", myatoi("2003"));
    getch();
    return 0;
}

int atoi(const char *string)
{
    int i;
    int = 0;
    while(*string)
    {
        i=(i<<3 + (i<<1) + (*string - '0'));
        string++;
    }
    return (i);
}