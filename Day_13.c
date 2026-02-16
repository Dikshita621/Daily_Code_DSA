/*Problem: You are given a rectangular matrix of integers. Starting from the outer boundary, traverse the matrix in a clockwise manner and continue moving inward layer by layer until all elements are visited.

Input:
- First line: two integers r and c representing the number of rows and columns
- Next r lines: c integers each representing the matrix elements

Output:
- Print all visited elements in the order of traversal, separated by spaces

Example:
Input:
3 3
1 2 3
4 5 6
7 8 9

Output:
1 2 3 6 9 8 7 4 5

Explanation:
The traversal begins along the top row, proceeds down the rightmost column, then moves across the bottom row in reverse, and finally goes up the leftmost column. The same pattern repeats for the inner submatrix.

Test Cases:

Test Case 1:
Input:
2 3
1 2 3
4 5 6
Output:
1 2 3 6 5 4

Test Case 2:
Input:
3 1
7
8
9
Output:
7 8 9*/

#include <stdio.h>

int main() {
    int r, c;
    scanf("%d %d", &r, &c);
    
    int matrix[100][100];  // Assuming max 100x100 matrix
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    
    int result[10000];  // Store traversal result
    int top = 0, bottom = r - 1, left = 0, right = c - 1;
    int index = 0;
    
    while(top <= bottom && left <= right) {
        // Top row: left to right
        for(int j = left; j <= right; j++) {
            result[index++] = matrix[top][j];
        }
        top++;
        
        // Right column: top to bottom
        for(int i = top; i <= bottom; i++) {
            result[index++] = matrix[i][right];
        }
        right--;
        
        // Bottom row: right to left (if rows remain)
        if(top <= bottom) {
            for(int j = right; j >= left; j--) {
                result[index++] = matrix[bottom][j];
            }
            bottom--;
        }
        
        // Left column: bottom to top (if columns remain)
        if(left <= right) {
            for(int i = bottom; i >= top; i--) {
                result[index++] = matrix[i][left];
            }
            left++;
        }
    }
    
    // Print result with spaces
    for(int i = 0; i < index; i++) {
        printf("%d", result[i]);
        if(i < index - 1) printf(" ");
    }
    printf("\n");
    
    return 0;
}
