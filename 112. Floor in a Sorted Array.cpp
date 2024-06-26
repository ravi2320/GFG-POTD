/*
Floor in a Sorted Array
Difficulty: EasyAccuracy: 33.75%Submissions: 252K+Points: 2
Given a sorted array arr[] of size n without duplicates, and given a value x. Floor of x is defined as the largest element k in arr[] such that k is smaller than or equal to x. Find the index of k(0-based indexing).

Examples

Input: n = 7, x = 0 arr[] = {1,2,8,10,11,12,19}
Output: -1
Explanation: No element less than 0 is found. So output is "-1".
Input: n = 7, x = 5 arr[] = {1,2,8,10,11,12,19}
Output: 1
Explanation: Largest Number less than 5 is 2 (i.e k = 2), whose index is 1(0-based indexing).
Your Task:
The task is to complete the function findFloor() which returns an integer denoting the index value of K or return -1 if there isn't any such number.

Expected Time Complexity: O(log N).
Expected Auxiliary Space: O(1).

Constraints:
1 ≤ n ≤ 107
1 ≤ arr[i] ≤ 1018
0 ≤ x ≤ arr[n-1]
*/

/**
 * Intuition:
 * - To find the floor of a given number `x` in a sorted array, we can use binary search.
 * - The floor of `x` is the largest element in the array that is less than or equal to `x`.
 * - Using binary search, we efficiently find the floor by narrowing down the search space.

 * Time Complexity: O(log n)
 * - We perform a binary search which takes logarithmic time relative to the size of the array.

 * Space Complexity: O(1)
 * - We use only a constant amount of extra space.

 * @param v: the sorted vector in which to find the floor of x
 * @param n: the size of the vector
 * @param x: the element whose floor we need to find
 * @return: the index of the floor of x in the vector
 */

class Solution {
public:
    int findFloor(vector<long long> v, long long n, long long x) {
        long long low = 0;
        long long high = n - 1;
        long long ans = -1;

        while (low <= high) {
            long long mid = low + (high - low) / 2;

            if (v[mid] <= x) {
                // If v[mid] is less than or equal to x, it could be the floor
                ans = mid;
                // Move to the right to find a potentially larger floor value
                low = mid + 1;
            } else {
                // If v[mid] is greater than x, move to the left
                high = mid - 1;
            }
        }

        return ans;
    }
};
