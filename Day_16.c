/*Problem: Given an array of integers, count the frequency of each distinct element and print the result.

Input:
- First line: integer n (size of array)
- Second line: n integers

Output:
- Print each element followed by its frequency in the format element:count

Example:
Input:
5
1 2 2 3 1

Output:
1:2 2:2 3:1*/
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    
    int arr[100];  // Assuming n <= 100
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    // Count frequency of each element
    for(int i = 0; i < n; i++) {
        int count = 1;  // Count current element
        
        // Skip already counted elements
        if(arr[i] == -9999) continue;
        
        // Count frequency
        for(int j = i + 1; j < n; j++) {
            if(arr[i] == arr[j]) {
                count++;
                arr[j] = -9999;  // Mark as counted
            }
        }
        
        printf("%d:%d ", arr[i], count);
    }
    printf("\n");
    
    return 0;
}
