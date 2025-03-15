/*
Coin Change (Minimum Coins)
Difficulty: MediumAccuracy: 26.74%Submissions: 240K+Points: 4
You are given an array coins[], where each element represents a coin of a different denomination, and a target value sum. You have an unlimited supply of each coin type {coins1, coins2, ..., coinsm}.

Your task is to determine the minimum number of coins needed to obtain the target sum. If it is not possible to form the sum using the given coins, return -1.

Examples:

Input: coins[] = [25, 10, 5], sum = 30
Output: 2
Explanation: Minimum 2 coins needed, 25 and 5  
Input: coins[] = [9, 6, 5, 1], sum = 19
Output: 3
Explanation: 19 = 9 + 9 + 1
Input: coins[] = [5, 1], sum = 0
Output: 0
Explanation: For 0 sum, we do not need a coin
Input: coins[] = [4, 6, 2], sum = 5
Output: -1
Explanation: Not possible to make the given sum.
 
Constraints:
1 ≤ sum * coins.size() ≤ 106
0 <= sum <= 104
1 <= coins[i] <= 104
1 <= coins.size() <= 103
*/

/**
 * Approach: Dynamic Programming (Memoization)
 * - Use recursion with memoization to avoid redundant calculations.
 * - Choices:
 *   1. Take the coin (if sum - coins[idx] >= 0)
 *   2. Skip the coin (move to next index)
 * - Use a DP table `dp[idx][sum]` to store results.
 *
 * 🔹 **Time Complexity:** O(N * sum) → Each state is computed once.
 * 🔹 **Space Complexity:** O(N * sum) → DP table storage.
 */

class Solution {
  public:
    int solve(int idx, int n, vector<int> &coins, int sum, vector<vector<int>> &dp) {
        if (sum == 0) return 0;  // If sum is 0, we need 0 coins
        if (idx >= n) return 1e6;  // If we run out of coins and sum > 0, return large value

        if (dp[idx][sum] != -1) return dp[idx][sum]; // Return memoized result

        // Option 1: Take the current coin (if we can)
        int take = INT_MAX;
        if (sum - coins[idx] >= 0)
            take = 1 + solve(idx, n, coins, sum - coins[idx], dp);

        // Option 2: Skip the current coin
        int skip = solve(idx + 1, n, coins, sum, dp);

        return dp[idx][sum] = min(take, skip);
    }

    int minCoins(vector<int> &coins, int sum) {
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1)); // DP table initialization
        
        int ans = solve(0, n, coins, sum, dp);
        return ans == 1e6 ? -1 : ans; // If no solution, return -1
    }
};


/**
 * Approach: Bottom-Up Dynamic Programming (Tabulation)
 * - Use a 1D DP array to store minimum coins required for each sum.
 * - Iterate over coins and update the DP table.
 *
 * 🔹 **Time Complexity:** O(N * sum)
 * 🔹 **Space Complexity:** O(sum) → Optimized from O(N * sum) to O(sum)
 */

class Solution {
  public:
    int minCoins(vector<int> &coins, int sum) {
        int INF = 1e6; // Large value to indicate "not possible"
        vector<int> dp(sum + 1, INF); 
        dp[0] = 0; // Base case: 0 coins for sum = 0

        for (int coin : coins) {
            for (int j = coin; j <= sum; j++) {
                dp[j] = min(dp[j], 1 + dp[j - coin]); // Take or skip coin
            }
        }

        return dp[sum] == INF ? -1 : dp[sum];
    }
};