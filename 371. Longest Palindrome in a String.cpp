/*
Longest Palindrome in a String
Difficulty: MediumAccuracy: 23.2%Submissions: 318K+Points: 4
Given a string s, your task is to find the longest palindromic substring within s.

A substring is a contiguous sequence of characters within a string, defined as s[i...j] where 0 ≤ i ≤ j < len(s).

A palindrome is a string that reads the same forward and backward. More formally, s is a palindrome if reverse(s) == s.

Note: If there are multiple palindromic substrings with the same length, return the first occurrence of the longest palindromic substring from left to right.

Examples :

Input: s = “forgeeksskeegfor” 
Output: “geeksskeeg”
Explanation: There are several possible palindromic substrings like “kssk”, “ss”, “eeksskee” etc. But the substring “geeksskeeg” is the longest among all.
Input: s = “Geeks” 
Output: “ee”
Explanation: "ee" is the longest palindromic substring of "Geeks". 
Input: s = “abc” 
Output: “a”
Explanation: "a", "b" and "c" are longest palindromic substrings of same length. So, the first occurrence is returned.
Constraints:
1 ≤ s.size() ≤ 103
s consist of only lowercase English letters.
*/

/**
 * Approach:
 * - **Check every possible substring** to see if it's a palindrome.
 * - **Store the longest palindromic substring found.**
 * 
 * 🔹 **Steps**:
 *   1️⃣ Iterate over all possible **(i, j) pairs** to form substrings.
 *   2️⃣ Use `isPalindrome(i, j, s)` to check if it's a palindrome.
 *   3️⃣ If it's **longer than the previously found palindrome**, update `res`.
 * 
 * 🔹 **Time Complexity**: O(N³) → O(N²) for substring checks × O(N) for `isPalindrome`
 * 🔹 **Space Complexity**: O(1) → Only uses a few extra variables.
 */

class Solution {
  public:
    bool isPalindrome(int i, int j, string &s) {
        while (i < j) {
            if (s[i] != s[j]) return false;
            i++, j--;
        }
        return true;
    }

    string longestPalindrome(string &s) {
        int n = s.length();
        string res;
        
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) { // Check every substring from i to j
                if (isPalindrome(i, j, s) && (j - i + 1) > res.length()) {
                    res = s.substr(i, j - i + 1);
                }
            }
        }

        return res;
    }
};


/**
 * Approach:
 * - Use a **DP table `dp[i][j]`** where:
 *   - `dp[i][j] = true` if substring `s[i:j]` is a palindrome.
 * - Iterate over **lengths (L) of substrings** from **2 to n**:
 *   - Base case: **Single-letter substrings (`L=1`) are always palindromes**.
 *   - Check **two-letter substrings (`L=2`)** separately.
 *   - For longer substrings (`L ≥ 3`), use the formula:
 *     - `dp[i][j] = (s[i] == s[j] && dp[i+1][j-1])`
 * - Maintain `maxLen` and `SP` (start position) for the longest palindrome found.
 *
 * 🔹 **Time Complexity**: O(N²) → DP table with N² states.
 * 🔹 **Space Complexity**: O(N²) → DP table storage.
 */

class Solution {
public:
    string longestPalindrome(string &s) {
        int n = s.length();
        vector<vector<bool>> dp(n, vector<bool>(n, false));

        int maxLen = 1, SP = 0;

        // Every single character is a palindrome
        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
        }

        // Check substrings of length 2 separately
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = true;
                maxLen = 2;
                SP = i;
            }
        }

        // Check longer substrings (L ≥ 3)
        for (int L = 3; L <= n; L++) {
            for (int i = 0; i <= n - L; i++) {
                int j = i + L - 1;
                if (s[i] == s[j] && dp[i + 1][j - 1]) {
                    dp[i][j] = true;
                    if (maxLen < L) {
                        maxLen = L;
                        SP = i;
                    }
                }
            }
        }

        return s.substr(SP, maxLen);
    }
};
