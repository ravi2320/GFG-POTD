/*
Count ways to N'th Stair(Order does not matter)
Difficulty: MediumAccuracy: 50.49%Submissions: 57K+Points: 4
There are n stairs, and a person standing at the bottom wants to reach the top. The person can climb either 1 stair or 2 stairs at a time. Count the number of ways, the person can reach the top (order does not matter).
Note: Order does not matter means for n = 4:- {1 2 1},{2 1 1},{1 1 2} are considered same.

Examples :

Input: n = 4
Output: 3
Explanation: Three ways to reach at 4th stair. They are {1, 1, 1, 1}, {1, 1, 2}, {2, 2}.
Input: n = 5
Output: 3
Explanation: Three ways to reach at 5th stair. They are {1, 1, 1, 1, 1}, {1, 1, 2, 1} and {1, 2, 2}.
Expected Time Complexity: O(n)
Expected Space Complexity: O(n)

Constraints:
1 ≤ n ≤ 104
*/

/*
**Problem Statement:**
- Given a staircase with `n` steps, you can either take 1 step or 2 steps at a time. The goal is to determine the number of ways to reach the nth step, assuming you can start from step 0.

**Approach:**
1. **Dynamic Programming:**
   - The problem is solved using dynamic programming with a recursive approach. 
   - A memoization array `dp` is used to store the number of ways to reach each step, which avoids redundant calculations.
   - The base cases are:
     - `f(0) = 1`: There's only one way to stay at step 0 (by not moving).
     - `f(1) = 1`: There's only one way to reach step 1, which is by taking a single step from step 0.
   - For each step `n`, the number of ways to reach that step is calculated by taking one step from `n-1` or two steps from `n-2`.

2. **Time Complexity:**
   - The time complexity of this approach is `O(n)`, since each state `f(n)` is computed once and stored in the `dp` array.

3. **Space Complexity:**
   - The space complexity is also `O(n)` due to the `dp` array storing results for each step from 0 to `n`.

**Example Usage:**
- Given `n = 4`, the function will return `3`, representing the three ways to reach the 4th step: (1,1,1,1), (1,1,2), and (2,2).

*/

class Solution {
public:
    // Helper function that returns the number of ways to reach step `n`
    int f(int n, vector<int> &dp) {
        if(n == 0) return 1; // Base case: Only one way to stay at step 0
        if(n == 1) return 1; // Base case: Only one way to reach step 1

        if(dp[n] != -1) return dp[n]; // Return cached result if already computed

        // Store the computed result in dp array
        return dp[n] = 1 + min(f(n-1, dp), f(n-2, dp));
    }

    // Main function to find the number of ways to reach the nth step
    int nthStair(int n) {
        vector<int> dp(n + 1, -1); // Initialize dp array with -1 for memoization
        return f(n, dp); // Start the recursion from step n
    }
};

// Example usage:
int main() {
    Solution sol;
    int n = 4;
    int result = sol.nthStair(n);
    cout << "Number of ways to reach the " << n << "th step: " << result << endl; // Output should be 3
    return 0;
}
