/*
Print Bracket Number
Difficulty: EasyAccuracy: 51.19%Submissions: 42K+Points: 2
Given a string str, the task is to find the bracket numbers, i.e., for each bracket in str, return i if the bracket is the ith opening or closing bracket to appear in the string. 

 Examples:

Input:  str = "(aa(bdc))p(dee)"
Output: 1 2 2 1 3 3
Explanation: The highlighted brackets in
the given string (aa(bdc))p(dee) are
assigned the numbers as: 1 2 2 1 3 3.
Input:  str = "(((()("
Output: 1 2 3 4 4 5
Explanation: The highlighted brackets in
the given string (((()( are assigned
the numbers as: 1 2 3 4 4 5
Expected Time Complexity: O(|str|)
Expected Auxiliary Space: O(|str|)

Constraints:
1 <= |str| <= 105
str contains lowercase English alphabets, and '(', ')' characters
At any index, the number of opening brackets is greater than or equal to closing brackets
*/

/*
Intuition:
- Use a counter to assign numbers to opening brackets '('.
- Use a stack to keep track of the position of these opening brackets.
- When encountering a closing bracket ')', retrieve the corresponding number from the stack.

Time Complexity:
- O(n): We traverse the string once, making the complexity linear.

Space Complexity:
- O(n): In the worst case, the stack will store all the opening brackets in the string.

*/

class Solution {
public:
    vector<int> bracketNumbers(string str) {
        int cnt = 0;
        vector<int> ans;
        stack<int> st;

        for (char ch : str) {
            if (ch == '(') {
                cnt++;
                st.push(cnt);
                ans.push_back(cnt);
            } else if (ch == ')') {
                if (!st.empty()) {
                    ans.push_back(st.top());
                    st.pop();
                }
            }
        }

        return ans;
    }
};
