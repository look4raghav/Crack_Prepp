#include <stdio.h>
#include <limits.h>
#include <string.h>

#define UPPER "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define LOWER "abcdefghijklmnopqrstuvwxyz"

int toUpper(int c)
{
    const char *upper;
    const char *const lower = LOWER;

    upper = (((CHAR_MAX >= c)&&(c>'\0')) ?strchr(lower, c) : NULL);
    return((upper != NULL)?UPPER[upper - lower] : c);
}