/*
1574. Shortest Subarray to be Removed to Make Array Sorted
Solved
Medium
Topics
Companies
Hint
Given an integer array arr, remove a subarray (can be empty) from arr such that the remaining elements in arr are non-decreasing.

Return the length of the shortest subarray to remove.

A subarray is a contiguous subsequence of the array.

 

Example 1:

Input: arr = [1,2,3,10,4,2,3,5]
Output: 3
Explanation: The shortest subarray we can remove is [10,4,2] of length 3. The remaining elements after that will be [1,2,3,3,5] which are sorted.
Another correct solution is to remove the subarray [3,10,4].
Example 2:

Input: arr = [5,4,3,2,1]
Output: 4
Explanation: Since the array is strictly decreasing, we can only keep a single element. Therefore we need to remove a subarray of length 4, either [5,4,3,2] or [4,3,2,1].
Example 3:

Input: arr = [1,2,3]
Output: 0
Explanation: The array is already non-decreasing. We do not need to remove any elements.
 

Constraints:

1 <= arr.length <= 105
0 <= arr[i] <= 109
*/

/*
Approach:
1. **Initial Observation**:
   - We want to find the shortest subarray that can be removed to make the remaining array sorted.
   - An optimal way is to first check for the largest non-decreasing suffix from the end. Let `j` be the index where this suffix starts.

2. **Finding Minimum Subarray to Remove**:
   - Initialize `res` to `j`, which assumes removing the prefix of length `j` is the minimum to achieve a sorted array.
   - Iterate through the array from the beginning (using index `i`) while the prefix is non-decreasing.
   - For each `i`, find the first position `j` (if any) such that the value at `arr[i]` is not greater than `arr[j]`.
   - Calculate the length of the subarray that can be removed as `j - i - 1`.
   - Keep track of the minimum value of this length.

3. **Result**:
   - Return the minimum length of the subarray that needs to be removed.

Time Complexity:
- O(n) — Since both `i` and `j` iterate over the entire array, but in separate loops.

Space Complexity:
- O(1) — No additional space is required.

*/

class Solution {
public:
    // Function to find the length of the shortest subarray that can be removed to make the array sorted
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();

        // Step 1: Find the longest non-decreasing suffix starting from the end
        int j = n - 1;
        while (j > 0 && arr[j] >= arr[j - 1]) {
            j--;
        }

        // If the entire array is already sorted, no subarray needs to be removed
        if (j == 0) {
            return 0;
        }

        // Initialize result to remove the prefix (j elements)
        int res = j;
        int i = 0;

        // Step 2: Iterate through the prefix to minimize the length to be removed
        while (i < j && (i == 0 || arr[i] >= arr[i - 1])) {
            // Move `j` forward to find the correct spot where `arr[i] <= arr[j]`
            while (j < n && arr[i] > arr[j]) {
                j++;
            }

            // Update result with the current minimum subarray length to be removed
            res = min(res, j - i - 1);

            // Move to the next element in the prefix
            i++;
        }

        return res;
    }
};
