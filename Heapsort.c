#include <stdio.h>
#include <stdlib.h>

int max_compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int min_compare(const void *a, const void *b) {
    return (*(int*)b - *(int*)a);
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        printf("%d ",arr[i]);
    }

    printf("\n");
}

int main() {

    //READ IN ARRAY
    int arr[5];
    int i = 0;

    printf("Please input an array to sort: ");

    while (i < 5) {
        scanf("%d",&arr[i]);
        ++i;
    }

    int n = sizeof(arr)/sizeof(arr[0]);

    //SORT ARRAY INTO MAX HEAP
    qsort(arr, n, sizeof(int), max_compare);
    //PRINT
    printArray(arr, n);

    //SORT ARRAY INTO MAX HEAP
    qsort(arr, n, sizeof(int), min_compare);
    //PRINT
    printArray(arr, n);

    return 0;
}