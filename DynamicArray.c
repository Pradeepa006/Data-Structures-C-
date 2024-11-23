#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* dynamicArray(int n, int queries_count, char** queries, int* result_count) {
    int lastAnswer = 0;
    int** seqList = malloc(n * sizeof(int*));
    int* seqSizes = calloc(n, sizeof(int));
    int* results = malloc(queries_count * sizeof(int));
    int resultIndex = 0;

    for (int i = 0; i < n; i++) {
        seqList[i] = malloc(1 * sizeof(int));
    }

    for (int i = 0; i < queries_count; i++) {
        int queryType, x, y;
        sscanf(queries[i], "%d %d %d", &queryType, &x, &y);

        int idx = (x ^ lastAnswer) % n;

        if (queryType == 1) {
            seqList[idx] = realloc(seqList[idx], (seqSizes[idx] + 1) * sizeof(int));
            seqList[idx][seqSizes[idx]] = y;
            seqSizes[idx]++;
        } else if (queryType == 2) {
            int elementIdx = y % seqSizes[idx];
            lastAnswer = seqList[idx][elementIdx];
            results[resultIndex++] = lastAnswer;
        }
    }

    *result_count = resultIndex;

    for (int i = 0; i < n; i++) {
        free(seqList[i]);
    }
    free(seqList);
    free(seqSizes);

    return results;
}
int main() {
    int n = 2, queries_count = 5;
    char* queries[] = {"1 0 5", "1 1 7", "1 0 3", "2 1 0", "2 1 1"};
    int result_count;
    
    int* result = dynamicArray(n, queries_count, queries, &result_count);

    for (int i = 0; i < result_count; i++) {
        printf("%d\n", result[i]);
    }

    free(result);
    return 0;
}
