/*
Remaining String
Difficulty: EasyAccuracy: 17.06%Submissions: 59K+Points: 2
Given a string s without spaces, a character ch and an integer count. Your task is to return the substring that remains after the character ch has appeared count number of times.
Note:  Assume upper case and lower case alphabets are different. “”(Empty string) should be returned if it is not possible, or the remaining substring is empty.

Examples:

Input: s = "Thisisdemostring", ch = 'i', count = 3
Output: ng
Explanation: The remaining substring of s after the 3rd
occurrence of 'i' is "ng", hence the output is ng.
Input: s = "Thisisdemostri", ch = 'i', count = 3
Output: ""
Explanation: The 3rd occurence of 'i' is at the last index. In this case the remaining substring is empty, hence we return empty string.
Input: s = "abcd", ch = 'x', count = 2
Output: ""
Explanation: The character x is not present in the string, hence we return empty string.
Expected Time Complexity: O(|s|)
Expected Auxiliary Space: O(1)

Constraints:
1<= s.length()<=105
1<=count<=s.length()
s[i] is both upper case and lower case
*/

class Solution {
public:
    // Intuition:
    // - The task is to find the substring that comes after the `count`-th occurrence of the character `ch` in the given string `s`.
    // - We can iterate through the string and count the occurrences of `ch`.
    // - Once we find the `count`-th occurrence, we return the substring starting from the next character.
    // - If the `count`-th occurrence is not found, we return an empty string.

    // Time Complexity: O(N)
    // - We iterate through the string once to find the `count`-th occurrence of `ch`, where N is the length of the string.

    // Space Complexity: O(1)
    // - We use a few extra variables for counting and indexing, which take constant space.

    string printString(string s, char ch, int count) {
        int cnt = 0;
        int n = s.length();
        
        // Iterate through the string
        for (int i = 0; i < n; i++) {
            // Increment count if the current character matches `ch`
            if (s[i] == ch) {
                cnt++;
            }
            
            // If we reach the `count`-th occurrence, return the substring starting from the next character
            if (cnt == count) {
                return s.substr(i + 1);
            }
        }
        
        // If the `count`-th occurrence is not found, return an empty string
        return "";
    }
};
