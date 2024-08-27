/*
Maximum Difference
Difficulty: MediumAccuracy: 33.3%Submissions: 61K+Points: 4
Given an integer array arr of integers, the task is to find the maximum absolute difference between the nearest left smaller element and the nearest right smaller element of every element in array arr. If for any component of the arr, the nearest smaller element doesn't exist then consider it as 0.

Examples :

Input: arr = [2, 1, 8]
Output: 1
Explanation: left smaller array ls = [0, 0, 1], right smaller array rs = [1, 0, 0]. Maximum Diff of abs(ls[i] - rs[i]) = 1
Input: arr = [2, 4, 8, 7, 7, 9, 3]
Output: 4
Explanation: left smaller array ls = [0, 2, 4, 4, 4, 7, 2], right smaller rs = [0, 3, 7, 3, 3, 3, 0]. Maximum Diff of abs(ls[i] - rs[i]) = abs(7 - 3) = 4
Expected Time Complexity: O(n)
Expected Space Complexity: O(n)

Constraints:
1 <= arr.size() <= 106
1<= arr[i] <=109
*/

/*
Intuition:
The problem asks to find the maximum absolute difference between the nearest smaller elements on the left and the right for each element in an array. This can be efficiently done using a stack to maintain the nearest smaller elements as we traverse the array from left to right and from right to left.

Approach:
1. **Find Nearest Smaller to Left (NSL)**:
   - Traverse the array from left to right.
   - Use a stack to keep track of elements, ensuring that the top of the stack is the nearest smaller element.
   - For each element in the array, pop elements from the stack until you find a smaller element or the stack is empty. If the stack is empty, use a sentinel value (e.g., `0`).

2. **Find Nearest Smaller to Right (NSR)**:
   - Similar to NSL, but traverse the array from right to left.
   - Use the same technique with a stack to find the nearest smaller element on the right.

3. **Calculate Maximum Difference**:
   - After filling the `left` and `right` arrays with nearest smaller elements, compute the absolute difference for each element and track the maximum difference.

Time Complexity:
- The time complexity is `O(n)` where `n` is the number of elements in the array. Each element is pushed and popped from the stack at most once.

Space Complexity:
- The space complexity is `O(n)` due to the additional arrays for storing nearest smaller elements and the stack.

*/

class Solution {
  public:
    /* You are required to complete this method */
    int findMaxDiff(vector<int> &arr) {
        int n = arr.size();
        vector<int> left(n), right(n);
        stack<int> st;

        // Sentinel value, assuming array contains only positive integers.
        st.push(0);

        // Finding nearest smaller to the left (NSL)
        for(int i = 0; i < n; i++) {
            while(st.top() >= arr[i]) {
                st.pop();
            }
            left[i] = st.top();
            st.push(arr[i]);
        }

        // Clear the stack for re-use
        while(!st.empty()) st.pop();

        // Sentinel value, assuming array contains only positive integers.
        st.push(0);

        // Finding nearest smaller to the right (NSR)
        for(int i = n - 1; i >= 0; i--) {
            while(st.top() >= arr[i]) {
                st.pop();
            }
            right[i] = st.top();
            st.push(arr[i]);
        }

        // Calculate the maximum absolute difference
        int maxDiff = 0;
        for(int i = 0; i < n; i++) {
            maxDiff = max(maxDiff, abs(left[i] - right[i]));
        }

        return maxDiff;
    }
};
