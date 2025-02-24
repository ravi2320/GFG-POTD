/*
Stock span problem
Difficulty: MediumAccuracy: 43.56%Submissions: 205K+Points: 4
The stock span problem is a financial problem where we have a series of daily price quotes for a stock and we need to calculate the span of stock price for all days. The span arr[i] of the stocks price on a given day i is defined as the maximum number of consecutive days just before the given day, for which the price of the stock on the given day is less than or equal to its price on the current day.

Examples:

Input: arr[] = [100, 80, 60, 70, 60, 75, 85]
Output: [1, 1, 1, 2, 1, 4, 6]
Explanation: Traversing the given input span 100 is greater than equal to 100 and there are no more elements behind it so the span is 1, 80 is greater than equal to 80 and smaller than 100 so the span is 1, 60 is greater than equal to 60 and smaller than 80 so the span is 1, 70 is greater than equal to 60,70 and smaller than 80 so the span is 2 and so on.  Hence the output will be 1 1 1 2 1 4 6.
Input: arr[] = [10, 4, 5, 90, 120, 80]
Output: [1, 1, 2, 4, 5, 1]
Explanation: Traversing the given input span 10 is greater than equal to 10 and there are no more elements behind it so the span is 1, 4 is greater than equal to 4 and smaller than 10 so the span is 1, 5 is greater than equal to 4,5 and smaller than 10 so the span is 2,  and so on. Hence the output will be 1 1 2 4 5 1.
Input: arr[] = [11, 4, 5, 90, 120, 80]
Output: [1, 1, 2, 4, 5, 1]
Explanation: Traversing the given input span 11 is greater than equal to 11 and there are no more elements behind it so the span is 1, 4 is greater than equal to 4 and smaller than 10 so the span is 1, 5 is greater than equal to 4,5 and smaller than 10 so the span is 2, and so on. Hence the output will be 1 1 2 4 5 1.
Constraints:
1 ≤ arr.size()≤ 105
1 ≤ arr[i] ≤ 105
*/

/**
 * Approach:
 * - We use a **monotonic decreasing stack** to keep track of indices of elements.
 * - If the stack is empty, the span is `i+1` (since there are no previous greater elements).
 * - Otherwise, the span is calculated as `i - st.top()`, where `st.top()` is the last index of a greater element.
 * - We push the **current index** onto the stack after processing.
 *
 * Intuition:
 * - The **span** of a stock price on a given day is the maximum number of consecutive days 
 *   (including the current day) the price has been **less than or equal to today's price**.
 * - The stack **stores indices of previous elements**, allowing efficient O(1) lookup for the nearest greater element.
 *
 * Time Complexity:
 * - **O(N)** → Each element is pushed and popped from the stack **at most once**.
 *
 * Space Complexity:
 * - **O(N)** → Stack stores indices of elements (worst case, strictly decreasing order).
 */

class Solution {
  public:
    vector<int> calculateSpan(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n, 0); // Stores span values for each day
        stack<int> st; // Monotonic decreasing stack (stores indices)

        for (int i = 0; i < n; i++) {
            // Pop elements from the stack while they are smaller than or equal to arr[i]
            while (!st.empty() && arr[st.top()] <= arr[i]) {
                st.pop();
            }

            // If stack is empty, it means all previous elements are smaller → span = i + 1
            // Else, span is the difference between the current index and last greater element index
            ans[i] = st.empty() ? (i + 1) : (i - st.top());

            // Push current index onto stack
            st.push(i);
        }

        return ans;
    }
};