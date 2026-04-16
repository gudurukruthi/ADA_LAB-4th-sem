#include <stdio.h>

#define MAX 100

int main() {
    int n;
    int V[MAX][MAX];
    int Indegree[MAX];
    int visited[MAX];
    int TP[MAX];
    int tp_count = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &V[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        Indegree[i] = 0;
        for (int j = 0; j < n; j++) {
            if (V[j][i] == 1) {
                Indegree[i]++;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    while (1) {
        int w = -1;

        for (int i = 0; i < n; i++) {
            if (visited[i] == 0 && Indegree[i] == 0) {
                w = i;
                break;
            }
        }

        if (w == -1)
            break;

        TP[tp_count++] = w;
        visited[w] = 1;

        for (int i = 0; i < n; i++) {
            if (V[w][i] == 1) {
                Indegree[i]--;
            }
        }
    }

    if (tp_count < n) {
        printf("No Topological Sequence (cycle detected)\n");
    } else {
        printf("Topological Sequence:\n");
        for (int i = 0; i < tp_count; i++) {
            printf("%d ", TP[i]);
        }
        printf("\n");
    }

    return 0;
}
