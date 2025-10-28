#include <stdio.h>

// Recursive Binary Search Function
int recursiveBinarySearch(int array[], int start_index, int end_index, int element) {
    if (end_index >= start_index) {
        int middle = start_index + (end_index - start_index) / 2;
        if (array[middle] == element)
            return middle;
        if (array[middle] > element)
            return recursiveBinarySearch(array, start_index, middle - 1, element);
        return recursiveBinarySearch(array, middle + 1, end_index, element);
    }
    return -1;
}

// Non-Recursive Binary Search Function
int nonRecursiveBinarySearch(int array[], int n, int element) {
    int start_index = 0;
    int end_index = n - 1;

    while (start_index <= end_index) {
        int middle = start_index + (end_index - start_index) / 2;
        if (array[middle] == element)
            return middle;
        if (array[middle] < element)
            start_index = middle + 1;
        else
            end_index = middle - 1;
    }
    return -1;
}

int main(void) {
    int n, element;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int array[n];
    printf("Enter %d elements in sorted order:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    printf("Enter the element to search: ");
    scanf("%d", &element);

    // Using Recursive Binary Search
    int found_index_recursive = recursiveBinarySearch(array, 0, n - 1, element);
    if (found_index_recursive == -1) {
        printf("Recursive: Element not found in the array.\n");
    } else {
        printf("Recursive: Element found at index: %d\n", found_index_recursive);
    }

    // Using Non-Recursive Binary Search
    int found_index_non_recursive = nonRecursiveBinarySearch(array, n, element);
    if (found_index_non_recursive == -1) {
        printf("Non-Recursive: Element not found in the array.\n");
    } else {
        printf("Non-Recursive: Element found at index: %d\n", found_index_non_recursive);
    }

    return 0;
}
