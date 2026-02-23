/*Problem: Given an array of integers, count the number of subarrays whose sum is equal to zero.

Input:
- First line: integer n
- Second line: n integers

Output:
- Print the count of subarrays having sum zero

Example:
Input:
6
1 -1 2 -2 3 -3

Output:
6

Explanation: A subarray is a continuous part of the array. For the input array 1 -1 2 -2 3 -3,
the following subarrays have sum zero: [1, -1], [2, -2], [3, -3], [1, -1, 2, -2], [2, -2, 3, -3], and 
[1, -1, 2, -2, 3, -3]. Since there are 6 such subarrays, the output is 6*/

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    
    int arr[1000];  // Assuming reasonable array size
    long long prefix = 0;
    int count = 0;
    int freq[10001] = {0};  // freq[5000] = sum 0 (offset for negatives)
    freq[5000] = 1;         // Empty prefix before index 0
    
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        prefix += arr[i];
        
        // Offset prefix by 5000 to handle negative sums
        int index = prefix + 5000;
        count += freq[index];
        freq[index]++;
    }
    
    printf("%d\n", count);
    return 0;
}
