#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

void main() {
    int arr[] = { 4, 2, 5, 3, 1 };

    int n = sizeof(arr) / sizeof(arr[0]);
    int i,j;
    clrscr();

    printf("\nArray Elements is:  ");
    for(j=0;j<n;j++)
    {
	printf("%d ",arr[j]);
    }
    qsort(arr, n, sizeof(int), compare);

    printf("\n\nSorted Array is:  ");
    for (i = 0; i < n; i++)
	printf("%d ", arr[i]);

    getch();
}