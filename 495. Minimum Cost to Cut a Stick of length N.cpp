/*
Minimum Cost to Cut a Stick of length N
Difficulty: HardAccuracy: 84.01%Submissions: 552+Points: 8
You are given a wooden stick of length n, labeled from 0 to n. You are also given an integer array cuts[], where each element cuts[i] represents a position along the stick at which you can make a cut.
Each cut costs an amount equal to the length of the stick being cut at that moment. After performing a cut, the stick is divided into two smaller sticks.
You can perform the cuts in any order. Your task is to determine the minimum total cost required to perform all the cuts.

Example:

Input: n = 10, cuts[] = [2, 4, 7]
Output: 20
Explanation: 
    
If we cut the stick in the order [4, 2, 7], the cost will be 10 + 4 + 6 = 20, which is the minimum total cost.
Input: n = 8, cuts[] = [1, 6, 3, 5]
Output: 19
Explanation: If we cut the stick in the order [3, 6, 1, 5], the cost will be 8 + 5 + 3 + 3 = 19, which is the minimum total cost.
Constraints:
2 ≤ n ≤ 106
1 ≤ cuts[i] ≤ n - 1
1 ≤ cuts.size() ≤ 100
*/

// Intuition:
// The problem asks us to minimize the cost of making cuts in a rod of length `n`.
// The cuts are given as positions in an array, and the cost of each cut is determined
// by the length of the segment being cut. The goal is to find the optimal way to make
// cuts such that the total cost is minimized. This is a classical problem that can be
// solved using dynamic programming (DP).

// Approach:
// 1. We can treat this as a "minimum cost to split" problem, where we need to calculate
//    the minimum cost to cut the rod into segments defined by the positions in `cuts`.
// 2. We define a DP state `dp[l][r]` as the minimum cost to make cuts between positions
//    `cuts[l]` and `cuts[r]` (exclusive). The base case is when the length between two cuts
//    is less than 2, meaning no further cuts are needed, so the cost is 0.
// 3. The recurrence relation is as follows: To calculate `dp[l][r]`, we try making a cut at
//    every position between `l` and `r` and recursively calculate the cost of the resulting two
//    subproblems. The cost for making a cut at `index` is `cuts[r] - cuts[l] + dp[l][index] + dp[index][r]`.
// 4. We use memoization to store previously computed results and avoid redundant calculations.


// Time Complexity:
// The DP table is of size `O(m^2)`, where `m` is the number of cuts (including the initial 0 and `n`).
// For each pair `(l, r)`, we attempt to make cuts at every index between `l` and `r`, leading to
// a time complexity of `O(m^3)` due to the three nested loops:
// 1. The first loop iterates over all possible pairs `(l, r)` (O(m^2)).
// 2. The second loop iterates over all possible intermediate cuts (O(m)).
// Thus, the overall time complexity is `O(m^3)` where `m` is the number of cuts (including 0 and `n`).

// Space Complexity:
// The space complexity is determined by the DP table, which has a size of `O(m^2)`, where `m` is the number of cuts.
// Therefore, the space complexity is `O(m^2)`.

class Solution {
    vector<vector<int>> dp;  // DP table to store the minimum cost between cuts

  public:
    // Helper function to calculate minimum cost to cut between cuts[l] and cuts[r]
    int solve(int l, int r, vector<int>& cuts) {
        // Base case: if the length of the segment is less than 2, no further cuts needed
        if (r - l < 2)
            return 0;

        // If this subproblem is already computed, return the stored result
        if (dp[l][r] != -1)
            return dp[l][r];

        int ans = INT_MAX;  // Initialize the minimum cost as infinity

        // Try making a cut at every position between cuts[l] and cuts[r]
        for (int index = l + 1; index <= r - 1; index++) {
            // The cost of making a cut at `index` is the segment length (cuts[r] - cuts[l]),
            // plus the cost of making cuts between [l, index] and [index, r]
            int cost = cuts[r] - cuts[l] + solve(l, index, cuts) + solve(index, r, cuts);
            
            // Update the minimum cost
            ans = min(ans, cost);
        }

        // Store the result for this subproblem and return it
        return dp[l][r] = ans;
    }

    // Main function to compute the minimum cost of making cuts
    int minCutCost(int n, vector<int>& cuts) {
        // Add the start and end of the rod to the cuts array
        cuts.push_back(0);
        cuts.push_back(n);
        int m = cuts.size();  // Total number of cuts (including 0 and n)

        // Initialize the DP table with -1 (indicating that no subproblem has been solved yet)
        dp.resize(m, vector<int>(m, -1));

        // Sort the cuts array to ensure the cuts are in increasing order
        sort(cuts.begin(), cuts.end());

        // Call the helper function to calculate the minimum cost of making all cuts
        return solve(0, cuts.size() - 1, cuts);
    }
};
