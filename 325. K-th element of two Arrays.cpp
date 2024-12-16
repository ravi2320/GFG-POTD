/*
K-th element of two Arrays
Difficulty: MediumAccuracy: 37.4%Submissions: 297K+Points: 4
Given two sorted arrays a[] and b[] and an element k, the task is to find the element that would be at the kth position of the combined sorted array.

Examples :

Input: a[] = [2, 3, 6, 7, 9], b[] = [1, 4, 8, 10], k = 5
Output: 6
Explanation: The final combined sorted array would be [1, 2, 3, 4, 6, 7, 8, 9, 10]. The 5th element of this array is 6.
Input: a[] = [100, 112, 256, 349, 770], b[] = [72, 86, 113, 119, 265, 445, 892], k = 7
Output: 256
Explanation: Combined sorted array is [72, 86, 100, 112, 113, 119, 256, 265, 349, 445, 770, 892]. The 7th element of this array is 256.
Constraints:

1 <= a.size(), b.size() <= 106
1 <= k <= a.size() + b.size()
0 <= a[i], b[i] < 108
*/

/*
Approach:
1. Use a two-pointer technique to find the k-th smallest element in the union of two sorted arrays `a` and `b`.
2. Perform a merge-like operation:
   - Compare the current elements of `a` and `b`.
   - Increment the pointer of the smaller element and decrement `k` until `k == 0`.
3. Handle remaining elements in either array if one array is exhausted before finding the k-th element.

Steps:
1. Initialize pointers `i` and `j` to traverse arrays `a` and `b`.
2. Traverse both arrays simultaneously, decrementing `k` for each element visited.
3. If one array is exhausted, continue traversing the other.
4. Return the k-th element when `k` reaches 0.

Time Complexity:
- O(k): The merge operation processes at most `k` elements.

Space Complexity:
- O(1): Constant space is used.

Edge Cases:
- `k = 1`: Return the minimum of the first elements of both arrays.
- One array is empty: Return the k-th element of the other array.
- `k` is larger than the combined size of both arrays (invalid input).

*/

class Solution {
public:
    int kthElement(vector<int>& a, vector<int>& b, int k) {
        int n = a.size(), m = b.size();
        int i = 0, j = 0; // Pointers for arrays `a` and `b`

        // Perform a merge-like operation to find the k-th element
        while (i < n && j < m) {
            if (a[i] <= b[j]) {
                if (--k == 0) return a[i]; // Return k-th element from `a`
                i++; // Move the pointer in `a`
            } else {
                if (--k == 0) return b[j]; // Return k-th element from `b`
                j++; // Move the pointer in `b`
            }
        }

        // If there are remaining elements in `a`
        while (i < n) {
            if (--k == 0) return a[i];
            i++;
        }

        // If there are remaining elements in `b`
        while (j < m) {
            if (--k == 0) return b[j];
            j++;
        }

        return -1; // This case will never be reached if `k` is valid
    }
};