/*
Maximum sum of hour glass
MediumAccuracy: 54.82%Submissions: 27K+Points: 4
Matrix Partners India: Exclusive Job-A-Thon | Apply to 15+ Companies via 1 Hiring Challenge | Starting from 29th April onwards

banner
Given two integers n, m and a 2D matrix mat of dimensions nxm, the task is to find the maximum sum of an hourglass.
An hourglass is defined as a part of the matrix with the following form:



Return -1 if any hourglass is not found.

Example 1:

Input:
n = 3, m = 3
mat = [[1, 2, 3],
       [4, 5, 6],
       [7, 8, 9]]
Output:
35
Explanation:
There is only one hour glass which is
1 2 3
  5
7 8 9   and its sum is 35.
Example 2:

Input:
n = 2, m = 3
mat = [[1, 2, 3],
       [4, 5, 6]]
Output:
-1
Explanation:
There are no hour glasses in this matrix.
Your Task:
You don't need to read input or print anything. Your task is to complete the function findMaxSum() which takes the two integers n, m, and the 2D matrix mat as input parameters and returns the maximum sum of an hourglass in the matrix. If there are no hourglasses, it returns -1.

Expected Time Complexity: O(n*m)
Expected Auxillary Space: O(1)

Constraints:
1 <= n <= 150
3 <= m <= 150
0 <= mat[i][j] <= 106

Topic Tags
MatrixData Structures
*/

// Intuition:
// This class provides a solution to find the maximum sum of submatrices of size 3x3 in the given matrix.
// The algorithm iterates through the matrix and calculates the sum of each 3x3 submatrix, updating
// the maximum sum encountered so far.

// Time Complexity: O(n * m)
// - 'n' and 'm' are the dimensions of the input matrix.
// - The algorithm iterates through each cell of the matrix once and computes the sum of each 3x3 submatrix.

// Space Complexity: O(1) [Fixed size, independent of input]
// - The algorithm uses only a constant amount of extra space for variables.

#include <vector>
#include <climits> // For INT_MIN
using namespace std;

class Solution {
public:
    int findMaxSum(int n, int m, vector<vector<int>> mat) {
        if (n < 3 || m < 3)
            return -1; // Return -1 if the matrix is smaller than 3x3

        int ans = INT_MIN; // Initialize the maximum sum to the minimum possible integer value

        // Iterate through each cell of the matrix
        for (int i = 2; i < n; i++) {
            for (int j = 1; j < m - 1; j++) {
                // Calculate the sum of the current 3x3 submatrix
                int res = mat[i - 2][j - 1] + mat[i - 2][j] + mat[i - 2][j + 1] +
                          mat[i - 1][j] +
                          mat[i][j - 1] + mat[i][j] + mat[i][j + 1];
                // Update the maximum sum encountered so far
                ans = max(ans, res);
            }
        }
        // Return the maximum sum of 3x3 submatrices
        return ans;
    }
};

// Sample Usage
#include <iostream>
int main() {
    Solution obj;
    int n = 4, m = 5;
    vector<vector<int>> mat = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20}
    };
    cout << "Maximum sum of 3x3 submatrices: " << obj.findMaxSum(n, m, mat) << endl; // Output: 99
    return 0;
}
