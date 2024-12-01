/*
Non Repeating Character
Difficulty: EasyAccuracy: 40.43%Submissions: 236K+Points: 2
Given a string s consisting of lowercase Latin Letters. Return the first non-repeating character in s. If there is no non-repeating character, return '$'.
Note: When you return '$' driver code will output -1.

Examples:

Input: s = "geeksforgeeks"
Output: 'f'
Explanation: In the given string, 'f' is the first character in the string which does not repeat.
Input: s = "racecar"
Output: 'e'
Explanation: In the given string, 'e' is the only character in the string which does not repeat.
Input: s = "aabbccc"
Output: -1
Explanation: All the characters in the given string are repeating.
Constraints:
1 <= s.size() <= 105
*/

/*
Approach:
1. **Frequency Counting**:
   - Use a frequency array of size 26 (for lowercase English letters) to count the occurrences of each character in the string.

2. **First Non-Repeating Character**:
   - Traverse the string a second time and return the first character whose frequency is 1.

3. **Edge Case**:
   - If no non-repeating character exists, return the special character '$'.

Time Complexity:
- **O(n)**: Single traversal for frequency counting and another traversal to check for the non-repeating character.

Space Complexity:
- **O(1)**: Frequency array uses a constant amount of space.

*/

class Solution {
public:
    // Function to find the first non-repeating character in a string
    char nonRepeatingChar(string &s) {
        // Frequency array to store the count of each character
        vector<int> freq(26, 0);

        // Count the frequency of each character
        for (char &x : s) {
            freq[x - 'a']++;
        }

        // Find the first character with frequency 1
        for (char &x : s) {
            if (freq[x - 'a'] == 1) {
                return x;
            }
        }

        // If no non-repeating character is found, return '$'
        return '$';
    }
};
