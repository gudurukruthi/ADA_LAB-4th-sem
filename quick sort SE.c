
#include <stdio.h>
#include <time.h>

int partition(int a[], int low, int high) {
    int i = low;
    int j = high + 1;
    int pivot = a[low];
    int temp;

    while (i < j) {
        do {
            i++;
        } while (i <= high && a[i] <= pivot);

        do {
            j--;
        } while (a[j] > pivot);

        if (i < j) {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }

    temp = a[low];
    a[low] = a[j];
    a[j] = temp;

    return j;
}

void quickSort(int a[], int low, int high) {
    if (low < high) {
        int j = partition(a, low, high);
        quickSort(a, low, j - 1);
        quickSort(a, j + 1, high);
    }
}

int main() {
    int n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int a[n];

    printf("Enter elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // Start time
    clock_t start = clock();

    quickSort(a, 0, n - 1);

    // End time
    clock_t end = clock();

    printf("Sorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    // Calculate execution time
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("\nStart time: %ld", start);
    printf("\nEnd time: %ld", end);
    printf("\nExecution time: %f seconds\n", time_taken);

    return 0;
}
