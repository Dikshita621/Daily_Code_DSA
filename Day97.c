/*Problem: Given meeting intervals, find minimum number of rooms required.
Sort by start time and use min-heap on end times.*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int start, end;
} Meeting;

// Sort by start time
int compare(const void *a, const void *b) {
    return ((Meeting *)a)->start - ((Meeting *)b)->start;
}

// Simple function to find index of minimum end time
int findMin(int endTimes[], int size) {
    int minIdx = 0;
    for (int i = 1; i < size; i++) {
        if (endTimes[i] < endTimes[minIdx])
            minIdx = i;
    }
    return minIdx;
}

int main() {
    int n;
    scanf("%d", &n);

    Meeting arr[MAX];

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &arr[i].start, &arr[i].end);
    }

    // Step 1: Sort meetings
    qsort(arr, n, sizeof(Meeting), compare);

    int endTimes[MAX];
    int rooms = 0;

    for (int i = 0; i < n; i++) {
        if (rooms == 0) {
            endTimes[rooms++] = arr[i].end;
        } else {
            int minIdx = findMin(endTimes, rooms);

            if (arr[i].start >= endTimes[minIdx]) {
                // reuse room
                endTimes[minIdx] = arr[i].end;
            } else {
                // need new room
                endTimes[rooms++] = arr[i].end;
            }
        }
    }

    printf("%d\n", rooms);

    return 0;
}
