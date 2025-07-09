/*
Sum of subarray minimum
Difficulty: MediumAccuracy: 46.92%Submissions: 15K+Points: 4Average Time: 30m
Given an array arr[] of positive integers, find the total sum of the minimum elements of every possible subarrays.

Note: It is guaranteed that the total sum will fit within a 32-bit unsigned integer.

Examples:

Input: arr[] = [3, 1, 2, 4]
Output: 17
Explanation: Subarrays are [3], [1], [2], [4], [3, 1], [1, 2], [2, 4], [3, 1, 2], [1, 2, 4], [3, 1, 2, 4]. Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1. Sum of all these is 17.
Input: arr[] = [71, 55, 82, 55]
Output: 593
Explanation: The sum of the minimum of all the subarrays is 593.
Constraints:
1 ≤ arr.size() ≤ 3*104
1 ≤ arr[i] ≤ 103
*/

/*
Approach:
- We want to find the sum of the minimum values across all possible subarrays.
- For each element `arr[i]`, determine:
  - How many subarrays it is the **minimum** in.
  - This is done by identifying:
    - PSE (Previous Smaller Element): first smaller element to the left
    - NSE (Next Smaller Element): first smaller element to the right
- If `arr[i]` is the minimum in all subarrays from (pse[i]+1) to (nse[i]-1),
  then it contributes `(i - pse[i]) * (nse[i] - i) * arr[i]` to the total sum.

Intuition:
- Each element is the minimum of multiple subarrays.
- Rather than generating subarrays explicitly (which is O(n²)), we calculate its impact using span on both sides.

Time Complexity: O(n)
- Each element is pushed/popped at most once from the stack (amortized O(n)).

Space Complexity: O(n)
- For storing PSE, NSE, and stack.
*/

class Solution {
  public:
    // Find indices of Next Smaller Element (NSE) for each element
    vector<int> findNSE(vector<int> &arr){
        int n = arr.size();
        vector<int> nse(n, n);  // default to n (no NSE found)
        stack<int> st;

        for(int i = n - 1; i >= 0; i--){
            while(!st.empty() && arr[st.top()] > arr[i]){
                st.pop();
            }
            if(!st.empty())
                nse[i] = st.top();
            st.push(i);
        }

        return nse;
    }

    // Find indices of Previous Smaller Element (PSE) for each element
    vector<int> findPSE(vector<int> &arr){
        int n = arr.size();
        vector<int> pse(n, -1);  // default to -1 (no PSE found)
        stack<int> st;

        for(int i = 0; i < n; i++){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            if(!st.empty())
                pse[i] = st.top();
            st.push(i);
        }

        return pse;
    }

    int sumSubMins(vector<int> &arr) {
        int n = arr.size();
        vector<int> nse = findNSE(arr);  // Next Smaller Element index
        vector<int> pse = findPSE(arr);  // Previous Smaller Element index

        long long sum = 0;
        int mod = 1e9 + 7;

        for(int i = 0; i < n; i++){
            long long left = i - pse[i];
            long long right = nse[i] - i;
            sum = (sum + (arr[i] * left % mod) * right % mod) % mod;
        }

        return (int)sum;
    }
};
