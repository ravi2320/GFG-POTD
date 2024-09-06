/*
Kadane's Algorithm
Difficulty: MediumAccuracy: 36.28%Submissions: 961K+Points: 4
Given an integer array arr[]. Find the contiguous sub-array(containing at least one number) that has the maximum sum and return its sum.

Examples:

Input: arr[] = [1, 2, 3, -2, 5]
Output: 9
Explanation: Max subarray sum is 9 of elements (1, 2, 3, -2, 5) which is a contiguous subarray.
Input: arr[] = [-1, -2, -3, -4]
Output: -1
Explanation: Max subarray sum is -1 of element (-1)
Input: arr[] = [5, 4, 7]
Output: 16
Explanation: Max subarray sum is 16 of element (5, 4, 7)
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ arr.size() ≤ 105
-107 ≤ arr[i] ≤ 107
*/

/*
**Problem Statement:**
- Given an array `arr`, the task is to find the sum of the contiguous subarray within the array that has the largest sum.

**Approach (Kadane's Algorithm):**
1. **Track Current Sum:**
   - Traverse through the array while maintaining a `sum` variable that stores the sum of the current subarray.
   - If the current `sum` becomes negative, reset it to zero, as starting a new subarray would yield a higher sum.

2. **Track Maximum Sum:**
   - Throughout the traversal, keep track of the `maxSum`, which stores the maximum subarray sum encountered so far.
   - After every update to `sum`, compare it with `maxSum` and update `maxSum` if `sum` is greater.

3. **Return Maximum Sum:**
   - After traversing the entire array, return `maxSum`, which will be the maximum sum of any contiguous subarray.

**Key Considerations:**
   - If all elements in the array are negative, the maximum sum will be the largest single element.

**Time Complexity:**
   - O(n), where `n` is the number of elements in the array, since we only traverse the array once.

**Space Complexity:**
   - O(1), as we only use a few extra variables.

**Example Usage:**
   - For the array `{-2, 1, -3, 4, -1, 2, 1, -5, 4}`, the function will return `6`, which is the sum of the subarray `{4, -1, 2, 1}`.
*/

class Solution {
  public:
    // Function to find the sum of contiguous subarray with maximum sum.
    int maxSubarraySum(vector<int> &arr) {
        // Initialize the sum and maxSum
        int sum = 0;
        int maxSum = INT_MIN;

        // Iterate through the array
        for (int &x : arr) {
            sum += x;               // Add current element to sum
            maxSum = max(maxSum, sum); // Update maxSum if current sum is larger

            // If sum becomes negative, reset it to 0
            if (sum < 0) sum = 0;
        }

        // Return the maximum subarray sum
        return maxSum;
    }
};
