/*
Substrings with same first and last characters
Difficulty: EasyAccuracy: 50.0%Submissions: 16K+Points: 2
Given a string s consisting of lowercase characters, the task is to find the count of all substrings that start and end with the same character.

Examples:

Input: s = "abcab"
Output: 7
Explanation: There are 7 substrings where the first and last characters are the same: "a", "abca", "b", "bcab", "c", "a", and "b"
Input: s = "aba"
Output: 4
Explanation: There are 4 substrings where the first and last characters are the same: "a", "aba", "b", "a"
Constraints:
1 <= |s| <= 104
s contains lower case english alphabets
*/

/*
Approach:
- We iterate through the string and maintain a frequency array of characters seen so far.
- For each character `x`, we compute:
    - If `x` has appeared before, it can form substrings with all its previous occurrences.
    - So, add `freq[x - 'a'] + 1` to the count.
    - Else, it's the first occurrence — we count the character itself as a 1-length substring.
- We increment the frequency of the character after using it in calculation.

Intuition:
- For every new character, we are counting all new substrings ending at this position
  that contain this character, based on how many times it has appeared before.

Example:
- Input: "abca"
- Substrings: "a", "b", "c", "a", "ab", "bc", "ca", "abc", "bca", "abca"
- Logic captures substrings involving repeated characters more efficiently.

Time Complexity: O(n), where n = length of string
Space Complexity: O(1), for fixed-size frequency array
*/

class Solution {
public:
    int countSubstring(string &s) {
        vector<int> freq(26, 0); // Frequency of characters
        int cnt = 0; // Count of substrings

        for (char &x : s) {
            // If character x has appeared freq[x - 'a'] times,
            // it can form freq[x - 'a'] + 1 new substrings
            cnt += freq[x - 'a'] + 1;
            freq[x - 'a']++;
        }

        return cnt;
    }
};