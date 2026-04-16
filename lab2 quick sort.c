#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 50000

int a[MAX];

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int a[], int low, int high) {
    int i = low;
    int j = high + 1;
    int pivot = a[low];

    do {
        do {
            i++;
        } while (i <= high && a[i] <= pivot);

        do {
            j--;
        } while (a[j] > pivot);

        if (i < j)
            swap(&a[i], &a[j]);

    } while (i < j);

    swap(&a[low], &a[j]);
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

    int arr[n];

    printf("Enter elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    clock_t start, end;
    double time_taken;

    start = clock();
    quickSort(arr, 0, n - 1);
    end = clock();

    time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Sorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\nTime taken for this input: %lf seconds\n\n", time_taken);

    printf("N\tTime Taken (seconds)\n");

    for (n = 10000; n <= 50000; n += 10000) {

        for (i = 0; i < n; i++) {
            a[i] = rand() % 10000;
        }

        start = clock();
        quickSort(a, 0, n - 1);
        end = clock();

        time_taken = (double)(end - start) / CLOCKS_PER_SEC;

        printf("%d\t%lf\n", n, time_taken);
    }

    return 0;
}
