/*
Kth Smallest Number in Multiplication Table
Difficulty: HardAccuracy: 50.15%Submissions: 13K+Points: 8
Given three integers m, n and k. Consider a grid of m * n, where mat[i][j] = i * j (1 based index). The task is to return the kth smallest element in the m * n multiplication table.

Examples :

Input: m = 3, n = 3, k = 5
Output: 3
Explanation: 

The 5th smallest element is 3. 
Input: m = 2, n = 3, k = 6
Output: 6 
Explanation: [1, 2, 3][2, 4, 6]. The 6th smallest element is 6.
Constraints:
1 <= m, n <= 3 * 104
1 <= k <= m * n
*/

/*
Approach:
- We use binary search to find the k-th smallest element in the m x n multiplication table.
- For a given value `mid`, we count how many elements in the table are ≤ mid.
- If that count is < k, it means the k-th smallest is larger, so we move right.
- Otherwise, we search the left half including mid.

Time Complexity:
- O(m * log(m * n)), where m and n are the table dimensions.
- For each binary search iteration, we compute count in O(m) time.

Space Complexity: O(1)
*/

class Solution {
public:
    // Counts how many numbers are ≤ ele in the multiplication table
    int elementLessThanMid(int ele, int m, int n) {
        int count = 0;

        // For each row i, the row contains: i, 2i, 3i, ..., ni
        for (int i = 1; i <= m; i++) {
            // Count of elements ≤ ele in row i is min(ele / i, n)
            count += min(ele / i, n);
        }

        return count;
    }

    int kthSmallest(int m, int n, int k) {
        int low = 1, high = m * n;

        // Binary search on the answer
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (elementLessThanMid(mid, m, n) < k) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return low;
    }
};
