#include <stdio.h>
int main()
{
int total, i, j, swapp;
int array[20];
printf("How many number you want to input?\n");
scanf("%d", &total);
printf("Please enter %d integers that has to be sorted\n", total);
for (i = 0; i < total; i++)
scanf("%d", &array[i]);
for (i = 0 ; i < total - 1; i++)
{
for (j = 0 ; j < total - i - 1; j++)
{
if (array[j] > array[j+1]) /* For decreasing order use < */
{
swapp      = array[j];
array[j]   = array[j+1];
array[j+1] = swapp;
}
}
}
printf("Below is the list of elements sorted in ascending order:\n");
for (i = 0; i < total; i++)
printf("%d\n", array[i]);
return 0;
}
































/*https://www.educba.com/sorting-in-c/*/