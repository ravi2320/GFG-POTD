/*
Min Cost Climbing Stairs
Difficulty: MediumAccuracy: 50.04%Submissions: 17K+Points: 4
Given an array of integers cost[] where cost[i] is the cost of the ith step on a staircase. Once the cost is paid, you can either climb one or two steps. Return the minimum cost to reach the top of the floor.
Assume 0-based Indexing. You can either start from the step with index 0, or the step with index 1.

Examples:

Input: cost[] = [10, 15, 20]
Output: 15
Explanation: Cheapest option is to start at cost[1], pay that cost, and go to the top.



Input: cost[] = [1, 100, 1, 1, 1, 100, 1, 1, 100, 1]
Output: 6
Explanation: Cheapest option is to start on cost[0], and only step on 1s, skipping cost[3].


Constraints:
2 ≤ cost.size() ≤ 105
0 ≤ cost[i] ≤ 999
*/

/**
 * Approach:
 * - Define `solve(i)` as the **minimum cost** to reach step `i`.
 * - You can start from **index 0 or index 1**.
 * - **Recurrence relation:** `dp[i] = cost[i] + min(dp[i+1], dp[i+2])`
 * - Base case: If `i >= n`, return `0` (no more cost).
 * 
 * 🔹 **Time Complexity:** O(N) → Each state is computed once.
 * 🔹 **Space Complexity:** O(N) → Recursion stack + dp array.
 */

class Solution {
    int n;
  public:
    int solve(int i, vector<int> &cost, vector<int> &dp) {
        if (i >= n) return 0; // Base case: No cost beyond top

        if (dp[i] != -1) return dp[i]; // Memoization

        return dp[i] = cost[i] + min(solve(i + 1, cost, dp), solve(i + 2, cost, dp));
    }

    int minCostClimbingStairs(vector<int>& cost) {
        n = cost.size();
        vector<int> dp(n, -1);
        
        // Start from index 0 or 1 and take the minimum cost
        return min(solve(0, cost, dp), solve(1, cost, dp));
    }
};
