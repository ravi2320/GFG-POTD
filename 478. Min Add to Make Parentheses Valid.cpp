/*
Min Add to Make Parentheses Valid

Difficulty: MediumAccuracy: 64.41%Submissions: 9K+Points: 4
You are given a string s consisting only of the characters '(' and ')'. Your task is to determine the minimum number of parentheses (either '(' or ')') that must be inserted at any positions to make the string s a valid parentheses string.

A parentheses string is considered valid if:

Every opening parenthesis '(' has a corresponding closing parenthesis ')'.
Every closing parenthesis ')' has a corresponding opening parenthesis '('.
Parentheses are properly nested.
Examples:

Input: s = "(()("
Output: 2
Explanation: There are two unmatched '(' at the end, so we need to add two ')' to make the string valid.
Input: s = ")))"
Output: 3
Explanation: Three '(' need to be added at the start to make the string valid.
Input: s = ")()()"
Output: 1 
Explanation: The very first ')' is unmatched, so we need to add one '(' at the beginning.
Constraints:
1 ≤ s.size() ≤ 105
s[i] ∈ { '(' , ')' }
*/

/*
Approach:
1. Use a counter `cnt` to track the number of unmatched '(' parentheses.
2. Traverse the string:
   - If the character is '(', increment `cnt`.
   - If the character is ')':
       - If there is an unmatched '(', decrement `cnt` (pair it).
       - Otherwise, increment `ans` (we need an extra '(').
3. At the end:
   - `cnt` represents unmatched '(' that need closing ')'.
   - `ans` represents unmatched ')' that need opening '('.
4. Return `ans + cnt`.

Intuition:
- Every unmatched '(' must be closed.
- Every unmatched ')' must be opened.
- By counting them separately, we directly compute the minimum insertions needed.

Time Complexity: O(n)  
- Single pass through the string of length n.

Space Complexity: O(1)  
- Uses only a few integer variables.

*/

class Solution {
  public:
    int minParentheses(string& s) {
        int cnt = 0; // track unmatched '('
        int ans = 0; // track required '(' insertions

        for (char &x : s) {
            if (x == '(') {
                cnt++; // add unmatched '('
            } else {
                if (cnt) {
                    cnt--; // match with previous '('
                } else {
                    ans++; // no '(' to match, need an extra one
                }
            }
        }
        
        // ans = required '(' insertions
        // cnt = required ')' insertions
        return ans + cnt;
    }
};

