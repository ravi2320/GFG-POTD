/*
Second Largest
Difficulty: EasyAccuracy: 26.72%Submissions: 779K+Points: 2
Given an array of positive integers arr[], return the second largest element from the array. If the second largest element doesn't exist then return -1.

Note: The second largest element should not be equal to the largest element.

Examples:

Input: arr[] = [12, 35, 1, 10, 34, 1]
Output: 34
Explanation: The largest element of the array is 35 and the second largest element is 34.
Input: arr[] = [10, 5, 10]
Output: 5
Explanation: The largest element of the array is 10 and the second largest element is 5.
Input: arr[] = [10, 10, 10]
Output: -1
Explanation: The largest element of the array is 10 and the second largest element does not exist.
Constraints:
2 ≤ arr.size() ≤ 105
1 ≤ arr[i] ≤ 105
*/

/*
Approach:
1. Traverse through the array to find the second largest element.
2. Maintain two variables:
   - `max1`: To store the largest element found so far.
   - `max2`: To store the second largest element found so far.
3. Iterate over the array:
   - If the current element is greater than `max1`, update `max2` to `max1` and `max1` to the current element.
   - If the current element is smaller than `max1` but greater than `max2`, update `max2` to the current element.
4. The value of `max2` at the end of the iteration will be the second largest element.

Time Complexity:
- O(n) — Only one traversal of the array is needed.

Space Complexity:
- O(1) — No additional space is required except for a few integer variables.

*/

class Solution {
public:
    // Function to find the second largest element in the array
    int getSecondLargest(vector<int> &arr) {
        int n = arr.size();        // Get the size of the array
        int max1 = arr[0];         // Initialize the largest element with the first element
        int max2 = -1;             // Initialize the second largest element with -1 (indicating no second largest yet)
        
        // Iterate through the array to find the second largest element
        for(int i = 1; i < n; i++) {
            // If the current element is greater than the current largest (max1)
            if(arr[i] > max1) {
                max2 = max1;       // Update second largest to current largest
                max1 = arr[i];     // Update largest to the current element
            }
            // If the current element is between max1 and max2
            else if(max1 > arr[i] && arr[i] > max2) {
                max2 = arr[i];     // Update second largest to the current element
            }
        }
        
        return max2;  // Return the second largest element
    }
};