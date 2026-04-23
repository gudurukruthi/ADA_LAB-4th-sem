#include <stdio.h>
#include <stdbool.h>

#define LEFT_TO_RIGHT 1
#define RIGHT_TO_LEFT 0

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int getMobile(int a[], int dir[], int n) {
    int mobile = 0;

    for (int i = 0; i < n; i++) {
        if (dir[a[i] - 1] == RIGHT_TO_LEFT && i != 0) {
            if (a[i] > a[i - 1] && a[i] > mobile)
                mobile = a[i];
        }
        if (dir[a[i] - 1] == LEFT_TO_RIGHT && i != n - 1) {
            if (a[i] > a[i + 1] && a[i] > mobile)
                mobile = a[i];
        }
    }
    return mobile;
}

int findPosition(int a[], int n, int mobile) {
    for (int i = 0; i < n; i++) {
        if (a[i] == mobile)
            return i;
    }
    return -1;
}

void printPermutation(int n) {
    int a[n];
    int dir[n];

    for (int i = 0; i < n; i++) {
        a[i] = i + 1;
        dir[i] = RIGHT_TO_LEFT;
    }

    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");

    while (1) {
        int mobile = getMobile(a, dir, n);
        if (mobile == 0)
            break;

        int pos = findPosition(a, n, mobile);

        if (dir[mobile - 1] == RIGHT_TO_LEFT)
            swap(&a[pos], &a[pos - 1]);
        else
            swap(&a[pos], &a[pos + 1]);

        int newPos = findPosition(a, n, mobile);

        for (int i = 0; i < n; i++) {
            if (a[i] > mobile)
                dir[a[i] - 1] = !dir[a[i] - 1];
        }

        for (int i = 0; i < n; i++)
            printf("%d ", a[i]);
        printf("\n");
    }
}

int main() {
    int n;
    printf("Enter n:");
    scanf("%d",&n);
    printPermutation(n);
    return 0;
}
