#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10005

int a[MAX], b[MAX];

void mergeSort(int low, int high);
void merge(int low, int mid, int high);
void quickSort(int p, int r);
int partition(int p, int r);

int main() {
    int n, ch, i;
    printf("Enter Max array size: ");
    scanf("%d", &n);

    printf("Enter the choice::\n1. User input\n2. Random\n");
    scanf("%d", &ch);

    if (ch == 1) 
    { // User input
        printf("Enter the array elements: \n");
        for (i = 0; i < n; i++)
            scanf("%d", &a[i]);
    } 
    else if (ch == 2) 
    { // Random input
        srand(time(NULL));
        printf("The input array elements are: \n");
        for (i = 0; i < n; i++) 
        {
            a[i] = rand() % 1000;
            printf("%d ", a[i]);
        }
        printf("\n");
    }

    // Copy elements of a[] to b[] for quick sort
    for (i = 0; i < n; i++)
        b[i] = a[i];

    // Measure time for Merge Sort
    clock_t startTime = clock();
    mergeSort(0, n - 1);
    clock_t stopTime = clock();
    double mergeTime = ((double)(stopTime - startTime)) / CLOCKS_PER_SEC * 1000;
    printf("Time Complexity (ms) for n [Merge sort] = %d is : %.3f ms\n", n, mergeTime);

    // Measure time for Quick Sort
    startTime = clock();
    quickSort(0, n - 1);
    stopTime = clock();
    double quickTime = ((double)(stopTime - startTime)) / CLOCKS_PER_SEC * 1000;
    printf("Time Complexity (ms) for n [Quick sort] = %d is : %.3f ms\n", n, quickTime);

    // Print time difference
    printf("The difference in time:: time(merge) - time(quick) = %.3f ms\n", mergeTime - quickTime);

    // Print sorted arrays
    printf("Sorted Array (Merge Sort):\n");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");

    printf("Sorted Array (Quick Sort):\n");
    for (i = 0; i < n; i++)
        printf("%d ", b[i]);
    printf("\n");

    return 0;
}

void mergeSort(int low, int high) 
{
    if (low < high) 
    {
        int mid = (low + high) / 2;
        mergeSort(low, mid);
        mergeSort(mid + 1, high);
        merge(low, mid, high);
    }
}

void merge(int low, int mid, int high) 
{
    int temp[MAX];
    int h = low, i = low, j = mid + 1, k;

    while (h <= mid && j <= high) 
    {
        if (a[h] < a[j])
            temp[i++] = a[h++];
        else
            temp[i++] = a[j++];
    }

    while (h <= mid)
        temp[i++] = a[h++];
    while (j <= high)
        temp[i++] = a[j++];

    for (k = low; k <= high; k++)
        a[k] = temp[k];
}

void quickSort(int p, int r) 
{
    if (p < r) 
    {
        int q = partition(p, r);
        quickSort(p, q - 1);
        quickSort(q + 1, r);
    }
}

int partition(int p, int r) 
{
    int pivot = b[p];
    int i = p + 1, j = r, temp;

    while (1) 
    {
        while (i <= r && b[i] < pivot) i++;
        while (b[j] > pivot) j--;

        if (i < j) 
        {
            temp = b[i];
            b[i] = b[j];
            b[j] = temp;
        } 
        else 
        {
            break;
        }
    }

    b[p] = b[j];
    b[j] = pivot;
    return j;
}