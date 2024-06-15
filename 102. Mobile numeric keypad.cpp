/*
Mobile numeric keypad
MediumAccuracy: 32.6%Submissions: 45K+Points: 4
Solve today's problem-> Be the comment of the day-> Win a GfG T-Shirt!
Daily rewards up for grabs!

banner
There is a standard numeric keypad on a mobile phone. You can only press the current button or buttons that are directly up, left, right, or down from it (for ex if you press 5, then pressing 2, 4, 6 & 8 are allowed). Diagonal movements and pressing the bottom row corner buttons (* and #) are prohibited.



Given a number n, find the number of possible unique sequences of length n that you can create by pressing buttons. You can start from any digit.

Examples

Input: n = 1
Output: 10
Explanation: Number of possible numbers are 10 (0, 1, 2, 3, 4, 5, 6, 7, 8, 9)  
Input: n = 2
Output: 36
Explanation: Possible numbers: 00, 08, 11, 12, 14, 22, 21, 23, 25 and so on. If we start with 0, valid numbers will be 00, 08 (count: 2). If we start with 1, valid numbers will be 11, 12, 14 (count: 3). If we start with 2, valid numbers  will be 22, 21, 23,25 (count: 4). If we start with 3, valid numbers will be 33, 32, 36 (count: 3). If we start with 4, valid numbers will be 44,41,45,47 (count: 4). If we start with 5, valid numbers will be 55,54,52,56,58 (count: 5) and so on.
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(n)

Constraints:
1 ≤ n ≤ 25
*/

/*
Intuition:
- The problem is to count the number of possible sequences of length `n` that can be formed by moving on a numeric keypad.
- The movements allowed are up, down, left, right, and staying on the same key.
- Certain keys like '*' and '#' cannot be part of the sequence.

Approach:
1. Use dynamic programming to keep track of the count of sequences ending at each key for each length.
2. Use a 3D DP array where dp[i][j][n] represents the count of sequences of length `n` ending at the key at position (i, j) on the keypad.
3. Base Case:
   - If `n` is 1, the count for each key is 1.
4. Recursive Case:
   - For each position (i, j), the count for sequences of length `n` is the sum of counts of sequences of length `n-1` that can reach (i, j) through valid movements.
5. Invalid positions and keys are handled with boundary checks.

Time Complexity:
- The overall time complexity is O(4 * 3 * n) because we iterate through the entire DP array for every key and sequence length.

Space Complexity:
- The space complexity is O(4 * 3 * (n+1)) due to the 3D DP array.

*/

class Solution {
  public:
    long long help(int i, int j, int n, vector<vector<vector<long long>>> &dp){
        if(i > 3 || j > 2 || i < 0 || j < 0) // Boundary check
            return 0;
            
        if(i == 3 && (j == 0 || j == 2)) // Invalid keys '*' and '#'
            return 0;
            
        if(n == 1) // Base case: sequences of length 1
            return 1;
            
        if(dp[i][j][n] != -1) // Check if already computed
            return dp[i][j][n];
            
        n--; // Decrease the sequence length by 1
        // Recursive calculation of sequences
        return dp[i][j][n+1] = help(i-1, j, n, dp) + help(i+1, j, n, dp) + help(i, j-1, n, dp) + help(i, j+1, n, dp) + help(i, j, n, dp);
    }

    long long getCount(int n) {
        // Calculate the total number of sequences of length `n`
        long long ans = 0;
        vector<vector<vector<long long>>> dp(4, vector<vector<long long>>(3, vector<long long>(n+1, -1)));
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 3; j++){
                if(i == 3 && (j == 0 || j == 2)) // Skip invalid keys
                    continue;
                ans += help(i, j, n, dp);
            }
        }
        
        return ans;
    }
};
