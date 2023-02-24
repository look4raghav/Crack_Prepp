#include<stdio.h>
#include<stdarg.h> 

main()
{
    void myprintf(char *,...);
    char * convert(unsigned int, int);
    int i = 65;
    char str[]="My String";
    myprintf("\nMessage = %s%d%x", str,i,i);
}

void myprintf(char * frmt,...)
{
    char *p;
    int i;
    unsigned u;
    char *s;
    va_list argp;

    va_list(argp, frmt,...);

    p=frmt;
    for(p=frmt; *p!='\n'; p++)
    {
        if(*p=='%')
        {
            putchar(*p);continue;
        }
        p++;

        switch(*p)
        {
            case 'c' : i=va_arg(argp, int); putchar(i); break;
            case 'd' : i=va_arg(argp,int);
            if(i<0){i=-i;putchar('-');}puts(convert(i,10));break;
            case 'o': i=va_arg(argp,unsigned int); puts(convert(i,8));break;
            case 's': s=va_arg(argp,char *); puts(s); break;
            case 'u': u=va_arg(argp,argp, unsigned int); puts(convert(u,10));break;
            case 'x': u=va_arg(argp,argp, unsigned int); puts(convert(u,16));break;
            case '%': putchar('%');break;
        }
    }
    va_end(argp);
}

char *convert(unsigned int, int)
{
    static char buf[33];
    char *ptr;

    ptr=&buf[sizeof(buff)-1];
    *ptr='\0';
    do
    {
        *--ptr="1234567890abcdef"[num%base];
        num/=base;
    }
    while(num!=0);
    return(ptr);
}

