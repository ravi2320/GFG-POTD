/*
Strings Rotations of Each Other
Difficulty: EasyAccuracy: 43.83%Submissions: 211K+Points: 2
You are given two strings of equal lengths, s1 and s2. The task is to check if s2 is a rotated version of the string s1.

Note: The characters in the strings are in lowercase.

Examples :

Input: s1 = "abcd", s2 = "cdab"
Output: true
Explanation: After 2 right rotations, s1 will become equal to s2.
Input: s1 = "aab", s2 = "aba"
Output: true
Explanation: After 1 left rotation, s1 will become equal to s2.
Input: s1 = "abcd", s2 = "acbd"
Output: false
Explanation: Strings are not rotations of each other.
Constraints:
1 <= s1.size(), s2.size() <= 105
*/

/*
Approach:
1. To determine if `s2` is a rotation of `s1`, we concatenate `s1` with itself.
   - A valid rotation of `s1` will always appear as a substring of this concatenated string.
2. However, to optimize, we use the Knuth-Morris-Pratt (KMP) algorithm for pattern matching:
   - Concatenate `s2 + "$" + s1 + s1` (using a separator "$" to avoid overlaps).
   - Build the Longest Prefix Suffix (LPS) array for the concatenated string.
   - Use the LPS array to find if `s2` exists as a substring.

Time Complexity:
- **O(n + m)**: `n` is the length of the concatenated string, and `m` is the length of `s2`.

Space Complexity:
- **O(n)**: Space for the LPS array.

*/

class Solution {
public:
    // Function to check if two strings are rotations of each other
    bool areRotations(string &s1, string &s2) {
        // If lengths differ, they cannot be rotations
        if (s1.length() != s2.length()) return false;

        string concatenated = s2 + "$" + s1 + s1; // Combine strings with a separator
        int n = concatenated.length(), m = s2.length(); // Lengths of concatenated string and `s2`
        vector<int> lps(n, 0); // Longest Prefix Suffix (LPS) array

        int i = 0, j = 1; // Pointers for LPS construction
        while (j < n) {
            if (concatenated[i] == concatenated[j]) {
                lps[j++] = ++i; // Match found, increment pointers
                // If a full match of `s2` is found, return true
                if (i == m) return true;
            } else if (i > 0) {
                i = lps[i - 1]; // Move `i` back to check smaller prefix
            } else {
                j++; // No match, move `j`
            }
        }

        return false; // No match found
    }
};
