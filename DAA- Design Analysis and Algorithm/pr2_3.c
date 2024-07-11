#include <stdio.h>
#include <stdlib.h>
#include <time.h> // For time analysis
// Function to swap two elements in an array
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
// Function to partition the array and return the pivot index
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Choose the last element as the pivot
    int i = (low - 1); // Index of smaller element
    
    for (int j = low; j <= high - 1; j++) {
        // If current element is smaller than or equal to pivot
        if (arr[j] <= pivot) {
            i++; // Increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
// Function to perform Quick Sort
void quick_sort(int arr[], int low, int high) {
    if (low < high) {
        // pi is partitioning index, arr[pi] is now at right place
        int pi = partition(arr, low, high);       
        // Separately sort elements before partition and after partition
        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}
// Function to print array elements
void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
// Main function to test Quick Sort with dynamic values insertion and time analysis
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
    // Perform Quick Sort
    quick_sort(arr, 0, n - 1);
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