/*
Smallest window containing all characters
Difficulty: HardAccuracy: 30.19%Submissions: 183K+Points: 8Average Time: 30m
Given two strings s and p. Find the smallest substring in s consisting of all the characters (including duplicates) of the string p. Return empty string in case no such substring is present.
If there are multiple such substring of the same length found, return the one with the least starting index.

Examples:

Input: s = "timetopractice", p = "toc"
Output: "toprac"
Explanation: "toprac" is the smallest substring in which "toc" can be found.
Input: s = "zoomlazapzo", p = "oza"
Output: "apzo"
Explanation: "apzo" is the smallest substring in which "oza" can be found.
Input: s = "zoom", p = "zooe"
Output: ""
Explanation: No substring is present containing all characters of p.
Constraints: 
1 ≤ s.length(), p.length() ≤ 106
s, p consists of lowercase english letters
*/

/*
Approach:
---------
1. We want the smallest substring of `s` that contains all characters of `p` (including duplicates).
2. Maintain frequency counts:
   - `reqFreq`: frequency of required characters from `p`.
   - `currFreq`: frequency of current window characters from `s`.
3. Use a sliding window with two pointers `i` (start) and `j` (end):
   - Expand `j` forward and include characters in `currFreq`.
   - While the window is valid (all required characters are present), try shrinking it from the left (`i`) to minimize length.
4. Keep track of the minimum length window and starting index.
5. Return the substring if found; otherwise, return an empty string.

Intuition:
----------
We use a **two-pointer sliding window** approach. The key idea is:
- First expand the window until it satisfies the requirement.
- Then contract it as much as possible while still valid to find the minimum-length substring.
This ensures we always check the smallest valid window for each `j`.

Time Complexity:
----------------
- O(|s| * 256) in worst case since `isPossible` checks all 256 chars for every shrink step.
- Can be optimized to O(|s|) using "matched characters count" instead of scanning all 256.
- But as written: O(n * 256), where n = |s|.

Space Complexity:
-----------------
- O(256) = O(1), constant space for frequency arrays.

*/

class Solution {
  public:
    // Utility function to check if current window has all required characters
    bool isPossible(vector<int> &currFreq, vector<int> &reqFreq) {
        for (int i = 0; i < 256; i++) {
            if (currFreq[i] < reqFreq[i]) {
                return false; // missing required character
            }
        }
        return true;
    }

    string smallestWindow(string &s, string &p) {
        string res = "";
        vector<int> reqFreq(256, 0), currFreq(256, 0); // store ASCII frequencies
        int n = s.length();

        // Build frequency map of characters in pattern `p`
        for (char &x : p) {
            reqFreq[x]++;
        }

        int i = 0;                // left pointer of sliding window
        int minLen = INT_MAX;     // store minimum window length found
        int startIndex = -1;      // store starting index of result window

        // Expand window by moving right pointer `j`
        for (int j = 0; j < n; j++) {
            currFreq[s[j]]++;

            // Once valid window found, try shrinking it from left
            while (isPossible(currFreq, reqFreq)) {
                if (j - i + 1 < minLen) {
                    minLen = j - i + 1; // update best length
                    startIndex = i;     // update starting index
                }

                // Shrink from left
                currFreq[s[i]]--;
                i++;
            }
        }

        // If valid window found, extract substring
        if (startIndex != -1) {
            res = s.substr(startIndex, minLen);
        }

        return res;
    }
};
