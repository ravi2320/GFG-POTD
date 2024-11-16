/*
Move All Zeroes to End
Difficulty: EasyAccuracy: 45.51%Submissions: 200K+Points: 2
Given an array arr[]. Push all the zeros of the given array to the right end of the array while maintaining the order of non-zero elements. Do the mentioned change in the array in place.

Examples:

Input: arr[] = [1, 2, 0, 4, 3, 0, 5, 0]
Output: [1, 2, 4, 3, 5, 0, 0, 0]
Explanation: There are three 0s that are moved to the end.
Input: arr[] = [10, 20, 30]
Output: [10, 20, 30]
Explanation: No change in array as there are no 0s.
Input: arr[] = [0, 0]
Output: [0, 0]
Explanation: No change in array as there are all 0s.
Constraints:
1 ≤ arr.size() ≤ 105
0 ≤ arr[i] ≤ 105
*/


/*
Approach:
1. Use a two-pointer strategy to rearrange the array in-place:
   - `idx` is used to track the position where the next non-zero element should be placed.
   - Traverse the array, and whenever a non-zero element is encountered, place it at the current `idx` position and increment `idx`.
2. Count the number of zeros during the traversal.
3. Once all non-zero elements are placed in the correct position, fill the remaining slots with zeros using the count.

Time Complexity:
- O(n) — We traverse the array once to move non-zero elements and count zeros, and another pass to fill zeros.

Space Complexity:
- O(1) — No additional space is used except for a few integers.

*/

class Solution {
  public:
    // Function to push all zeros in the array to the end
    void pushZerosToEnd(vector<int>& arr) {
        int n = arr.size();
        int idx = 0;  // Index to place the next non-zero element
        int cnt = 0;  // Count of zeros encountered

        // Traverse the array and move non-zero elements to the front
        for (int i = 0; i < n; i++) {
            if (arr[i] != 0) {
                arr[idx++] = arr[i];
            } else {
                cnt++;  // Count the zeros
            }
        }

        // Fill the remaining positions with zeros
        while (cnt--) {
            arr[idx++] = 0;
        }
    }
};