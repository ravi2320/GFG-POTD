/*
Median of 2 Sorted Arrays of Different Sizes
Difficulty: HardAccuracy: 28.4%Submissions: 113K+Points: 8
Given two sorted arrays array1 and array2 of size m and n respectively. Find the median of the two sorted arrays.

Example 1:

Input:
m = 3, n = 4
array1[] = {1,5,9}
array2[] = {2,3,6,7}
Output: 5
Explanation: The middle element for
{1,2,3,5,6,7,9} is 5
Example 2:

Input:
m = 2, n = 4
array1[] = {4,6}
array2[] = {1,2,3,5}
Output: 3.5
Your Task:
The task is to complete the function MedianOfArrays() that takes array1 and array2 as input and returns their median. 

Can you solve the problem in expected time complexity?

Expected Time Complexity: O(min(log n, log m)).
Expected Auxiliary Space: O((n+m)/2).

Constraints: 
0 ≤ m,n ≤ 106
1 ≤ array1[i], array2[i] ≤ 109
*/

/**
 * Intuition:
 * - To find the median of two sorted arrays, we need to merge them up to the middle element (or elements, if the total length is even).
 * - By merging up to the middle element, we avoid unnecessary merging operations beyond what is needed to find the median.
 * - This approach leverages the properties of sorted arrays to efficiently find the median.
 * 
 * Time Complexity:
 * - O(n + m), where n and m are the lengths of the two input arrays.
 * - We are merging the arrays only up to the middle element, so the complexity remains linear.
 * 
 * Space Complexity:
 * - O(min(n, m)), which is the space used by the temporary array up to the middle element.
 */

class Solution {
public:
    double MedianOfArrays(vector<int>& array1, vector<int>& array2) {
        int n = array1.size();
        int m = array2.size();
        int len = n + m;
        int mid = len / 2;

        // Temporary array to store elements up to the middle
        vector<int> temp(mid + 1);
        int i = 0, j = 0, k = 0;

        // Merge arrays up to the middle element
        while (i < n && j < m && k <= mid) {
            if (array1[i] <= array2[j]) {
                temp[k++] = array1[i++];
            } else {
                temp[k++] = array2[j++];
            }
        }

        // If elements are left in array1
        while (i < n && k <= mid) {
            temp[k++] = array1[i++];
        }

        // If elements are left in array2
        while (j < m && k <= mid) {
            temp[k++] = array2[j++];
        }

        // If the total length is even, return the average of the two middle elements
        if (len % 2 == 0) {
            return (temp[mid - 1] + temp[mid]) / 2.0;
        }

        // If the total length is odd, return the middle element
        return temp[mid];
    }
};
