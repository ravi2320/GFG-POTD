/*
Wildcard Pattern Matching
Difficulty: HardAccuracy: 31.13%Submissions: 70K+Points: 8
Given two strings pattern and str which may be of different size, You have to return 1 if the wildcard pattern i.e. pattern, matches with str else return 0. All characters of the string str and pattern always belong to the Alphanumeric characters.

The wildcard pattern can include the characters ? and *
‘?’ – matches any single character.
‘*’ – Matches any sequence of characters (including the empty sequence).

Note: The matching should cover the entire str (not partial str).

Examples:

Input: pattern = "ba*a?", str = "baaabab"
Output: 1
Explanation: replace '*' with "aab" and 
'?' with 'b'.
Input: pattern = "a*ab", str = "baaabab"
Output: 0
Explanation: Because in string pattern character 'a' at first position,
pattern and str can't be matched. 
Expected Time Complexity: O(n*m)
Expected Auxiliary Space: O(n*m)

Constraints:
1 <= length of(str, pattern) <= 200
*/

/*
Intuition:
The problem is about matching a string with a pattern where the pattern may contain wildcard characters:
- `?` matches any single character.
- `*` matches any sequence of characters (including an empty sequence).
We need to determine if the entire string can be matched with the pattern.

Approach:
1. **Recursive Approach with Memoization (`f`)**:
   - Define a recursive function `f(i, j)` that checks if the first `i` characters of the pattern can match the first `j` characters of the string.
   - Use a memoization table `dp[i][j]` to store the results of subproblems.
   - Base Cases:
     - If both `i` and `j` are zero, return true (both are empty).
     - If the pattern is empty but the string is not, return false.
     - If the pattern has characters left, but the string is empty, ensure that all remaining characters in the pattern are `*`.
   - Recurrence:
     - If the current characters in both pattern and string match or the pattern has a `?`, recurse on the previous characters.
     - If the pattern has a `*`, it can either match zero characters or more, leading to two recursive calls.
   
2. **Tabulation Approach (`fTab`)**:
   - Convert the recursive solution to an iterative one using a 2D table.
   - Iterate through the pattern and string to fill the table based on the recurrence relations defined in the recursive approach.
   
3. **Space-Optimized Tabulation (`fTabOpti`)**:
   - Optimize the space complexity by reducing the 2D table to a 1D array since the current state only depends on the previous state.

Time Complexity:
- The time complexity for all approaches is O(n * m), where `n` is the length of the pattern and `m` is the length of the string. This is because each subproblem is solved once.

Space Complexity:
- **Recursive with Memoization**: O(n * m) for the memoization table.
- **Tabulation**: O(n * m) for the table.
- **Space-Optimized Tabulation**: O(m) for the 1D array.

*/

class Solution {
  public:
    // Recursive function with memoization to solve the problem
    bool f(int i, int j, string pattern, string str, vector<vector<int>> &dp){
        if(i == 0 && j == 0) return true;
        if(i == 0 && j >= 1) return false;
        if(i >= 1 && j == 0) {
            for(int k = 0; k < i; k++) {
                if(pattern[k] != '*') return false;
            }
            return true;
        }
        if(dp[i][j] != -1) return dp[i][j];

        if(pattern[i-1] == str[j-1] || pattern[i-1] == '?') {
            return dp[i][j] = f(i-1, j-1, pattern, str, dp);
        }

        if(pattern[i-1] == '*') {
            return dp[i][j] = f(i-1, j, pattern, str, dp) | f(i, j-1, pattern, str, dp);
        }

        return dp[i][j] = false;
    }
    
    // Tabulation approach
    bool fTab(string pattern, string str){
        int n = pattern.size(), m = str.size();
        vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));
        dp[0][0] = true;

        for(int i = 1; i <= n; i++) {
            bool flag = true;
            for(int k = 0; k < i; k++) {
                if(pattern[k] != '*') {
                    flag = false;
                    break;
                }
            }
            dp[i][0] = flag;
        }

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(pattern[i-1] == str[j-1] || pattern[i-1] == '?') {
                    dp[i][j] = dp[i-1][j-1];
                }
                else if(pattern[i-1] == '*') {
                    dp[i][j] = dp[i-1][j] | dp[i][j-1];
                }
                else dp[i][j] = false;
            }
        }

        return dp[n][m];
    }
    
    // Space-optimized tabulation approach
    bool fTabOpti(string pattern, string str){
        int n = pattern.size(), m = str.size();
        vector<bool> prev(m+1, 0);
        prev[0] = true;

        for(int i = 1; i <= n; i++) {
            vector<bool> curr(m+1, 0);
            curr[0] = prev[0] & (pattern[i-1] == '*');
            for(int j = 1; j <= m; j++) {
                if(pattern[i-1] == str[j-1] || pattern[i-1] == '?') {
                    curr[j] = prev[j-1];
                }
                else if(pattern[i-1] == '*') {
                    curr[j] = prev[j] | curr[j-1];
                }
                else curr[j] = false;
            }
            prev = curr;
        }

        return prev[m];
    }
    
    // Main function to solve the wildcard matching problem
    int wildCard(string pattern, string str) {
        // Uncomment one of the following methods to use:
        
        // Memoization approach
        // int n = pattern.size(), m = str.size();
        // vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        // return f(n, m, pattern, str, dp);
        
        // Tabulation approach
        // return fTab(pattern, str);
        
        // Space-optimized tabulation approach
        return fTabOpti(pattern, str);
    }
};
