/*
Toeplitz matrix
Difficulty: MediumAccuracy: 49.05%Submissions: 21K+Points: 4
A Toeplitz (or diagonal-constant) matrix is a matrix in which each descending diagonal from left to right is constant, i.e., all elements in a diagonal are the same. Given a rectangular matrix mat, your task is to complete the function isToeplitz which returns true if the matrix is Toeplitz otherwise, it returns false.

Examples:

Input:
mat = [[6, 7, 8],
       [4, 6, 7],
       [1, 4, 6]]
Output: true
Explanation: The test case represents a 3x3 matrix
 6 7 8 
 4 6 7 
 1 4 6
Output will be true, as values in all downward diagonals from left to right contain the same elements.
Input: 
mat = [[1,2,3],
       [4,5,6]]
Output: false
Explanation: Matrix of order 2x3 will be 1 2 3 4 5 6 Output: false as values in all diagonals are not the same.
Constraints:
1<=mat.size,mat[0].size<=40
0<=mat[i][j]<=100

Expected time complexity: O(n*m)
Expected space complexity: O(1)


*/

/**
 * Intuition:
 * - A matrix is Toeplitz if every diagonal from top-left to bottom-right has the same elements.
 * - To verify this, we need to check each diagonal starting from the first row and then each diagonal starting from the first column.

 * Time Complexity: O(n * m)
 * - We iterate through each element of the matrix once to check the diagonals.

 * Space Complexity: O(1)
 * - We use a constant amount of extra space.

 * @param mat: a 2D vector representing the matrix
 * @return: true if the matrix is Toeplitz, otherwise false
 */

bool isToeplitz(vector<vector<int>>& mat) {
    int n = mat.size();
    int m = mat[0].size();
    
    // Check diagonals starting from the first row
    for (int i = 0; i < m; i++) {
        int val = mat[0][i];
        int x = 1, y = i + 1;
        while (x < n && y < m) {
            if (mat[x][y] != val) {
                return false;
            }
            x++;
            y++;
        }
    }
    
    // Check diagonals starting from the first column
    for (int i = 1; i < n; i++) { // Start from 1 to avoid re-checking the first diagonal
        int val = mat[i][0];
        int x = i + 1, y = 1;
        while (x < n && y < m) {
            if (mat[x][y] != val) {
                return false;
            }
            x++;
            y++;
        }
    }
    
    return true;
}

/**
 * Intuition:
 * - A matrix is Toeplitz if every diagonal from top-left to bottom-right has the same elements.
 * - We only need to check each element with the one just above and to the left of it.

 * Time Complexity: O(n * m)
 * - We iterate through each element of the matrix once.

 * Space Complexity: O(1)
 * - We use a constant amount of extra space.

 * @param mat: a 2D vector representing the matrix
 * @return: true if the matrix is Toeplitz, otherwise false
 */

bool isToeplitz(vector<vector<int>>& mat) {
    int n = mat.size();
    int m = mat[0].size();

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (mat[i][j] != mat[i - 1][j - 1]) {
                return false;
            }
        }
    }

    return true;
}
