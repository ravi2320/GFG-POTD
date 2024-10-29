/*
Swap two numbers
Difficulty: BasicAccuracy: 70.02%Submissions: 70K+Points: 1
Swap given two numbers and print them. (Try to do it without a temporary variable.) and return it.

Example 1:

Input: a = 13, b = 9
Output: 9 13
Explanation: after swapping it
becomes 9 and 13.
Example 2:

Input: a = 15, b = 8
Output: 8 15
Explanation: after swapping it
becomes 8 and 15.
Your Task:  
You don't need to read input or print anything. Your task is to complete the function get() which takes a, b as inputs and returns the list of integers contains the new value of a and b after swap.

Expected Time Complexity: O(1)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ a, b ≤ 106
*/

/*
Approach:
1. This function uses XOR bitwise operations to swap two integers, `a` and `b`, without using a temporary variable.
   - XOR has the property where `x ^ x = 0` and `x ^ 0 = x`.
2. The steps involved:
   - `a = a ^ b`: This sets `a` to `a XOR b`.
   - `b = a ^ b`: This resets `b` to `a`'s original value.
   - `a = a ^ b`: This resets `a` to `b`'s original value.
3. This effectively swaps `a` and `b` without extra storage.

Time Complexity: O(1)
Space Complexity: O(1)

*/

class Solution {   
public:
    pair<int, int> get(int a, int b) {
        // XOR swap algorithm
        a = a ^ b; // Step 1: a now holds a XOR b
        b = a ^ b; // Step 2: b now holds the original value of a
        a = a ^ b; // Step 3: a now holds the original value of b
        return {a, b}; // Return the swapped values as a pair
    }
};
