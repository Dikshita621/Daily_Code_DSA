/*Problem: Given an array of integers, find two elements whose sum is closest to zero.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the pair of elements whose sum is closest to zero

Example:
Input:
5
1 60 -10 70 -80

Output:
-10 1

Explanation: Among all possible pairs, the sum of -10 and 1 is -9, which is the closest to zero compared to other pairs*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n;
    scanf("%d", &n);
    
    int arr[100];  // Assuming n <= 100
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    // Sort the array
    qsort(arr, n, sizeof(int), compare);
    
    int closest_sum = abs(arr[0] + arr[1]);
    int left = 0, right = 1;
    int min_left = 0, min_right = 1;
    
    while (right < n) {
        int sum = arr[left] + arr[right];
        int abs_sum = abs(sum);
        
        if (abs_sum < closest_sum) {
            closest_sum = abs_sum;
            min_left = left;
            min_right = right;
        }
        
        if (sum < 0) {
            left++;
        } else {
            right++;
        }
        
        if (left == right) {
            right++;
        }
    }
    
    // Print the pair (smaller index first, but since sorted, print as is)
    printf("%d %d\n", arr[min_left], arr[min_right]);
    
    return 0;
}
