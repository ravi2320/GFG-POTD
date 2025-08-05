/*
Palindrome Sentence

avatar
Discuss Approach
arrow-up
Difficulty: EasyAccuracy: 50.04%Submissions: 26K+Points: 2
Given a single string s, the task is to check if it is a palindrome sentence or not.
A palindrome sentence is a sequence of characters, such as word, phrase, or series of symbols that reads the same backward as forward after converting all uppercase letters to lowercase and removing all non-alphanumeric characters (including spaces and punctuation).

Examples:

Input: s = "Too hot to hoot"
Output: true
Explanation: If we remove all non-alphanumeric characters and convert all uppercase letters to lowercase, string s will become "toohottohoot" which is a palindrome.
Input: s = "Abc 012..## 10cbA"
Output: true
Explanation: If we remove all non-alphanumeric characters and convert all uppercase letters to lowercase, string s will become "abc01210cba" which is a palindrome.
Input: s = "ABC $. def01ASDF"
Output: false
Explanation: The processed string becomes "abcdef01asdf", which is not a palindrome.
Constraints:
1 ≤ s.length() ≤ 106

Expected Complexities
Time Complexity: O(n)
Auxiliary Space: O(1)
*/

/*
Approach:
- Use a two-pointer technique to check whether the sentence is a palindrome.
- Skip non-alphanumeric characters and compare the lowercase form of characters from both ends.

Intuition:
- A sentence is a palindrome if it reads the same forward and backward after removing non-alphanumeric characters and ignoring case.
- By using two pointers (`i` from start and `j` from end), we efficiently compare valid characters.

Time Complexity:
- O(n), where n is the length of the string. We process each character at most once.

Space Complexity:
- O(1), since we use only a few extra variables for pointers and checks.
*/

class Solution {
  public:
    bool isPalinSent(string &str) {
        int n = str.length();
        int i = 0, j = n - 1;

        // Two-pointer approach to check characters from both ends
        while (i < j) {
            // Skip non-alphanumeric characters from the left
            if (!isalnum(str[i])) {
                i++;
            }
            // Skip non-alphanumeric characters from the right
            else if (!isalnum(str[j])) {
                j--;
            }
            else {
                // Compare characters after converting to lowercase
                if (tolower(str[i]) != tolower(str[j])) {
                    return false;
                }
                i++, j--;
            }
        }

        // If all characters matched, it's a palindrome
        return true;
    }
};