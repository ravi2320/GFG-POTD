/*
Bitonic Point
Difficulty: EasyAccuracy: 58.67%Submissions: 147K+Points: 2Average Time: 15m
Given an array of integers arr[] that is first strictly increasing and then maybe strictly decreasing, find the bitonic point, that is the maximum element in the array.
Bitonic Point is a point before which elements are strictly increasing and after which elements are strictly decreasing.

Note: It is guaranteed that the array contains exactly one bitonic point.

Examples:

Input: arr[] = [1, 2, 4, 5, 7, 8, 3]
Output: 8
Explanation: Elements before 8 are strictly increasing [1, 2, 4, 5, 7] and elements after 8 are strictly decreasing [3].
Input: arr[] = [10, 20, 30, 40, 50]
Output: 50
Explanation: Elements before 50 are strictly increasing [10, 20, 30 40] and there are no elements after 50.
Input: arr[] = [120, 100, 80, 20, 0]
Output: 120
Explanation: There are no elements before 120 and elements after 120 are strictly decreasing [100, 80, 20, 0].
Constraints:
3 ≤ arr.size() ≤ 105
1 ≤ arr[i] ≤ 106
*/

/*
Intuition:
- The array is **bitonic**, meaning it first increases and then decreases.
- The maximum element is the point where the transition happens from increasing to decreasing.

Approach:
- Traverse the array and compare each element with the next one.
- The first time you find `arr[i] > arr[i+1]`, it means `arr[i]` is the peak (maximum element).
- If the array is strictly increasing, return the last element.

Time Complexity: O(N)
- In the worst case, we check every pair until the end.

Space Complexity: O(1)
- No extra space used.
*/

class Solution {
  public:
    int findMaximum(vector<int> &arr) {
        int n = arr.size();

        // Traverse to find the first point where the sequence stops increasing
        for (int i = 0; i < n - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                return arr[i]; // Found the peak
            }
        }

        // If we never found a decreasing point, the last element is the maximum
        return arr[n - 1];
    }
};
