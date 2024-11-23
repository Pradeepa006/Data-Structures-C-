#include <stdio.h>
#include <stdlib.h>

int* rotateLeft(int d, int* arr, int n) {
    int* rotated = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        rotated[i] = arr[(i + d) % n];
    }
    return rotated;
}

int main() {
    int n, d;
    scanf("%d %d", &n, &d);

    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int* result = rotateLeft(d, arr, n);
    for (int i = 0; i < n; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    free(arr);
    free(result);
    return 0;
}
