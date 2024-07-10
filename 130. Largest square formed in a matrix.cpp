/*
Largest square formed in a matrix
Difficulty: MediumAccuracy: 36.98%Submissions: 89K+Points: 4
Given a binary matrix mat of size n * m, find out the maximum length of a side of a square sub-matrix with all 1s.

Examples:

Input: n = 6, m = 5
mat = [[0, 1, 1, 0, 1], 
       [1, 1, 0, 1, 0],
       [0, 1, 1, 1, 0],
       [1, 1, 1, 1, 0],
       [1, 1, 1, 1, 1],
       [0, 0, 0, 0, 0]]
Output: 3
Explanation: 

The maximum length of a side of the square sub-matrix is 3 where every element is 1.
Input: n = 2, m = 2
mat = [[1, 1], 
       [1, 1]]
Output: 2
Explanation: The maximum length of a side of the square sub-matrix is 2. The matrix itself is the maximum sized sub-matrix in this case.
Input: n = 2, m = 2
mat = [[0, 0], 
       [0, 0]]
Output: 0
Explanation: There is no 1 in the matrix.
Expected Time Complexity: O(n*m)
Expected Auxiliary Space: O(n*m)

Constraints:
1 ≤ n, m ≤ 500
0 ≤ mat[i][j] ≤ 1 
*/

/*
 * Intuition:
 * We need to find the size of the largest square containing all 1's in a given binary matrix. This can be solved using dynamic programming.
 * We use a recursive function with memoization to find the largest square ending at each cell and update the global maximum size.
 * The recurrence relation for the solution is:
 * dp[i][j] = 1 + min(dp[i+1][j], dp[i][j+1], dp[i+1][j+1]) if mat[i][j] == 1
 * dp[i][j] = 0 if mat[i][j] == 0
 *
 * Time Complexity: O(n * m), where n is the number of rows and m is the number of columns. Each cell is visited once.
 * Space Complexity: O(n * m) for the dp table.
 */

class Solution {
public:
    int solve(vector<vector<int>> &mat, int i, int j, int &maxi, vector<vector<int>> &dp) {
        // Base case: if the indices are out of bounds, return 0
        if (i >= mat.size() || j >= mat[0].size())
            return 0;

        // If the subproblem is already solved, return the stored value
        if (dp[i][j] != -1)
            return dp[i][j];

        // Recursively solve for right, diagonal, and down subproblems
        int right = solve(mat, i, j + 1, maxi, dp);
        int diagonal = solve(mat, i + 1, j + 1, maxi, dp);
        int down = solve(mat, i + 1, j, maxi, dp);

        // If the current cell is 1, calculate the size of the square
        if (mat[i][j] == 1) {
            dp[i][j] = 1 + min(right, min(diagonal, down));
            maxi = max(maxi, dp[i][j]); // Update the maximum size found
            return dp[i][j];
        } else {
            return dp[i][j] = 0; // If the cell is 0, no square can end here
        }
    }

    int maxSquare(int n, int m, vector<vector<int>> mat) {
        int maxi = 0; // To keep track of the maximum square size found
        vector<vector<int>> dp(n, vector<int>(m, -1)); // Initialize dp table with -1
        solve(mat, 0, 0, maxi, dp); // Start the recursion from the top-left corner
        return maxi; // Return the maximum square size found
    }
};


/*
 * Intuition:
 * We need to find the size of the largest square containing all 1's in a given binary matrix. This can be solved using dynamic programming.
 * The tabulation method fills a dp table from the bottom-right to top-left, avoiding the need for recursion.
 * The recurrence relation for the solution is:
 * dp[i][j] = 1 + min(dp[i+1][j], dp[i][j+1], dp[i+1][j+1]) if mat[i][j] == 1
 * dp[i][j] = 0 if mat[i][j] == 0
 *
 * Time Complexity: O(n * m), where n is the number of rows and m is the number of columns. Each cell is visited once.
 * Space Complexity: O(n * m) for the dp table.
 */

class Solution {
public:
    void solveTab(vector<vector<int>> &mat, int &maxi) {
        int row = mat.size();
        int col = mat[0].size();
        
        vector<vector<int>> dp(row + 1, vector<int>(col + 1, 0)); // Extra row and column to handle boundaries
        
        for (int i = row - 1; i >= 0; i--) {
            for (int j = col - 1; j >= 0; j--) {
                // If the current cell is 1, calculate the size of the square ending at (i, j)
                if (mat[i][j] == 1) {
                    dp[i][j] = 1 + min(dp[i][j + 1], min(dp[i + 1][j], dp[i + 1][j + 1]));
                    maxi = max(maxi, dp[i][j]); // Update the maximum size found
                } else {
                    dp[i][j] = 0; // If the cell is 0, no square can end here
                }
            }
        }
    }
  
    int maxSquare(int n, int m, vector<vector<int>> mat) {      
        int maxi = 0; // To keep track of the maximum square size found
        solveTab(mat, maxi); // Fill the dp table and find the maximum square size
        return maxi; // Return the maximum square size found
    }
};


/*
 * Intuition:
 * We need to find the size of the largest square containing all 1's in a given binary matrix. This can be solved using dynamic programming.
 * The space-optimized method reduces the space complexity by using only two vectors instead of a full dp table.
 * The recurrence relation for the solution is:
 * curr[j] = 1 + min(curr[j+1], next[j], next[j+1]) if mat[i][j] == 1
 * curr[j] = 0 if mat[i][j] == 0
 *
 * Time Complexity: O(n * m), where n is the number of rows and m is the number of columns. Each cell is visited once.
 * Space Complexity: O(m) for the two vectors used.
 */

class Solution {
public:
    void solveSO(vector<vector<int>> &mat, int &maxi) {
        int row = mat.size();
        int col = mat[0].size();
        
        vector<int> curr(col + 1, 0); // Current row DP
        vector<int> next(col + 1, 0); // Next row DP
        
        for (int i = row - 1; i >= 0; i--) {
            for (int j = col - 1; j >= 0; j--) {
                // If the current cell is 1, calculate the size of the square ending at (i, j)
                if (mat[i][j] == 1) {
                    curr[j] = 1 + min(curr[j + 1], min(next[j], next[j + 1]));
                    maxi = max(maxi, curr[j]); // Update the maximum size found
                } else {
                    curr[j] = 0; // If the cell is 0, no square can end here
                }
            }
            next = curr; // Move to the next row
        }
    }
  
    int maxSquare(int n, int m, vector<vector<int>> mat) {      
        int maxi = 0; // To keep track of the maximum square size found
        solveSO(mat, maxi); // Fill the dp table and find the maximum square size
        return maxi; // Return the maximum square size found
    }
};
