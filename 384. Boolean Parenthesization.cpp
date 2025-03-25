/*
Boolean Parenthesization
Difficulty: HardAccuracy: 20.15%Submissions: 131K+Points: 8Average Time: 30m
You are given a boolean expression s containing
    'T' ---> true
    'F' ---> false 
and following operators between symbols
   &   ---> boolean AND
    |   ---> boolean OR
   ^   ---> boolean XOR
Count the number of ways we can parenthesize the expression so that the value of expression evaluates to true.

Note: The answer is guaranteed to fit within a 32-bit integer.

Examples:

Input: s = "T|T&F^T"
Output: 4
Explaination: The expression evaluates to true in 4 ways: ((T|T)&(F^T)), (T|(T&(F^T))), (((T|T)&F)^T) and (T|((T&F)^T)).
Input: s = "T^F|F"
Output: 2
Explaination: The expression evaluates to true in 2 ways: ((T^F)|F) and (T^(F|F)).
Constraints:
1 ≤ |s| ≤ 100 
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    int dp[101][101][2]; // Memoization table
    const int MOD = 1e9 + 7; // Modulo to prevent overflow

  public:
    // Recursive function to count ways to parenthesize the expression to evaluate to isTrue
    int f(int i, int j, bool isTrue, string &s) {
        // Base Case: Invalid range
        if (i > j) return 0;

        // Base Case: Single character (T or F)
        if (i == j) {
            return isTrue ? (s[i] == 'T') : (s[i] == 'F');
        }

        // Check if already computed
        if (dp[i][j][isTrue] != -1) return dp[i][j][isTrue];

        int ways = 0;

        // Iterate over operators at odd positions
        for (int idx = i + 1; idx <= j - 1; idx += 2) {
            // Calculate left and right partition results
            int lT = f(i, idx - 1, true, s);
            int lF = f(i, idx - 1, false, s);
            int rT = f(idx + 1, j, true, s);
            int rF = f(idx + 1, j, false, s);

            // Apply operator logic
            if (s[idx] == '&') { // AND
                if (isTrue) {
                    ways = (ways + (1LL * lT * rT) % MOD) % MOD;
                } else {
                    ways = (ways + (1LL * lT * rF) % MOD + (1LL * lF * rT) % MOD + (1LL * lF * rF) % MOD) % MOD;
                }
            } else if (s[idx] == '|') { // OR
                if (isTrue) {
                    ways = (ways + (1LL * lT * rF) % MOD + (1LL * lF * rT) % MOD + (1LL * lT * rT) % MOD) % MOD;
                } else {
                    ways = (ways + (1LL * lF * rF) % MOD) % MOD;
                }
            } else { // XOR (^)
                if (isTrue) {
                    ways = (ways + (1LL * lT * rF) % MOD + (1LL * lF * rT) % MOD) % MOD;
                } else {
                    ways = (ways + (1LL * lT * rT) % MOD + (1LL * lF * rF) % MOD) % MOD;
                }
            }
        }

        // Store and return the computed value
        return dp[i][j][isTrue] = ways;
    }

    // Function to count the number of ways to parenthesize the boolean expression to evaluate to true
    int countWays(string &s) {
        int n = s.length();
        memset(dp, -1, sizeof(dp)); // Initialize DP table with -1
        return f(0, n - 1, true, s); // Start recursive computation
    }
};

// Driver function
int main() {
    string expression = "T|T&F^T";
    Solution obj;
    cout << obj.countWays(expression) << endl; // Output: Number of ways to evaluate to True
    return 0;
}