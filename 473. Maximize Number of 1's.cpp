/*
Maximize Number of 1's
Difficulty: MediumAccuracy: 39.46%Submissions: 66K+Points: 4Average Time: 20m
Given a binary array arr[] containing only 0s and 1s and an integer k, you are allowed to flip at most k 0s to 1s. Find the maximum number of consecutive 1's that can be obtained in the array after performing the operation at most k times.

Examples:

Input: arr[] = [1, 0, 1], k = 1
Output: 3
Explanation: By flipping the zero at index 1, we get the longest subarray from index 0 to 2 containing all 1’s.
Input: arr[] = [1, 0, 0, 1, 0, 1, 0, 1], k = 2
Output: 5
Explanation: By flipping the zeroes at indices 4 and 6, we get the longest subarray from index 3 to 7 containing all 1’s.
Input: arr[] = [1, 1], k = 2
Output: 2
Explanation: Since the array is already having the max consecutive 1's, hence we dont need to perform any operation. Hence the answer is 2.
Constraints:
1 ≤ arr.size() ≤ 105
0 ≤ k ≤ arr.size()
0 ≤ arr[i] ≤ 1
*/

/*
Approach:
----------
We use the **sliding window (two pointers)** technique to find the longest subarray 
that can contain at most `k` zeros (which we can flip into ones).
- Maintain two pointers `i` and `j` representing the current window.
- Track the number of zeros in the window (`zeroCnt`).
- Expand the right pointer `j` and include elements.
- If zeros exceed `k`, shrink the window by moving `i` until `zeroCnt <= k`.
- At each step, update the maximum window size.

Intuition:
----------
To maximize consecutive 1s after at most `k` flips, we need the largest 
window containing at most `k` zeros. By sliding the window and 
keeping zero count under control, we ensure the result is optimal.

Time Complexity:
----------------
O(n) → Each element is processed at most twice (once by `j`, once by `i`).

Space Complexity:
-----------------
O(1) → Only a few extra variables are used.
*/

class Solution {
  public:
    int maxOnes(vector<int>& arr, int k) {
        int n = arr.size();
        int zeroCnt = 0;  // Count of zeros in the current window
        int ans = 0;      // Stores maximum consecutive 1s (after flips)
        int i = 0;        // Left pointer of sliding window
        
        // Traverse with right pointer `j`
        for (int j = 0; j < n; j++) {
            
            // If current element is 0, increase zero count
            if (arr[j] == 0) {
                zeroCnt++;
            }
            
            // If window has more than k zeros, shrink from left
            while (zeroCnt > k) {
                if (arr[i] == 0) {
                    zeroCnt--;  // Remove a zero from count
                }
                i++;  // Move left pointer
            }
            
            // Update the maximum window size
            ans = max(ans, j - i + 1);
        }
        
        return ans;
    }
};
