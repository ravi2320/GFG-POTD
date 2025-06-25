/*
Check if frequencies can be equal
Difficulty: MediumAccuracy: 16.67%Submissions: 130K+Points: 4
Given a string s consisting only lowercase alphabetic characters, check whether it is possible to remove at most one character such that the  frequency of each distinct character in the string becomes same. Return true if it is possible; otherwise, return false.

Examples:

Input: s = "xyyz"
Output: true 
Explanation: Removing one 'y' will make frequency of each distinct character to be 1.
Input: s = "xyyzz"
Output: true
Explanation: Removing one 'x' will make frequency of each distinct character to be 2.
Input: s = "xxxxyyzz"
Output: false
Explanation: Frequency can not be made same by removing at most one character.
Constraints:
1 ≤ s.size() ≤ 105
*/

/*
Approach:
We are asked to determine if a given string `s` can have **equal character frequencies**
either already, or by **removing exactly one character**.

Steps:
1. Count frequency of each character in the string.
2. Use a map to count how many characters have the same frequency (`freqCnt`).
3. There are 3 valid cases to return true:
   - All characters have the same frequency (freqCnt.size() == 1).
   - Only two different frequencies exist, and:
     a) One frequency is 1 and occurs only once (i.e., one character appears once and can be removed).
     b) The higher frequency is greater than the lower by 1 and occurs only once (i.e., reduce one character's count by 1).

Time Complexity: O(n + 26) → O(n)
- n for counting character frequency, 26 is constant for alphabet.

Space Complexity: O(26 + 26) → O(1)
- Fixed space for lowercase characters and their frequency counts.
*/

class Solution {
public:
    bool sameFreq(string& s) {
        vector<int> freq(26, 0);

        // Count frequency of each character
        for (char &x : s) {
            freq[x - 'a']++;
        }

        unordered_map<int, int> freqCnt;  // Frequency -> Count of such frequencies

        // Count how many characters have each frequency
        for (int &x : freq) {
            if (x > 0)
                freqCnt[x]++;
        }

        // Case 1: All characters already have the same frequency
        if (freqCnt.size() == 1)
            return true;

        // Case 2: Only two frequencies present
        if (freqCnt.size() == 2) {
            auto it = freqCnt.begin();
            int freq1 = it->first, cnt1 = it->second;
            it++;
            int freq2 = it->first, cnt2 = it->second;

            // Check if one frequency can be removed or reduced to match the other
            if ((freq1 + 1 == freq2 && cnt2 == 1) || 
                (freq2 + 1 == freq1 && cnt1 == 1)) {
                return true;
            }

            // Check if there's only one character with frequency 1
            if ((freq1 == 1 && cnt1 == 1) || (freq2 == 1 && cnt2 == 1)) {
                return true;
            }
        }

        return false;  // Otherwise, not possible
    }
};
