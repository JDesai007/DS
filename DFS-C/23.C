#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define MAX 10

int getMax(int arr[], int n) {
    int max = arr[0];
    int i;
    for (i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

void countingSort(int arr[], int n, int exp) {
    int *output = (int *)malloc(n * sizeof(int));
    int count[10] = {0};
    int i;

    for (i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }

    for (i=1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (i = 0; i < n; i++) {
        arr[i] = output[i];
    }

    free(output);  // Free dynamically allocated memory
}

void radixSort(int arr[], int n) {
    int max = getMax(arr, n);
    int exp;
    for (exp = 1; max / exp > 0; exp *= 10) {
        countingSort(arr, n, exp);
    }
}

void printArray(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void main() {
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr) / sizeof(arr[0]);

    clrscr();
    printf("Original Array: \n");
    printArray(arr, n);

    radixSort(arr, n);

    printf("\nSorted Array: \n");
    printArray(arr, n);

    getch();
}
