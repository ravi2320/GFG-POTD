/*
Binary representation of next number
EasyAccuracy: 50.0%Submissions: 25K+Points: 2
In need of more Geekbits? Win from a pool of 3500+ Geekbits via DSA-based Coding Contest every sunday!

banner
Given a binary representation in the form of a string(s) of a number n, the task is to find a binary representation of n+1.

Note: Output binary string should not contain leading zeros.

Example 1:

Input: s = "10"
Output: 11
Explanation: "10" is the binary representation of 2 and binary representation of 3 is "11"
Example 2:

Input: s = "111"
Output: 1000
Explanation: "111" is the binary representation of 7 and binary representation of 8 is "1000"
Your Task:  
You don't need to read input or print anything. Complete the function binaryNextNumber()which takes s as input parameter and returns the string.

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(n) to store resultant string  

Constraints:
1 <= n <= 105
*/

// Intuition:
// - The task is to find the binary representation of the next number after the given binary string `s`.
// - This can be done by simulating the addition of 1 to the binary number represented by `s`.

// Approach:
// - Start from the least significant bit (rightmost bit) and move towards the most significant bit (leftmost bit).
// - Change the first '0' encountered to '1' and all preceding '1's to '0's to simulate binary addition.
// - If no '0' is found and all bits are '1's, the resulting number will have an additional '1' at the most significant bit.

// Time Complexity: O(n)
// - We iterate through the string `s` once, where `n` is the length of the string.

// Space Complexity: O(1)
// - The space used is constant, aside from the input and output.

class Solution {
public:
    string binaryNextNumber(string s) {
        bool flag = true;
        
        // Traverse the string from the end towards the start
        for (int i = s.length() - 1; i >= 0; i--) {
            if (s[i] == '0') {
                s[i] = '1';  // Change the first '0' to '1'
                flag = false;
                break;
            } else {
                s[i] = '0';  // Change '1' to '0'
            }
        }
        
        if (flag) {
            // If no '0' was found and all bits are '1's, prepend '1'
            s = '1' + s;
        } else {
            // Remove leading zeros if present
            while (s[0] == '0') {
                s.erase(s.begin());
            }
        }
        
        return s;
    }
};
