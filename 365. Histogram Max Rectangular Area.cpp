/*
Histogram Max Rectangular Area
Difficulty: HardAccuracy: 32.12%Submissions: 181K+Points: 8
You are given a histogram represented by an array arr, where each element of the array denotes the height of the bars in the histogram. All bars have the same width of 1 unit.

Your task is to find the largest rectangular area possible in the given histogram, where the rectangle can be formed using a number of contiguous bars.

Examples:

Input: arr[] = [60, 20, 50, 40, 10, 50, 60]
 Largest-Rectangular-Area-in-a-Histogram
Output: 100
Explanation: We get the maximum by picking bars highlighted above in green (50, and 60). The area is computed (smallest height) * (no. of the picked bars) = 50 * 2 = 100.
Input: arr[] = [3, 5, 1, 7, 5, 9]
Output: 15
Explanation:  We get the maximum by picking bars 7, 5 and 9. The area is computed (smallest height) * (no. of the picked bars) = 5 * 3 = 15.
Input: arr[] = [3]
Output: 3
Explanation: In this example the largest area would be 3 of height 3 and width 1.
Constraints:
1 ≤ arr.size() ≤ 105
0 ≤ arr[i] ≤ 104
*/

/**
 * Approach:
 * - Use a **monotonic stack** to track **indices of increasing height bars**.
 * - Whenever we encounter a **smaller height**, we pop from the stack and calculate 
 *   the **area of the rectangle** using the popped bar as the smallest height.
 * - The width of the rectangle is determined by:
 *   - **Previous Smaller Element (PSE)** → index before the popped element.
 *   - **Next Smaller Element (NSE)** → index where we find a smaller element.
 * - The stack helps maintain increasing order, ensuring efficient calculations.
 * 
 * Intuition:
 * - The **width** of the rectangle for a given height extends from **PSE + 1 to NSE - 1**.
 * - By popping from the stack when encountering a smaller element, we ensure that each 
 *   bar is used as the **smallest height** in its valid range.
 *
 * Time Complexity:
 * - **O(N)** → Each element is pushed and popped from the stack at most once.
 * 
 * Space Complexity:
 * - **O(N)** → Stack stores indices.
 */

class Solution {
public:
    int getMaxArea(vector<int> &arr) {
        stack<int> st;  // Monotonic stack to store indices
        int n = arr.size();
        int maxArea = 0;

        // Traverse the histogram bars
        for (int i = 0; i < n; i++) {
            // Process stack until the current bar is greater than or equal to the top
            while (!st.empty() && arr[st.top()] > arr[i]) {
                int height = arr[st.top()];
                st.pop();

                int rightBoundary = i; // Next smaller element (NSE)
                int leftBoundary = st.empty() ? -1 : st.top(); // Previous smaller element (PSE)

                // Width of the rectangle = NSE - PSE - 1
                maxArea = max(maxArea, height * (rightBoundary - leftBoundary - 1));
            }
            
            st.push(i); // Push current index onto the stack
        }

        // Process remaining elements in stack
        while (!st.empty()) {
            int height = arr[st.top()];
            st.pop();
            
            int rightBoundary = n; // NSE is the end of the array
            int leftBoundary = st.empty() ? -1 : st.top(); // PSE
            
            maxArea = max(maxArea, height * (rightBoundary - leftBoundary - 1));
        }

        return maxArea;
    }
};
