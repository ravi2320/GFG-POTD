/*
Shortest Common Supersequence
Difficulty: MediumAccuracy: 55.62%Submissions: 126K+Points: 4
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
1<= s1.size(), s2.size() <= 500
*/

/**
 * Approach:
 * - **Recursive DP with Memoization**:
 *   - Define `dp[i][j]` as the length of the SCS for `s1[i..n]` and `s2[j..m]`.
 *   - If characters match → Include it in SCS and move diagonally.
 *   - Otherwise, take the minimum SCS length by adding either `s1[i]` or `s2[j]`.
 *
 * 🔹 **Time Complexity**: O(N * M) → Memoization avoids redundant computations.
 * 🔹 **Space Complexity**: O(N * M) → Memoization table.
 */

class Solution {
public:
    int solve(int i, int j, string &s1, string &s2, vector<vector<int>> &dp) {
        // Base case: if one string is exhausted, append the remaining of the other
        if (i == s1.size()) return dp[i][j] = s2.size() - j;
        if (j == s2.size()) return dp[i][j] = s1.size() - i;
        
        // If already computed, return stored result
        if (dp[i][j] != -1) return dp[i][j];

        // If characters match, take diagonal move
        if (s1[i] == s2[j]) {
            return dp[i][j] = 1 + solve(i + 1, j + 1, s1, s2, dp);
        }

        // Otherwise, take the minimum of either adding s1[i] or s2[j]
        int option1 = 1 + solve(i + 1, j, s1, s2, dp);
        int option2 = 1 + solve(i, j + 1, s1, s2, dp);

        return dp[i][j] = min(option1, option2);
    }

    int shortestCommonSupersequence(string &s1, string &s2) {
        int n = s1.size(), m = s2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));  // Memoization table

        return solve(0, 0, s1, s2, dp);  // Start recursion from (0, 0)
    }
};


/**
 * Approach:
 * - **Bottom-Up DP**:
 *   - Define `dp[i][j]` as the length of the SCS for `s1[i..n]` and `s2[j..m]`.
 *   - If characters match → Include it in SCS and move diagonally.
 *   - Otherwise, take the minimum SCS length by adding either `s1[i]` or `s2[j]`.
 *
 * 🔹 **Time Complexity**: O(N * M) → Filling a 2D DP table.
 * 🔹 **Space Complexity**: O(N * M) → 2D DP array.
 */

class Solution {
public:
    int shortestCommonSupersequence(string &s1, string &s2) {
        int n = s1.size(), m = s2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // Base Case: If one string is exhausted, add remaining characters of the other
        for (int i = 0; i <= n; i++) dp[i][m] = n - i;
        for (int j = 0; j <= m; j++) dp[n][j] = m - j;

        // Fill DP Table (Bottom-Up)
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                if (s1[i] == s2[j]) {
                    dp[i][j] = 1 + dp[i + 1][j + 1];  // Include matching character
                } else {
                    dp[i][j] = 1 + min(dp[i + 1][j], dp[i][j + 1]);  // Take the minimum path
                }
            }
        }

        return dp[0][0];  // Answer stored at dp[0][0]
    }
};