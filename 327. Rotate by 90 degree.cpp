/*
Rotate by 90 degree
Difficulty: EasyAccuracy: 56.88%Submissions: 99K+Points: 2
Given a square matrix mat[][] of size n x n. The task is to rotate it by 90 degrees in an anti-clockwise direction without using any extra space. 

Examples:

Input: mat[][] = [[1, 2, 3],
                [4, 5, 6]
                [7, 8, 9]]
Output: Rotated Matrix:
[3, 6, 9]
[2, 5, 8]
[1, 4, 7]
Input: mat[][] = [[1, 2],
                [3, 4]]
Output: Rotated Matrix:
[2, 4]
[1, 3]
Constraints:
1 ≤ n ≤ 102
0 <= mat[i][j] <= 103
*/

/*
Approach:
To rotate a matrix by 90 degrees anticlockwise:
1. Reverse each row of the matrix. This operation mirrors the matrix horizontally.
2. Transpose the matrix, swapping elements symmetrically around its diagonal.

Steps:
1. Iterate through each row and reverse its elements.
2. Perform the transpose of the matrix by swapping `mat[i][j]` with `mat[j][i]` for `i < j`.

Time Complexity:
- O(n^2): Two passes over the matrix:
  - O(n^2) to reverse all rows.
  - O(n^2) to transpose the matrix.

Space Complexity:
- O(1): Transformation is done in place.

Edge Cases:
- 1x1 matrix.
- Empty matrix (no rotation needed).

*/

class Solution {
public:
    // Function to rotate matrix anticlockwise by 90 degrees.
    void rotateby90(vector<vector<int>>& mat) {
        int n = mat.size();
        
        // Step 1: Reverse each row.
        for (int i = 0; i < n; i++) {
            reverse(mat[i].begin(), mat[i].end());
        }
        
        // Step 2: Transpose the matrix.
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(mat[i][j], mat[j][i]);
            }
        }
    }
};
