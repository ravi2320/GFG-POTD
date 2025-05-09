/*
Two Smallests in Every Subarray
Difficulty: EasyAccuracy: 52.96%Submissions: 10K+Points: 2
Given an array of integers arr, the task is to find and return the maximum sum of the smallest and second smallest element among all possible subarrays of size greater than one. If it is not possible, then return -1.

Examples:

Input: arr = [4, 3, 1, 5, 6]
Output: 11
Explanation: Subarrays with smallest and second smallest are,
Subarray: [4, 3], smallest = 3, second smallest = 4, sum = 7
Subarray: [4, 3, 1], smallest = 1, second smallest = 3, sum = 4
Subarray: [4, 3, 1, 5], smallest = 1, second smallest = 3, sum = 4
Subarray: [4, 3, 1, 5, 6], smallest = 1, second smallest = 3, sum = 4
Subarray: [3, 1], smallest = 1, second smallest = 3, sum = 4
Subarray: [3, 1, 5], smallest = 1, second smallest = 3, sum = 4
Subarray: [3, 1, 5, 6], smallest = 1, second smallest = 3, sum = 4
Subarray: [1, 5], smallest = 1, second smallest = 5, sum = 6
Subarray: [1, 5, 6] ,smallest = 1, second smallest = 5, sum = 6
Subarray: [5, 6], smallest = 5, second smallest = 6, sum = 11
Maximum sum among all above choices is, 5 + 6 = 11, hence the answer is 11.
Input: arr = [1]
Output: -1
Explanation: Here the size of array is 1, but we need minimum 2 elements. Hence, the answer is -1.
Expected Time Complexity: O(n)
Expected Space Complexity: O(1)

Constraints:
1<=arr.size()<=105 
1<=arr[i]<=105
*/

/*
Approach:
1. Iterate through the array from index 1 to the end.
2. For each consecutive pair arr[i] and arr[i-1], calculate their sum.
3. Keep track of the maximum sum found during the iteration.
4. Return the maximum sum at the end.

Time Complexity: O(n), where n is the size of the array.
Space Complexity: O(1), since we only use a few extra variables.
*/

class Solution {
  public:
    int pairWithMaxSum(vector<int>& arr) {
        // Get the size of the array
        int n = arr.size();

        // Initialize maxSum to a very small value
        int maxSum = -1;

        // Iterate over the array from the second element
        for(int i = 1; i < n; i++) {
            // Calculate the sum of consecutive elements
            int sum = arr[i] + arr[i - 1];

            // Update maxSum if current sum is greater
            maxSum = max(maxSum, sum);
        }

        // Return the maximum sum found
        return maxSum;
    }
};
