/*
Largest Divisible Subset
Difficulty: MediumAccuracy: 44.04%Submissions: 8K+Points: 4Average Time: 20m
Given an array arr[] of distinct positive integers. Your task is to find the largest subset such that for every pair of elements (x, y) in the subset, either x divides y or y divides x.
Note : If multiple subsets of the same maximum length exist, return the one that is lexicographically greatest, after sorting the subset in ascending order.

Examples:

Input: arr[] = [1, 16, 7, 8, 4]
Output: [1, 4, 8, 16]
Explanation: The largest divisible subset is [1, 4, 8, 16], where each element divides the next one. This subset is already the lexicographically greatest one.
Input: arr[] = [2, 4, 3, 8]
Output: [2, 4, 8]
Explanation: The largest divisible subset is [2, 4, 8], where each element divides the next one. This subset is already the lexicographically greatest one.
Constraint:
1 ≤ arr.size() ≤ 103
1  ≤ arr[i] ≤ 109
*/

/*
Approach:
This is a variation of the **Longest Divisible Subset** problem.

Goal: Return the largest subset such that for every pair (Si, Sj) in the subset, 
either Si % Sj == 0 or Sj % Si == 0.

Steps:
1. Sort the array so that for any `i < j`, arr[j] >= arr[i]. This ensures if arr[j] is divisible by arr[i], it's valid.
2. Use **recursion with memoization**:
   - At every index, decide whether to include or exclude the current element based on divisibility with the previous picked index.
   - Use a 3D DP array to store results for (idx, prevIdx + 1) to avoid recomputation.
3. Choose the path (take or not take) that yields a larger subset. If they are equal in size, take the lexicographically larger one.

Intuition:
Sorting ensures smaller elements come first, which is important for divisibility. We explore both options—taking or skipping each element.

Time Complexity: O(n² × k)
- `n` positions × `n` previous positions × `k` average size for vector comparison and copying.

Space Complexity: O(n² × k)
- For the DP cache where each state stores a vector (could be up to length `n`).

Note: Can be optimized further using iterative DP.
*/

class Solution {
    int n;
    vector<vector<vector<int>>> dp; // Memoization table

public:
    // Recursive function to find the largest divisible subset
    vector<int> solve(int idx, vector<int> &arr, int prevIdx) {
        if (idx == n) return {};

        // Return already computed result
        if (!dp[idx][prevIdx + 1].empty()) {
            return dp[idx][prevIdx + 1];
        }

        vector<int> taken;

        // If first element or divisible condition satisfied, include current
        if (prevIdx == -1 || arr[idx] % arr[prevIdx] == 0) {
            taken = solve(idx + 1, arr, idx);
            taken.insert(taken.begin(), arr[idx]);  // Include current element
        }

        // Option to exclude current element
        vector<int> not_taken = solve(idx + 1, arr, prevIdx);

        // Take the longer subset; if equal, prefer lexicographically larger
        vector<int> res = (taken.size() > not_taken.size() || 
                          (taken.size() == not_taken.size() && taken > not_taken)) ? 
                          taken : not_taken;

        return dp[idx][prevIdx + 1] = res;
    }

    // Main function
    vector<int> largestSubset(vector<int>& arr) {
        n = arr.size();
        dp.resize(n, vector<vector<int>>(n + 1));  // Resize DP table
        sort(arr.begin(), arr.end());              // Sort input array
        return solve(0, arr, -1);                   // Start recursion
    }
};

