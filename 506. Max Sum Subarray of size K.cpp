/*
Max Sum Subarray of size K

avatar
Discuss Approach
arrow-up
Difficulty: EasyAccuracy: 49.6%Submissions: 236K+Points: 2
Given an array of integers arr[]  and a number k. Return the maximum sum of a subarray of size k.

Note: A subarray is a contiguous part of any given array.

Examples:

Input: arr[] = [100, 200, 300, 400], k = 2
Output: 700
Explanation: arr2 + arr3 = 700, which is maximum.
Input: arr[] = [1, 4, 2, 10, 23, 3, 1, 0, 20], k = 4
Output: 39
Explanation: arr1 + arr2 + arr3 + arr4 = 39, which is maximum.
Input: arr[] = [100, 200, 300, 400], k = 1
Output: 400
Explanation: arr3 = 400, which is maximum.
Constraints:
1 ≤ arr.size() ≤ 106
1 ≤ arr[i] ≤ 106
1 ≤ k ≤ arr.size()
*/

/*
Approach:
---------
We are given an array `arr` and an integer `k`.
We need to find the maximum sum of any subarray
having **size at most k**.

Key Idea:
---------
Use a sliding window technique.

Steps:
------
1. Maintain a running sum of the current window.
2. Expand the window by adding arr[i].
3. If window size exceeds k, shrink it from the left
   by subtracting arr[i - k].
4. At each step, update the maximum sum.

Intuition:
----------
A sliding window avoids recomputing sums for each subarray.
By keeping the window size limited to k, we efficiently
track the best possible subarray sum.

Time Complexity:
----------------
O(n) — Single pass through the array.

Space Complexity:
-----------------
O(1) — Constant extra space.

*/

class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        int n = arr.size();
        int sum = 0;
        int ans = 0;
        
        // Sliding window
        for (int i = 0; i < n; i++) {
            
            // Remove element leaving the window
            if (i >= k) {
                sum -= arr[i - k];
            }
            
            // Add current element
            sum += arr[i];
            
            // Update maximum sum
            ans = max(ans, sum);
        }
        
        return ans;
    }
};
