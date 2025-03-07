/*
Longest Palindromic Subsequence
Difficulty: MediumAccuracy: 56.57%Submissions: 99K+Points: 4
Given a string s, return the length of the longest palindromic subsequence.

A subsequence is a sequence that can be derived from the given sequence by deleting some or no elements without changing the order of the remaining elements.

A palindromic sequence is a sequence that reads the same forward and backward.

Examples:

Input: s = "bbabcbcab"
Output: 7
Explanation: Subsequence "babcbab" is the longest subsequence which is also a palindrome.
Input: s = "abcd"
Output: 1
Explanation: "a", "b", "c" and "d" are palindromic and all have a length 1.
Input: s = "agbdba"
Output: 5
Explanation: The longest palindromic subsequence is "abdba", which has a length of 5. The characters in this subsequence are taken from the original string "agbdba", and they maintain the order of the string while forming a palindrome.
Constraints:
1 ≤ s.size() ≤ 1000
The string contains only lowercase letters.
*/

/**
 * Approach:
 * - The **Longest Palindromic Subsequence (LPS)** is the longest common subsequence (LCS)
 *   between the given string and its reversed version.
 * - This reduces the problem to **finding the LCS of the string and its reverse**.
 * 
 * 🔹 **Recursive + Memoization (Top-Down Approach)**:
 *   - `solve(i, j)`: Finds LCS between `s1[0...i]` and `s2[0...j]`
 *   - If `s1[i] == s2[j]`: Take 1 + LCS of remaining.
 *   - Otherwise, take the maximum of:
 *       - Skipping `s1[i]`
 *       - Skipping `s2[j]`
 * 
 * 🔹 **Time Complexity**: O(n²) → Standard DP LCS approach.
 * 🔹 **Space Complexity**: O(n²) → DP Table.
 */

class Solution {
    int n;
  public:
    int solve(int i, int j, string &s1, string &s2, vector<vector<int>> &dp){
        if(i == n || j == n) return 0; // Base case: End of string
        
        if(dp[i][j] != -1) return dp[i][j]; // Memoized
        
        if(s1[i] == s2[j]) {
            return dp[i][j] = 1 + solve(i + 1, j + 1, s1, s2, dp);
        }
        
        return dp[i][j] = max(solve(i + 1, j, s1, s2, dp), solve(i, j + 1, s1, s2, dp));
    }

    int longestPalinSubseq(string &s) {
        n = s.length();
        string s2 = s;
        reverse(s2.begin(), s2.end()); // Reverse to find LCS
        
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(0, 0, s, s2, dp);
    }
};

class Solution {
public:
    int longestPalinSubseq(string s) {
        int n = s.length();
        string s2 = s;
        reverse(s2.begin(), s2.end());

        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (s[i-1] == s2[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[n][n];
    }
};


/**
 * Approach:
 * - The LPS problem asks for the **longest subsequence that is also a palindrome**.
 * - Instead of reversing the string and using LCS, we use a **recursive approach**:
 * 
 * 🔹 **Recursive + Memoization (Top-Down Approach)**:
 *   - `solve(i, j)`: Finds LPS in `s[i...j]`
 *   - If `s[i] == s[j]`: Take both and add `2 + LPS(i+1, j-1)`
 *   - Otherwise, take the **maximum** of:
 *       - Skipping `s[i]`
 *       - Skipping `s[j]`
 * 
 * 🔹 **Time Complexity**: O(n²) → DP stores results to avoid recomputation.
 * 🔹 **Space Complexity**: O(n²) → DP Table.
 */

class Solution {
    int n;
  public:
    int solve(int i, int j, string &s, vector<vector<int>> &dp){
        if(i == j) return 1;  // Single character is a palindrome of length 1
        if(i > j) return 0;   // Empty substring

        if(dp[i][j] != -1) return dp[i][j]; // Memoization

        if(s[i] == s[j]) {
            return dp[i][j] = 2 + solve(i+1, j-1, s, dp);
        }

        return dp[i][j] = max(solve(i+1, j, s, dp), solve(i, j-1, s, dp));
    }

    int longestPalinSubseq(string &s) {
        n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(0, n-1, s, dp);
    }
};


class Solution {
public:
    int longestPalinSubseq(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++) {
            dp[i][i] = 1; // Single character is a palindrome
        }

        for (int len = 2; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                if (s[i] == s[j]) {
                    dp[i][j] = 2 + dp[i+1][j-1];
                } else {
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                }
            }
        }

        return dp[0][n-1];
    }
};
