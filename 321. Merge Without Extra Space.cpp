/*
Merge Without Extra Space
Difficulty: HardAccuracy: 32.01%Submissions: 269K+Points: 8
Given two sorted arrays a[] and b[] of size n and m respectively, the task is to merge them in sorted order without using any extra space. Modify a[] so that it contains the first n elements and modify b[] so that it contains the last m elements.

Examples:

Input: a[] = [2, 4, 7, 10], b[] = [2, 3]
Output:
2 2 3 4
7 10
Explanation: After merging the two non-decreasing arrays, we get, 2 2 3 4 7 10
Input: a[] = [1, 5, 9, 10, 15, 20], b[] = [2, 3, 8, 13]
Output:
1 2 3 5 8 9
10 13 15 20
Explanation: After merging two sorted arrays we get 5 10 12 18 20.
Input: a[] = [0, 1], b[] = [2, 3]
Output:
0 1
2 3
Explanation: After merging two sorted arrays we get 0 1 2 3.
Constraints:
1 <= a.size(), b.size() <= 105
0 <= a[i], b[i] <= 107
*/

/*
Approach:
1. Use two pointers to iterate through arrays `a` and `b`.
2. Traverse `a` from the end and `b` from the beginning, swapping elements that are out of order.
3. After all necessary swaps, sort both arrays individually to ensure they are in non-decreasing order.

Steps:
- Start pointers at the appropriate ends (`i = n - 1` for `a`, `j = 0` for `b`).
- Swap elements if the element in `a` is greater than the element in `b`.
- Increment or decrement the pointers accordingly.
- Finally, sort both arrays.

Time Complexity:
- O(min(n, m)): For swapping elements in the worst case.
- O(n log n + m log m): For sorting arrays `a` and `b`.
- Overall: O(n log n + m log m).

Space Complexity:
- O(1): In-place swapping and sorting do not use extra space.

Edge Cases:
- One array is empty.
- Both arrays are already sorted and do not require any changes.

*/

class Solution {
  public:
    void mergeArrays(vector<int>& a, vector<int>& b) {
        int n = a.size(), m = b.size();
        int i = n - 1, j = 0;

        // Perform swapping if elements in `a` and `b` are out of order
        while (i >= 0 && j < m) {
            if (a[i] <= b[j]) {
                break; // Arrays are already sorted relative to each other
            }
            swap(a[i--], b[j++]); // Swap and move pointers
        }

        // Sort both arrays to finalize the merge
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
    }
};
