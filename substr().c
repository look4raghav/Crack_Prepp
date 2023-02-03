#include <stdio.h>
#include <conio.h>

void mySubstr(char *dest, char *src, int position, int length);

int main()
{
    char subStr[100];
    char str[]="My Name is Raghav Aggarwal.";
    mySubstr(subStr, str, 1, 5);
    printf("\nstr = [%s]"
            "\nsubStr = [%s]\n\n",
            str, subStr);
    getch();
    return 0;
}

void mySubstr(char *dest, char *src, int positionm int length)
{
    while(length>0)
    {
        *dest = *(src+position);
        dest++;
        src++;
        length--;
    }
}