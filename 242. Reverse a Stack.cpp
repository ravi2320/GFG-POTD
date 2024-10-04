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
Approach:
1. **pushAtBottom**:
   - This function pushes an element `num` at the bottom of the stack. It recursively pops elements until the stack is empty, then pushes the element `num`, and finally pushes all the popped elements back onto the stack in the correct order.

2. **Reverse**:
   - This function reverses a stack using recursion. It pops the top element, calls itself recursively to reverse the rest of the stack, and then uses the `pushAtBottom` function to put the popped element at the bottom of the reversed stack.

Time Complexity:
- **pushAtBottom**: O(N), where N is the number of elements in the stack, since we pop and push all elements once.
- **Reverse**: O(N^2), because for each element, we recursively call `pushAtBottom`, which takes O(N) in the worst case.

Space Complexity:
- O(N) due to the recursion stack, as each function call is added to the call stack until the base case is reached.

*/

class Solution{
public:
    // Function to push an element to the bottom of the stack
    void pushAtBottom(stack<int> &st, int num){
        // If stack is empty, push the number
        if(st.empty()){
            st.push(num);
            return;
        }
        
        int top = st.top();  // Store the current top element
        st.pop();  // Pop the top element
        
        // Recursive call to push the number at the bottom
        pushAtBottom(st, num);
        
        // After pushing num at the bottom, push the top element back
        st.push(top);
    }

    // Function to reverse a stack
    void Reverse(stack<int> &St){
        // Base case: if the stack is empty, return
        if(St.empty()){
            return;  
        } 
        
        int top = St.top();  // Store the current top element
        St.pop();  // Pop the top element
        
        // Recursive call to reverse the rest of the stack
        Reverse(St);
        
        // After reversing the remaining stack, push the top element at the bottom
        pushAtBottom(St, top);
    }
};
