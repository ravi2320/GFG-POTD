/*
Count Pairs whose sum is less than target
Difficulty: EasyAccuracy: 54.69%Submissions: 10K+Points: 2
Given an array arr[] and an integer target. You have to find the number of pairs in the array whose sum is strictly less than the target.

Examples:

Input: arr[] = [7, 2, 5, 3], target = 8
Output: 2
Explanation: There are 2 pairs with sum less than 8: (2, 5) and (2, 3). 
Input: arr[] = [5, 2, 3, 2, 4, 1], target = 5
Output: 4
Explanation: There are 4 pairs whose sum is less than 5: (2, 2), (2, 1), (3, 1) and (2, 1).
Input: arr[] = [2, 1, 8, 3, 4, 7, 6, 5], target = 7
Output: 6
Explanation: There are 6 pairs whose sum is less than 7: (2, 1), (2, 3), (2, 4), (1, 3), (1, 4) and (1, 5).
Constraints:
1 <= arr.size() <= 105
0 <= arr[i] <= 104
1 <= target <= 104
*/

/*
Approach:
1. Sort the input array to enable a two-pointer technique.
2. Use two pointers:
   - `i` starts at the beginning of the array.
   - `j` starts at the end of the array.
3. Check the sum of elements at `arr[i]` and `arr[j]`:
   - If their sum is less than the target, then all pairs formed by `arr[i]` and elements from `arr[i+1]` to `arr[j]` will also have a sum less than the target. Add `(j - i)` to the count and move `i` forward.
   - Otherwise, decrement `j` to reduce the sum.
4. Continue until the two pointers meet.

Intuition:
Sorting the array ensures that we can efficiently determine the number of valid pairs using the two-pointer technique. If the sum of a pair is less than the target, then all pairs with the same `i` but a smaller `j` are also valid. This reduces unnecessary checks compared to a brute-force approach.

Time Complexity:
- Sorting the array: \(O(N \log N)\), where \(N\) is the size of the array.
- Two-pointer traversal: \(O(N)\).
Overall: \(O(N \log N)\).

Space Complexity:
- Sorting uses \(O(1)\) additional space for in-place sorting.
Overall: \(O(1)\).

*/

class Solution {
public:
    int countPairs(vector<int> &arr, int target) {
        // Sort the array to apply the two-pointer technique
        sort(arr.begin(), arr.end());

        int i = 0, j = arr.size() - 1; // Initialize two pointers
        int cnt = 0;                  // Counter for valid pairs

        // Traverse the array with the two pointers
        while (i < j) {
            if (arr[i] + arr[j] < target) {
                // If the sum is less than the target, all pairs (i, i+1) to (i, j) are valid
                cnt += (j - i);
                i++; // Move the left pointer to check for new pairs
            } else {
                // If the sum is greater or equal, move the right pointer to reduce the sum
                j--;
            }
        }

        return cnt; // Return the total count of valid pairs
    }
};