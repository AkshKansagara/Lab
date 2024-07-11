#include <stdio.h>
#include <time.h> // For time analysis
// Function to perform linear search
int linear_search(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i;  // Return the index of the target element
        }
    }
    return -1;  // Target element not found
}
// Main function to test linear search
int main() {
    int n, target;
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
    // Input target element to search
    printf("Enter target element to search: ");
    scanf("%d", &target);
    // Start clock for time analysis
    start = clock();
    // Perform linear search
    int index = linear_search(arr, n, target);
    // End clock for time analysis
    end = clock();
    // Calculate time taken for search
    double time_taken = ((double) (end - start)) / CLOCKS_PER_SEC;
    if (index != -1) {
        printf("Element found at index: %d\n", index);
    } else {
        printf("Element not found\n");
    }
    printf("Time taken: %f seconds\n", time_taken);

    return 0;
}