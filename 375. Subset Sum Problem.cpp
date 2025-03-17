/*
Subset Sum Problem
Difficulty: MediumAccuracy: 32.0%Submissions: 322K+Points: 4
Given an array of positive integers arr[] and a value sum, determine if there is a subset of arr[] with sum equal to given sum. 

Examples:

Input: arr[] = [3, 34, 4, 12, 5, 2], sum = 9
Output: true 
Explanation: Here there exists a subset with target sum = 9, 4+3+2 = 9.
Input: arr[] = [3, 34, 4, 12, 5, 2], sum = 30
Output: false
Explanation: There is no subset with target sum 30.
Input: arr[] = [1, 2, 3], sum = 6
Output: true
Explanation: The entire array can be taken as a subset, giving 1 + 2 + 3 = 6.
Constraints:
1 <= arr.size() <= 200
1<= arr[i] <= 200
1<= sum <= 104
*/

/*
Approach:
---------
- Use recursion + memoization to check if a subset with the given sum exists.
- For each index i and remaining sum, we check two options:
    1. Include arr[i] if arr[i] <= sum.
    2. Exclude arr[i].
- Store the result for each (i, sum) state to avoid recomputation.

Intuition:
----------
- Classic DP problem with overlapping subproblems and optimal substructure.
- Memoization avoids redundant calculations.

Time Complexity: O(n * sum)
---------------------------
- Each state (i, sum) is computed once.
- Total states = n * sum.

Space Complexity: O(n * sum)
----------------------------
- DP table of size n * sum.
- Recursive stack depth = O(n).
*/

class Solution {
  public:
    // Recursive function with memoization
    bool solve(int i, int sum, vector<int> &arr, vector<vector<int>> &dp){
        // Base case: sum achieved
        if(sum == 0) return true;
        
        // Base case: no more elements
        if(i >= arr.size()) return false;
        
        // Check if already computed
        if(dp[i][sum] != -1) return dp[i][sum];
        
        // Include current element if it doesn't exceed the sum
        if(arr[i] <= sum){
            if(solve(i+1, sum - arr[i], arr, dp)) 
                return dp[i][sum] = true;
        }
        
        // Exclude current element
        if(solve(i+1, sum, arr, dp)) 
            return dp[i][sum] = true;
        
        // No valid subset found
        return dp[i][sum] = false;
    }

    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        
        // Initialize dp table with -1 (uncomputed)
        vector<vector<int>> dp(n+1, vector<int>(sum+1, -1));
        
        return solve(0, sum, arr, dp);
    }
};