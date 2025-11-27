/*
All Subsets Xor Sum

avatar
Discuss Approach
arrow-up
Difficulty: MediumAccuracy: 66.8%Submissions: 7K+Points: 4
Given an array arr[], return the sum of the XOR of all elements for every possible subset of the array. Subsets with the same elements should be counted multiple times.

An array a is a subset of an array b if a can be obtained from b by deleting some (possibly zero) elements of b.

Note: The answer is guaranteed to fit within a 32-bit integer.

Examples:

Input: arr[] = [7, 2]
Output: 14
Explanation: Subsets are: [[], [7], [2], [7, 2]]
Sum of all XOR's = 7 + 2 + (7 ^ 2) = 14.
Input: arr[] = [1, 2, 3]
Output: 12
Explanation: Subsets are: [[], [1], [2], [3], [1, 2], [1, 3], [2, 3], [1, 2, 3]]
Sum of all XOR's = 1 + 2 + 3 + (1 ^ 2)  + (1 ^ 3) + (2 ^ 3) + (1 ^ 2 ^ 3) = 12.
Constraints:
1 ≤ arr.size() ≤ 30
1 ≤ arr[i] ≤ 103
*/

/*
Intuition:
-----------
We want the sum of XOR of all possible subsets of the array.
Each element can either:
1. Be included in the subset → (Xor ^ arr[i])
2. Be excluded → (Xor)

This forms a classic recursion over subsets (2^n subsets total).

To avoid recomputation, we use **DP memoization**:
    dp[i][Xor] = sum of XOR values of all subsets starting from index i
                 with current XOR = Xor.

Why XOR limit is 1024?
-----------------------
Given constraints typically limit arr[i] ≤ 10^2–10^3.
Maximum possible XOR < 2^10 = 1024.
So dp array size 1024 is safe.

Approach:
---------
Recursive relation:
    solve(i, Xor) =
          solve(i+1, Xor)              // skip element i
        + solve(i+1, Xor ^ arr[i])     // take element i

Base case:  
    When i == n → return current Xor (this is the XOR of one full subset)

We memoize dp[i][Xor] to avoid recalculating states.

Time Complexity:
----------------
O(n * maxXor)  
Where maxXor ≈ 1024.

Space Complexity:
-----------------
O(n * maxXor) for DP table  
O(n) recursion stack

*/

class Solution {
    int n;
    vector<vector<int>> dp;  // Memoization table: dp[index][currentXor]

public:
    // Recursive function to compute subset XOR sum
    int solve(int i, int Xor, vector<int>& arr) {

        // If we have considered all elements, return the accumulated XOR
        if (i == n)
            return Xor;

        // If result already computed, return it
        if (dp[i][Xor] != -1)
            return dp[i][Xor];

        // Option 1: Skip current element
        int skip = solve(i + 1, Xor, arr);

        // Option 2: Include current element → XOR with arr[i]
        int take = solve(i + 1, (Xor ^ arr[i]), arr);

        // Store and return result
        return dp[i][Xor] = skip + take;
    }

    int subsetXORSum(vector<int>& arr) {
        n = arr.size();

        // dp size: (n+1) rows × 1024 possible XOR values
        dp.resize(n + 1, vector<int>(1024, -1));

        // Start recursion from index 0 with initial XOR = 0
        return solve(0, 0, arr);
    }
};


