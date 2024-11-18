/*
Rotate Array
Difficulty: MediumAccuracy: 37.06%Submissions: 381K+Points: 4
Given an unsorted array arr[]. Rotate the array to the left (counter-clockwise direction) by d steps, where d is a positive integer. Do the mentioned change in the array in place.

Note: Consider the array as circular.

Examples :

Input: arr[] = [1, 2, 3, 4, 5], d = 2
Output: [3, 4, 5, 1, 2]
Explanation: when rotated by 2 elements, it becomes 3 4 5 1 2.
Input: arr[] = [2, 4, 6, 8, 10, 12, 14, 16, 18, 20], d = 3
Output: [8, 10, 12, 14, 16, 18, 20, 2, 4, 6]
Explanation: when rotated by 3 elements, it becomes 8 10 12 14 16 18 20 2 4 6.
Input: arr[] = [7, 3, 9, 1], d = 9
Output: [3, 9, 1, 7]
Explanation: when we rotate 9 times, we'll get 3 9 1 7 as resultant array.
Constraints:
1 <= arr.size(), d <= 105
0 <= arr[i] <= 105
*/

/*
Approach:
1. To rotate the array by `d` elements in a counter-clockwise direction, the problem can be solved using a three-step reverse technique:
   - Reverse the first `d` elements.
   - Reverse the remaining `n - d` elements.
   - Reverse the entire array.
2. This approach efficiently rotates the array in-place without needing extra space.

Steps:
1. `d = d % n`: Normalize `d` to handle cases where `d >= n`.
2. Reverse the subarray from index `0` to `d-1`.
3. Reverse the subarray from index `d` to `n-1`.
4. Reverse the entire array to get the final rotated array.

Time Complexity:
- O(n) — Each reverse operation is O(n).

Space Complexity:
- O(1) — In-place rotation, no additional space required.

*/

class Solution {
public:
    // Function to rotate an array by d elements in counter-clockwise direction.
    void rotateArr(vector<int>& arr, int d) {
        int n = arr.size();
        d = d % n; // Normalize d to avoid unnecessary rotations

        // Step 1: Reverse the first d elements
        reverse(arr.begin(), arr.begin() + d);

        // Step 2: Reverse the remaining elements
        reverse(arr.begin() + d, arr.end());

        // Step 3: Reverse the entire array
        reverse(arr.begin(), arr.end());
    }
};
