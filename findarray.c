#include <stdio.h>
#include <stdlib.h>

int cmpfunc(const void* a, const void* b)
{
    return (*(int*)b - *(int*)a);
}

void kElement(int arr[], int n, int k)
{
    qsort(arr, n, sizeof(int), cmpfunc);
    for (int i = 0; i < k; i++)
    printf("%d ", arr[i]);
}
int main()
{
    int arr[] = { 1, 7, 3, 8, 2, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    kElement(arr, n, k);

}
