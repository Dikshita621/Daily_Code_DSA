/*Problem: Given intervals, merge all overlapping ones.
Sort first, then compare with previous.*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int start, end;
} Interval;

// Sort by start time
int compare(const void *a, const void *b) {
    return ((Interval *)a)->start - ((Interval *)b)->start;
}

int main() {
    int n;
    scanf("%d", &n);

    Interval arr[MAX];

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &arr[i].start, &arr[i].end);
    }

    // Step 1: Sort intervals
    qsort(arr, n, sizeof(Interval), compare);

    Interval result[MAX];
    int idx = 0;

    // Step 2: Merge
    result[idx++] = arr[0];

    for (int i = 1; i < n; i++) {
        // Last merged interval
        Interval *last = &result[idx - 1];

        if (arr[i].start <= last->end) {
            // Merge
            if (arr[i].end > last->end)
                last->end = arr[i].end;
        } else {
            // No overlap
            result[idx++] = arr[i];
        }
    }

    // Print merged intervals
    for (int i = 0; i < idx; i++) {
        printf("%d %d\n", result[i].start, result[i].end);
    }

    return 0;
}
