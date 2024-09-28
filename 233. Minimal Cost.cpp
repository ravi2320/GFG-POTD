/*
Minimal Cost
Difficulty: MediumAccuracy: 51.08%Submissions: 58K+Points: 4
There is an array arr of heights of stone and Geek is standing at the first stone and can jump to one of the following: Stone i+1, i+2, ... i+k stone, where k is the maximum number of steps that can be jumped and cost will be |hi-hj| is incurred, where j is the stone to land on. Find the minimum possible total cost incurred before the Geek reaches the last stone.

Example:

Input: k = 3, arr[]= [10, 30, 40, 50, 20]
Output: 30
Explanation: Geek will follow the path 1->2->5, the total cost would be | 10-30| + |30-20| = 30, which is minimum
Input: k = 1, arr[]= [10, 20, 10]
Output: 20
Explanation: Geek will follow the path 1->2->3, the total cost would be |10 - 20| + |20 - 10| = 20.
Expected Time Complexity: O(n*k)
Expected Auxilary Space: O(n)

Constraint:
1<= arr.size() <=104
1 <= k <= 100
1 <= arr[i] <= 104
*/

/*
 * Approach:
 * - Use a recursive function with memoization to minimize the cost of reaching the end of the array.
 * - Start from the first index and at each step, explore up to k forward positions.
 * - Calculate the cost as the absolute difference between the current and next positions.
 * 
 * Time Complexity:
 * - O(n * k), where n is the size of the array, and k is the maximum jump allowed.
 * 
 * Space Complexity:
 * - O(n) for the dp array and the recursion stack.
 */

class Solution {
    int n; // Variable to store the size of the array

public:
    // Recursive function to solve the problem with memoization
    int solve(int i, int k, vector<int> &arr, vector<int> &dp) {
        // Base case: If we reach the last index, the cost is zero
        if (i == n - 1)
            return 0;

        // Return the precomputed result if already solved
        if (dp[i] != -1)
            return dp[i];

        int ans = INT_MAX; // Initialize the answer to a large value

        // Explore next k positions from the current index i
        for (int j = i + 1; j <= i + k && j < n; j++) {
            // Calculate the cost to jump from i to j and recursively solve for j
            int cost = abs(arr[i] - arr[j]) + solve(j, k, arr, dp);
            ans = min(ans, cost); // Update the minimum cost
        }

        // Store and return the result for the current index
        return dp[i] = ans;
    }

    // Main function to minimize the cost
    int minimizeCost(int k, vector<int>& arr) {
        n = arr.size(); // Set the size of the array
        vector<int> dp(n, -1); // Initialize dp array with -1 for memoization
        return solve(0, k, arr, dp); // Start solving from index 0
    }
};
