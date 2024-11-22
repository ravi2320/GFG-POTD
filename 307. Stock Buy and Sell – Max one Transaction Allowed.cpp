/*
Stock Buy and Sell – Max one Transaction Allowed
Difficulty: EasyAccuracy: 49.33%Submissions: 31K+Points: 2
Given an array prices[] of length n, representing the prices of the stocks on different days. The task is to find the maximum profit possible by buying and selling the stocks on different days when at most one transaction is allowed. Here one transaction means 1 buy + 1 Sell. If it is not possible to make a profit then return 0.

Note: Stock must be bought before being sold.

Examples:

Input: prices[] = [7, 10, 1, 3, 6, 9, 2]
Output: 8
Explanation: You can buy the stock on day 2 at price = 1 and sell it on day 5 at price = 9. Hence, the profit is 8.
Input: prices[] = [7, 6, 4, 3, 1]
Output: 0 
Explanation: Here the prices are in decreasing order, hence if we buy any day then we cannot sell it at a greater price. Hence, the answer is 0.
Input: prices[] = [1, 3, 6, 9, 11]
Output: 10 
Explanation: Since the array is sorted in increasing order, we can make maximum profit by buying at price[0] and selling at price[n-1].
Constraint:
1 <= prices.size()<= 105
0 <= prices[i] <=104
*/

/*
Approach:
1. We aim to maximize the profit from a single buy-sell operation in a list of stock prices.
2. To solve this:
   - Initialize `mini` to the first price as the minimum price encountered so far.
   - Initialize `profit` to 0.
   - Iterate through the list of prices starting from the second element.
   - For each price, update `mini` with the lowest price encountered so far.
   - Calculate the potential profit by subtracting `mini` from the current price.
   - Update `profit` if the current potential profit is higher.
3. The final result is the maximum profit achievable from a single buy-sell operation.

Time Complexity:
- O(n) — where `n` is the number of elements in the `prices` vector. We only loop through the list once.

Space Complexity:
- O(1) — only a few variables are used for calculation.

*/

class Solution {
  public:
    // Function to find the maximum profit from a single buy-sell stock transaction
    int maximumProfit(vector<int> &prices) {
        int profit = 0;           // Initialize the maximum profit
        int mini = prices[0];     // Initialize the minimum price to the first price
        int n = prices.size();    // Number of prices

        // Iterate over prices starting from the second price
        for (int i = 1; i < n; i++) {
            // Update the minimum price encountered so far
            mini = min(mini, prices[i]);
            
            // Calculate potential profit and update the maximum profit if higher
            profit = max(profit, prices[i] - mini);
        }
        
        return profit;  // Return the maximum profit found
    }
};
