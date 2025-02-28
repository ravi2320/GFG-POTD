/*
Evaluation of Postfix Expression
Difficulty: MediumAccuracy: 63.04%Submissions: 98K+Points: 4
You are given an array of strings arr that represents a valid arithmetic expression written in Reverse Polish Notation (Postfix Notation). Your task is to evaluate the expression and return an integer representing its value.

Key Details:

The valid operators are '+', '-', '*', and '/'.
Each operand is guaranteed to be a valid integer or another expression.
The division operation between two integers always rounds the result towards zero, discarding any fractional part.
No division by zero will occur in the input.
The input is a valid arithmetic expression in Reverse Polish Notation.
The result of the expression and all intermediate calculations will fit in a 32-bit signed integer.
Examples:

Input: arr = ["2", "3", "1", "*", "+", "9", "-"]
Output: -4
Explanation: If the expression is converted into an infix expression, it will be 2 + (3 * 1) – 9 = 5 – 9 = -4.
Input: arr = ["100", "200", "+", "2", "/", "5", "*", "7", "+"]
Output: 757
Explanation: If the expression is converted into an infix expression, it will be ((100 + 200) / 2) * 5 + 7  = 150 * 5 + 7 = 757.
Constraints:

1 <= arr.size() <= 105
arr[i] is either an operator: "+", "-", "*", or "/", or an integer in the range [-104, 104]
*/

/**
 * Approach:
 * - Use a **stack** to store numbers.
 * - Iterate through the array:
 *   - If the element is an **operator (`+`, `-`, `*`, `/`)**, pop the last two numbers from the stack,
 *     apply the operation, and push the result back.
 *   - If the element is a **number**, push it onto the stack.
 * - The final result is the top element of the stack.
 *
 * 🔹 **Time Complexity**: O(N) → One pass over input.
 * 🔹 **Space Complexity**: O(N) → Stack stores numbers.
 */

class Solution {
public:
    int evaluate(vector<string>& arr) {
        stack<int> st;

        for (string &str : arr) {
            // Check if the token is an operator
            if (str == "+" || str == "-" || str == "*" || str == "/") {
                int n2 = st.top();  // Second operand
                st.pop();
                int n1 = st.top();  // First operand
                st.pop();

                // Perform operation and push result back
                if (str == "+") st.push(n1 + n2);
                else if (str == "-") st.push(n1 - n2);
                else if (str == "*") st.push(n1 * n2);
                else st.push(n1 / n2);  // Division
            } 
            else {
                st.push(stoi(str));  // Convert number string to integer
            }
        }

        return st.top();  // Final result is on top of the stack
    }
};