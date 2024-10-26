/*
Odd or Even
Difficulty: BasicAccuracy: 60.6%Submissions: 105K+Points: 1
Given a positive integer n, determine whether it is odd or even. Return a string "even" if the number is even and "odd" if the number is odd.

Examples:

Input: n = 15
Output: odd
Explanation: The number is not divisible by 2
Input: n = 44
Output: even
Explanation: The number is divisible by 2
Expected Time Complexity: O(1)
Expected Auxiliary Space: O(1)

Constraints:
0 <= n <= 104
*/

/*
Approach:
1. To determine if a number `n` is odd or even, we use a bitwise AND operation.
2. If `n & 1` is true (non-zero), the least significant bit of `n` is set, indicating `n` is odd.
3. Otherwise, the least significant bit is 0, indicating `n` is even.

Time Complexity: O(1), as bitwise operations take constant time.
Space Complexity: O(1), no additional space is required.
*/

class Solution {
  public:
    // Function to determine if a number is odd or even.
    string oddEven(int n) {
        // Check if the least significant bit is set.
        return (n & 1) ? "odd" : "even";
    }
};
