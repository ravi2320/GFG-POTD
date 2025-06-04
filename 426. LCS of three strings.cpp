/*
LCS of three strings
Difficulty: MediumAccuracy: 48.52%Submissions: 74K+Points: 4
Given three strings s1, s2, and s3 containing uppercase letters, lowercase letters, and digits, find the length of longest common sub-sequence in all three given strings.

Examples:

Input: s1 = "geeks", s2 = "geeksfor", s3 = "geeksforgeeks"
Output: 5
Explanation: "geeks"is the longest common subsequence with length 5.
Input: s1 = "abcd1e2", s2 = "bc12ea", s3 = "bd1ea"
Output: 3
Explanation:  Longest common subsequence is "b1e" i.e. length = 3.
Constraints:
1  ≤  s1.size(), s2.size(), s3.size()  ≤  100
*/

/*
Approach:
- Use 3D dynamic programming with recursion and memoization.
- dp[i][j][k] represents the length of the Longest Common Subsequence (LCS)
  of substrings s1[i:], s2[j:], and s3[k:].
- If the current characters match, include it in LCS and move all three pointers forward.
- Otherwise, move one pointer at a time and take the max result.

Intuition:
- LCS of 3 strings extends the 2-string LCS idea by checking one more string.
- If the characters at the current indices in all three strings match,
  include that character and recurse to the next indices in all strings.
- If not, try skipping one character in one of the strings and get the maximum LCS.

Time Complexity: O(n * m * s)
- Each state (i, j, k) is visited at most once due to memoization.

Space Complexity: O(n * m * s)
- For the dp table storing intermediate results.
*/

class Solution {
    int n, m, s; // lengths of s1, s2, s3
    int dp[101][101][101]; // DP memoization table

public:
    // Recursive function to compute LCS of 3 strings with memoization
    int solve(int i, int j, int k, string &s1, string &s2, string &s3){
        // Base case: if any string is fully traversed
        if(i == n || j == m || k == s) return 0;

        // Return already computed value
        if(dp[i][j][k] != -1) return dp[i][j][k];

        // If current characters of all 3 strings match
        if(s1[i] == s2[j] && s2[j] == s3[k]){
            return dp[i][j][k] = 1 + solve(i+1, j+1, k+1, s1, s2, s3);
        }
        else{
            // Try all combinations by skipping one character from each string
            int a = solve(i+1, j, k, s1, s2, s3);
            int b = solve(i, j+1, k, s1, s2, s3);
            int c = solve(i, j, k+1, s1, s2, s3);

            // Take the maximum among the three options
            return dp[i][j][k] = max({a, b, c});
        }
    }

    // Function to return length of LCS of three strings
    int lcsOf3(string& s1, string& s2, string& s3) {
        n = s1.size();
        m = s2.size();
        s = s3.size();

        // Initialize DP table with -1
        memset(dp, -1, sizeof(dp));

        // Call recursive function starting from index 0 of all strings
        return solve(0, 0, 0, s1, s2, s3);
    }
};

/*
Approach:
- Use 3D Dynamic Programming with tabulation (bottom-up DP).
- Define dp[i][j][k] as the length of the LCS of the first i characters of s1,
  first j characters of s2, and first k characters of s3.
- Build the solution iteratively using the recurrence relation:
  - If characters match: dp[i][j][k] = 1 + dp[i-1][j-1][k-1]
  - Else: take the max of skipping one character from any string.

Intuition:
- We build the solution from the smallest subproblems (empty prefixes of strings),
  up to the full strings.
- Comparing one character from each string at each iteration, we build up the LCS.

Time Complexity: O(n * m * s)
- Three nested loops covering all characters in each string.

Space Complexity: O(n * m * s)
- For the 3D dp array storing results of all subproblems.
*/

class Solution {
  public:
    int lcsOf3(string& s1, string& s2, string& s3) {
        int n = s1.size(), m = s2.size(), s = s3.size();

        // Initialize a 3D DP array with all values set to 0
        int dp[101][101][101] = {0};

        // Loop through all characters of s1, s2, and s3
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                for(int k = 1; k <= s; k++) {

                    // If characters match, extend the LCS by 1
                    if(s1[i-1] == s2[j-1] && s2[j-1] == s3[k-1]) {
                        dp[i][j][k] = 1 + dp[i-1][j-1][k-1];
                    }
                    else {
                        // Otherwise, take the max by skipping one char at a time
                        dp[i][j][k] = max({
                            dp[i-1][j][k],
                            dp[i][j-1][k],
                            dp[i][j][k-1]
                        });
                    }
                }
            }
        }

        // The answer is stored in dp[n][m][s]
        return dp[n][m][s];
    }
};
