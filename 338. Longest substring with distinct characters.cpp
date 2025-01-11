/*
Longest substring with distinct characters
Difficulty: EasyAccuracy: 31.32%Submissions: 135K+Points: 2
Given a string s, find the length of the longest substring with all distinct characters. 

Examples:

Input: s = "geeksforgeeks"
Output: 7
Explanation: "eksforg" is the longest substring with all distinct characters.
Input: s = "aaa"
Output: 1
Explanation: "a" is the longest substring with all distinct characters.
Input: s = "abcdefabcbb"
Output: 6
Explanation: The longest substring with all distinct characters is "abcdef", which has a length of 6.
Constraints:
1<= s.size()<=3*104
All the characters are in lowercase.
*/

/*
Approach:
1. Use the sliding window technique to maintain a window of unique characters.
2. Expand the window by moving the `j` pointer to include new characters.
3. If a duplicate character is encountered, shrink the window by moving the `i` pointer until all characters in the window are unique.
4. Track the length of the window during the process and update the maximum length.

Intuition:
- The sliding window technique helps in efficiently finding the longest substring without repeating characters by dynamically adjusting the size of the window.
- A frequency array is used to keep track of character counts in the current window.

Time Complexity:
- \(O(n)\): Each character is processed at most twice (once by `j` and once by `i`).

Space Complexity:
- \(O(1)\): A fixed-size frequency array of size 26 is used (constant space).

Edge Cases:
1. Empty string: The result should be 0.
2. String with all identical characters: The result is 1.
3. String with all unique characters: The result is the length of the string.

*/

class Solution {
public:
    int longestUniqueSubstr(string &s) {
        int n = s.length();          // Length of the input string
        vector<int> freq(26, 0);     // Frequency array to track character counts
        int i = 0, j = 0;            // Sliding window pointers
        int ans = 0;                 // To store the maximum length of unique substring

        // Traverse the string using the sliding window
        while (j < n) {
            int idx = s[j] - 'a';    // Calculate the index for the current character
            freq[idx]++;             // Increment the frequency of the character

            // If a duplicate character is found, shrink the window from the left
            while (i < j && freq[idx] > 1) {
                freq[s[i] - 'a']--;  // Decrement the frequency of the leftmost character
                i++;                 // Move the left pointer to the right
            }

            // Update the maximum length of the unique substring
            ans = max(ans, j - i + 1);
            j++;                     // Expand the window by moving the right pointer
        }

        return ans; // Return the maximum length of the unique substring
    }
};
