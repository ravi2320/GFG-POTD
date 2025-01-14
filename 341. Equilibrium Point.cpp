/*
Equilibrium Point
Difficulty: EasyAccuracy: 28.13%Submissions: 605K+Points: 2
Given an array of integers arr[], the task is to find the first equilibrium point in the array.

The equilibrium point in an array is an index (0-based indexing) such that the sum of all elements before that index is the same as the sum of elements after it. Return -1 if no such point exists. 

Examples:

Input: arr[] = [1, 2, 0, 3]
Output: 2 
Explanation: The sum of left of index 2 is 1 + 2 = 3 and sum on right of index 2 is 0 + 3 = 3.
Input: arr[] = [1, 1, 1, 1]
Output: -1
Explanation: There is no equilibrium index in the array.
Input: arr[] = [-7, 1, 5, 2, -4, 3, 0]
Output: 3
Explanation: The sum of left of index 3 is -7 + 1 + 5 = -1 and sum on right of index 3 is -4 + 3 + 0 = -1.
Constraints:
3 <= arr.size() <= 106
0 <= arr[i] <= 109
*/

/*
Approach:
1. Calculate the total sum of all elements in the array.
2. Traverse the array while maintaining a running sum of the elements to the left.
3. For each element at index `i`:
   - Check if the running sum (`sum`) equals the sum of elements to the right (`totalSum - sum - arr[i]`).
   - If true, return the current index `i` as the equilibrium point.
4. If no equilibrium point is found after the loop, return -1.

Intuition:
- An equilibrium point is where the sum of elements to its left equals the sum of elements to its right.
- By maintaining a running sum of the left and using the total sum, the sum to the right can be derived without an additional loop.

Time Complexity:
- \(O(n)\): One traversal to calculate the total sum, and another traversal to find the equilibrium point.

Space Complexity:
- \(O(1)\): Constant space used for variables.

Edge Cases:
1. Single element: Return index `0`.
2. No equilibrium point: Return `-1`.
3. All elements are equal: Handle correctly by the algorithm.

*/

class Solution {
public:
    // Function to find the equilibrium point in the array.
    int findEquilibrium(vector<int> &arr) {
        int n = arr.size(); // Size of the array

        // Calculate the total sum of the array
        int totalSum = accumulate(arr.begin(), arr.end(), 0);
        int sum = 0; // Running sum for the left side

        // Traverse the array to find the equilibrium point
        for (int i = 0; i < n; i++) {
            // Check if the current index is the equilibrium point
            if (sum == (totalSum - sum - arr[i])) {
                return i; // Return the equilibrium index
            }

            // Update the running sum for the left side
            sum += arr[i];
        }

        // No equilibrium point found
        return -1;
    }
};