/*
Coin Piles
Difficulty: MediumAccuracy: 20.51%Submissions: 37K+Points: 4Average Time: 20m
You are given an array arr[] of integers, where each element represents the number of coins in a pile. You are also given an integer k.
Your task is to remove the minimum number of coins such that the absolute difference between the number of coins in any two updated piles is at most k.

Note: You can also remove a pile by removing all the coins of that pile.

Examples:

Input: arr[] = [2, 2, 2, 2], k = 0
Output: 0
Explanation: For any two piles the difference in the number of coins is <= 0. So no need to remove any coin. 
Input: arr[] = [1, 5, 1, 2, 5, 1], k = 3
Output: 2
Explanation: If we remove one coin each from both the piles containing 5 coins, then for any two piles the absolute difference in the number of coins is <= 3. 
Constraints:
1 ≤ arr.size() ≤ 105
1 ≤ arr[i] ≤ 104
0 ≤ k ≤ 104
*/

/*
Approach:
We are given an array `arr` of coin values and an integer `k`. The goal is to minimize the extra coins
required to ensure that the value of every coin after the i-th index is at most `arr[i] + k`.

Steps:
1. Sort the array.
2. Use a prefix sum array to store cumulative values of coins for quick range sum queries.
3. For each position `i`, find the position `pos` such that `arr[pos] > arr[i] + k` using upper_bound.
   This ensures all coins beyond index `i` should be ≤ arr[i] + k.
4. Calculate:
   - `total`: sum of coin values from pos to n-1
   - `allowed`: maximum allowed sum for those coins = (count) * (arr[i] + k)
   - `extraCoins`: overpaid amount from beyond `pos` and before `i`
5. Track the minimum `extraCoins` among all i.

Intuition:
We are finding a reference value `arr[i] + k` and trimming coins that exceed this threshold.
We balance the sum across coins using prefix sums and binary search to minimize overpayment.

Time Complexity: O(n log n)
- Sorting: O(n log n)
- For each index: upper_bound takes O(log n), so total O(n log n)

Space Complexity: O(n)
- For the prefix sum array
*/

class Solution {
  public:
    int minimumCoins(vector<int>& arr, int k) {
        int n = arr.size();

        // Sort the array
        sort(arr.begin(), arr.end());

        // Build prefix sum array
        vector<int> prefixSum(n);
        prefixSum[0] = arr[0];
        for (int i = 1; i < n; i++) {
            prefixSum[i] = prefixSum[i - 1] + arr[i];
        }

        int ans = INT_MAX;
        int prev = 0; // sum of coins before current index i

        for (int i = 0; i < n; i++) {
            if (i != 0) {
                prev = prefixSum[i - 1];
            }

            // Find index where arr[pos] > arr[i] + k
            int pos = upper_bound(arr.begin() + i, arr.end(), arr[i] + k) - arr.begin();

            // Sum of values from pos to end
            int total = pos > 0 ? prefixSum[n - 1] - prefixSum[pos - 1] : 0;

            // Maximum allowed value for coins from pos to end
            int allowed = (n - pos) * (arr[i] + k);

            // Extra coins spent = (value spent) - (value allowed)
            int extraCoins = total + prev - allowed;

            // Track minimum across all positions
            ans = min(ans, extraCoins);
        }

        return ans;
    }
};
