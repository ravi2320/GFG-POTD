/*
Coverage of all Zeros in a Binary Matrix
Difficulty: EasyAccuracy: 55.68%Submissions: 16K+Points: 2
Given a binary matrix contains 0s and 1s only, we need to find the sum of coverage of all zeros of the matrix where coverage for a particular 0 is defined as a total number of ones around a zero in left, right, up and bottom directions.

Examples:

Input:
matrix = [[0, 1, 0],
          [0, 1, 1],
          [0, 0, 0]]
Output: 6
Explanation: There are a total of 6 coverage are there

Input: 
matrix = [[0, 1]]
Output: 1
Explanation: There are only 1 coverage.
Expected Time Complexity: O(n * m)
Expected Space Complexity: O(1)

Constraints:
1 <= matrix.size, matrix[0].size <= 100
*/

/**
 * Intuition:
 * - We need to calculate the "coverage" of the cells with value 1 by counting how many adjacent cells with value 0 surround them.
 * - We iterate through each cell in the matrix, and whenever we encounter a 0, we check its four possible adjacent cells (up, down, left, right).
 * - If any of those adjacent cells contain a 1, we increase our coverage count.

 * Time Complexity: O(n * m)
 * - We traverse each cell in the matrix exactly once, performing a constant amount of work for each cell.

 * Space Complexity: O(1)
 * - We use only a few extra variables, regardless of the input size.
 */

class Solution {
public:
    int findCoverage(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int ans = 0;

        // Traverse each cell in the matrix
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // If the current cell is 0
                if (matrix[i][j] == 0) {
                    // Check the cell above
                    if (i > 0 && matrix[i - 1][j] == 1)
                        ans++;

                    // Check the cell below
                    if (i < n - 1 && matrix[i + 1][j] == 1)
                        ans++;

                    // Check the cell to the left
                    if (j > 0 && matrix[i][j - 1] == 1)
                        ans++;

                    // Check the cell to the right
                    if (j < m - 1 && matrix[i][j + 1] == 1)
                        ans++;
                }
            }
        }

        return ans;
    }
};