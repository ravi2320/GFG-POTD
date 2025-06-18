/*
All Palindromic Partitions
Difficulty: MediumAccuracy: 61.47%Submissions: 23K+Points: 4Average Time: 30m
Given a string s, find all possible ways to partition it such that every substring in the partition is a palindrome.

Examples:

Input: s = "geeks"
Output: [[g, e, e, k, s], [g, ee, k, s]]
Explanation: [g, e, e, k, s] and [g, ee, k, s] are the only partitions of "geeks" where each substring is a palindrome.
Input: s = "abcba"
Output: [[a, b, c, b, a], [a, bcb, a], [abcba]]
Explanation: [a, b, c, b, a], [a, bcb, a] and [abcba] are the only partitions of "abcba" where each substring is a palindrome.
Constraints:
1 ≤ s.size() ≤ 20

Expected Complexities
Time Complexity: O(2^n * n)
Auxiliary Space: O(2^n * n)
*/

/*
Approach:
We need to find **all possible palindrome partitionings** of a given string `s`.
This is a **backtracking problem**, where we explore all substrings starting at index `idx` and recursively 
check further partitions only if the current substring is a palindrome.

Steps:
1. Use a helper function `isPalindrome()` to check if a substring s[i...j] is a palindrome.
2. Use a recursive function `solve()` to try all partitions from the current index `idx`.
   - If a valid palindrome is found, include it in the current path (`curr`) and recurse on the rest of the string.
   - If the end of the string is reached (`idx == n`), store the current partition as a result.

Intuition:
This explores all ways to cut the string into palindromic parts, collecting only valid partitions.

Time Complexity: O(2^n * n)
- O(2^n) for generating all partitions
- O(n) for checking palindrome in each call (optimized using two pointers)

Space Complexity: O(n) auxiliary stack space (depth of recursion), plus space for results.
*/

class Solution {
    int n;  // Store length of string globally
public:
    // Helper function to check if substring s[i...j] is a palindrome
    bool isPalindrome(string &s, int i, int j) {
        while (i < j) {
            if (s[i] != s[j]) return false;
            i++, j--;
        }
        return true;
    }

    // Recursive backtracking function to build partitions
    void solve(string &s, int idx, vector<string> curr, vector<vector<string>> &res) {
        // Base case: if index reaches end of string, store current partition
        if (idx == n) {
            res.push_back(curr);
            return;
        }

        // Try all partitions from current index to end
        for (int i = idx; i < n; i++) {
            // If s[idx...i] is a palindrome, consider it
            if (isPalindrome(s, idx, i)) {
                curr.push_back(s.substr(idx, i - idx + 1));  // Choose substring
                solve(s, i + 1, curr, res);  // Recurse on remaining string
                curr.pop_back();  // Backtrack
            }
        }
    }

    // Main function to initiate backtracking
    vector<vector<string>> palinParts(string &s) {
        n = s.length();
        vector<vector<string>> res;
        vector<string> temp;

        solve(s, 0, temp, res);  // Start from index 0

        return res;
    }
};