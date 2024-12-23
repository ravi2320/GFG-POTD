/*
Search in a row-wise sorted matrix
Difficulty: EasyAccuracy: 52.55%Submissions: 10K+Points: 2
Given a row-wise sorted 2D matrix mat[][] of size n x m and an integer x, find whether element x is present in the matrix.
Note: In a row-wise sorted matrix, each row is sorted in itself, i.e. for any i, j within bounds, mat[i][j] <= mat[i][j+1].

Examples :

Input: mat[][] = [[3, 4, 9],[2, 5, 6],[9, 25, 27]], x = 9
Output: true
Explanation: 9 is present in the matrix, so the output is true.
Input: mat[][] = [[19, 22, 27, 38, 55, 67]], x = 56
Output: false
Explanation: 56 is not present in the matrix, so the output is false.
Input: mat[][] = [[1, 2, 9],[65, 69, 75]], x = 91
Output: false
Explanation: 91 is not present in the matrix.
Constraints:
1 <= n, m <= 1000
1 <= mat[i][j] <= 105
1 <= x <= 105
*/

/*
Approach:
This solution is for searching a number `x` in a row-column sorted matrix. The algorithm leverages binary search within rows to efficiently locate the target.

Steps:
1. Traverse each row sequentially.
2. For each row:
   - Check if the target `x` is within the range of that row (i.e., greater than or equal to the first element and less than or equal to the last element).
   - If it is, apply binary search to find `x` in that row.
3. If the element is found in any row, return `true`.
4. If all rows are traversed without finding `x`, return `false`.

Time Complexity:
- O(n * log(m)): Each row is checked with a binary search, which takes O(log(m)), and there are `n` rows.

Space Complexity:
- O(1): No additional space is used.

Edge Cases:
1. Single-element matrix.
2. Element `x` not in the matrix.
3. Element `x` present at the start or end of a row.

*/

class Solution {
public:
    // Function to search a given number in row-column sorted matrix.
    bool searchRowMatrix(vector<vector<int>> &mat, int x) {
        int n = mat.size(), m = mat[0].size();

        for (int i = 0; i < n; i++) { // Traverse each row
            // Check if x could be in the current row
            if (mat[i][0] <= x && x <= mat[i][m - 1]) {
                int low = 0, high = m - 1;

                // Apply binary search in the row
                while (low <= high) {
                    int mid = (low + high) / 2;

                    if (mat[i][mid] == x) {
                        return true; // Element found
                    } else if (mat[i][mid] < x) {
                        low = mid + 1; // Move to the right half
                    } else {
                        high = mid - 1; // Move to the left half
                    }
                }
            }
        }

        return false; // Element not found in any row
    }
};