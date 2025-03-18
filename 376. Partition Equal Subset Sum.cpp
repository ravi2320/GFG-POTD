/*
Partition Equal Subset Sum
Difficulty: MediumAccuracy: 30.24%Submissions: 256K+Points: 4
Given an array arr[], determine if it can be partitioned into two subsets such that the sum of elements in both parts is the same.

Note: Each element must be in exactly one subset.

Examples:

Input: arr = [1, 5, 11, 5]
Output: true
Explanation: The two parts are [1, 5, 5] and [11].
Input: arr = [1, 3, 5]
Output: false
Explanation: This array can never be partitioned into two such parts.
Constraints:
1 ≤ arr.size ≤ 100
1 ≤ arr[i] ≤ 200
*/

/*
Approach:
---------
- Check if the total sum is even. If odd, partition is not possible.
- Use recursion + memoization to check if a subset with sum = total_sum / 2 exists.
- For each index 'i' and current sum, we check:
    1. Include arr[i] and add to currSum.
    2. Exclude arr[i].
- Memoize the result for each (i, currSum) state to avoid recomputation.

Intuition:
----------
- Classic DP problem with overlapping subproblems and optimal substructure.
- Memoization avoids recalculating the same state repeatedly.

Time Complexity: O(n * sum)
---------------------------
- Each state (i, currSum) is computed once.
- Total states = n * (sum/2).

Space Complexity: O(n * sum)
----------------------------
- DP table of size n * sum.
- Recursive stack depth = O(n).
*/

class Solution {
    int n, sum;
  public:
    // Recursive function with memoization
    bool solve(int i, int currSum, vector<int>& arr, vector<vector<int>> &dp){
        // Base case: Found equal partition
        if(currSum == sum - currSum){
            return true;
        }
        
        // Base case: no more elements
        if(i >= n){
            return false;
        }
        
        // Check if already computed
        if(dp[i][currSum] != -1){
            return dp[i][currSum];
        }
        
        // Include arr[i]
        if(solve(i+1, currSum + arr[i], arr, dp)){
            return dp[i][currSum] = true;
        }
        
        // Exclude arr[i]
        if(solve(i+1, currSum, arr, dp)){
            return dp[i][currSum] = true;
        }
        
        return dp[i][currSum] = false;
    }

    bool equalPartition(vector<int>& arr) {
        n = arr.size();
        sum = accumulate(arr.begin(), arr.end(), 0);
        
        // If sum is odd, partition is not possible
        if(sum % 2 != 0) return false;
        
        vector<vector<int>> dp(n+1, vector<int>(sum+1, -1));
        return solve(0, 0, arr, dp);
    }
};