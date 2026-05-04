/*Problem Statement
Given n stalls located at different positions along a straight line and k cows, place the cows in the stalls such that the minimum distance between any two cows is maximized.

This is an optimization problem where binary search on the answer is required.

Input Format
n k
n space-separated integers representing stall positions

Output Format
Print the maximum possible minimum distance between any two cows.

Sample Input
5 3
1 2 8 4 9

Sample Output
3

Explanation
Cows can be placed at positions 1, 4, and 8. The minimum distance between any two cows is 3, which is the maximum possible.*/
#include <stdio.h>
#include <stdlib.h>

// Comparator for sorting
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

// Check if we can place k cows with at least 'dist' distance
int canPlaceCows(int arr[], int n, int k, int dist) {
    int count = 1;  // first cow in first stall
    int lastPos = arr[0];

    for(int i = 1; i < n; i++) {
        if(arr[i] - lastPos >= dist) {
            count++;
            lastPos = arr[i];

            if(count == k)
                return 1;
        }
    }

    return 0;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int arr[n];

    // Input stalls
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Sort stall positions
    qsort(arr, n, sizeof(int), compare);

    int left = 1;
    int right = arr[n - 1] - arr[0];
    int ans = 0;

    // Binary search on answer
    while(left <= right) {
        int mid = left + (right - left) / 2;

        if(canPlaceCows(arr, n, k, mid)) {
            ans = mid;       // possible answer
            left = mid + 1;  // try for bigger distance
        } else {
            right = mid - 1;  // reduce distance
        }
    }

    printf("%d\n", ans);

    return 0;
}
