/*
Longest Prefix Suffix
Difficulty: HardAccuracy: 27.91%Submissions: 122K+Points: 8
Given a string of characters, find the length of the longest proper prefix which is also a proper suffix.

NOTE: Prefix and suffix can be overlapping but they should not be equal to the entire string.

Examples :

Input: str = "abab"
Output: 2
Explanation: "ab" is the longest proper prefix and suffix. 
Input: str = "aaaa"
Output: 3
Explanation: "aaa" is the longest proper prefix and suffix. 
Expected Time Complexity: O(|str|)
Expected Auxiliary Space: O(|str|)

Constraints:
1 ≤ |str| ≤ 106
str contains lower case English alphabets
*/

/*
 * Approach:
 * 1. The goal is to compute the Longest Prefix Suffix (LPS) array for the given string.
 * 2. Initialize an array LPS of the same length as the string to store the longest prefix which is also a suffix.
 * 3. Use two pointers: `len` to keep track of the length of the current longest prefix suffix, and `i` to traverse the string.
 * 4. If characters at position `i` and `len` match, increment both `len` and `i`, and set LPS[i] to len.
 * 5. If there is a mismatch and `len` is not zero, update `len` to LPS[len - 1] to check for a shorter prefix.
 * 6. If `len` is zero, set LPS[i] to zero and move to the next character by incrementing `i`.
 * 7. The final value of LPS[n-1] will give the length of the longest prefix which is also a suffix.
 *
 * Time Complexity: O(n), where n is the length of the input string.
 * Space Complexity: O(n), for storing the LPS array.
 */

class Solution {
public:
    // Function to compute the Longest Prefix Suffix (LPS) array
    int lps(string str) {
        int len = 0;                     // Length of the previous longest prefix suffix
        int n = str.length();            // Length of the input string
        vector<int> LPS(n, 0);           // LPS array initialized to zero

        int i = 1;                       // Start from the second character
        while (i < n) {
            // If characters match, increment length and set LPS value
            if (str[i] == str[len]) {
                len++;
                LPS[i] = len;
                i++;
            }
            // If there is a mismatch
            else {
                // If len is not zero, update len to the previous LPS value
                if (len != 0) {
                    len = LPS[len - 1];
                }
                // If len is zero, set LPS value to zero
                else {
                    LPS[i] = 0;
                    i++;
                }
            }
        }

        return LPS[n - 1]; // Return the length of the longest prefix which is also a suffix
    }
};
