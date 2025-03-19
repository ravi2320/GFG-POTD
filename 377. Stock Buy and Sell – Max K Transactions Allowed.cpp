/*
Stock Buy and Sell – Max K Transactions Allowed
Difficulty: HardAccuracy: 48.35%Submissions: 48K+Points: 8
In the stock market, a person buys a stock and sells it on some future date. You are given an array prices[] representing stock prices on different days and a positive integer k, find out the maximum profit a person can make in at-most k transactions.

A transaction consists of buying and subsequently selling a stock and new transaction can start only when the previous transaction has been completed.

Examples :

Input: prices[] = [10, 22, 5, 80], k = 2
Output: 87
Explaination:
1st transaction: Buy at 10 and sell at 22. 
2nd transaction : Buy at 5 and sell at 80.
Total Profit will be 12 + 75 = 87.
Input: prices[] = [20, 580, 420, 900], k = 3
Output: 1040
Explaination: 
1st transaction: Buy at 20 and sell at 580. 
2nd transaction : Buy at 420 and sell at 900.
Total Profit will be 560 + 480 = 1040.
Input: prices[] = [100, 90, 80, 50, 25],  k = 1
Output: 0
Explaination: Selling price is decreasing continuously
leading to loss. So seller cannot have any profit.
Constraints:
1 ≤ prices.size() ≤ 103
1 ≤ k ≤ 200
1 ≤ prices[i] ≤ 103
*/

/*
Approach:
---------
- We are allowed at most 'k' transactions (buy + sell = 1 transaction) to maximize profit.
- At each day 'idx', we have two choices based on 'buySell' state:
    -> buySell = 1 (we can buy): 
        - Either buy the stock → profit = -prices[idx] + solve(idx+1, 0, k, dp)
        - Or skip → profit = solve(idx+1, 1, k, dp)
    -> buySell = 0 (we can sell):
        - Either sell the stock → profit = prices[idx] + solve(idx+1, 1, k-1, dp)
        - Or skip → profit = solve(idx+1, 0, k, dp)
- We use DP memoization to store intermediate results to avoid recalculation.

States:
-------
1) idx → Current day (0 to n)
2) buySell → Can we buy (1) or sell (0)
3) k → Remaining transactions (0 to k)

Base Cases:
-----------
- If k == 0 → No transactions left → return 0
- If idx == n → No days left → return 0

Time Complexity:
----------------
O(n * k * 2) → n days, k transactions, 2 states (buy/sell)

Space Complexity:
-----------------
O(n * k * 2) for DP table + O(n) recursion stack
*/

class Solution {
    int n; // Number of days
public:
    // Recursive function with memoization
    int solve(int idx, int buySell, vector<int> &prices, int k, vector<vector<vector<int>>> &dp) {
        // Base cases
        if(k == 0 || idx == n) {
            return 0;
        }

        // Check memo table
        if(dp[idx][buySell][k] != -1) {
            return dp[idx][buySell][k];
        }

        // If allowed to buy
        if(buySell) {
            return dp[idx][buySell][k] = max(
                -prices[idx] + solve(idx + 1, 0, prices, k, dp), // Buy
                solve(idx + 1, 1, prices, k, dp)                // Skip
            );
        }
        // If allowed to sell
        else {
            return dp[idx][buySell][k] = max(
                prices[idx] + solve(idx + 1, 1, prices, k - 1, dp), // Sell
                solve(idx + 1, 0, prices, k, dp)                    // Skip
            );
        }
    }

    int maxProfit(vector<int>& prices, int k) {
        n = prices.size(); // Total number of days

        // 3D DP table: dp[n+1][2][k+1]
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(k + 1, -1)));

        // Start from day 0, can buy, and k transactions left
        return solve(0, 1, prices, k, dp);
    }
};


