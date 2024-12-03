/*
Min Chars to Add for Palindrome
Difficulty: HardAccuracy: 46.79%Submissions: 48K+Points: 8
Given a string s, the task is to find the minimum characters to be added at the front to make the string palindrome.

Note: A palindrome string is a sequence of characters that reads the same forward and backward.

Examples:

Input: s = "abc"
Output: 2
Explanation: Add 'b' and 'c' at front of above string to make it palindrome : "cbabc"
Input: s = "aacecaaaa"
Output: 2
Explanation: Add 2 a's at front of above string to make it palindrome : "aaaacecaaaa"
Constraints:
1 <= s.size() <= 106
*/

/*
Approach:
1. **Reverse the String**:
   - Reverse the input string `s` to create a new string `rev_str`.

2. **Concatenate Strings**:
   - Combine the original string, a delimiter (`#`), and the reversed string to form a new string `concat_str`.

3. **Calculate Longest Prefix-Suffix (LPS)**:
   - Use the Knuth-Morris-Pratt (KMP) algorithm to compute the LPS array for `concat_str`.
   - The value of the last element in the LPS array represents the length of the longest prefix of `s` that is also a suffix in `rev_str`.

4. **Determine Minimum Characters**:
   - The minimum characters to be added to make `s` a palindrome is `s.length() - LPS.back()`.

Time Complexity:
- **O(n)**: Where `n` is the length of the concatenated string. Computing the LPS array takes linear time.

Space Complexity:
- **O(n)**: For the LPS array.

*/

class Solution {
public:
    // Helper function to compute the Longest Prefix-Suffix (LPS) array
    vector<int> findLPS(string &s) {
        int n = s.length();
        vector<int> LPS(n, 0); // Initialize LPS array
        int len = 0;           // Length of the previous longest prefix
        int i = 1;

        // Compute LPS values
        while (i < n) {
            if (s[i] == s[len]) {
                len++;
                LPS[i] = len;
                i++;
            } else {
                if (len > 0) {
                    len = LPS[len - 1];
                } else {
                    LPS[i] = 0;
                    i++;
                }
            }
        }

        return LPS;
    }

    // Function to find the minimum number of characters to be added to make the string a palindrome
    int minChar(string &s) {
        // Reverse the string
        string rev_str = s;
        reverse(rev_str.begin(), rev_str.end());

        // Concatenate the original string, a delimiter, and the reversed string
        string concat_str = s + "#" + rev_str;

        // Compute the LPS array for the concatenated string
        vector<int> LPS = findLPS(concat_str);

        // Return the minimum number of characters to be added
        return s.length() - LPS.back();
    }
};
