/*
Shortest Common Supersequence

Given two strings s1 and s2, find the length of the smallest string which has both s1 and s2 as its sub-sequences.
Note: s1 and s2 can have both uppercase and lowercase English letters.

Examples:

Input: s1 = "geek", s2 = "eke"
Output: 5
Explanation: String "geeke" has both string "geek" and "eke" as subsequences.
Input: s1 = "AGGTAB", s2 = "GXTXAYB"
Output: 9
Explanation: String "AGXGTXAYB" has both string "AGGTAB" and "GXTXAYB" as subsequences.
Input: s1 = "geek", s2 = "ek"
Output: 4
Explanation: String "geek" has both string "geek" and "ek" as subsequences.
Constraints:
1 ≤ s1.size(), s2.size() ≤ 500
*/

// Intuition:
// The problem is asking for the length of the shortest supersequence that contains both s1 and s2.
// This can be thought of as a dynamic programming problem where we try to find the longest common subsequence (LCS) between s1 and s2.
// Once we know the LCS, the length of the shortest supersequence will be:
//   Length of s1 + Length of s2 - Length of LCS
//
// Approach:
// 1. We will use dynamic programming (DP) to find the LCS between the two strings. 
// 2. The DP state dp[i][j] represents the length of the LCS of s1[0..i-1] and s2[0..j-1].
// 3. We initialize a 2D DP table with all values set to -1, which will later store the computed LCS values.
// 4. For each pair of indices (i, j), if s1[i] == s2[j], we increment the LCS value by 1 and recursively solve the remaining subproblems.
// 5. If the characters are not the same, we try both options: 
//    - Skip the current character in s1 and solve the problem for s1[i+1] and s2[j], or
//    - Skip the current character in s2 and solve the problem for s1[i] and s2[j+1].
// 6. The result will be the length of the shortest supersequence, which is the sum of lengths of both strings minus the LCS length.

// Time Complexity:
// The time complexity is O(n * m), where n is the length of s1 and m is the length of s2, because we calculate each cell of the DP table once.

// Space Complexity:
// The space complexity is O(n * m) due to the DP table that stores the intermediate results.

class Solution {
    int n, m;                   // Lengths of s1 and s2
    vector<vector<int>> dp;      // DP table to store LCS results
    
  public:
    // Helper function to solve the subproblem of finding LCS between s1[i..n-1] and s2[j..m-1]
    int solve(int i, int j, string &s1, string &s2) {
        
        // If we have reached the end of s1, return the remaining characters of s2
        // This means we need to add all remaining characters of s2 to the supersequence.
        if(i >= n)
            return m - j;
            
        // If we have reached the end of s2, return the remaining characters of s1
        // This means we need to add all remaining characters of s1 to the supersequence.
        if(j >= m)
            return n - i;
        
        // If we have already computed the result for this subproblem, return it
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int ans = 0;
        
        // If characters match, include this character in the supersequence and move both pointers
        if(s1[i] == s2[j])
            ans = 1 + solve(i + 1, j + 1, s1, s2); // Both characters are part of the LCS
        
        // If characters do not match, try two options:
        // 1. Skip the current character of s1 and move forward in s1.
        // 2. Skip the current character of s2 and move forward in s2.
        else {
            ans = 1 + min(solve(i + 1, j, s1, s2), solve(i, j + 1, s1, s2));
        }
        
        // Store the result in the DP table and return it
        return dp[i][j] = ans;
    }

    // Function to find the length of the minimum supersequence
    int minSuperSeq(string &s1, string &s2) {
        // Initialize the lengths of s1 and s2
        n = s1.length(), m = s2.length();
        
        // Resize the DP table to hold the results for all subproblems
        dp.resize(n, vector<int>(m, -1));
        
        // Call the helper function starting from index (0, 0)
        return solve(0, 0, s1, s2);
    }
};
