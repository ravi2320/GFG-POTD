/*
Reverse Words
Difficulty: EasyAccuracy: 56.08%Submissions: 331K+Points: 2
Given a String str, reverse the string without reversing its individual words. Words are separated by dots.

Note: The last character has not been '.'. 

Examples :

Input: str = i.like.this.program.very.much
Output: much.very.program.this.like.i
Explanation: After reversing the whole string(not individual words), the input string becomes much.very.program.this.like.i
Input: str = pqr.mno
Output: mno.pqr
Explanation: After reversing the whole string , the input string becomes mno.pqr
Expected Time Complexity: O(|str|)
Expected Auxiliary Space: O(|str|)

Constraints:
1 <= |str| <= 105
*/

/*
Approach:
1. **Reverse Word-by-Word**: Start from the end of the string and extract each word by detecting the '.' delimiter.
2. **Build the Result**: Once a word is extracted, reverse it and add it to the result string. Repeat for all words.
3. **Edge Case Handling**: Ensure that after the last word (which doesn't end with a '.'), the word is reversed and added to the result.

Time Complexity:
- **O(n)**: The string is traversed once to reverse the order of words, and each word is reversed once, where `n` is the length of the string.

Space Complexity:
- **O(n)**: The additional space required is proportional to the size of the result string.

*/

class Solution {
  public:
    // Function to reverse words in a given string.
    string reverseWords(string str) {
        int n = str.length();  // Get the length of the input string
        string word = "";      // Temporary string to store individual words
        string ans = "";       // Final result string to store the reversed words

        // Traverse the string from the end to the beginning
        for(int i = n-1; i >= 0; i--) {
            if(str[i] == '.') {    // If a dot is encountered, it means a word has ended
                reverse(word.begin(), word.end());  // Reverse the current word
                ans += word + ".";   // Add the reversed word and dot to the result
                word = "";  // Reset word for the next one
            }
            else {
                word += str[i];  // Append characters to form the current word
            }
        }

        // Handle the last word after the loop (which won't end with a dot)
        reverse(word.begin(), word.end());  // Reverse the last word
        ans += word;  // Add the last word to the result

        return ans;  // Return the final reversed string
    }
};
