/*
Reverse an Array
Difficulty: EasyAccuracy: 55.32%Submissions: 44K+Points: 2
You are given an array of integers arr[]. Your task is to reverse the given array.

Examples:

Input: arr = [1, 4, 3, 2, 6, 5]
Output: [5, 6, 2, 3, 4, 1]
Explanation: The elements of the array are 1 4 3 2 6 5. After reversing the array, the first element goes to the last position, the second element goes to the second last position and so on. Hence, the answer is 5 6 2 3 4 1.
Input: arr = [4, 5, 2]
Output: [2, 5, 4]
Explanation: The elements of the array are 4 5 2. The reversed array will be 2 5 4.
Input: arr = [1]
Output: [1]
Explanation: The array has only single element, hence the reversed array is same as the original.
Constraints:
1<=arr.size()<=105
0<=arr[i]<=105
*/

/*
Approach:
1. Use two-pointer technique to reverse the elements of the array.
   - Initialize `i` to the start (0) and `j` to the end (size - 1) of the array.
   - Swap the elements at positions `i` and `j`.
   - Move `i` forward and `j` backward until they meet or cross each other.
2. This will result in the entire array being reversed in place.

Time Complexity:
- O(n) — Each element is visited at most once, where `n` is the size of the array.

Space Complexity:
- O(1) — In-place reversal without using additional space.

*/

class Solution {
public:
    // Function to reverse the given array
    void reverseArray(vector<int> &arr) {
        int i = 0, j = arr.size() - 1;

        // Two-pointer approach to swap elements until pointers meet
        while (i < j) {
            swap(arr[i++], arr[j--]);
        }
    }
};
