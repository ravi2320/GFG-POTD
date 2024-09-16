/*
Longest valid Parentheses
Difficulty: HardAccuracy: 26.13%Submissions: 108K+Points: 8
Given a string str consisting of opening and closing parenthesis '(' and ')'. Find length of the longest valid parenthesis substring.

A parenthesis string is valid if:

For every opening parenthesis, there is a closing parenthesis.
Opening parenthesis must be closed in the correct order.
Examples :

Input: str = ((()
Output: 2
Explaination: The longest valid parenthesis substring is "()".
Input: str = )()())
Output: 4
Explaination: The longest valid parenthesis substring is "()()".
Expected Time Complexity: O(|str|)
Expected Auxiliary Space: O(|str|)

Constraints:
1 ≤ |str| ≤ 105  
*/

/*
Approach:
1. We will traverse the string twice:
   - First from left to right, counting the number of open '(' and close ')' parentheses.
   - If at any point, the count of close parentheses exceeds the open parentheses, we reset both counts to 0 because the substring is invalid from that point.
   - Whenever the count of open and close parentheses is equal, we calculate the length of the valid substring and update the maximum length.
2. The second traversal is done from right to left to handle cases where an invalid substring starts with excess open parentheses.
3. This ensures that we count valid substrings even if they appear after an excess of opening parentheses at the start.

Time Complexity:
- O(n): We traverse the string twice, both in left-to-right and right-to-left directions.

Space Complexity:
- O(1): We only use a few integer variables to keep track of the counts and maximum length.

*/

class Solution {
  public:
    int maxLength(string& str) {
        int mx = 0, open = 0, close = 0;
        int n = str.size();

        // First pass: left to right
        for (char &x : str) {
            if (x == '(')
                open++;
            else
                close++;

            // Reset counts if more close brackets
            if (close > open)
                open = close = 0;

            // Update max length when open == close
            if (open == close)
                mx = max(mx, 2 * open);
        }

        // Second pass: right to left
        open = close = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (str[i] == ')')
                close++;
            else
                open++;

            // Reset counts if more open brackets
            if (open > close)
                open = close = 0;

            // Update max length when open == close
            if (open == close)
                mx = max(mx, 2 * open);
        }

        return mx;
    }
};
