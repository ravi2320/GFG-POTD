/*
Longest Substring with K Uniques
Difficulty: MediumAccuracy: 34.65%Submissions: 201K+Points: 4
You are given a string s consisting only lowercase alphabets and an integer k. Your task is to find the length of the longest substring that contains exactly k distinct characters.

Note : If no such substring exists, return -1. 

Examples:

Input: s = "aabacbebebe", k = 3
Output: 7
Explanation: The longest substring with exactly 3 distinct characters is "cbebebe", which includes 'c', 'b', and 'e'.
Input: s = "aaaa", k = 2
Output: -1
Explanation: There's no substring with 2 distinct characters.
Input: s = "aabaaab", k = 2
Output: 7
Explanation: The entire string "aabaaab" has exactly 2 unique characters 'a' and 'b', making it the longest valid substring.
Constraints:
1 ≤ s.size() ≤ 105
1 ≤ k ≤ 26
*/

/*
Approach:
We use the sliding window technique with two pointers (i, j) to maintain a window 
that contains at most `k` distinct characters. We expand the window by moving `j`,
and shrink it from the left by moving `i` if the number of distinct characters exceeds `k`.
We keep track of the maximum length of the substring when the number of distinct characters is exactly `k`.

Intuition:
The task is to find the longest substring that contains exactly `k` distinct characters.
Using a frequency array of size 26 (for lowercase English letters), we track character frequencies
and maintain the count of distinct characters in the current window.
When the count equals `k`, we consider the window as a potential answer.

Time Complexity: O(n) — Each character is processed at most twice (once by `j` and once by `i`).
Space Complexity: O(1) — Fixed-size array (26) for character frequencies.
*/

class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        int n = s.length();
        int i = 0, j = 0;
        int maxLen = -1;          // Initialize with -1 to handle "no valid substring" case
        int cnt = 0;              // Count of distinct characters in current window
        vector<int> freq(26, 0);  // Frequency of characters

        while(j < n){
            // If s[j] is a new character in the window
            if(freq[s[j] - 'a'] == 0) 
                cnt++;

            // Increase frequency of current character
            freq[s[j] - 'a']++;

            // Shrink the window from the left if distinct characters exceed k
            while(i < j && cnt > k){
                freq[s[i] - 'a']--;
                if(freq[s[i] - 'a'] == 0) 
                    cnt--;
                i++;
            }

            // Update maximum length if exactly k distinct characters
            if(cnt == k)
                maxLen = max(maxLen, j - i + 1);

            j++;
        }

        return maxLen;
    }
};