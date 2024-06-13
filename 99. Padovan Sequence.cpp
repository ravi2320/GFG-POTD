/*
Padovan Sequence
EasyAccuracy: 34.96%Submissions: 24K+Points: 2
Solve today's problem-> Be the comment of the day-> Win a GfG T-Shirt!
Daily rewards up for grabs!

banner
Given a number n, find the nth number in the Padovan Sequence.

A Padovan Sequence is a sequence which is represented by the following recurrence relation
P(n) = P(n-2) + P(n-3)
P(0) = P(1) = P(2) = 1

Note: Since the output may be too large, compute the answer modulo 10^9+7.

Examples :

Input: n = 3
Output: 2
Explanation: We already know, P1 + P0 = P3 and P1 = 1 and P0 = 1
Input: n = 4
Output: 2
Explanation: We already know, P4  = P2 + P1 and P2 = 1 and P1 = 1
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)

Constraints:
1 <= n <= 106
*/

/*
Intuition:
- The Padovan sequence is a sequence where each term after the third one is the sum of the two preceding terms, but shifted two places before.
- The recurrence relation is P(n) = P(n-2) + P(n-3).
- We need to compute this sequence efficiently using an iterative approach.

Approach:
1. Handle base cases where n is 0, 1, or 2 directly as they all return 1.
2. Initialize the first three terms of the sequence: P(0), P(1), and P(2) to 1.
3. Use a loop to iteratively compute the terms of the sequence from P(3) to P(n) using the recurrence relation.
4. Return the nth term after the loop ends.

Time Complexity:
- O(n), where n is the input number. This is because we are iterating from 3 to n.

Space Complexity:
- O(1), as we are using a constant amount of space regardless of the input size.

*/

class Solution
{
    public:
    int padovanSequence(int n)
    {
        // Modulo value for large number handling
        int mod = 1e9+7;
        
        // Base cases
        if(n <= 2)
            return 1;
        
        // Initialize the first three terms of the sequence
        int p0 = 1, p1 = 1, p2 = 1;
        int ans = 0;
        
        // Compute the sequence iteratively
        for(int i = 3; i <= n; i++){
            ans = (p0 + p1) % mod;
            p0 = p1;
            p1 = p2;
            p2 = ans;
        }
        
        // Return the nth term
        return ans % mod;
    }
};
