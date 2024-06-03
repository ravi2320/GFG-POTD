/*
Trail of ones
EasyAccuracy: 51.16%Submissions: 17K+Points: 2
In need of more Geekbits? Win from a pool of 3500+ Geekbits via DSA-based Coding Contest every sunday!

banner
Given a number n, find the number of binary strings of length n that contain consecutive 1's in them. Since the number can be very large, return the answer after modulo with 1e9+7.

Example 1:

Input: n = 2
Output: 1
Explanation: There are 4 strings of length 2, the strings are 00, 01, 10, and 11. Only the string 11 has consecutive 1's.
Example 2:

Input: n = 5
Output: 19
Explanation: There are 19 strings having consecutive 1's.
Your Task:

You don't need to read input or print anything. Your task is to complete the function numberOfConsecutiveOnes() which takes an integer n and returns the number of binary strings that contain consecutive 1's in them.

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(n)

Constraints
2 <= n <= 105
*/

// Intuition:
// - The problem involves finding the number of binary strings of length `n` that do not contain consecutive 1s.
// - This can be approached using dynamic programming by defining a recurrence relation for the number of valid strings.
// - Let `a` be the count of valid strings ending in 0 and `b` be the count of valid strings ending in 1.
// - For each length `i` from 3 to `n`, update `a` and `b` based on the previous values, and calculate the total number of valid strings.

// Time Complexity: O(n)
// - We iterate from 3 to `n` to compute the number of valid strings.

// Space Complexity: O(1)
// - We use a constant amount of extra space to store the variables `a`, `b`, and `ans`.

class Solution {
public:
    int numberOfConsecutiveOnes(int n) {
        // Base case for n = 2
        if (n == 2) return 1;

        // Initial values for length 2
        int a = 0, b = 1, ans = 1;
        const int mod = 1e9+7;

        // Iterate from 3 to n
        for (int i = 3; i <= n; i++) {
            // Calculate c as the sum of a and b
            int c = (a + b) % mod;
            // Update a and b for the next iteration
            a = b;
            b = c;
            // Update the answer for the total number of valid strings
            ans = ((ans * 2) % mod + c) % mod;
        }

        return ans;
    }
};
