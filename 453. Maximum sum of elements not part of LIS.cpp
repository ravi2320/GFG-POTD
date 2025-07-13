/*
Maximum sum of elements not part of LIS
Difficulty: MediumAccuracy: 48.67%Submissions: 14K+Points: 4
Given an array arr[] of positive integers, your task is to find the maximum possible sum of all elements that are not part of the Longest Increasing Subsequence (LIS).

Examples:

Input: arr[] = [4, 6, 1, 2, 3, 8]
Output: 10
Explanation: The elements which are not in LIS is 4 and 6.
Input: arr[] = [5, 4, 3, 2, 1]
Output: 14
Explanation: The elements which are not in LIS is 5, 4, 3 and 2.
Constraints:
1 ≤ arr.size() ≤ 103
1 ≤ arr[i] ≤ 105
*/

/*
Approach:
- We want to remove the Longest Increasing Subsequence (LIS) with the **minimum sum** from the array,
  so the sum of the remaining elements is **maximized**.
- Use dynamic programming to:
  - Compute the length of LIS ending at each index.
  - Track the sum of the LIS ending at each index.
- Find the LIS with maximum length and minimum sum.
- Subtract that minimum sum from the total array sum.

Intuition:
- There may be multiple LIS of the same length.
- Removing the one with the smallest sum keeps the rest of the array's sum as large as possible.

Time Complexity: O(n²), due to nested loops for LIS DP
Space Complexity: O(n), for `len` and `sum` arrays
*/

class Solution {
  public:
    int nonLisMaxSum(vector<int>& arr) {
        int n = arr.size();

        // Total sum of the array
        int total = accumulate(arr.begin(), arr.end(), 0);

        // len[i] = length of LIS ending at index i
        // sum[i] = sum of LIS ending at index i
        vector<int> len(n, 1), sum(n);
        int maxLen = 1;
        int LisMinSum = INT_MAX;

        for(int i = 0; i < n; i++) {
            sum[i] = arr[i]; // Base case: LIS ending at i is just arr[i]
            
            for(int j = 0; j < i; j++) {
                // If arr[i] extends the increasing subsequence
                if(arr[j] < arr[i]) {
                    if(len[j] + 1 > len[i]) {
                        len[i] = len[j] + 1;
                        sum[i] = sum[j] + arr[i];
                    }
                    else if(len[j] + 1 == len[i]) {
                        sum[i] = min(sum[i], sum[j] + arr[i]);
                    }
                }
            }

            maxLen = max(maxLen, len[i]);
        }

        // Find the minimum LIS sum for the maximum length
        for(int i = 0; i < n; i++) {
            if(len[i] == maxLen) {
                LisMinSum = min(LisMinSum, sum[i]);
            }
        }

        // Remaining max sum after removing LIS with min sum
        return total - LisMinSum;
    }
};