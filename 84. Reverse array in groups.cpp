/*
Reverse array in groups
BasicAccuracy: 37.48%Submissions: 317K+Points: 1
Be the comment of the day in POTD and win a GfG T-Shirt!
Solve right now

banner
Given an array arr[] of positive integers of size N. Reverse every sub-array group of size K.

Note: If at any instance, there are no more subarrays of size greater than or equal to K, then reverse the last subarray (irrespective of its size). You shouldn't return any array, modify the given array in-place.

Example 1:

Input:
N = 5, K = 3
arr[] = {1,2,3,4,5}
Output: 3 2 1 5 4
Explanation: First group consists of elements
1, 2, 3. Second group consists of 4,5.
 

Example 2:

Input:
N = 4, K = 3
arr[] = {5,6,8,9}
Output: 8 6 5 9
 

Your Task:
You don't need to read input or print anything. The task is to complete the function reverseInGroups() which takes the array, N and K as input parameters and modifies the array in-place. 

 

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

 

Constraints:
1 ≤ N, K ≤ 107
1 ≤ A[i] ≤ 1018
*/

// Intuition:
// - The problem is to reverse every sub-array of size k in the given array.
// - We can break the problem into two parts: reversing a sub-array and iterating over the array in steps of k to apply this reversal.

// Approach:
// 1. Define a helper function `solve` to reverse a sub-array from index l to r using recursion.
// 2. Iterate through the array in steps of k.
// 3. For each sub-array of size k (or smaller, if at the end), use the `solve` function to reverse it.

// Time Complexity: O(n), where n is the size of the array.
// - Each element is swapped at most once during the reversal, resulting in a linear time complexity.

// Space Complexity: O(1), excluding the recursion stack.
// - The space used for the recursion stack depends on the depth of recursion. In the worst case, it can be O(k), but since k is typically small compared to n, it's generally considered O(1) in terms of additional space used.

class Solution {
public:
    // Function to reverse every sub-array group of size k.
    void solve(vector<long long>& arr, int l, int r) {
        if (l >= r)
            return;
        swap(arr[l], arr[r]);
        solve(arr, l + 1, r - 1);
    }

    void reverseInGroups(vector<long long>& arr, int n, int k) {
        // Iterate through the array in steps of k
        for (int i = 0; i < n; i += k) {
            int l = i;
            int r = min(i + k - 1, n - 1);
            solve(arr, l, r);
        }
    }
};
