/*
Matrix Chain Multiplication
Difficulty: HardAccuracy: 49.64%Submissions: 144K+Points: 8
Given an array arr[] which represents the dimensions of a sequence of matrices where the ith matrix has the dimensions (arr[i-1] x arr[i]) for i>=1, find the most efficient way to multiply these matrices together. The efficient way is the one that involves the least number of multiplications.

Examples:

Input: arr[] = [2, 1, 3, 4]
Output: 20
Explanation: There are 3 matrices of dimensions 2 × 1, 1 × 3, and 3 × 4, Let this 3 input matrices be M1, M2, and M3. There are two ways to multiply: ((M1 x M2) x M3) and (M1 x (M2 x M3)), note that the result of (M1 x M2) is a 2 x 3 matrix and result of (M2 x M3) is a 1 x 4 matrix. 
((M1 x M2) x M3)  requires (2 x 1 x 3) + (2 x 3 x 4) = 30 
(M1 x (M2 x M3))  requires (1 x 3 x 4) + (2 x 1 x 4) = 20. 
The minimum of these two is 20.
Input: arr[] = [1, 2, 3, 4, 3]
Output: 30
Explanation: There are 4 matrices of dimensions 1 × 2, 2 × 3, 3 × 4, 4 × 3. Let this 4 input matrices be M1, M2, M3 and M4. The minimum number of multiplications are obtained by ((M1 x M2) x M3) x M4). The minimum number is (1 x 2 x 3) + (1 x 3 x 4) + (1 x 4 x 3) = 30.
Input: arr[] = [3, 4]
Output: 0
Explanation: As there is only one matrix so, there is no cost of multiplication.
Constraints: 
2 ≤ arr.size() ≤ 100
1 ≤ arr[i] ≤ 200
*/

/*
    Problem:
    - Given an array arr[] of size n that represents the chain of matrices,
      where the ith matrix has dimensions arr[i-1] x arr[i].
    - Goal: Find the minimum number of multiplications needed to multiply the chain.

    Approach:
    - Use recursion + memoization (Top-Down DP).
    - Try placing parentheses at every possible position and recursively calculate the cost.
    - Memoize overlapping subproblems using dp[][].

    Time Complexity: O(N^3), where N is the number of matrices.
    Space Complexity: O(N^2) for the dp table + O(N) recursion stack space.
*/

class Solution {
public:
    // Recursive function to compute minimum multiplications
    int f(int i, int j, vector<int> &arr, vector<vector<int>> &dp) {
        // Base Case: Single matrix, no multiplication needed
        if (i == j) return 0;

        // Return memoized result if available
        if (dp[i][j] != -1) return dp[i][j];

        int mini = INT_MAX;

        // Try all possible places to split the chain
        for (int k = i; k < j; k++) {
            int steps = arr[i - 1] * arr[k] * arr[j]    // Cost of multiplying the two parts
                      + f(i, k, arr, dp)                // Left part
                      + f(k + 1, j, arr, dp);           // Right part

            mini = min(mini, steps); // Keep track of the minimum cost
        }

        return dp[i][j] = mini;
    }

    int matrixMultiplication(vector<int> &arr) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, -1)); // Initialize dp table with -1

        // Start recursion from first matrix to last matrix
        return f(1, n - 1, arr, dp);
    }
};

// Approach:
// We use Bottom-Up Dynamic Programming (Tabulation) to solve the problem.
// dp[i][j] will store the minimum number of multiplications needed to multiply matrices from index i to j.
// For each pair (i, j), we try all possible partitions (k) between i and j, and choose the partition which gives minimum cost.

// Intuition:
// Since matrix multiplication is associative, we can divide the problem into subproblems, solve them, and combine their solutions.
// Optimal substructure and overlapping subproblems make DP applicable.

// Time Complexity: O(N^3) 
//   -> Three nested loops: i, j, and k up to N.
// Space Complexity: O(N^2) 
//   -> For the DP table of size N*N.

class Solution {
  public:
    int matrixMultiplication(vector<int> &arr) {
        int n = arr.size(); // Number of matrices is n-1
        vector<vector<int>> dp(n, vector<int>(n, 0)); // DP table to store minimum multiplications
        
        // Bottom-up filling
        for(int i = n - 1; i >= 1; i--) { // Start from last matrix towards the first
            for(int j = i + 1; j < n; j++) { // End matrix index must be greater than start
                int mini = 1e9; // Initialize to large number
                
                // Try all possible partitions
                for(int k = i; k < j; k++) {
                    int steps = arr[i - 1] * arr[k] * arr[j] // Cost of multiplying current partition
                                + dp[i][k]                 // Cost for left partition
                                + dp[k + 1][j];            // Cost for right partition
                    
                    mini = min(mini, steps); // Take minimum over all k
                }
                
                dp[i][j] = mini; // Store the result in DP table
            }
        }
        
        return dp[1][n - 1]; // Minimum cost to multiply matrices from 1 to n-1
    }
};


