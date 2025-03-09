/*
Palindrome SubStrings
Difficulty: MediumAccuracy: 45.8%Submissions: 30K+Points: 4Average Time: 30m
Given a string s, count all palindromic sub-strings present in the string. The length of the palindromic sub-string must be greater than or equal to 2. 

Examples

Input: s = "abaab"
Output: 3
Explanation: All palindromic substrings are : "aba" , "aa" , "baab".
Input: s = "aaa"
Output: 3
Explanation: All palindromic substrings are : "aa", "aa", "aaa".
Input: s = "abbaeae"
Output: 4
Explanation: All palindromic substrings are : "bb" , "abba" , "aea", "eae".
Constraints:
2 ≤ s.size() ≤ 103
string contains only lowercase english characters
*/

/**
 * Approach:
 * - Use a **DP table `dp[i][j]`** where:
 *   - `dp[i][j] = true` if `s[i:j]` is a palindrome.
 * - Iterate over **lengths (L) of substrings** from **2 to n**:
 *   - Base case: **Single-letter substrings (`L=1`) are always palindromes**.
 *   - Check **two-letter substrings (`L=2`)** separately.
 *   - For longer substrings (`L ≥ 3`), use:
 *     - `dp[i][j] = (s[i] == s[j] && dp[i+1][j-1])`
 * - Count all palindromic substrings.
 *
 * 🔹 **Time Complexity**: O(N²) → DP table with N² states.
 * 🔹 **Space Complexity**: O(N²) → DP table storage.
 */

class Solution {
  public:
    int countPS(string &s) {
        int n = s.length();
        int cnt = 0;
        vector<vector<bool>> dp(n, vector<bool>(n, false));

        // Every single character is a palindrome
        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
            cnt++;  // Single-letter palindromes
        }

        // Check substrings of length 2 separately
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = true;
                cnt++;  // Two-letter palindromes
            }
        }

        // Check longer substrings (L ≥ 3)
        for (int L = 3; L <= n; L++) {
            for (int i = 0; i <= n - L; i++) {
                int j = i + L - 1;
                if (s[i] == s[j] && dp[i + 1][j - 1]) {
                    dp[i][j] = true;
                    cnt++;
                }
            }
        }

        return cnt;
    }
};