/*
Add Binary Strings
Difficulty: MediumAccuracy: 23.25%Submissions: 66K+Points: 4
Given two binary strings s1 and s2 consisting of only 0s and 1s. Find the resultant string after adding the two Binary Strings.
Note: The input strings may contain leading zeros but the output string should not have any leading zeros.

Input: s1 = "1101", s2 = "111"
Output: 10100
Explanation:
 1101
+ 111
10100
Input: s1 = "00100", s2 = "010"
Output: 110
Explanation: 
  100
+  10
  110
Constraints:
1 ≤s1.size(), s2.size()≤ 106
*/

/*
Approach:
1. Perform binary addition by iterating from the least significant bit (rightmost bit) to the most significant bit.
2. Use three components for each step of addition:
   - `bit1` from `s1`.
   - `bit2` from `s2`.
   - `carry` from the previous step.
3. Compute the sum of the bits (`bit1 + bit2 + carry`):
   - Append the result's least significant bit (`sum % 2`) to the result string.
   - Update the carry to `sum / 2`.
4. Handle remaining carry if both strings are processed.
5. Remove leading zeros from the result.

Time Complexity:
- O(max(n, m)), where `n` and `m` are the lengths of `s1` and `s2`.

Space Complexity:
- O(max(n, m)) for the result string.

Edge Cases:
- If either string is empty.
- If the result has leading zeros, they should be trimmed.

*/

class Solution {
public:
    string addBinary(string& s1, string& s2) {
        int i = s1.length() - 1, j = s2.length() - 1; // Pointers to traverse s1 and s2
        int carry = 0; // Initialize carry
        string ans = ""; // Result string

        // Process both strings and carry
        while (i >= 0 || j >= 0 || carry) {
            // Fetch current bits or 0 if out of bounds
            int bit1 = i >= 0 ? s1[i] - '0' : 0;
            int bit2 = j >= 0 ? s2[j] - '0' : 0;

            int sum = bit1 + bit2 + carry; // Compute sum
            ans = char((sum % 2) + '0') + ans; // Append sum's least significant bit
            carry = sum / 2; // Update carry

            i--; // Move to the next bit in s1
            j--; // Move to the next bit in s2
        }

        // Remove leading zeros (if any)
        size_t pos = ans.find_first_not_of('0');
        return pos != string::npos ? ans.substr(pos) : "0";
    }
};
