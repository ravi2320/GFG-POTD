/*
Search in a Row-Column sorted matrix
Difficulty: EasyAccuracy: 41.62%Submissions: 144K+Points: 2
Given a 2D integer matrix mat[][] of size n x m, where every row and column is sorted in increasing order and a number x, the task is to find whether element x is present in the matrix.

Examples:

Input: mat[][] = [[3, 30, 38],[20, 52, 54],[35, 60, 69]], x = 62
Output: false
Explanation: 62 is not present in the matrix, so output is false.
Input: mat[][] = [[18, 21, 27],[38, 55, 67]], x = 55
Output: true
Explanation: 55 is present in the matrix.
Input: mat[][] = [[1, 2, 3],[4, 5, 6],[7, 8, 9]], x = 3
Output: true
Explanation: 3 is present in the matrix.
Constraints:
1 <= n, m <=1000
1 <= mat[i][j] <= 109
1<= x <= 109
*/

/*
Approach:
This problem is solved using a "staircase search" technique, which efficiently traverses the matrix to locate the target `x`.

Steps:
1. Start from the top-right corner of the matrix.
2. Compare the current element with `x`:
   - If it's equal, return `true`.
   - If it's greater than `x`, move left (reduce the column index).
   - If it's less than `x`, move down (increase the row index).
3. Continue until either:
   - The element is found, or
   - The indices go out of bounds.
4. If the loop ends without finding `x`, return `false`.

This approach works because the matrix is sorted row-wise and column-wise, allowing for systematic elimination of rows or columns.

Time Complexity:
- O(n + m): At most, one full traversal of rows and columns is performed.

Space Complexity:
- O(1): No additional space is used.

Edge Cases:
1. Single-element matrix.
2. Element not in the matrix.
3. Element found in the first or last position.

*/

class Solution {
public:
    bool matSearch(vector<vector<int>> &mat, int x) {
        int n = mat.size(), m = mat[0].size();
        int row = 0, col = m - 1; // Start from the top-right corner

        while (row < n && col >= 0) {
            if (mat[row][col] == x) {
                return true; // Element found
            }
            else if (mat[row][col] > x) {
                col--; // Move left
            }
            else {
                row++; // Move down
            }
        }

        return false; // Element not found
    }
};