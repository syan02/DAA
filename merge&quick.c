#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Merge Sort Functions
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1, n2 = right - mid;
    int L[n1], R[n2];

    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int i = 0; i < n2; i++) R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// Quick Sort Functions
int partition(int arr[], int low, int high) {
    int pivot = arr[high], i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Function to print an array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Main Function
int main() {
    int arr[] = {10, 7, 8, 9, 1, 5, 3, 6, 2, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Copying the array to maintain original values
    int arr1[n], arr2[n];
    for (int i = 0; i < n; i++) {
        arr1[i] = arr[i];
        arr2[i] = arr[i];
    }

    // Merge Sort Execution Time
    clock_t start_merge = clock();
    mergeSort(arr1, 0, n - 1);
    clock_t end_merge = clock();
    double time_merge = ((double)(end_merge - start_merge)) / CLOCKS_PER_SEC;

    printf("Sorted array using Merge Sort:\n");
    printArray(arr1, n);
    printf("Time taken by Merge Sort: %f seconds\n\n", time_merge);

    // Quick Sort Execution Time
    clock_t start_quick = clock();
    quickSort(arr2, 0, n - 1);
    clock_t end_quick = clock();
    double time_quick = ((double)(end_quick - start_quick)) / CLOCKS_PER_SEC;

    printf("Sorted array using Quick Sort:\n");
    printArray(arr2, n);
    printf("Time taken by Quick Sort: %f seconds\n", time_quick);

    return 0;
}

/*Sorted array using Merge Sort:
1 2 3 4 5 6 7 8 9 10
Time taken by Merge Sort: 0.000003 seconds

Sorted array using Quick Sort:
1 2 3 4 5 6 7 8 9 10
Time taken by Quick Sort: 0.000002 seconds*/