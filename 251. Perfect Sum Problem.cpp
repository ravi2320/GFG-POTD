/*
Perfect Sum Problem
Difficulty: MediumAccuracy: 20.58%Submissions: 401K+Points: 4
Given an array arr of size n of non-negative integers and an integer sum, the task is to count all subsets of the given array with a sum equal to a given sum.

Note: Answer can be very large, so, output answer modulo 109+7.

Examples:

Input: 
n = 6, arr = [5, 2, 3, 10, 6, 8], sum = 10
Output: 
3
Explanation: 
{5, 2, 3}, {2, 8}, {10} are possible subsets.
Input: 
n = 5, arr = [2, 5, 1, 4, 3], sum = 10
Output: 
3
Explanation: 
{2, 1, 4, 3}, {5, 1, 4}, {2, 5, 3} are possible subsets.

Expected Time Complexity: O(n*sum)
Expected Auxiliary Space: O(n*sum)

Constraints:
1 ≤ n*sum ≤ 106
0 ≤ arr[i] ≤ 106
*/

/*
Approach:
1. This problem is about counting subsets whose sum equals a given target.
   
2. We use recursion to solve the problem and apply memoization to store already computed results to avoid recomputation (Dynamic Programming - DP).

3. **Base Cases**:
   - If the sum is non-zero and we have no elements left (`n == 0`), then we return 0 as no valid subset exists.
   - If there is one element (`n == 1`):
     - If the element matches the sum, return 1.
     - If the element is zero and the sum is zero, return 2 (counting both including and excluding the zero).
   - If both `n == 0` and `sum == 0`, return 1 (empty subset).

4. **Recursion and Memoization**:
   - We either include the current element in the subset or exclude it.
   - We use a `dp` table where `dp[n][sum]` stores the result of subsets that add up to `sum` using the first `n` elements.

5. **Time Complexity**:
   - **O(n * sum)**: Each subproblem is computed once due to memoization, and there are `n * sum` subproblems.
   
6. **Space Complexity**:
   - **O(n * sum)**: Space is used by the `dp` table.

*/

class Solution {
  public:
    int mod = 1e9 + 7; // Modulo value for large numbers to prevent overflow

    // Recursive function to calculate the number of subsets with a given sum
    int solve(int arr[], int n, int sum, vector<vector<int>> &dp) {
        // Check if the result has been computed previously (memoization)
        if (dp[n][sum] != -1) 
            return dp[n][sum];
        
        // If no elements left and sum is greater than zero, return 0
        if (n == 0 && sum > 0) 
            return 0;
        
        // If there's only one element to consider
        if (n == 1) {
            if (sum == 0) {
                if (arr[0] == 0) 
                    return 2; // Two possibilities: include or exclude the zero
                else 
                    return 1; // One possibility: exclude the element
            } else {
                if (arr[0] == sum) 
                    return 1; // Subset equals the sum
                else 
                    return 0; // No subset equals the sum
            }
        }

        // If no elements left and sum is zero, there's one valid subset: the empty subset
        if (n == 0 && sum == 0) 
            return 1;

        // Calculate the number of subsets excluding the current element
        int ans = solve(arr, n - 1, sum, dp) % mod;

        // If the current element can be included in the subset, calculate including it
        if (arr[n - 1] <= sum) {
            ans += solve(arr, n - 1, sum - arr[n - 1], dp) % mod;
            ans = ans % mod; // Apply modulo to avoid overflow
        }

        // Store the computed result in the dp table
        return dp[n][sum] = ans;
    }
    
    // Function to return the count of subsets with sum equal to a given value
    int perfectSum(int arr[], int n, int sum) {
        // Initialize dp table with -1 (indicating uncomputed states)
        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));
        
        // Call the recursive function with memoization
        return solve(arr, n, sum, dp) % mod;
    }
};
