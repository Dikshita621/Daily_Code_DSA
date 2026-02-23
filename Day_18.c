/*Problem: Given an array of integers, rotate the array to the right by k positions.

Input:
- First line: integer n
- Second line: n integers
- Third line: integer k

Output:
- Print the rotated array

Example:
Input:
5
1 2 3 4 5
2

Output:
4 5 1 2 */

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    
    int arr[100];  // Assuming n <= 100
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    int k;
    scanf("%d", &k);
    k = k % n;  // Optimize for large k
    
    // Method 1: Simple shift k times (works for small k)
    for(int rot = 0; rot < k; rot++) {
        int last = arr[n-1];
        for(int i = n-1; i > 0; i--) {
            arr[i] = arr[i-1];
        }
        arr[0] = last;
    }
    
    // Print output
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}
