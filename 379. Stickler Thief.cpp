/*
Stickler Thief
Difficulty: MediumAccuracy: 37.98%Submissions: 239K+Points: 4Average Time: 20m
Stickler the thief wants to loot money from the houses arranged in a line. He cannot loot two consecutive houses and aims to maximize his total loot.
Given an array, arr[] where arr[i] represents the amount of money in the i-th house.
Determine the maximum amount he can loot.

Examples:

Input: arr[] = [6, 5, 5, 7, 4]
Output: 15
Explanation: Maximum amount he can get by looting 1st, 3rd and 5th house. Which is 6 + 5 + 4 = 15.
Input: arr[] = [1, 5, 3]
Output: 5
Explanation: Loot only 2nd house and get maximum amount of 5.
Input: arr[] = [4, 4, 4, 4]
Output: 8
Explanation: The optimal choice is to loot every alternate house. Looting the 1st and 3rd houses, or the 2nd and 4th, both give a maximum total of 4 + 4 = 8.
Constraints:
1 ≤ arr.size() ≤ 105
1 ≤ arr[i] ≤ 104
*/

/*
    Approach:
    - Classic problem of "House Robber" type: For each element, you decide whether to pick it and skip the next one or skip it.
    - Use recursion with memoization (Top-Down DP) to store already computed results in a dp[] array to avoid recomputation.

    Intuition:
    - Since you can't pick adjacent elements, at each index:
        - Either pick the current element + recursively call for idx+2.
        - Or skip current element and move to idx+1.
    - Return the maximum of both choices.
    
    Time Complexity: O(N)
        - Each index is visited once due to memoization.
    Space Complexity: O(N)
        - dp[] array of size N used for memoization + recursion stack.
*/

class Solution {
  public:
    // Recursive function with memoization
    int solve(int idx, vector<int> &arr, int n, vector<int> &dp){
        // Base case: if index goes out of bounds, return 0
        if(idx >= n){
            return 0;
        }
        
        // If already computed, return stored result
        if(dp[idx] != -1){
            return dp[idx];
        }
        
        // Option 1: Take current element and skip next
        int take = arr[idx] + solve(idx+2, arr, n, dp);
        
        // Option 2: Skip current element
        int skip = solve(idx+1, arr, n, dp);
        
        // Store and return max of both
        return dp[idx] = max(take, skip);
    }

    int findMaxSum(vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(n+1, -1);  // dp[i] stores max sum from index i
        return solve(0, arr, n, dp);
    }
};


/*
    Approach:
    - Bottom-Up Dynamic Programming (Tabulation) solution.
    - Starting from the end of the array, we decide at each index whether to:
        1. Take the current element and add dp[i+2].
        2. Skip the current element and take dp[i+1].
    - We use a dp[] array of size n+2 (to avoid index out of bounds).

    Intuition:
    - Similar to the "House Robber" problem.
    - Since adjacent elements cannot be picked together, we check two options at every index and store the maximum sum possible from that point onward.

    Time Complexity: O(N)
        - Single pass through the array from end to start.
    Space Complexity: O(N)
        - dp[] array of size n+2 used.
*/

class Solution {
  public:
    int findMaxSum(vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(n+2, 0);  // Extra space to handle out-of-bound cases for dp[i+2]
        
        // Traverse from the end towards the beginning
        for(int i = n-1; i >= 0; i--) {
            // Two choices: take current element + dp[i+2], or skip current element (dp[i+1])
            dp[i] = max(arr[i] + dp[i+2], dp[i+1]);
        }
        
        return dp[0];  // Maximum sum starting from index 0
    }
};


/*
    Approach:
    - Space Optimized Bottom-Up Dynamic Programming.
    - Instead of using a DP array, we use three variables:
        1. curr: Stores the maximum sum at current index.
        2. next: Stores the maximum sum at index i+1.
        3. secNext: Stores the maximum sum at index i+2.
    - We iterate backwards and update these variables accordingly.

    Intuition:
    - At each index, we decide:
        1. Take current element + secNext (skip next element).
        2. Skip current element and take next.
    - We store only the last two results instead of the entire DP array.

    Time Complexity: O(N)
        - Single traversal through the array.
    Space Complexity: O(1)
        - Constant extra space used (3 variables).
*/

class Solution {
  public:
    int findMaxSum(vector<int>& arr) {
        int n = arr.size();
        int next = 0, secNext = 0, curr = 0;
        
        // Iterate from end to start
        for (int i = n - 1; i >= 0; i--) {
            // Max of taking current + secNext OR skipping current
            curr = max(arr[i] + secNext, next);
            
            // Move variables forward
            secNext = next;
            next = curr;
        }
        
        return next;  // Final result stored in 'next'
    }
};