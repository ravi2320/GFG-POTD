/*
Form a palindrome
Difficulty: MediumAccuracy: 45.4%Submissions: 97K+Points: 4
Given a string, find the minimum number of characters to be inserted to convert it to a palindrome.

Examples :

Input: str = "abcd"
Output: 3
Explanation: Inserted character marked with bold characters in dcbabcd, here we need minimum three characters to make it palindrome.
Input: str = "aa"
Output: 0
Explanation: "aa" is already a palindrome.
Expected Time Complexity: O(n2)
Expected Auxiliary Space: O(n2)

Constraints:
1 ≤ |str| ≤ 500
str contains only lowercase alphabets.
*/

/*
Intuition:
The problem is to find the minimum number of insertions needed to make a given string a palindrome. This can be approached by using dynamic programming to find the longest palindromic subsequence (LPS) and then calculating the difference between the string's length and the LPS. Instead of directly finding the LPS, we can use a recursive approach with memoization to find the minimum number of insertions required by comparing characters from the start and end of the string and solving the subproblems.

Time Complexity:
The recursive function with memoization runs in O(N^2) time complexity, where N is the length of the string. This is because there are N^2 possible subproblems (i, j) that we solve at most once.

Space Complexity:
The space complexity is O(N^2) due to the storage requirements of the memoization table (`dp`). This table stores the results of subproblems to avoid redundant calculations, with each entry dp[i][j] representing the minimum number of insertions needed for the substring from index i to j.
*/

class Solution {
public:
    // Helper function to recursively calculate the minimum insertions required
    int solve(string &str, int i, int j, vector<vector<int>> &dp) {
        if (i >= j) return dp[i][j] = 0; // No insertions needed for empty or single-character substring
        
        if (dp[i][j] != -1) {
            return dp[i][j]; // Return the stored result if already computed
        }

        if (str[i] == str[j]) {
            return dp[i][j] = solve(str, i+1, j-1, dp); // No insertion needed if characters match
        }

        // Minimum insertions needed if characters do not match
        return dp[i][j] = 1 + min(solve(str, i+1, j, dp), solve(str, i, j-1, dp));
    }

    // Main function to find the minimum number of insertions
    int countMin(string str) {
        vector<vector<int>> dp(501, vector<int>(501, -1)); // Initialize memoization table with -1
        return solve(str, 0, str.length() - 1, dp); // Calculate result for the full string
    }
};
