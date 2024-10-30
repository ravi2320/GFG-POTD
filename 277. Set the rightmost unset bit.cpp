/*
Set the rightmost unset bit
Difficulty: BasicAccuracy: 47.64%Submissions: 43K+Points: 1
Given a non-negative number n . The problem is to set the rightmost unset bit in the binary representation of n.

Examples :

Input: n = 6
Output: 7
Explanation: The binary representation of 6 is 110. After setting right most bit it becomes 111 which is 7.
Input: n = 15
Output: 31
Explanation: The binary representation of 15 is 01111. After setting right most bit it becomes 11111 which is 31.
Expected Time Complexity: O(Logn)
Expected Auxiliary Space: O(1)


Constraints:
1 <= n <= 109
*/

/*
Approach:
1. To set the rightmost unset bit of a given integer `n`, we use the bitwise OR operation `n | (n + 1)`.
2. Adding 1 to `n` changes all the bits after the rightmost 0-bit to 1, effectively setting the rightmost unset bit in `n`.

Example:
For `n = 12` (binary: 1100), `n + 1 = 13` (binary: 1101). The result of `n | (n + 1)` is `1101`, which sets the rightmost unset bit in `n`.

Time Complexity: O(1), as bitwise operations are constant time.
Space Complexity: O(1), since no extra space is used.

*/

class Solution {
public:
    // Function to set the rightmost unset bit of n
    int setBit(int n) {
        return n | (n + 1); // OR operation to set the rightmost unset bit
    }
};
