/*
Minimum repeat to make substring
Difficulty: MediumAccuracy: 51.22%Submissions: 46K+Points: 4
Given two strings s1 and s2. Return a minimum number of times s1 has to be repeated such that s2 is a substring of it. If s2 can never be a substring then return -1.

Note: Both the strings contain only lowercase letters.

Examples:

Input: s1 = "ww", s2 = "www"
Output: 2
Explanation: Repeating s1 two times (wwww), s2 is a substring of it.
Input: s1 = "abcd", s2 = "cdabcdab" 
Output: 3 
Explanation: Repeating s1 three times (abcdabcdabcd), s2 is a substring of it. s2 is not a substring of s2 when it is repeated less than 3 times.
Input: s1 = "ab", s2 = "cab"
Output: -1
Explanation: No matter how many times we repeat s1, we can't get a string such that s2 is a substring of it.
Constraints:
1 ≤ |s1|, |s2| ≤ 105
*/

/*
Approach:
1. Initialize a temporary copy of `s1` in `temp` and a counter `cnt` set to 1.
2. Repeat appending `temp` to `s1` and incrementing `cnt` until `s1`'s length is at least as long as `s2`'s length.
3. Check if `s2` is a substring of `s1` after each extension:
   - If `s2` is found in `s1`, return `cnt` as the minimum number of repeats.
4. Append `temp` one more time to `s1` to ensure all potential matches.
5. If `s2` is found in the extended `s1`, return `cnt`; otherwise, return `-1`.

Time Complexity: O(n * m), where `n` is the length of `s1` and `m` is the length of `s2` (due to repeated string concatenations and substring checks).
Space Complexity: O(n + m), for the combined storage of `s1` and `s2`.

*/

class Solution {
  public:
    int minRepeats(string& s1, string& s2) {
        // Initialize the repeated string as s1 and set count to 1
        string temp = s1;
        int cnt = 1;
        
        // Keep appending until s1 length meets or exceeds s2 length
        while (s1.length() < s2.length()) {
            s1 += temp;
            cnt++;
        }
        
        // Check if s2 is now a substring of s1
        if (s1.find(s2) != string::npos) 
            return cnt;
            
        // Append one more time to cover edge cases
        s1 += temp;
        cnt++;
        
        // Final check for s2 in the extended s1
        if (s1.find(s2) != string::npos)
            return cnt;
        
        return -1;  // Return -1 if s2 is not a substring
    }
};
