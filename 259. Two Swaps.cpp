/*
Two Swaps
Difficulty: EasyAccuracy: 49.85%Submissions: 18K+Points: 2
Given a permutation of some of the first natural numbers in an array arr[], determine if the array can be sorted in exactly two swaps. A swap can involve the same pair of indices twice.

Return true if it is possible to sort the array with exactly two swaps, otherwise return false.

Examples:

Input: arr = [4, 3, 2, 1]
Output: true
Explanation: First, swap arr[0] and arr[3]. The array becomes [1, 3, 2, 4]. Then, swap arr[1] and arr[2]. The array becomes [1, 2, 3, 4], which is sorted.
Input: arr = [4, 3, 1, 2]
Output: false
Explanation: It is not possible to sort the array with exactly two swaps.
Constraints:
1 ≤ arr.size() ≤ 106
1 ≤ arr[i] ≤ arr.size()
*/

/*
Approach:
- The goal is to check if an array can be sorted by performing exactly two swaps or if it's already sorted.
- The logic is based on the observation that if a number is not in its correct position, we swap it with the number at the position where it should be.
- The variable `cnt` keeps track of how many swaps have been made.
- The algorithm works as follows:
  1. For each index `i`, if the element at position `i` is not equal to `i+1`, we swap it with the correct position `arr[i] - 1`.
  2. If more than two swaps are required, the function immediately returns `false`.
  3. If exactly two swaps or zero swaps are made, the function returns `true`.

Time Complexity:
- O(n), where `n` is the size of the array. This is because each element is swapped only once during the process.

Space Complexity:
- O(1) since we are using a constant amount of extra space besides the input array.

*/

class Solution {
public:
    // Function to check if array can be sorted with exactly two swaps
    bool checkSorted(vector<int> &arr) {
        int cnt = 0; // Counter to track the number of swaps
        int n = arr.size(); // Size of the array
        int i = 0;

        // Iterate over the array
        while (i < n) {
            // If the current element is not in the correct position, swap it
            if (arr[i] != i + 1) {
                swap(arr[i], arr[arr[i] - 1]); // Swap with the correct position
                cnt++; // Increment the swap counter
            } else {
                i++; // Move to the next element if no swap is required
            }

            // If more than 2 swaps have been made, return false
            if (cnt > 2) return false;
        }

        // Return true if exactly 0 or 2 swaps were made
        return cnt == 2 || cnt == 0;
    }
};
