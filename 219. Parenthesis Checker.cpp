/*
Parenthesis Checker
Difficulty: EasyAccuracy: 28.56%Submissions: 589K+Points: 2
Given an expression string x. Examine whether the pairs and the orders of {,},(,),[,] are correct in exp.
For example, the function should return 'true' for exp = [()]{}{[()()]()} and 'false' for exp = [(]).

Note: The driver code prints "balanced" if function return true, otherwise it prints "not balanced".

Examples :

Input: {([])}
Output: true
Explanation: { ( [ ] ) }. Same colored brackets can form balanced pairs, with 0 number of unbalanced bracket.
Input: ()
Output: true
Explanation: (). Same bracket can form balanced pairs,and here only 1 type of bracket is present and in balanced way.
Input: ([]
Output: false
Explanation: ([]. Here square bracket is balanced but the small bracket is not balanced and Hence , the output will be unbalanced.
Expected Time Complexity: O(|x|)
Expected Auixilliary Space: O(|x|)

Constraints:
1 ≤ |x| ≤ 105

*/

/*
Approach:
1. We use a stack to keep track of opening brackets.
2. As we traverse the string, we push opening brackets ('(', '{', '[') onto the stack.
3. For closing brackets (')', '}', ']'), we check if the stack is non-empty and the top of the stack has the matching opening bracket.
   - If it matches, we pop the stack.
   - If it does not match or the stack is empty, the string is unbalanced.
4. After processing all characters, if the stack is empty, it means all opening brackets have matching closing brackets, and the string is balanced.
5. If the stack is not empty, it indicates there are unmatched opening brackets, making the string unbalanced.

Time Complexity:
- O(n): The time complexity is linear, where `n` is the length of the string. Each character is processed once.

Space Complexity:
- O(n): The space complexity is also linear due to the use of the stack, which may hold up to `n` opening brackets in the worst case.

*/

class Solution
{
public:
    // Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        stack<char> st; // Stack to keep track of opening brackets
        
        for(char ch : x) {
            // Push opening brackets onto the stack
            if(ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
            }
            // Check for matching closing brackets
            else if(ch == ')' && !st.empty() && st.top() == '(') {
                st.pop(); // Pop the matching opening bracket
            }
            else if(ch == ']' && !st.empty() && st.top() == '[') {
                st.pop(); // Pop the matching opening bracket
            }
            else if(ch == '}' && !st.empty() && st.top() == '{') {
                st.pop(); // Pop the matching opening bracket
            }
            else {
                return false; // If no match or stack is empty when it should not be
            }
        }
        
        // If stack is empty, all brackets were matched; otherwise, they were not
        return st.empty();
    }
};
