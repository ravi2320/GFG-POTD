/*
Next Permutation
Difficulty: MediumAccuracy: 40.66%Submissions: 140K+Points: 4
Given an array of integers arr[] representing a permutation, implement the next permutation that rearranges the numbers into the lexicographically next greater permutation. If no such permutation exists, rearrange the numbers into the lowest possible order (i.e., sorted in ascending order). 

Note - A permutation of n numbers is any possible arrangement of all the integers in range [1-n] where each integer occurs exactly once. 

Examples:

Input: arr = [2, 4, 1, 7, 5, 0]
Output: [2, 4, 5, 0, 1, 7]
Explanation: The next permutation of the given array is {2, 4, 5, 0, 1, 7}.
Input: arr = [3, 2, 1]
Output: [1, 2, 3]
Explanation: As arr[] is the last permutation, the next permutation is the lowest one.
Input: arr = [3, 4, 2, 5, 1]
Output: [3, 4, 5, 1, 2]
Explanation: The next permutation of the given array is {3, 4, 5, 1, 2}.
Constraints:
1 ≤ arr.size() ≤ 105
1 ≤ arr[i] ≤ 105
*/

/*
Approach:
1. The problem is to find the next lexicographical permutation of the input vector `arr`.
   - If such a permutation does not exist (the array is sorted in descending order), the array should be rearranged to the lowest possible order (ascending).
  
Steps:
1. Traverse the array from right to left to find the first index `idx` where `arr[idx] < arr[idx+1]`. This indicates the point where we need to make a swap to increase the permutation.
2. If no such `idx` is found, the array is in descending order. Simply reverse the array to get the lowest permutation.
3. If an `idx` is found, traverse the array from the end to find the first element that is greater than `arr[idx]` and swap them.
4. Reverse the sub-array from `idx+1` to the end to get the next permutation.

Time Complexity:
- O(n) — A single pass to find `idx`, another pass to find the correct element to swap, and a reverse operation.

Space Complexity:
- O(1) — Only in-place modifications are done.

*/

class Solution {
public:
    // Function to find the next lexicographical permutation
    void nextPermutation(vector<int>& arr) {
        int n = arr.size();
        int idx = n - 2;
        
        // Step 1: Find the first decreasing element from the right
        while (idx >= 0) {
            if (arr[idx] < arr[idx + 1]) {
                break;
            }
            idx--;
        }
        
        // Step 2: If no such element is found, reverse the entire array
        if (idx == -1) {
            reverse(arr.begin(), arr.end());
            return;
        }
        
        // Step 3: Find the element just larger than arr[idx] from the end and swap
        for (int i = n - 1; i > idx; i--) {
            if (arr[i] > arr[idx]) {
                swap(arr[i], arr[idx]);
                break;
            }
        }
        
        // Step 4: Reverse the elements from idx+1 to the end of the array
        reverse(arr.begin() + idx + 1, arr.end());
    }
};