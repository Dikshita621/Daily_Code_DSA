/*Problem: Sort array of non-negative integers using counting sort.
Find max, build freq array, compute prefix sums, build output.*/
#include <stdio.h>

#define MAX 100

int main() {
    int n, arr[MAX];

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Step 1: Find max
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
    }

    int count[max + 1];

    // Step 2: Initialize count array
    for (int i = 0; i <= max; i++)
        count[i] = 0;

    // Step 3: Store frequencies
    for (int i = 0; i < n; i++)
        count[arr[i]]++;

    // Step 4: Prefix sum
    for (int i = 1; i <= max; i++)
        count[i] += count[i - 1];

    int output[MAX];

    // Step 5: Build output (stable)
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // Copy back
    for (int i = 0; i < n; i++)
        arr[i] = output[i];

    // Print sorted array
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}
