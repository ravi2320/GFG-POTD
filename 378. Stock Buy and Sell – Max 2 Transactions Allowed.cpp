/*
Stock Buy and Sell – Max 2 Transactions Allowed
Difficulty: HardAccuracy: 50.13%Submissions: 60K+Points: 8Average Time: 20m
In daily share trading, a trader buys shares and sells them on the same day. If the trader is allowed to make at most 2 transactions in a day, find out the maximum profit that a share trader could have made.

You are given an array prices[] representing stock prices throughout the day. Note that the second transaction can only start after the first one is complete (buy->sell->buy->sell).

Examples:

Input: prices[] = [10, 22, 5, 75, 65, 80]
Output: 87
Explanation: 
Trader will buy at 10 and sells at 22. 
Profit earned in 1st transaction = 22 - 10 = 12. 
Then he buys at 5 and sell at 80. 
Profit earned in 2nd transaction = 80 - 5 = 75. 
Total profit earned = 12 + 75 = 87. 
Input: prices[] = [2, 30, 15, 10, 8, 25, 80]
Output: 100
Explanation: 
Trader will buy at 2 and sells at 30. 
Profit earned in 1st transaction = 30 - 2 = 28. 
Then he buys at 8 and sell at 80. 
Profit earned in 2nd transaction = 80 - 8 = 72. 
Total profit earned = 28 + 72 = 100.
Constraints:
1 <= prices.size() <= 105
1 <= prices[i] <= 105
*/

/*
Approach:
---------
- Similar to Best Time to Buy & Sell Stock IV but k is fixed = 2.
- We reduce space by keeping only two 2D arrays:
    → curr[2][3] → current day
    → after[2][3] → next day
- For each day:
    -> buy == 1: Either buy or skip
    -> buy == 0: Either sell or skip
- Maximum 2 transactions allowed → cap ∈ [1,2].

Transition:
-----------
- curr[1][cap] = max(-prices[idx] + after[0][cap], after[1][cap])  // Buy
- curr[0][cap] = max(prices[idx] + after[1][cap-1], after[0][cap]) // Sell

Final answer → after[1][2] → Start at day 0, buy allowed, 2 transactions left.

Time Complexity:
----------------
O(n * 2 * 2) → O(n)

Space Complexity:
-----------------
O(2 * 3) → Optimized space

*/

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        vector<vector<int>> after(2, vector<int>(3, 0)); // after[buy][cap]
        vector<vector<int>> curr(2, vector<int>(3, 0));  // curr[buy][cap]
        
        // Iterate backward from last day
        for(int idx = n - 1; idx >= 0; idx--) {
            for(int cap = 1; cap <= 2; cap++) {         // Max 2 transactions
                for(int buy = 0; buy <= 1; buy++) {     // Buy or Sell state
                    
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
            // Update after for next day
            after = curr;
        }
        
        // Starting at day 0, allowed to buy, 2 transactions left
        return after[1][2];
    }
};