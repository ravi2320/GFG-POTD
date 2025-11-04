/*
Frog Jump

avatar
Discuss Approach
arrow-up
Difficulty: MediumAccuracy: 49.55%Submissions: 177K+Points: 4Average Time: 15m
Given an integer array height[] where height[i] represents the height of the i-th stair, a frog starts from the first stair and wants to reach the last stair. From any stair i, the frog has two options: it can either jump to the (i+1)th stair or the (i+2)th stair. The cost of a jump is the absolute difference in height between the two stairs. Determine the minimum total cost required for the frog to reach the last stair.

Example:

Input: heights[] = [20, 30, 40, 20]
Output: 20
Explanation:  Minimum cost is incurred when the frog jumps from stair 0 to 1 then 1 to 3:
jump from stair 0 to 1: cost = |30 - 20| = 10
jump from stair 1 to 3: cost = |20 - 30| = 10
Total Cost = 10 + 10 = 20
Input: heights[] = [30, 20, 50, 10, 40]
Output: 30
Explanation: Minimum cost will be incurred when frog jumps from stair 0 to 2 then 2 to 4:
jump from stair 0 to 2: cost = |50 - 30| = 20
jump from stair 2 to 4: cost = |40 - 50| = 10
Total Cost = 20 + 10 = 30
Constraints:
1 ≤ height.size() ≤ 105
0 ≤ height[i] ≤ 104
*/

// Intuition:
// The problem is to minimize the cost of jumping from the first stone to the last stone,
// where the cost of jumping from stone i to stone j is the absolute difference in their heights.
// At each stone, you can either:
// 1. Jump from the previous stone (i-1), or
// 2. Jump from two stones back (i-2), if possible.
// The solution uses dynamic programming (DP) to store the minimum cost of reaching each stone.
// We use memoization to avoid recalculating the result for the same subproblem.
// The goal is to compute the minimum cost to reach the last stone (n-1).

// Time Complexity:
// O(n), where n is the number of elements in the height vector.
// The function `solve()` is called recursively for each index, but each subproblem is computed at most once.
// The dp array stores the results of subproblems, so no subproblem is recalculated, leading to linear time complexity.

// Space Complexity:
// O(n), due to the dp array used to store the minimum cost to reach each index. 
// The recursion depth also contributes to the space complexity, which is O(n) in the worst case.

class Solution {
    vector<int> dp;  // dp array to store the minimum cost for each index

  public:
    // Helper function to compute the minimum cost to reach the current index
    int solve(int idx, vector<int> &height){
        // Base case: if we're at the first stone, no cost to reach it
        if(idx == 0)
            return 0;
        
        // If this subproblem has already been solved (i.e., dp[idx] is not -1), return the stored result
        if(dp[idx] != -1)
            return dp[idx];
        
        // Option 1: Jump from the previous stone (idx-1)
        int one = solve(idx - 1, height) + abs(height[idx] - height[idx-1]);
        
        // Option 2: Jump from two stones back (idx-2), if possible
        int two = INT_MAX;  // Initialize with a very high value (infinity)
        if(idx > 1)
            two = solve(idx - 2, height) + abs(height[idx] - height[idx - 2]);
        
        // Store the minimum cost in dp[idx] and return the result
        return dp[idx] = min(one, two);
    }
    
    // Main function to calculate the minimum cost to reach the last index
    int minCost(vector<int>& height) {
        int n = height.size();
        
        // If there is only one stone, no cost is needed
        if(n == 1)
            return 0;
        
        // Initialize the dp array with -1 (indicating no subproblem has been solved yet)
        dp.resize(n, -1);
        
        // Start solving from the last index and return the minimum cost to reach it
        return solve(n-1, height);
    }
};
