/*
Number of paths in a matrix with k coins

avatar
Discuss Approach
arrow-up
Difficulty: MediumAccuracy: 16.96%Submissions: 61K+Points: 4
You are given a matrix mat[][] of size n x m, where each of its cells contains some coins. Count the number of ways to collect exactly k coins while moving from the top left cell of the matrix to the bottom right cell.
From a cell (i, j), you can only move to cell (i+1, j) or (i, j+1).

Note: It is guaranteed that the answer will not exceed 32-bit integer limits.

Examples:

Input: k = 12, mat[] = [[1, 2, 3],
                      [4, 6, 5],
                      [3, 2, 1]]
Output: 2
Explanation: There are 2 possible paths with exactly 12 coins, (1 + 2 + 6 + 2 + 1) and (1 + 2 + 3 + 5 + 1).
Input: k = 16, mat[] = [[1, 2, 3], 
                      [4, 6, 5], 
                      [9, 8, 7]]
Output: 0 
Explanation: There are no possible paths that lead to sum = 16.
Constraints:
1 ≤ k ≤ 100
1 ≤ n, m ≤ 100
0 ≤ mat[i][j] ≤ 200

Expected Complexities
Time Complexity: O(n * m * k)
Auxiliary Space: O(n * m * k)
*/

/*
Intuition:
- We are given a matrix where each cell contains some coins. The task is to count the number of valid paths from the top-left corner (0,0) to the bottom-right corner (n-1,m-1), such that the sum of coins collected along the path equals exactly `k`.
- The movement is restricted to either going down (i+1, j) or right (i, j+1).
- We can approach this problem using dynamic programming (DP) to store subproblems (number of ways to reach a cell with a specific remaining sum `k`).

Approach:
1. **Recursive function `solve(i, j, k)`**:
    - This function tries to count the number of ways to reach cell `(i, j)` with a remaining coin sum of `k`.
    - Base Case: If we go out of bounds or if `k` becomes negative, we return 0 as it is not a valid path.
    - If we have already solved this state, we return the stored result from the `dp` table.
    - If we are at the destination (bottom-right corner), we check if the coin value at this position matches the remaining `k`.
    - We explore both possible moves (right and down) recursively while reducing the value of `k` by the current cell value (`matrix[i][j]`).
    - We store the result for each state in the `dp` table to avoid redundant computations.

2. **Dynamic Programming Table (`dp`)**:
    - We use a 3D DP array `dp[i][j][k]`, where:
      - `i`, `j`: Current cell in the matrix.
      - `k`: Remaining sum of coins we need to collect.
      - `dp[i][j][k]`: Stores the number of valid paths from `(i, j)` to the bottom-right corner with exactly `k` coins collected.
    - We initialize the DP table with `-1` to indicate uncomputed states.

Time Complexity:
- The time complexity is `O(n * m * k)` because:
  - We have `n * m` cells in the matrix.
  - For each cell, we have to check `k` possible remaining coin values (from 0 to `k`).
  - Each cell is computed only once due to memoization.
  
Space Complexity:
- The space complexity is also `O(n * m * k)` because:
  - We store the results for each `(i, j)` cell and for each possible value of `k` in the DP table.

*/

class Solution {
    int n, m;  // dimensions of the matrix (rows and columns)
    vector<vector<vector<int>>> dp;  // DP table to store results
    
  public:
    
    // Recursive function to compute the number of ways to reach (i, j) with exactly k coins
    virtual int solve(int i, int j, vector<vector<int>> &matrix, int k) {
        // Base case: if out of bounds or k becomes negative
        if (i >= n || j >= m || k < 0)
            return 0;

        // If the result is already computed, return the stored result
        if (dp[i][j][k] != -1)
            return dp[i][j][k];

        // If we have reached the destination (bottom-right corner), check if the remaining k equals the coin value at the current cell
        if (i == n - 1 && j == m - 1) {
            return k == matrix[i][j] ? 1 : 0;
        }

        // Initialize answer to 0
        int ans = 0;

        // Move down (i+1, j) and subtract the current coin value from k
        ans += solve(i + 1, j, matrix, k - matrix[i][j]);

        // Move right (i, j+1) and subtract the current coin value from k
        ans += solve(i, j + 1, matrix, k - matrix[i][j]);

        // Store the result in dp[i][j][k]
        return dp[i][j][k] = ans;
    }
    
    // Main function to count the number of valid paths from top-left to bottom-right
    virtual int numberOfPath(vector<vector<int>>& mat, int k) {
        // Initialize the dimensions of the matrix
        n = mat.size();
        m = mat[0].size();
        
        // Initialize the DP table with -1 to indicate uncomputed states
        dp.resize(n, vector<vector<int>>(m, vector<int>(k + 1, -1)));
        
        // Start the recursion from the top-left corner (0, 0) with remaining sum k
        return solve(0, 0, mat, k);
    }
};
