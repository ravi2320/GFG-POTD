/*
Get Minimum Squares
Given a positive integer n, find the minimum number of perfect squares (square of an integer) that sum up to n.

Note: Every positive integer can be expressed as a sum of square numbers since 1 is a perfect square, and any number can be represented as 1*1 + 1*1 + 1*1 + ....

Examples:

Input: n = 100
Output: 1
Explanation: 10 * 10 = 100
Input: n = 6
Output: 3
Explanation = 1 * 1 + 1 * 1 + 2 * 2 = 6 
Constraints:
1 ≤ n ≤ 104


*/

// Problem Intuition:
// The problem is asking for the minimum number of perfect squares that sum up to a given number 'n'.
// A perfect square is a number that can be expressed as the square of an integer (e.g., 1, 4, 9, 16, etc.).
// The goal is to find the minimum count of perfect squares that sum up to 'n'.

// Approach:
// 1. We will use a dynamic programming (DP) approach to solve this problem, where dp[i][j] represents the
//    minimum number of perfect squares required to sum up to 'j' using numbers from 1^2 to i^2.
// 2. We start by initializing the base case: dp[0][0] = 0 (0 perfect squares are needed to sum up to 0).
// 3. For each number 'i', we can either use the perfect square of 'i' (i^2) or not, and we compute the minimum
//    number of squares recursively.
// 4. The recursive relationship is based on whether we include or exclude a particular perfect square at each step.
// 5. The result will be found in dp[sqrt(n)][n] after processing all numbers.


/* Time Complexity:
   - The solve function is called recursively, and in each call, the problem is divided into two subproblems.
   - The maximum number of subproblems is O(sqrt(n) * n), where sqrt(n) is the largest integer 'i' such that i^2 <= n, 
     and n is the total sum we are trying to form.
   - Hence, the time complexity is O(sqrt(n) * n).

   Space Complexity:
   - The space complexity is determined by the space required for the DP table, which has a size of O(sqrt(n) * n) 
     since we store the result for each combination of i and n.
   - Hence, the space complexity is O(sqrt(n) * n).
*/

class Solution {
    vector<vector<int>> dp;

  public:
    // solve function is a helper function to calculate the minimum number of squares for a given 'i' and 'n'.
    int solve(int i, int n){
        // Base case: If i is less than or equal to 1, return n because we cannot use any number greater than 1.
        if(i <= 1)
            return n;
        
        // If dp[i][n] is already calculated, return the stored value to avoid recomputation.
        if(dp[i][n] != -1)
            return dp[i][n];
        
        int ans = INT_MAX;
        
        // If the current square i^2 is larger than n, we skip using it and solve for i-1.
        if(i * i > n){
            ans = solve(i-1, n);
        }
        else{
            // Case 1: Include i^2 and solve for remaining sum (n - i^2)
            int take = 1 + solve(i, n - (i * i));
            
            // Case 2: Skip i^2 and solve for the same sum with i-1
            int skip = solve(i-1, n);
            
            // The minimum of both cases will be the answer for dp[i][n]
            ans = min(take, skip);
        }
        
        // Store the result in dp[i][n] to avoid recomputing.
        return dp[i][n] = ans;
    }

    // minSquares function initializes the DP table and starts the computation.
    int minSquares(int n) {
        // Start by finding the largest integer i such that i^2 <= n
        int i = sqrt(n);
        
        // Initialize the DP table with -1 (indicating that the value is not yet computed).
        // dp[i][n] will represent the minimum number of squares for sum n using numbers from 1^2 to i^2.
        dp.resize(i + 1, vector<int>(n + 1, -1));
        
        // Call the solve function starting from the largest integer whose square is <= n
        return solve(i, n);
    }
};


// Problem Intuition:
// The goal is to find the minimum number of perfect squares that sum up to a given number 'n'.
// A perfect square is a number that can be expressed as the square of an integer (e.g., 1, 4, 9, 16, etc.).
// The task is to find the minimum number of these perfect squares that sum up to 'n'.

// Approach:
// 1. The problem can be solved using dynamic programming. We'll use a 2D DP table, where dp[i][j] represents 
//    the minimum number of squares required to sum up to 'j' using squares of numbers from 1 to i.
// 2. If the current square i^2 is larger than j, we don't include i^2 in the sum and carry forward the value from dp[i-1][j].
// 3. If i^2 is less than or equal to j, we can either:
//    - Include i^2 (add 1 to the result of dp[i][j - i^2]), or
//    - Skip i^2 and take the result from dp[i-1][j].
// 4. We will fill the DP table iteratively, and the result will be found in dp[div][n], where 'div' is the integer 
//    square root of n (i.e., the largest i such that i^2 <= n).

/* Time Complexity:
   - The time complexity is O(sqrt(n) * n), where sqrt(n) is the number of different perfect squares 
     we consider (i.e., 1^2, 2^2, ..., div^2), and n is the sum we want to form.
   - We iterate through each square number (i.e., 1^2, 2^2, ..., sqrt(n)^2) and for each, 
     we compute the result for every sum from 1 to n.

   Space Complexity:
   - The space complexity is O(sqrt(n) * n) due to the 2D DP table of size (sqrt(n) + 1) * (n + 1), where
     each entry stores the minimum number of squares required for a particular sum using squares up to i^2.
*/


class Solution {
  public:
    // minSquares function computes the minimum number of perfect squares that sum up to n.
    int minSquares(int n) {
        // div is the largest integer whose square is <= n.
        int div = sqrt(n);
        
        // Initialize DP table: dp[i][j] represents the minimum number of perfect squares 
        // that sum up to 'j' using squares from 1^2 to i^2.
        vector<vector<int>> dp(div + 1, vector<int>(n + 1, 0));
        
        // Iterate through each i (representing squares of numbers from 1 to i).
        for (int i = 1; i <= div; i++) {
            // Iterate through each sum from 1 to n.
            for (int j = 1; j <= n; j++) {
                
                // Base case: If i == 1, the only possible square is 1, so dp[1][j] = j.
                if (i == 1) {
                    dp[i][j] = j;
                }
                // If i^2 is greater than j, we cannot use i^2, so the result will be same as dp[i-1][j].
                else if (i * i > j) {
                    dp[i][j] = dp[i - 1][j];
                }
                // If i^2 is less than or equal to j, we can either:
                // 1. Include i^2 and solve for (j - i^2).
                // 2. Skip i^2 and solve for j with the previous squares (i-1).
                else {
                    dp[i][j] = min(1 + dp[i][j - (i * i)], dp[i - 1][j]);
                }
            }
        }
        
        // The answer will be found in dp[div][n], which is the minimum number of perfect squares for sum n.
        return dp[div][n];
    }
};