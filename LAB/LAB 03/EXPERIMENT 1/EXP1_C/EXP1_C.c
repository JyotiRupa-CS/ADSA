#include <stdio.h>

// Function to find median of three elements and return its index
int medianOfThree(int array[], int low, int mid, int high) {
    printf("Choosing median among: %d (low), %d (mid), %d (high)\n", array[low], array[mid], array[high]);

    if ((array[low] > array[mid]) != (array[low] > array[high]))
        return low;
    else if ((array[mid] > array[low]) != (array[mid] > array[high]))
        return mid;
    else
        return high;
}

// Partition function using median pivot
int partition(int array[], int low, int high) {
    int mid = low + (high - low) / 2;
    int medianIndex = medianOfThree(array, low, mid, high);

    printf("Median selected: %d at index %d\n", array[medianIndex], medianIndex);

    // Swap median element with the last element to use it as pivot
    int temp = array[medianIndex];
    array[medianIndex] = array[high];
    array[high] = temp;

    int pivot = array[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (array[j] < pivot) {
            i++;
            // Swap array[i] and array[j]
            int t = array[i];
            array[i] = array[j];
            array[j] = t;
        }
    }
    // Swap pivot to its correct position
    temp = array[i + 1];
    array[i + 1] = array[high];
    array[high] = temp;

    printf("Partitioned array: ");
    for (int k = low; k <= high; k++)
        printf("%d ", array[k]);
    printf("\n\n");

    return i + 1;
}

// Quick Sort function
void quickSort(int array[], int low, int high) {
    if (low < high) {
        int pi = partition(array, low, high);
        quickSort(array, low, pi - 1);
        quickSort(array, pi + 1, high);
    }
}

// Function to print the entire array
void printArray(int array[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", array[i]);
    printf("\n");
}

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int array[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &array[i]);

    printf("\nStarting Quick Sort with median-of-three pivot:\n\n");
    quickSort(array, 0, n - 1);

    printf("Sorted array:\n");
    printArray(array, n);

    return 0;
}
