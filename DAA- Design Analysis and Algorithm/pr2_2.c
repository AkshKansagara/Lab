#include <stdio.h>
#include <stdlib.h>
#include <time.h> // For time analysis
// Function to perform Selection Sort
void selection_sort(int arr[], int n) {
    int min_idx;
    for (int i = 0; i < n - 1; i++) {
        min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        // Swap arr[i] and arr[min_idx]
        int temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
    }
}
// Function to print array elements
void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
// Main function to test Selection Sort with dynamic values insertion and time analysis
int main() {
    int n;
    clock_t start, end;   
    // Input number of elements in array
    printf("Enter number of elements in array: ");
    scanf("%d", &n);

    int arr[n];  // Declare array of size n
    // Input array elements
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    // Print unsorted array
    printf("Unsorted array: ");
    print_array(arr, n);
    // Start clock for time analysis
    start = clock();
    // Perform Selection Sort
    selection_sort(arr, n);
    // End clock for time analysis
    end = clock();
    // Print sorted array
    printf("Sorted array: ");
    print_array(arr, n);
    // Calculate time taken for sorting
    double time_taken = ((double) (end - start)) / CLOCKS_PER_SEC;
    
    printf("Time taken for sorting: %f seconds\n", time_taken);
    
    return 0;
}