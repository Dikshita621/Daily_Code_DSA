/*Problem Statement
Given n boards of different lengths and k painters, each painter paints contiguous boards. Painting a unit length of board takes one unit of time.

Determine the minimum time required to paint all boards.

Input Format
n k
n space-separated integers representing board lengths

Output Format
Print the minimum time required to paint all boards.

Sample Input
4 2
10 20 30 40

Sample Output
60

Explanation
One painter paints boards of length 10, 20, and 30 (total 60), while the other paints board of length 40*/
#include <stdio.h>

#define MAX 100

int boards[MAX];
int n, k;

// Check if possible within maxTime
int isPossible(int maxTime) {
    int painters = 1;
    int currSum = 0;

    for (int i = 0; i < n; i++) {
        if (boards[i] > maxTime)
            return 0;

        if (currSum + boards[i] <= maxTime) {
            currSum += boards[i];
        } else {
            painters++;
            currSum = boards[i];

            if (painters > k)
                return 0;
        }
    }
    return 1;
}

int minTime() {
    int low = 0, high = 0;

    // Find range
    for (int i = 0; i < n; i++) {
        if (boards[i] > low)
            low = boards[i];  // max element
        high += boards[i];   // total sum
    }

    int result = high;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (isPossible(mid)) {
            result = mid;
            high = mid - 1;  // try smaller
        } else {
            low = mid + 1;   // increase limit
        }
    }

    return result;
}

int main() {
    scanf("%d %d", &n, &k);

    for (int i = 0; i < n; i++) {
        scanf("%d", &boards[i]);
    }

    printf("%d\n", minTime());

    return 0;
}
