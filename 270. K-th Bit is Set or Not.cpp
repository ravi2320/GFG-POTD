/*
K-th Bit is Set or Not
Difficulty: EasyAccuracy: 52.75%Submissions: 202K+Points: 2
Given a number n and a bit number k, check if the kth index bit of n is set or not. A bit is called set if it is 1. The position of set bit '1' should be indexed starting with 0 from the LSB side in the binary representation of the number.
Note: Index is starting from 0. You just need to return true or false, driver code will take care of printing "Yes" and "No".

Examples : 

Input: n = 4, k = 0
Output: No
Explanation: Binary representation of 4 is 100, in which 0th index bit from LSB is not set. So, return false.
Input: n = 4, k = 2
Output: Yes
Explanation: Binary representation of 4 is 100, in which 2nd index bit from LSB is set. So, return true.
Input: n = 500, k = 3
Output: No
Explanation: Binary representation of 500 is 111110100, in which 3rd index bit from LSB is not set. So, return false.

Constraints:
1 ≤ n ≤ 109
0 ≤ k ≤ 31
*/

/*
Approach:
1. To check if the `k`th bit of an integer `n` is set, we can use a bitwise operation.
2. Right-shift `n` by `k` positions to bring the `k`th bit to the least significant bit position.
3. Perform a bitwise AND with `1`. If the result is `1`, the `k`th bit is set; otherwise, it is not.

Time Complexity: O(1), as bitwise operations are performed in constant time.
Space Complexity: O(1), no extra space is used.
*/

class Solution {
  public:
    // Function to check if Kth bit is set or not.
    bool checkKthBit(int n, int k) {
        // Right shift `n` by `k` bits, and check if the least significant bit is 1.
        return (n >> k) & 1;
    }
};
