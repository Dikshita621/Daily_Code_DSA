/*Problem: For each element, count how many smaller elements appear on right side.
Use merge sort technique or Fenwick Tree (BIT).*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int value;
    int index;
} Pair;

int result[MAX];

void merge(Pair arr[], int left, int mid, int right) {
    Pair temp[MAX];
    int i = left, j = mid + 1, k = left;
    int rightCount = 0;

    while (i <= mid && j <= right) {
        if (arr[j].value < arr[i].value) {
            temp[k++] = arr[j++];
            rightCount++;  // smaller element from right
        } else {
            result[arr[i].index] += rightCount;
            temp[k++] = arr[i++];
        }
    }

    while (i <= mid) {
        result[arr[i].index] += rightCount;
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (i = left; i <= right; i++) {
        arr[i] = temp[i];
    }
}

void mergeSort(Pair arr[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    Pair arr[MAX];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i].value);
        arr[i].index = i;
        result[i] = 0;
    }

    mergeSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++) {
        printf("%d ", result[i]);
    }

    return 0;
}
