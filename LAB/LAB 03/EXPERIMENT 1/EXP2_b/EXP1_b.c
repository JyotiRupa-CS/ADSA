#include <stdio.h>

// ======================== QUICK SORT =========================

// Partition function for Quick Sort
int partition(int array[], int low, int high) {
    int pivot = array[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (array[j] < pivot) {
            i++;
            // Swap array[i] and array[j]
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }
    // Swap array[i+1] and array[high] (pivot)
    int temp = array[i + 1];
    array[i + 1] = array[high];
    array[high] = temp;
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

// ======================== MERGE SORT =========================

// Merge function for Merge Sort
void merge(int array[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = array[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = array[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            array[k++] = L[i++];
        } else {
            array[k++] = R[j++];
        }
    }

    while (i < n1)
        array[k++] = L[i++];
    while (j < n2)
        array[k++] = R[j++];
}

// Merge Sort function
void mergeSort(int array[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(array, left, mid);
        mergeSort(array, mid + 1, right);
        merge(array, left, mid, right);
    }
}

// ======================== HEAP SORT =========================

// Heapify function for Heap Sort
void heapify(int array[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && array[left] > array[largest])
        largest = left;
    if (right < n && array[right] > array[largest])
        largest = right;

    if (largest != i) {
        int temp = array[i];
        array[i] = array[largest];
        array[largest] = temp;
        heapify(array, n, largest);
    }
}

// Heap Sort function
void heapSort(int array[], int n) {
    // Build heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(array, n, i);

    // Extract elements one by one
    for (int i = n - 1; i >= 0; i--) {
        int temp = array[0];
        array[0] = array[i];
        array[i] = temp;
        heapify(array, i, 0);
    }
}

// ======================== UTILITY FUNCTIONS =========================

// Function to print an array
void printArray(int array[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", array[i]);
    printf("\n");
}

// Function to copy one array into another
void copyArray(int source[], int destination[], int n) {
    for (int i = 0; i < n; i++)
        destination[i] = source[i];
}

// ======================== MAIN FUNCTION =========================

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int original[n], arrQuick[n], arrMerge[n], arrHeap[n];

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &original[i]);

    // Copy original array to others
    copyArray(original, arrQuick, n);
    copyArray(original, arrMerge, n);
    copyArray(original, arrHeap, n);

    // Quick Sort
    quickSort(arrQuick, 0, n - 1);
    printf("Sorted array using Quick Sort:\n");
    printArray(arrQuick, n);

    // Merge Sort
    mergeSort(arrMerge, 0, n - 1);
    printf("Sorted array using Merge Sort:\n");
    printArray(arrMerge, n);

    // Heap Sort
    heapSort(arrHeap, n);
    printf("Sorted array using Heap Sort:\n");
    printArray(arrHeap, n);

    return 0;
}

