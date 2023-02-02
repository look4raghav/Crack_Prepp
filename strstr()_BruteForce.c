#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void BruteForce(char *x, int m, char *y, int n)
{
    int i, j;
    printf("\nstring : [&s]"
            "\nlength : [&d]"
            "\npattern : [&s]"
            "\nlength : [&d]\n\n", y,n,x,m);

    for (j=0; j<=(n-m); ++j)
    {
        for (i = 0; i < m && x[i] == y[i + j]; ++i);
        if (i >= m)
        {
            printf("\nMatch found at\n\n->[%d]\n->[%s]\n",j,y+j);
        }
    }
}

int main()
{
 char *string = "hereroheroero";
 char *pattern = "hero";
 BF(pattern,strlen(pattern),string,strlen(string));
 printf("\n\n");

 return(0);
} 