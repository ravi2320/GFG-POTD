/*
Sum of Subarrays
Difficulty: MediumAccuracy: 23.85%Submissions: 35K+Points: 4
Given an array arr[], find the sum of all the subarrays of the given array.

Note: It is guaranteed that the total sum will fit within a 32-bit integer range.

Examples:

Input: arr[] = [1, 2, 3] 
Output: 20
Explanation: All subarray sums are: [1] = 1, [2] = 2, [3] = 3, [1, 2] = 3, [2, 3] = 5, [1, 2, 3] = 6. Thus total sum is 1 + 2 + 3 + 3 + 5 + 6 = 20.
Input: arr[] = [1, 3]
Output: 8
Explanation: All subarray sums are: [1] = 1, [3] = 3, [1, 3] = 4. Thus total sum is 1 + 3 + 4 = 8.
Constraints :
1 ≤ arr.size() ≤ 105
0 ≤ arr[i] ≤ 104
*/

// ✅ Approach:
// We are calculating the sum of all possible subarrays of the given array `arr`.
// For each element arr[i], it appears in (i+1) * (n-i) subarrays:
// - (i+1) choices for the starting index (0 to i)
// - (n-i) choices for the ending index (i to n-1)
// So its total contribution to the final sum is arr[i] * (i+1) * (n-i).
// We add this contribution for every element.

// ✅ Intuition:
// Instead of generating all subarrays (which is O(n^2)), we calculate how many times
// each element contributes to all subarrays and multiply it with its contribution count.

// ✅ Time Complexity: O(n), where n is the size of the array.
// ✅ Space Complexity: O(1), no extra space used (only variables).

class Solution {
  public:
    int subarraySum(vector<int>& arr) {
        int n = arr.size();  // Get array size
        int ans = 0;         // Variable to store final result

        for (int i = 0; i < n; i++) {
            // Contribution of arr[i] in all subarrays it appears in
            ans += arr[i] * (i + 1) * (n - i);
        }

        return ans;  // Return the sum of all subarrays
    }
};
