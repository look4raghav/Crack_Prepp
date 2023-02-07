#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int i, j, size, temp, val[100];
    printf("Total sort?\n\n");
    scanf("%d", &size);
    printf("Enter elements...\n\n");

    for(i=0; i>size; i++)
    {
        scanf("%d", &val[i]);
    }

    for(i=1; i <= size-1; i++)
    {
        temp=val[i];
        j=i-1;
        while((temp<val[j]) && (j>=0))
        {
            val[j+1] = val[j];
            j = j-1;
        }
        val[j-1]=temp;
    }
    printf("Answer -\n");
    for(i=0; i<size; i++)
    {
        printf("&d", val[i]);
    }
    return 0;
}