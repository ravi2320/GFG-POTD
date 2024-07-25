/*
Second Largest
Difficulty: EasyAccuracy: 26.72%Submissions: 617K+Points: 2
Given an array arr, return the second largest distinct element from an array. If the second largest element doesn't exist then return -1.

Examples:

Input: arr = [12, 35, 1, 10, 34, 1]
Output: 34
Explanation: The largest element of the array is 35 and the second largest element is 34.
Input: arr = [10, 10]
Output: -1
Explanation: The largest element of the array is 10 and the second largest element does not exist so answer is -1.
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)

Constraints:
2 ≤ arr.size() ≤ 105
1 ≤ arri ≤ 105
*/

/**
 * Intuition:
 * - To find the second largest element in an array, maintain two variables, `num1` and `num2`, to track the largest and the second-largest numbers encountered so far.
 * - Traverse the array and update these variables accordingly.
 *
 * Time Complexity: O(n)
 * - The solution involves a single pass through the array, making it linear in time complexity.
 *
 * Space Complexity: O(1)
 * - The algorithm uses a constant amount of additional space.
 */

class Solution {
  public:
    // Function to return the second largest element in the array
    int print2largest(vector<int> &arr) {
        int num1 = arr[0]; // Largest element
        int num2 = -1;     // Second largest element
        int n = arr.size();
        
        for(int i = 1; i < n; i++) {
            if(arr[i] > num1) {
                num2 = num1; // Update second largest
                num1 = arr[i]; // Update largest
            } else if(arr[i] < num1 && arr[i] > num2) {
                num2 = arr[i]; // Update second largest if it's smaller than the largest but greater than the current second largest
            }
        }
        
        return num2;
    }
};
