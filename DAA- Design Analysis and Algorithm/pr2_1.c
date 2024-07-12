#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j+1]
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int *arr, n, i;
    clock_t start, end;
    double cpu_time_used;

    printf("Enter the number of elements: ");
    scanf("%d", &n);
    // Allocate memory dynamically for array
    arr = (int *)malloc(n * sizeof(int));

    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    // Input elements
    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    // Record start time
    start = clock();
    // Perform bubble sort
    bubbleSort(arr, n);
    // Record end time
    end = clock();
    // Calculate time taken for sorting
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    // Output sorted array
    printf("\nSorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    // Output time taken
    printf("\nTime taken for sorting: %f seconds\n", cpu_time_used);
    // Free dynamically allocated memory
    free(arr);

    return 0;
}
