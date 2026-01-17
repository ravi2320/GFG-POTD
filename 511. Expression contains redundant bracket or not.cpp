/*
Expression contains redundant bracket or not
Difficulty: MediumAccuracy: 48.71%Submissions: 41K+Points: 4
Given a string of balanced expression s, check if it contains a redundant parenthesis or not. A set of parenthesis are redundant if the same sub-expression is surrounded by unnecessary or multiple brackets.
Note: Expression may contain + , - , *, and / operators. Given expression is valid and there are no white spaces present.

Examples:

Input: s = "((a+b))"
Output: true 
Explanation: ((a+b)) can reduced to (a+b).
Input: s = "(a+(b)/c)"
Output: true
Explanation: (a+(b)/c) can reduced to (a+b/c) because b is surrounded by () which is redundant.
Input: s = "(a+b+(c+d))"
Output: false
Explanation:(a+b+(c+d)) doesn't have any redundant or multiple brackets.
Constraints:
1 ≤ |s| ≤105
*/

/*
Approach:
---------
1. Traverse the expression character by character.
2. Use a stack where each opening bracket '(' stores:
      - the bracket itself
      - a flag indicating whether an operator exists inside it
3. When '(' is encountered, push it with operator-flag = 0.
4. When an operator is encountered, mark the top stack element's flag as 1.
5. When ')' is encountered:
      - If no operator was found inside the matching '(',
        then the brackets are redundant → return true.
      - Otherwise, pop the stack.
6. If traversal ends without finding redundant brackets, return false.

Intuition:
----------
Redundant brackets are those which do not enclose any operator,
such as:
    ((a)), (a), (b)
Valid brackets must contain at least one operator inside.
By tracking whether an operator exists between '(' and ')',
we can detect redundancy efficiently.

Time Complexity:
----------------
O(N)
- Single traversal of the expression

Space Complexity:
-----------------
O(N)
- Stack usage in worst case for nested brackets
*/

class Solution {
public:
    // Helper function to check if a character is an operator
    bool isOperator(char &ch) {
        return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
    }

    bool checkRedundancy(string &s) {
        stack<pair<char, int>> st;
        // pair<char, int> → ('(', operator_present_flag)

        for (char &ch : s) {

            // Opening bracket: push with operator flag = 0
            if (ch == '(') {
                st.push({'(', 0});
            }

            // Operator: mark presence inside current brackets
            else if (isOperator(ch)) {
                if (!st.empty())
                    st.top().second = 1;
            }

            // Closing bracket
            else if (ch == ')') {
                if (st.empty())
                    return false;

                // No operator inside → redundant
                if (st.top().second == 0)
                    return true;

                // Valid bracket, pop it
                st.pop();
            }
        }

        return false;
    }
};
