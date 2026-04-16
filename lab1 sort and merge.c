#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 50000

int arr[MAX], temp[MAX];

void merge(int low, int mid, int high)
{
    int i = low;
    int j = mid + 1;
    int k = low;

    while (i <= mid && j <= high)
    {
        if (arr[i] < arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while (i <= mid)
        temp[k++] = arr[i++];

    while (j <= high)
        temp[k++] = arr[j++];

    for (i = low; i <= high; i++)
        arr[i] = temp[i];
}

void mergesort(int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;

        mergesort(low, mid);

        mergesort(mid + 1, high);

        merge(low, mid, high);
    }
}

int main()
{
    int n, i;
    clock_t start, end;
    double time_taken;

    srand(time(NULL));

    printf("N\tTime Taken (seconds)\n");

    for (n = 10000; n <= 50000; n += 10000)
    {
        for (i = 0; i < n; i++)
        {
            arr[i] = rand() % 50000;
        }

        start = clock();

        mergesort(0, n - 1);

        end = clock();

        time_taken = (double)(end - start) / CLOCKS_PER_SEC;

        printf("%d\t%.10f\n", n, time_taken);
    }

    return 0;
}


