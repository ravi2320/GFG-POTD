/*
Minimum Deletions
Difficulty: MediumAccuracy: 58.8%Submissions: 63K+Points: 4
Given a string s, write a program to delete the minimum number of characters from the string so that the resultant string is a palindrome, while maintaining the order of characters.

Examples:

Input: s = "aebcbda"
Output: 2
Explanation: Remove characters 'e' and 'd'.
Input: s = "geeksforgeeks"
Output: 8
Explanation: To make "geeksforgeeks" a palindrome, the longest palindromic subsequence is "eefee" (length 5). The minimum deletions are:
13 (length of s) - 5 = 8.
Constraints:
1 ≤ s.size() ≤ 103
*/

/*
Approach:
- We want to find the minimum number of deletions to make the string a palindrome.
- The idea is based on finding the **Longest Palindromic Subsequence (LPS)**.
- If we know the length of the LPS, the minimum deletions = total length - LPS length.
- However, this solution directly uses recursion + memoization:
  - If characters at both ends match, move inward.
  - Else, try deleting either end and take the min.

Time Complexity: O(n^2)
Space Complexity: O(n^2) due to 2D dp array

Intuition:
- At each step, we either delete one of the ends if they don't match,
  and recurse accordingly to minimize deletions.
*/

class Solution {
public:
    // Recursive function with memoization
    int solve(string &s, int i, int j, vector<vector<int>> &dp) {
        if(i >= j) {
            return 0; // Already a palindrome or empty
        }

        if(dp[i][j] != -1) {
            return dp[i][j]; // Use memoized value
        }

        if(s[i] == s[j]) {
            return dp[i][j] = solve(s, i+1, j-1, dp); // No deletion needed
        } else {
            // Delete either s[i] or s[j] and take minimum
            return dp[i][j] = 1 + min(solve(s, i+1, j, dp), solve(s, i, j-1, dp));
        }
    }

    int minDeletions(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, -1));

        return solve(s, 0, n-1, dp);
    }
};


/*
Approach:
- Use bottom-up Dynamic Programming to avoid recursion.
- dp[i][j] = minimum deletions needed to make s[i..j] a palindrome.

Transition:
- If s[i] == s[j], no deletion needed → dp[i][j] = dp[i+1][j-1]
- Else, try deleting either s[i] or s[j] → dp[i][j] = 1 + min(dp[i+1][j], dp[i][j-1])

Final answer: dp[0][n-1], which stores the minimum deletions for the entire string.

Time Complexity: O(n^2)
Space Complexity: O(n^2)
*/

class Solution {
public:
    int minDeletions(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, 0));  // dp[i][j] = min deletions for s[i..j]

        // Build the table for all substring lengths starting from 2
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;  // Ending index of current substring

                if (s[i] == s[j]) {
                    dp[i][j] = dp[i + 1][j - 1];  // No deletion needed
                } else {
                    dp[i][j] = 1 + min(dp[i + 1][j], dp[i][j - 1]);  // Delete one character
                }
            }
        }

        return dp[0][n - 1];  // Answer for full string
    }
};
