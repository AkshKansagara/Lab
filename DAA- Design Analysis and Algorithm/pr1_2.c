
#include <stdio.h>
#include <time.h> // For time analysis
// Function to perform binary search (assumes array is sorted in ascending order)
int binary_search(int arr[], int low, int high, int target) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (arr[mid] == target) {
            return mid;  // Return index of the target element
        } else if (arr[mid] < target) {
            low = mid + 1;  // Target is in the right half
        } else {
            high = mid - 1;  // Target is in the left half
        }
    }
    return -1;  // Target element not found
}
// Main function to test binary search
int main() {
    int n, target;
    clock_t start, end;   
    // Input number of elements in array
    printf("Enter number of elements in array: ");
    scanf("%d", &n);
    
    int arr[n];  // Declare array of size n
    // Input sorted array elements
    printf("Enter %d sorted elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    // Input target element to search
    printf("Enter target element to search: ");
    scanf("%d", &target);
    // Start clock for time analysis
    start = clock();
    // Perform binary search
    int index = binary_search(arr, 0, n - 1, target);
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