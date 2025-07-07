/*
Next Greater Element in Circular Array
Difficulty: MediumAccuracy: 56.97%Submissions: 42K+Points: 4
Given a circular integer array arr[], the task is to determine the next greater element (NGE) for each element in the array.

The next greater element of an element arr[i] is the first element that is greater than arr[i] when traversing circularly. If no such element exists, return -1 for that position.

Circular Property:

Since the array is circular, after reaching the last element, the search continues from the beginning until we have looked at all elements once.

Examples: 

Input: arr[] = [1, 3, 2, 4]
Output: [3, 4, 4, -1]
Explanation:
The next greater element for 1 is 3.
The next greater element for 3 is 4.
The next greater element for 2 is 4.
The next greater element for 4 does not exist, so return -1.
Input: arr[] = [0, 2, 3, 1, 1]
Output: [2, 3, -1, 2, 2]
Explanation:
The next greater element for 0 is 2.
The next greater element for 2 is 3.
The next greater element for 3 does not exist, so return -1.
The next greater element for 1 is 2 (from circular traversal).
The next greater element for 1 is 2 (from circular traversal).
Constraints:
1 ≤ arr.size() ≤ 105
0 ≤ arr[i] ≤ 106
*/

/*
Approach:
- We traverse the array in reverse (right to left) and use a stack to keep track of potential next greater elements.
- Since we want the "next greater element", for circular behavior we simulate by iterating the array twice (2n times).
- For each element:
   - We remove all smaller or equal elements from the stack (since they can't be the answer).
   - If the stack is not empty, its top is the next greater element.
   - We push the current element to the stack for future comparisons.

Intuition:
- Using a monotonic stack (decreasing) ensures we always have the next greater element at the top.
- Simulating a circular array by looping from `2n-1` to `0` lets us reuse earlier values as possible answers.

Time Complexity:
- O(n), where n is the size of the array.
- Each element is pushed and popped from the stack at most once.

Space Complexity:
- O(n) for the result array and the stack.
*/

class Solution {
  public:
    vector<int> nextLargerElement(vector<int> &arr) {
        int n = arr.size();
        vector<int> ans(n, -1);        // Result array initialized with -1
        stack<int> st;                 // Monotonic decreasing stack
        
        // Loop through the array twice (simulate circular behavior)
        for(int i = 2*n - 1; i >= 0; i--) {
            int idx = i % n;  // Circular index

            // Remove elements from the stack that are smaller or equal
            while(!st.empty() && st.top() <= arr[idx]) {
                st.pop();
            }

            // If stack is not empty, the top is the next greater element
            if(!st.empty()) {
                ans[idx] = st.top();
            }

            // Push current element onto the stack
            st.push(arr[idx]);
        }

        return ans;
    }
};