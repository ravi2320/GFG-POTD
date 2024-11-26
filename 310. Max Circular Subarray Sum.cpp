/*
Max Circular Subarray Sum
Difficulty: HardAccuracy: 29.37%Submissions: 121K+Points: 8
Given an array of integers arr[] in a circular fashion. Find the maximum subarray sum that we can get if we assume the array to be circular.

Examples:

Input: arr[] = [8, -8, 9, -9, 10, -11, 12]
Output: 22
Explanation: Starting from the last element of the array, i.e, 12, and moving in a circular fashion, we have max subarray as 12, 8, -8, 9, -9, 10, which gives maximum sum as 22.
Input: arr[] = [10, -3, -4, 7, 6, 5, -4, -1]
Output: 23
Explanation: Maximum sum of the circular subarray is 23. The subarray is [7, 6, 5, -4, -1, 10].
Input: arr[] = [-1, 40, -14, 7, 6, 5, -4, -1] 
Output: 52
Explanation: Circular Subarray [7, 6, 5, -4, -1, -1, 40] has the maximum sum, which is 52.
Constraints:
1 <= arr.size() <= 105
-104 <= arr[i] <= 104
*/

/*
Approach:
1. The problem is to find the maximum sum of a subarray in a circular array.
2. There are two main cases to consider:
   - Case 1: The maximum sum subarray is a normal (non-circular) subarray, which can be found using Kadane's algorithm.
   - Case 2: The maximum sum subarray is a circular subarray. In this case, the optimal subarray is the total sum of the array minus the minimum subarray sum.
3. We calculate the maximum sum of a normal subarray and the minimum sum of a subarray to handle the circular case.
4. If all elements are negative, the result should be the maximum normal subarray sum because total - minimum will be 0 (which isn't a valid subarray).

Steps:
1. Use Kadane's algorithm to find:
   - `mx`: Maximum subarray sum.
   - `mn`: Minimum subarray sum.
2. Calculate the total sum of the array.
3. The result is the maximum of `mx` and `total - mn`.
4. Special case: if all elements are negative, return `mx`.

Time Complexity:
- O(n), where n is the size of the input array because we traverse the array once to compute all required values.

Space Complexity:
- O(1), as no extra space is used other than a few integer variables.

*/

class Solution {
public:
    // Function to find maximum circular subarray sum.
    int circularSubarraySum(vector<int> &arr) {
        int n = arr.size();
        int sum1 = 0, sum2 = 0;
        int mx = INT_MIN, mn = INT_MAX;
        int total = 0;
        
        // Traverse the array to find the necessary values
        for(int i = 0; i < n; i++) {
            total += arr[i];  // Calculate the total sum of the array
            
            // Calculate the maximum subarray sum using Kadane's algorithm
            sum1 = max(arr[i], sum1 + arr[i]);
            mx = max(sum1, mx);
            
            // Calculate the minimum subarray sum
            sum2 = min(arr[i], sum2 + arr[i]);
            mn = min(sum2, mn);
        }
        
        // If all elements are negative, return the maximum subarray sum
        if (mx < 0) return mx;
        
        // Return the maximum of the normal and circular cases
        return max(mx, total - mn);
    }
};
