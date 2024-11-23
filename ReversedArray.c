#include <stdio.h>
#include <stdlib.h>

int* reverseArray(int* A, int n) {
    int* reversed = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        reversed[i] = A[n - 1 - i];
    }
    return reversed;
}

int main() {
    int n;
    scanf("%d", &n);

    int* A = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    int* result = reverseArray(A, n);
    for (int i = 0; i < n; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    free(A);
    free(result);
    return 0;
}
