/*
Stickler Thief II
Difficulty: MediumAccuracy: 52.99%Submissions: 12K+Points: 4Average Time: 30m
You are given an array arr[] which represents houses arranged in a circle, where each house has a certain value. A thief aims to maximize the total stolen value without robbing two adjacent houses.
Determine the maximum amount the thief can steal.

Note: Since the houses are in a circle, the first and last houses are also considered adjacent.

Examples:

Input: arr[] = [2, 3, 2]
Output: 3
Explanation: arr[0] and arr[2] can't be robbed because they are adjacent houses. Thus, 3 is the maximum value thief can rob.
Input: arr[] = [1, 2, 3, 1]
Output: 4
Explanation: Maximum stolen value: arr[0] + arr[2] = 1 + 3 = 4
Input: arr[] = [2, 2, 3, 1, 2]
Output: 5
Explanation: Maximum stolen value: arr[0] + arr[2] = 2 + 3 = 5 or arr[2] + arr[4] = 3 + 2 = 5
Constraints:
2 ≤ arr.size() ≤ 105
0 ≤ arr[i] ≤ 104
*/

/*
    Approach:
    - This problem is a variation of the "House Robber II" problem (Circular DP problem).
    - Since the first and last houses are adjacent (circular condition), we can't take both.
    - So, we split the problem into two cases:
        1. Exclude last element (index 0 to n-2).
        2. Exclude first element (index 1 to n-1).
    - Solve both cases using recursive + memoization approach and take the maximum.

    Intuition:
    - Similar to "Non-Adjacent Sum" problem but with a circular condition.

    Time Complexity: O(N)
        - Each index is visited only once due to memoization.
    Space Complexity: O(N)
        - DP array of size N used for memoization + recursion stack.
*/

class Solution {
  public:
    // Helper function for memoized recursion
    int solve(int idx, vector<int> &arr, int n, vector<int> &dp){
        if (idx >= n) {
            return 0;
        }
        
        if (dp[idx] != -1) {
            return dp[idx];
        }
        
        // Option 1: Take current element and move to idx+2
        int take = arr[idx] + solve(idx + 2, arr, n, dp);
        
        // Option 2: Skip current element
        int skip = solve(idx + 1, arr, n, dp);
        
        // Store and return maximum of take or skip
        return dp[idx] = max(take, skip);
    }

    int maxValue(vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(n + 1, -1);

        // Case 1: Exclude last element (0 to n-2)
        int case1 = solve(0, arr, n - 1, dp);
        
        // Reset dp array for second case
        fill(dp.begin(), dp.end(), -1);
        
        // Case 2: Exclude first element (1 to n-1)
        int case2 = solve(1, arr, n, dp);
        
        // Return maximum of both cases
        return max(case1, case2);
    }
};

/*
    Approach:
    - This problem is a variant of the House Robber II problem (Circular DP).
    - We cannot take both first and last elements because they are adjacent.
    - So, we solve the problem in two cases:
        1. Exclude last element → consider subarray [0, n-2].
        2. Exclude first element → consider subarray [1, n-1].
    - For both cases, apply Bottom-Up DP to find maximum sum without adjacent elements.
    - Finally, return the maximum of both cases.

    Intuition:
    - Reduce circular problem into two linear problems and apply standard DP.

    Time Complexity: O(N)
    Space Complexity: O(N) → can be optimized to O(1)
*/

class Solution {
  public:
    int maxValue(vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(n+2, 0);  // Extra space to handle out-of-bound access
        
        // Case 1: Exclude last element, consider arr[0] to arr[n-2]
        for(int i = n - 2; i >= 0; i--) {
            dp[i] = max(arr[i] + dp[i+2], dp[i+1]);
        }
        int case1 = dp[0];

        // Reset dp array for next case
        fill(dp.begin(), dp.end(), 0);
        
        // Case 2: Exclude first element, consider arr[1] to arr[n-1]
        for(int i = n - 1; i >= 1; i--) {
            dp[i] = max(arr[i] + dp[i+2], dp[i+1]);
        }
        int case2 = dp[1];

        // Return the maximum of both cases
        return max(case1, case2);
    }
};


/*
    Approach:
    - Problem is similar to House Robber II (circular array, can't take both first and last).
    - Split problem into two cases:
        1. Exclude last element → consider arr[0] to arr[n-2].
        2. Exclude first element → consider arr[1] to arr[n-1].
    - For both cases, apply space-optimized Bottom-Up DP.
    - In DP:
        - curr = max(arr[i] + secNext, next)
        - secNext = next, next = curr
    - Finally, return max(case1, case2).

    Intuition:
    - Standard House Robber solution applied twice due to circular nature.
    - Space optimization achieved by using 3 variables instead of DP array.

    Time Complexity: O(N)
    Space Complexity: O(1)
*/

class Solution {
  public:
    int maxValue(vector<int>& arr) {
        int n = arr.size();
        
        // Case 1: Exclude last element, consider arr[0] to arr[n-2]
        int curr = 0, next = 0, secNext = 0;
        for (int i = n - 2; i >= 0; i--) {
            curr = max(arr[i] + secNext, next);
            secNext = next;
            next = curr;
        }
        int case1 = next;
        
        // Reset variables for second case
        curr = 0, next = 0, secNext = 0;
        
        // Case 2: Exclude first element, consider arr[1] to arr[n-1]
        for (int i = n - 1; i >= 1; i--) {
            curr = max(arr[i] + secNext, next);
            secNext = next;
            next = curr;
        }
        int case2 = next;
        
        // Return maximum of both cases
        return max(case1, case2);
    }
};