/*
Dice throw
Difficulty: MediumAccuracy: 36.52%Submissions: 37K+Points: 4Average Time: 30m
Given n dice each with m faces. Find the number of ways to get sum x which is the summation of values on each face when all the dice are thrown.

Example:

Input: m = 6, n = 3, x = 12
Output: 25
Explanation: There are 25 total ways to get the Sum 12 using 3 dices with faces from 1 to 6.
Input: m = 2, n = 3, x = 6
Output: 1
Explanation: There is only 1 way to get the Sum 6 using 3 dices with faces from 1 to 2. All the dices will have to land on 2.
Constraints:
1 <= m,n,x <= 50
*/

/*
Approach:
- Use recursive dynamic programming with memoization to count the number of ways to get a sum `x` using `n` dice with `m` faces.
- At each step, we try all possible face values from 1 to m and recursively reduce the target sum.
- Store intermediate results in a dp table to avoid recomputation.

Intuition:
- If we use all dice (i == n), we check if the remaining target sum is 0. If yes, it’s a valid way.
- Otherwise, for each die, we try all values from 1 to m and recursively check if we can reach the target.

Time Complexity: O(n * x * m)
Space Complexity: O(n * x) for the dp table and O(n) recursion stack depth
*/

class Solution {
public:
    // Recursive helper function with memoization
    int solve(int i, int curr, int m, int n, vector<vector<int>> &dp) {
        // If we've used all dice, check if remaining sum is 0
        if (i == n) {
            return curr == 0 ? 1 : 0;
        }

        // If remaining sum is negative, not a valid configuration
        if (curr < 0) return 0;

        // If already computed, return from dp table
        if (dp[i][curr] != -1) {
            return dp[i][curr];
        }

        int ans = 0;

        // Try all face values from 1 to m
        for (int j = 1; j <= m; j++) {
            ans += solve(i + 1, curr - j, m, n, dp);
        }

        // Store the result in dp table
        return dp[i][curr] = ans;
    }

    // Main function to count number of ways
    int noOfWays(int m, int n, int x) {
        // dp[i][curr] = number of ways to form sum `curr` using `i` dice
        vector<vector<int>> dp(n + 1, vector<int>(x + 1, -1));

        // Start from 0th dice and target sum x
        return solve(0, x, m, n, dp);
    }
};


/*
Approach:
- Use bottom-up dynamic programming (tabulation).
- Define dp[i][j] as the number of ways to get a sum `j` using `i` dice.
- Build up the solution iteratively:
    - For each number of dice from 1 to n,
    - For each possible sum from 1 to x,
    - Try all face values from 1 to m and accumulate the count of ways.

Intuition:
- To get sum `j` with `i` dice, try all face values `f` such that `j - f` is a valid sum with `i - 1` dice.
- Add all possible ways from previous state `dp[i - 1][j - f]` to current state.

Time Complexity: O(n * x * m)  
Space Complexity: O(n * x)  
*/

class Solution {
public:
    int noOfWays(int m, int n, int x) {
        // dp[i][j] = number of ways to get sum j using i dice
        vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));

        dp[0][0] = 1;  // Base case: 1 way to make sum 0 with 0 dice

        // Loop over number of dice
        for (int i = 1; i <= n; i++) {
            // Loop over all possible target sums
            for (int sum = 1; sum <= x; sum++) {
                // Try every face value for the current die
                for (int face = 1; face <= m; face++) {
                    // Only consider valid subproblems
                    if (sum - face >= 0) {
                        dp[i][sum] += dp[i - 1][sum - face];
                    }
                }
            }
        }

        // Final answer is number of ways to get sum x with n dice
        return dp[n][x];
    }
};
