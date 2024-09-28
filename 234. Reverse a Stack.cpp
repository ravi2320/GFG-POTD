/*
Reverse a Stack
Difficulty: MediumAccuracy: 80.5%Submissions: 86K+Points: 4
You are given a stack St. You have to reverse the stack using recursion.

Example 1:

Input:
St = {3,2,1,7,6}
Output:
{6,7,1,2,3}
Explanation:
Input stack after reversing will look like the stack in the output.
Example 2:

Input:
St = {4,3,9,6}
Output:
{6,9,3,4}
Explanation:
Input stack after reversing will look like the stack in the output.
Your Task:

You don't need to read input or print anything. Your task is to complete the function Reverse() which takes the stack St as input and reverses the given stack.

Expected Time Complexity: O(N2)
Expected Auxiliary Space: O(1)

Constraints:
1 <= size of the stack <= 104
-109 <= Each element of the stack <= 109
Sum of N over all test cases doesn't exceeds 106
Array may contain duplicate elements. 


*/

/*
 * Approach:
 * - The goal is to reverse a stack using recursion.
 * - We define two functions: 
 *   1. `Reverse`: This function reverses the entire stack.
 *   2. `insertAtBottom`: This helper function inserts an element at the bottom of the stack.
 * - The `Reverse` function removes the top element, recursively calls itself to reverse the rest of the stack, and then uses `insertAtBottom` to place the removed element at the bottom.
 * - The `insertAtBottom` function handles inserting elements recursively by popping elements off the stack until it is empty, then placing the new element, and finally pushing the popped elements back onto the stack.
 * 
 * Time Complexity:
 * - O(n^2): Each call to `insertAtBottom` processes all elements of the stack, leading to n calls each taking O(n) time.
 * 
 * Space Complexity:
 * - O(n): The maximum space used by the call stack in recursive calls.
 */

class Solution {
public:
    // Function to insert an element at the bottom of the stack
    void insertAtBottom(stack<int> &st, int element) {
        // Base case: If stack is empty, push the element
        if (st.empty()) {
            st.push(element);
            return;
        }
        
        // Store the top element and pop it
        int top = st.top();
        st.pop();
        
        // Recursive call to insert the element at the bottom
        insertAtBottom(st, element);
        
        // Push the top element back onto the stack
        st.push(top);
    }

    // Function to reverse the stack
    void Reverse(stack<int> &st) {
        // Base case: If the stack is empty, return
        if (st.empty()) {
            return;
        }
        
        // Store the top element and pop it
        int top = st.top();
        st.pop();
        
        // Recursive call to reverse the remaining stack
        Reverse(st);
        
        // Insert the popped element at the bottom of the stack
        insertAtBottom(st, top);
    }
};
