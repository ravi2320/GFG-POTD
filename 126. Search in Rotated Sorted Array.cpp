/*
Search in Rotated Sorted Array
Difficulty: MediumAccuracy: 37.64%Submissions: 213K+Points: 4
Given a sorted (in ascending order) and rotated array arr of distinct elements which may be rotated at some point and given an element key, the task is to find the index of the given element key in the array arr. The whole array arr is given as the range to search.

Rotation shifts elements of the array by a certain number of positions, with elements that fall off one end reappearing at the other end.

Note:- 0-based indexing is followed & returns -1 if the key is not present.

Examples :

Input: arr[] = [5, 6, 7, 8, 9, 10, 1, 2, 3], key = 10
Output: 5
Explanation: 10 is found at index 5.
Input: arr[] = [3, 5, 1, 2], key = 6
Output: -1
Explanation: There is no element that has value 6.
Expected Time Complexity: O(log n)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ arr.size() ≤ 106
0 ≤ arr[i] ≤ 106
1 ≤ key ≤ 105
*/

/*
 * Intuition:
 * The task is to search for a target value in a rotated sorted array. The array was originally sorted in ascending order but then rotated.
 * The idea is to use binary search, leveraging the properties of the rotated array to determine which part to search in.
 * 
 * Time Complexity: O(log n), where n is the number of elements in the array. This is because binary search is used.
 * Space Complexity: O(1), as the solution uses constant extra space.
 */

class Solution {
public:
    int search(vector<int>& arr, int key) {
        int low = 0;
        int high = arr.size() - 1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] == key) {
                return mid;
            }

            // If the left part is sorted
            if (arr[low] <= arr[mid]) {
                // Check if the key is in the left part
                if (arr[low] <= key && key <= arr[mid]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            // If the right part is sorted
            else {
                // Check if the key is in the right part
                if (arr[mid] <= key && key <= arr[high]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }

        return -1; // Key not found
    }
};
