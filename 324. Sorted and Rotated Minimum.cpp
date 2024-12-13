/*
Sorted and Rotated Minimum
Difficulty: EasyAccuracy: 40.57%Submissions: 130K+Points: 2
A sorted array of distinct elements arr[] is rotated at some unknown point, the task is to find the minimum element in it. 

Examples:

Input: arr[] = [5, 6, 1, 2, 3, 4]
Output: 1
Explanation: 1 is the minimum element in the array.
Input: arr[] = [3, 1, 2]
Output: 1
Explanation: Here 1 is the minimum element.
Input: arr[] = [4, 2, 3]
Output: 2
Explanation: Here 2 is the minimum element.
Constraints:
1 ≤ arr.size() ≤ 106
1 ≤ arr[i] ≤ 109
*/

/*
Approach:
1. Use binary search to find the minimum element in a rotated sorted array.
2. The array is divided into two parts: one that is strictly sorted and another that contains the rotation.
3. Compare the middle element `arr[mid]` with the rightmost element `arr[high]`:
   - If `arr[mid] <= arr[high]`, the minimum lies in the left part (including mid).
   - Otherwise, the minimum lies in the right part.
4. Repeat until the `low` and `high` pointers converge to the minimum element.

Steps:
- Initialize two pointers `low` and `high` to the start and end of the array.
- Use a while loop to perform binary search while `low < high`:
  - Calculate the middle index `mid = (low + high) / 2`.
  - Update the pointers based on the comparison of `arr[mid]` and `arr[high]`.
- Return the element at index `low` as the minimum.

Time Complexity:
- O(log n): The binary search reduces the search space by half in each iteration.

Space Complexity:
- O(1): Constant space used for pointers.

Edge Cases:
- Array is not rotated (sorted in ascending order).
- Array contains duplicate elements.
- Single-element array.

*/

class Solution {
public:
    int findMin(vector<int>& arr) {
        int low = 0, high = arr.size() - 1;

        // Perform binary search
        while (low < high) {
            int mid = (low + high) / 2;

            // Check which part contains the minimum
            if (arr[mid] <= arr[high]) {
                high = mid; // Minimum is in the left part (or mid itself)
            } else {
                low = mid + 1; // Minimum is in the right part
            }
        }

        // Return the minimum element
        return arr[low];
    }
};
