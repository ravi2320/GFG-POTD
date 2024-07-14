/*
Segregate 0s and 1s
Difficulty: EasyAccuracy: 54.25%Submissions: 94K+Points: 2
Given an array arr consisting of only 0's and 1's in random order. Modify the array in-place to segregate 0s onto the left side and 1s onto the right side of the array.

Examples :

Input: arr[] = [0, 0, 1, 1, 0]
Output: [0, 0, 0, 1, 1]
Explanation:  After segregation, all the 0's are on the left and 1's are on the right. Modified array will be [0, 0, 0, 1, 1].
Input: arr[] = [1, 1, 1, 1]
Output: [1, 1, 1, 1]
Explanation: There are no 0s in the given array, so the modified array is [1, 1, 1, 1]
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ arr.size() ≤ 106
0 ≤ arr[i] ≤ 1


*/

/*
 * Intuition:
 * The problem is to segregate 0s and 1s in a given array such that all 0s come before all 1s.
 * We can solve this using two pointers:
 * - Pointer `i` will mark the position where the next 0 should be placed.
 * - Pointer `j` will traverse through the array.
 * 
 * Time Complexity: O(n), where n is the number of elements in the array. We traverse the array once.
 * Space Complexity: O(1), since we are using only a constant amount of extra space.
 */

class Solution {
public:
    void segregate0and1(vector<int> &arr) {
        int n = arr.size();
        int i = 0; // Pointer to place the next 0
        int j = 0; // Pointer to traverse the array

        // Move i and j to the first non-zero element
        while (j < n && arr[j] == 0) {
            i++;
            j++;
        }

        // Traverse the array and place 0s in the correct position
        while (j < n) {
            if (arr[j] == 0) {
                swap(arr[i], arr[j]); // Place 0 at the current position of i
                i++;
            }
            j++;
        }
    }
};
