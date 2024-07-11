#include <stdio.h>
#include <stdlib.h>
#include <time.h> // For time analysis
// Function to perform Bubble Sort
void bubble_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j + 1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
// Function to print array elements
void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
// Main function to test Bubble Sort and analyze time complexity
int main() {
    int n;
    clock_t start, end;   
    // Input number of elements in array
    printf("Enter number of elements in array: ");
    scanf("%d", &n);
    
    int arr[n];  // Declare array of size n
    // Generate random array elements
    srand(time(NULL));  // Seed for random number generation
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000;  // Random numbers between 0 and 999
    }
    // Print unsorted array
    printf("Unsorted array: ");
    print_array(arr, n);
    // Start clock for time analysis
    start = clock();
    // Perform Bubble Sort
    bubble_sort(arr, n);
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