/*
Ways to Reach the n'th Stair
Difficulty: MediumAccuracy: 21.9%Submissions: 217K+Points: 4
There are n stairs, a person standing at the bottom wants to reach the top. The person can climb either 1 stair or 2 stairs at a time. Your task is to count the number of ways, the person can reach the top (order does matter).

Examples:

Input: n = 1
Output: 1
Explanation: There is only one way to climb 1 stair. 
Input: n = 2
Output: 2
Explanation: There are 2 ways to reach 2th stair: {1, 1} and {2}.  
Input: n = 4
Output: 5
Explanation: There are five ways to reach 4th stair: {1, 1, 1, 1}, {1, 1, 2}, {2, 1, 1}, {1, 2, 1} and {2, 2}.
Constraints:
1 ≤ n ≤ 44
*/

/**
 * Approach:
 * - Instead of storing the entire DP array, **keep only the last two values**.
 * - This reduces **space complexity to O(1)**.
 * 
 * 🔹 **Time Complexity:** O(N)
 * 🔹 **Space Complexity:** O(1)
 */

class Solution {
  public:
    int countWays(int n) {
        if (n == 0) return 1;
        if (n == 1) return 1;

        int prev2 = 1, prev1 = 1, curr;

        for (int i = 2; i <= n; i++) {
            curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};
