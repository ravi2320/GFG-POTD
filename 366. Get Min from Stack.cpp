/*
Get Min from Stack
Difficulty: MediumAccuracy: 22.59%Submissions: 268K+Points: 4Average Time: 30m
Given q queries, You task is to implement the following four functions for a stack:

push(x) – Insert an integer x onto the stack.
pop() – Remove the top element from the stack.
peek() - Return the top element from the stack. If the stack is empty, return -1.
getMin() – Retrieve the minimum element from the stack in O(1) time. If the stack is empty, return -1.
Each query can be one of the following:

1 x : Push x onto the stack.
2 : Pop the top element from the stack.
3: Return the top element from the stack. If the stack is empty, return -1.
4: Return the minimum element from the stack.
Examples:

Input: q = 7, queries = [[1, 2], [1, 3], [3], [2], [4], [1, 1], [4]]
Output: [3, 2, 1]
Explanation: 
push(2): Stack is [2]
push(3): Stack is [2, 3]
peek(): Top element is 3
pop(): Removes 3, stack is [2]
getMin(): Minimum element is 2
push(1): Stack is [2, 1]
getMin(): Minimum element is 1
Input: q = 4, queries = [[1, 4], [1, 2], [4], [3]]
Output: [2, 2]
Explanation: 
push(4): Stack is [4]
push(2): Stack is [4, 2]
getMin(): Minimum element is 2
peek(): Top element is 2
Input: q = 5, queries = [[1, 10], [4], [1, 5], [4], [2]]
Output: [10, 5]
Explanation: 
push(10): Stack is [10]
getMin(): Minimum element is 10
push(5): Stack is [10, 5]
getMin(): Minimum element is 5
pop(): Removes 5, stack is [10]
Constraints:
1 <= q <= 105
0 <= values on the stack <= 109
*/

/**
 * Approach:
 * - We maintain a **stack of pairs**, where:
 *   - **First element** of pair = Actual stack value
 *   - **Second element** of pair = Minimum value in stack up to this point
 * - This allows `getMin()` to retrieve the minimum element **in O(1) time**.
 *
 * 🔹 **Time Complexity**: O(1) for push, pop, peek, and getMin.
 * 🔹 **Space Complexity**: O(N) for storing elements.
 */

class Solution {
    stack<pair<int, int>> st;  // Stack stores {element, min_so_far}
  
public:
    Solution() {
        // Constructor initializes an empty stack
    }

    // Push element onto stack
    void push(int x) {
        if (st.empty()) {
            st.push({x, x});  // First element is always the min
        } else {
            int mini = min(x, st.top().second);
            st.push({x, mini});
        }
    }

    // Remove top element from stack
    void pop() {
        if (!st.empty()) {
            st.pop();
        }
    }

    // Return top element of stack
    int peek() {
        if (st.empty()) return -1;
        return st.top().first;
    }

    // Return minimum element in stack
    int getMin() {
        if (st.empty()) return -1;
        return st.top().second;
    }
};
