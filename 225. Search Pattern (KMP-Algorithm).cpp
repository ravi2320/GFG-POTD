/*
Search Pattern (KMP-Algorithm)
Difficulty: MediumAccuracy: 45.04%Submissions: 64K+Points: 4
Given two strings, one is a text string, txt and other is a pattern string, pat. The task is to print the indexes of all the occurences of pattern string in the text string. Use one-based indexing while returning the indices. 
Note: Return an empty list incase of no occurences of pattern. Driver will print -1 in this case.

Example 1:

Input:
txt = "geeksforgeeks"
pat = "geek"
Output: 
1 9
Explanation: 
The string "geek" occurs twice in txt, one starts are index 1 and the other at index 9. 
Example 2:

Input: 
txt = "abesdu"
pat = "edu"
Output: 
-1
Explanation: 
There's not substring "edu" present in txt.
Your Task:
You don't need to read input or print anything. Your task is to complete the function search() which takes the string txt and the string pat as inputs and returns an array denoting the start indices (1-based) of substring pat in the string txt. 

Expected Time Complexity: O(|txt|).
Expected Auxiliary Space: O(|txt|).

Constraints:
1 ≤ |txt| ≤ 106
1 ≤ |pat| < |S|
Both the strings consists of lowercase English alphabets.
*/

/*
 * Approach:
 * 1. The goal is to find all occurrences of the pattern `pat` in the text `txt` using the KMP algorithm.
 * 2. First, compute the Longest Prefix Suffix (LPS) array for the pattern `pat` using the `findLPS` function.
 * 3. Use two pointers, `i` to traverse the text and `j` to traverse the pattern.
 * 4. If the characters at `txt[i]` and `pat[j]` match, increment both `i` and `j`.
 * 5. If a complete match of the pattern is found (`j == m`), store the starting index of the match in the result vector.
 * 6. If there's a mismatch and `j != 0`, reset `j` using the LPS array. If `j == 0`, increment `i`.
 * 7. Repeat this process until the entire text is traversed.
 *
 * Time Complexity: O(n + m), where n is the length of the text and m is the length of the pattern.
 * Space Complexity: O(m), for storing the LPS array.
 */

class Solution {
public:
    // Function to compute the LPS array for the pattern
    void findLPS(string pat, vector<int>& LPS, int m) {
        int i = 1;                       // Pointer to traverse the pattern
        int len = 0;                     // Length of the previous longest prefix suffix

        // Build the LPS array
        while (i < m) {
            if (pat[i] == pat[len]) {    // If characters match, increment len and set LPS value
                len++;
                LPS[i] = len;
                i++;
            } else {                     // If there is a mismatch
                if (len != 0) {          // If len is not zero, update len to the previous LPS value
                    len = LPS[len - 1];
                } else {                 // If len is zero, set LPS value to zero and move to the next character
                    LPS[i] = 0;
                    i++;
                }
            }
        }
    }

    // Function to find all occurrences of the pattern in the text using the KMP algorithm
    vector<int> search(string pat, string txt) {
        int n = txt.length();            // Length of the text
        int m = pat.size();              // Length of the pattern
        vector<int> res;                 // Result vector to store the starting indices of matches
        vector<int> LPS(m, 0);           // LPS array for the pattern

        // Compute the LPS array for the pattern
        findLPS(pat, LPS, m);

        int i = 0, j = 0;                // i is the pointer for the text, j is for the pattern
        while (i < n) {
            if (txt[i] == pat[j]) {      // If characters match, increment both pointers
                i++;
                j++;
            }

            if (j == m) {                // If a full match is found
                res.push_back(i - m + 1); // Store the starting index of the match
                j = LPS[j - 1];          // Reset j to continue searching
            } 
            // Mismatch after some matches
            else if (i < n && txt[i] != pat[j]) {
                if (j != 0) {            // Use LPS array to reset j
                    j = LPS[j - 1];
                } else {                 // If j is zero, simply move to the next character in text
                    i++;
                }
            }
        }

        return res;                      // Return the result vector containing all match positions
    }
};