/*
Approach:
---------
- We are solving the problem using Bottom-Up DP (Tabulation).
- DP State:
    dp[idx][buy][cap] → Maximum profit starting from day 'idx', with buy/sell state 'buy' (1-buy, 0-sell), and 'cap' transactions left.
- At each day:
    -> If 'buy' == 1: Either buy stock or skip
    -> If 'buy' == 0: Either sell stock or skip
- Transition:
    dp[idx][1][cap] = max(-prices[idx] + dp[idx+1][0][cap], dp[idx+1][1][cap])
    dp[idx][0][cap] = max(prices[idx] + dp[idx+1][1][cap-1], dp[idx+1][0][cap])
- Final answer: dp[0][1][k] → Start from day 0, allowed to buy, k transactions left.

Time Complexity:
----------------
O(n * 2 * k) = O(nk), where n = number of days, k = max transactions

Space Complexity:
-----------------
O(n * 2 * k) → For DP table

*/

class Solution {
public:
    int maxProfit(vector<int>& prices, int k) {
        int n = prices.size();
        // DP table: dp[n+1][2][k+1] initialized to 0
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(k+1, 0)));

        // Iterate from last day to first
        for(int idx = n-1; idx >= 0; idx--) {
            for(int buy = 0; buy <= 1; buy++) {          // Buy/Sell state
                for(int cap = 1; cap <= k; cap++) {      // Remaining transactions
                    if(buy) {
                        // Buy → -price + move to sell state, or skip
                        dp[idx][buy][cap] = max(
                            -prices[idx] + dp[idx+1][0][cap],
                            dp[idx+1][1][cap]
                        );
                    } else {
                        // Sell → +price + move to buy state (cap - 1), or skip
                        dp[idx][buy][cap] = max(
                            prices[idx] + dp[idx+1][1][cap-1],
                            dp[idx+1][0][cap]
                        );
                    }
                }
            }
        }

        // Start at day 0, can buy, k transactions left
        return dp[0][1][k];
    }
};


/*
Approach:
---------
- We are optimizing the previous Bottom-Up DP solution to reduce space complexity.
- Instead of using a 3D DP table, we use two 2D arrays:
    → curr[2][k+1] → current day
    → after[2][k+1] → next day (future state)
- At each day:
    -> If buy == 1: Choose to buy stock or skip.
    -> If buy == 0: Choose to sell stock or skip.
- We update 'after' state with 'curr' after each day's computation.

Transition:
-----------
- curr[1][cap] = max(-prices[idx] + after[0][cap], after[1][cap])  // Buy
- curr[0][cap] = max(prices[idx] + after[1][cap-1], after[0][cap]) // Sell

Final answer → after[1][k] → Start from day 0, allowed to buy, k transactions left.

Time Complexity:
----------------
O(n * 2 * k) = O(nk)

Space Complexity:
-----------------
O(2 * k) → Optimized space using only two 2D arrays

*/

class Solution {
public:
    int maxProfit(vector<int>& prices, int k) {
        int n = prices.size();

        // Space optimized: Only need curr & after (2 x k+1 arrays)
        vector<vector<int>> curr(2, vector<int>(k+1, 0));
        vector<vector<int>> after(2, vector<int>(k+1, 0));

        // Iterate from last day to first
        for(int idx = n - 1; idx >= 0; idx--) {

            for(int buy = 0; buy <= 1; buy++) {          // Buy/Sell state
                for(int cap = 1; cap <= k; cap++) {      // Remaining transactions

                    if(buy) {
                        // Option to buy or skip
                        curr[buy][cap] = max(
                            -prices[idx] + after[0][cap], // Buy
                            after[1][cap]                 // Skip
                        );
                    } else {
                        // Option to sell or skip
                        curr[buy][cap] = max(
                            prices[idx] + after[1][cap - 1], // Sell
                            after[0][cap]                   // Skip
                        );
                    }
                }
            }

            // Move curr to after for next iteration
            after = curr;
        }

        // Start at day 0, allowed to buy, k transactions left
        return after[1][k];
    }
};