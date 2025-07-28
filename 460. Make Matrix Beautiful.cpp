/*
Make Matrix Beautiful
Difficulty: MediumAccuracy: 64.75%Submissions: 58K+Points: 4Average Time: 20m
A beautiful matrix is defined as a square matrix in which the sum of elements in every row and every column is equal. Given a square matrix mat[][], your task is to determine the minimum number of operations required to make the matrix beautiful.
In one operation, you are allowed to increment the value of any single cell by 1.

Examples:

Input: mat[][] = [[1, 2], 
                [3, 4]]
Output: 4
Explanation:
Increment value of cell(0, 0) by 3, 
Increment value of cell(0, 1) by 1. 
Matrix after the operations: [[4, 3], 
                            [3, 4]]
Here, sum of each row and column is 7.
Hence total 4 operation are required.
Input: mat[][] = [[1, 2, 3],
                [4, 2, 3],
                [3, 2, 1]]
Output: 6
Explanation: 
Increment value of cell(0, 0) by 1, 
Increment value of cell(0, 1) by 2, 
Increment value of cell(2, 1) by 1, 
Increment value of cell(2, 2) by 2. 
Matrix after the operations: [[2, 4, 3], 
                            [4, 2, 3],
                            [3, 3, 3]] 
Here, sum of each row and column is 9.
Hence total 6 operation are required.
Constraints:
1 ≤ mat.size() ≤ 900
0 ≤ mat[i][j] ≤ 106
*/

// ✅ Approach:
// 1. Calculate the sum of each row and column in the matrix.
// 2. Find the maximum sum among all rows and columns — this is our target sum for all rows and columns.
// 3. The number of operations required is the total number of unit increments needed to make 
//    each row sum equal to this maximum sum (since each operation increases a cell value by 1).
//    We only need to process row differences because column adjustments will naturally align 
//    due to equal cell increments in square matrix rows.

// ✅ Intuition:
// To balance the matrix such that all row and column sums are equal,
// we need to bring all row sums up to the maximum row/column sum observed. 
// Each increment in a matrix cell increases both a row and a column sum, so handling rows is sufficient.

// ✅ Time Complexity: O(N²), where N is the number of rows/columns in the square matrix.
// ✅ Space Complexity: O(1), as only a few integer variables are used.

class Solution {
public:
    int balanceSums(vector<vector<int>>& mat) {
        int n = mat.size();
        int maxSum = 0;      // Target sum for all rows and columns
        int operations = 0;  // Total number of unit operations required

        // Step 1: Find the maximum of any row sum or column sum
        for (int i = 0; i < n; i++) {
            int rowSum = 0, colSum = 0;
            for (int j = 0; j < n; j++) {
                rowSum += mat[i][j];
                colSum += mat[j][i];
            }
            maxSum = max({maxSum, rowSum, colSum});
        }

        // Step 2: Compute total operations needed to make all row sums equal to maxSum
        for (int i = 0; i < n; i++) {
            int rowSum = 0;
            for (int j = 0; j < n; j++) {
                rowSum += mat[i][j];
            }
            operations += (maxSum - rowSum);  // Each unit difference requires one operation
        }

        return operations;
    }
};
