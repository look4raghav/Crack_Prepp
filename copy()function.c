#include <stdio.h>
#define MAX_LINE_LEN 1000

void main(int argc, char* argc[])
{
    char* file_path_from;
    char* file_path_to;
    FILE* f_from;
    FILE* f_to;
    char buf[MAX_LINE_LEN+1];


    file_path_from = "<somethinggg_somethingggg>";
    file_path_to = "<kuch kuchh>";

    f_from = fopen(file_path_from, "r");
    if(!f_from) 
    {
        exit(1);
    }

    f_to = fopen(file_path_to, "w++");
    if(!f_to)
    {
        exit(1);
    }

    while(fgets(buf, MAX_LINE_LEN+1, f_from))
    {
        if(fputs(buf, f_to) == EOF)
        {
            exit(1);
        }
    }
    if(!feof(f_from))
    {
        exit(1);
    }
    if(fclose(f_from) == EOF)
    {
        exit(1);
    }
    if(fclose(f_to) == EOF)
    {
        exit(1);
    }
    return 0;
}

/**/