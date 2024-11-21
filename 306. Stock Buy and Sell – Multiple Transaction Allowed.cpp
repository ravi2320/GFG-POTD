/*
Stock Buy and Sell – Multiple Transaction Allowed
Difficulty: HardAccuracy: 13.43%Submissions: 126K+Points: 8
The cost of stock on each day is given in an array price[]. Each day you may decide to either buy or sell the stock at price[i], you can even buy and sell the stock on the same day. Find the maximum profit that you can get.

Note: A stock can only be sold if it has been bought previously and multiple stocks cannot be held on any given day.

Examples:

Input: prices[] = [100, 180, 260, 310, 40, 535, 695]
Output: 865
Explanation: Buy the stock on day 0 and sell it on day 3 => 310 – 100 = 210. Buy the stock on day 4 and sell it on day 6 => 695 – 40 = 655. Maximum Profit = 210 + 655 = 865.

Input: prices[] = [4, 2, 2, 2, 4]
Output: 2
Explanation: Buy the stock on day 3 and sell it on day 4 => 4 – 2 = 2. Maximum Profit = 2.
Constraints:
1 <= prices.size() <= 105
0 <= prices[i] <= 104
*/

/*
Approach:
1. To maximize profit from stock trading with unlimited transactions, buy when there is an opportunity for profit. This means adding up all instances where the price increases from one day to the next.
2. Iterate through the list of stock prices. For each day, calculate the difference between the current day and the previous day.
   - If the difference is positive (i.e., the price increased), add it to the total profit.
   - Ignore any days where the price decreased or stayed the same.

Time Complexity:
- O(n) — We only traverse the prices array once, where n is the number of days.

Space Complexity:
- O(1) — No additional space required apart from variables to track profit.

*/

class Solution {
public:
    // Function to calculate the maximum profit with unlimited transactions
    int maximumProfit(vector<int> &prices) {
        int n = prices.size();         // Total number of days
        int totalProfit = 0;           // Accumulated profit

        // Iterate over the prices starting from the second day
        for (int i = 1; i < n; i++) {
            // Calculate the profit from buying on the previous day and selling today
            int currProfit = prices[i] - prices[i - 1];

            // If the profit is positive, add it to the total profit
            if (currProfit > 0) {
                totalProfit += currProfit;
            }
        }

        return totalProfit;  // Return the total maximum profit
    }
};
