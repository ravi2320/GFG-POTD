/*
Smallest distinct window
Difficulty: MediumAccuracy: 31.85%Submissions: 102K+Points: 4
Given a string str, your task is to find the length of the smallest window that contains all the characters of the given string at least once.

Example:

Input: str = "aabcbcdbca"
Output: 4
Explanation: Sub-String "dbca" has the smallest length that contains all the characters of str.
Input: str = "aaab"
Output: 2
Explanation: Sub-String "ab" has the smallest length that contains all the characters of str.
Input: str = "geeksforgeeks"
Output: 8
Explanation: There are multiple substring with smallest length that contains all characters of str, "geeksfor" and "forgeeks". 
Constraints:
1 ≤ str.size() ≤ 105
str contains only lower-case english alphabets.
*/

/*
Approach:
- We want to find the length of the smallest substring of `str` that contains all **distinct characters** of `str`.
- First, count the number of distinct characters in the string.
- Then use the sliding window technique:
    - Expand the right pointer `j` and add characters to a frequency map.
    - When the map contains all distinct characters, try to shrink the window from the left to minimize the window size.

Intuition:
- The idea is similar to the "minimum window substring" problem.
- We keep expanding until we have all distinct characters, then start shrinking while maintaining all characters.

Time Complexity: O(N), where N is the length of the string. Each character is processed at most twice (once by `j`, once by `i`).
Space Complexity: O(K), where K is the number of distinct characters in the string.
*/

class Solution {
  public:
    int findSubString(string& str) {
        // Step 1: Count distinct characters using a set
        unordered_set<char> st;
        for (char &ch : str) {
            st.insert(ch);
        }
        
        int distinctChar = st.size(); // Total number of distinct characters
        unordered_map<char, int> mp;  // Frequency map for sliding window
        int n = str.size();
        int i = 0, j = 0;              // Sliding window pointers
        int res = INT_MAX;            // Initialize result with max
        
        // Step 2: Sliding window
        while (j < n) {
            mp[str[j]]++;  // Include current character in window
            
            // If window contains all distinct characters, try to shrink
            while (mp.size() == distinctChar) {
                res = min(res, j - i + 1); // Update result
                mp[str[i]]--;             // Shrink from left
                if (mp[str[i]] == 0) {
                    mp.erase(str[i]);     // Remove char from map if count is zero
                }
                i++;
            }
            j++;
        }
        
        return res;
    }
};
