/*Problem: Given n real numbers in [0,1), sort using bucket sort algorithm.
Distribute into buckets, sort each, concatenate.*/
#include <stdio.h>

#define MAX 100
// Insertion sort for individual buckets
void insertionSort(float arr[], int n) {
    for (int i = 1; i < n; i++) {
        float key = arr[i];
        int j = i - 1:

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int n;
    float arr[MAX];

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
    }

    // Buckets
    float bucket[MAX][MAX];
    int count[MAX] = {0};

    // Step 1: Distribute elements into buckets
    for (int i = 0; i < n; i++) {
        int index = (int)(n * arr[i]);
        bucket[index][count[index]++] = arr[i];
    }

    // Step 2: Sort each bucket
    for (int i = 0; i < n; i++) {
        insertionSort(bucket[i], count[i]);
    }

    // Step 3: Concatenate buckets
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < count[i]; j++) {
            arr[k++] = bucket[i][j];
        }
    }

    // Print sorted array
    for (int i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }

    return 0;
}
