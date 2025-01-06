/*
Sum Pair closest to target
Difficulty: EasyAccuracy: 44.75%Submissions: 35K+Points: 2
Given an array arr[] and a number target, find a pair of elements (a, b) in arr[], where a<=b whose sum is closest to target.
Note: Return the pair in sorted order and if there are multiple such pairs return the pair with maximum absolute difference. If no such pair exists return an empty array.

Examples:

Input: arr[] = [10, 30, 20, 5], target = 25
Output: [5, 20]
Explanation: As 5 + 20 = 25 is closest to 25.
Input: arr[] = [5, 2, 7, 1, 4], target = 10
Output: [2, 7]
Explanation: As (4, 7) and (2, 7) both are closest to 10, but absolute difference of (2, 7) is 5 and (4, 7) is 3. Hence, [2, 7] has maximum absolute difference and closest to target. 
Input: arr[] = [10], target = 10
Output: []
Explanation: As the input array has only 1 element, return an empty array.
Constraints:
1 <= arr.size() <= 2*105
0 <= target<= 2*105
0 <= arr[i] <= 105
*/

/*
Approach:
1. Sort the array in ascending order to use the two-pointer technique.
2. Initialize two pointers:
   - `i` at the beginning of the array.
   - `j` at the end of the array.
3. Calculate the sum of the elements at `i` and `j` (`pairSum`).
   - Compare the absolute difference between `target` and `pairSum` with the current minimum difference (`diff`).
   - If it is smaller, update the result with the current pair.
4. Adjust pointers based on the relationship between `pairSum` and `target`:
   - If `pairSum < target`, increment `i` to increase the sum.
   - If `pairSum > target`, decrement `j` to decrease the sum.
   - If `pairSum == target`, return the pair immediately as the exact match is found.
5. Continue until the pointers meet.
6. Return the pair with the closest sum to the target.

Intuition:
The two-pointer technique is ideal for problems requiring pair-based comparisons in a sorted array. Sorting ensures the array is in ascending order, allowing efficient adjustment of pointers to approach the target.

Time Complexity:
- Sorting the array: \(O(N \log N)\), where \(N\) is the size of the array.
- Two-pointer traversal: \(O(N)\).
Overall: \(O(N \log N)\).

Space Complexity:
- Sorting is in-place, so no additional space is required for the array.
Overall: \(O(1)\).

*/

class Solution {
public:
    vector<int> sumClosest(vector<int>& arr, int target) {
        // Step 1: Sort the array
        sort(arr.begin(), arr.end());
        
        int diff = INT_MAX;         // Initialize the minimum difference
        vector<int> ans;            // To store the result pair
        int i = 0, j = arr.size() - 1; // Two pointers: one at the start, one at the end

        // Step 2: Use two-pointer technique to find the closest sum
        while (i < j) {
            int pairSum = arr[i] + arr[j]; // Calculate the sum of the current pair
            
            // Update result if the current pair is closer to the target
            if (abs(target - pairSum) < diff) {
                diff = abs(target - pairSum);
                ans = {arr[i], arr[j]}; // Store the current closest pair
            }
            
            // Adjust pointers based on the comparison between pairSum and target
            if (pairSum < target) {
                i++; // Move the left pointer to increase the sum
            } else if (pairSum > target) {
                j--; // Move the right pointer to decrease the sum
            } else {
                return ans; // Exact match found
            }
        }

        return ans; // Return the pair with the closest sum to the target
    }
};
