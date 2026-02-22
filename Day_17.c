/*Problem: Write a program to find the maximum and minimum values present in a given array of integers.

Input:
- First line: integer n
- Second line: n integers

Output:
- Print the maximum and minimum elements

Example:
Input:
6
3 5 1 9 2 8

Output:
Max: 9
Min: 1*/
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    
    int arr[100];  // Assuming n <= 100
    
    // Read array elements
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    // Initialize max and min with first element
    int max = arr[0];
    int min = arr[0];
    
    // Find max and min
    for(int i = 1; i < n; i++) {
        if(arr[i] > max) {
            max = arr[i];
        }
        if(arr[i] < min) {
            min = arr[i];
        }
    }
    
    // Print result in exact format
    printf("Max: %d\n", max);
    printf("Min: %d\n", min);
    
    return 0;
}
