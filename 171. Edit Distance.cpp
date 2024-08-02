/*
Edit Distance
Difficulty: HardAccuracy: 35.14%Submissions: 205K+Points: 8
Given two strings str1 and str2. Return the minimum number of operations required to convert str1 to str2.
The possible operations are permitted:

Insert a character at any position of the string.
Remove any character from the string.
Replace any character from the string with any other character.
Examples:

Input: str1 = "geek", srt2 = "gesek"
Output: 1
Explanation: One operation is required, inserting 's' between two 'e'.
Input : str1 = "gfg", str2 = "gfg"
Output: 0
Explanation: Both strings are same.
Expected Time Complexity: O(|str1|*|str2|)
Expected Space Complexity: O(|str1|*|str2|)

Constraints:
1 ≤ str1.length(), str2.length() ≤ 100
Both the strings are in lowercase.
*/

/*
Intuition:
The edit distance problem is a classic dynamic programming problem that aims to find the minimum number of operations (insertions, deletions, or substitutions) required to convert one string into another. The recursive solution explores all possible operations at each step, and the dynamic programming (DP) table is used to store intermediate results to avoid redundant calculations.

Time Complexity:
The time complexity is O(n*m) where n and m are the lengths of the two strings. This is because each subproblem (i, j) is solved only once.

Space Complexity:
The space complexity is O(n*m) due to the DP table of size 101x101.

*/

class Solution {
  public:
    // Helper function to compute the edit distance using recursion and memoization
    int f(int i, int j, string &str1, string &str2, vector<vector<int>> &dp) {
        if (i < 0) return j + 1; // insert operations needed for str2[0..j]
        if (j < 0) return i + 1; // delete operations needed for str1[0..i]

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        if (str1[i] == str2[j]) {
            return dp[i][j] = f(i - 1, j - 1, str1, str2, dp); // characters match, move both pointers
        }

        return dp[i][j] = 1 + min(
            f(i, j - 1, str1, str2, dp),   // insert operation
            min(
                f(i - 1, j, str1, str2, dp), // delete operation
                f(i - 1, j - 1, str1, str2, dp) // replace operation
            )
        );
    }

    // Function to compute the edit distance between two strings
    int editDistance(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        vector<vector<int>> dp(101, vector<int>(101, -1));
        return f(n - 1, m - 1, str1, str2, dp);
    }
};


/*
Intuition:
The edit distance problem can be efficiently solved using dynamic programming. Instead of relying on recursion with memoization, we construct a DP table where each cell (i, j) represents the minimum number of operations required to convert the first i characters of str1 to the first j characters of str2.

Time Complexity:
The time complexity is O(n*m), where n is the length of str1 and m is the length of str2. This is because we fill out an (n+1) x (m+1) table.

Space Complexity:
The space complexity is also O(n*m) due to the DP table.

*/

class Solution {
  public:
    // Function to compute the edit distance between two strings
    int editDistance(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        
        // DP table to store the results of subproblems
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        
        // Initializing the base cases
        for (int i = 0; i <= n; i++) {
            dp[i][0] = i; // Cost of converting str1[0..i-1] to an empty string
        }
        for (int j = 0; j <= m; j++) {
            dp[0][j] = j; // Cost of converting an empty string to str2[0..j-1]
        }
        
        // Filling the DP table
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (str1[i-1] == str2[j-1]) {
                    dp[i][j] = dp[i-1][j-1]; // Characters match, no operation needed
                } else {
                    dp[i][j] = 1 + min({
                        dp[i][j-1], // Insert operation
                        dp[i-1][j], // Delete operation
                        dp[i-1][j-1] // Replace operation
                    });
                }
            }
        }
        
        // The answer is in the cell dp[n][m]
        return dp[n][m];
    }
};


/*
Intuition:
The edit distance problem can be solved efficiently using dynamic programming. By optimizing the space complexity, we use only two 1D arrays (`curr` and `prev`) instead of a 2D array.

Time Complexity:
The time complexity is O(n*m), where n is the length of str1 and m is the length of str2. This is because we iterate over the entire (n+1) x (m+1) matrix.

Space Complexity:
The space complexity is O(m) because we only store two 1D arrays of size m+1.

*/

class Solution {
  public:
    // Function to compute the edit distance between two strings
    int editDistance(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        
        // Two 1D arrays to store current and previous row of DP table
        vector<int> curr(m+1, 0), prev(m+1, 0);
        
        // Initializing the base case for the first row
        for (int j = 0; j <= m; j++) {
            prev[j] = j; // Cost of converting an empty string to str2[0..j-1]
        }
        
        // Filling the DP table
        for (int i = 1; i <= n; i++) {
            curr[0] = i; // Cost of converting str1[0..i-1] to an empty string
            for (int j = 1; j <= m; j++) {
                if (str1[i-1] == str2[j-1]) {
                    curr[j] = prev[j-1]; // Characters match, no operation needed
                } else {
                    curr[j] = 1 + min({
                        curr[j-1], // Insert operation
                        prev[j], // Delete operation
                        prev[j-1] // Replace operation
                    });
                }
            }
            // Move current row to previous row for next iteration
            prev = curr;
        }
        
        // The answer is in the last cell of the previous row
        return prev[m];
    }
};
