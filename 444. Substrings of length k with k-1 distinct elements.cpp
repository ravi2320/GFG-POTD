/*
Substrings of length k with k-1 distinct elements
Difficulty: MediumAccuracy: 57.85%Submissions: 28K+Points: 4Average Time: 15m
Given a string s consisting only lowercase alphabets and an integer k. Find the count of all substrings of length k which have exactly k-1 distinct characters.

Examples:

Input: s = "abcc", k = 2
Output: 1
Explaination: Possible substring of length k = 2 are,
ab : 2 distinct characters
bc : 2 distinct characters
cc : 1 distinct characters
Only one valid substring so, count is equal to 1.
Input: "aabab", k = 3
Output: 3
Explaination: Possible substring of length k = 3 are, 
aab : 2 distinct charcters
aba : 2 distinct characters
bab : 2 distinct characters
All these substring are valid so, the total count is equal to 3.
Constrains:
1 ≤ s.size() ≤ 105
2 ≤ k ≤ 27

Expected Complexities
Time Complexity: O(n)
Auxiliary Space: O(1)
*/

/*
Approach:
We are given a string `s` and an integer `k`. The goal is to count the number of substrings 
of length `k` that contain exactly `k-1` distinct characters.

Steps:
1. Use a sliding window of size `k` and maintain a frequency array to track characters.
2. Track the number of distinct characters in the current window.
3. Initially, compute the distinct count for the first window of size `k`.
4. Slide the window one character at a time:
   - Remove the outgoing character and update distinct count if needed.
   - Add the incoming character and update distinct count if needed.
5. If at any point the number of distinct characters is `k-1`, increment the answer.

Intuition:
We maintain a fixed-size window and only update the frequency of characters entering or leaving the window,
which allows us to check each substring in O(1) time after the initial setup.

Time Complexity:
- O(n): We traverse the string once and use O(1) operations inside the loop.

Space Complexity:
- O(1): Since the frequency array is of fixed size (26 lowercase letters)
*/

class Solution {
  public:
    int substrCount(string &s, int k) {
        int n = s.length();
        vector<int> freq(26, 0); // Frequency of characters in current window
        int ans = 0;
        int distinctChar = 0;

        // Initialize the first window
        for (int i = 0; i < k; i++) {
            if (freq[s[i] - 'a'] == 0)
                distinctChar++;
            freq[s[i] - 'a']++;
        }

        // Check if the first window has exactly k-1 distinct characters
        if (distinctChar == k - 1)
            ans++;

        // Slide the window through the string
        for (int i = k; i < n; i++) {
            char outChar = s[i - k]; // Character going out
            char inChar = s[i];      // Character coming in

            // Remove the character that's sliding out
            freq[outChar - 'a']--;
            if (freq[outChar - 'a'] == 0)
                distinctChar--;

            // Add the new character coming into the window
            freq[inChar - 'a']++;
            if (freq[inChar - 'a'] == 1)
                distinctChar++;

            // If window has exactly k-1 distinct characters, count it
            if (distinctChar == k - 1)
                ans++;
        }

        return ans;
    }
};