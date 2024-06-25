/*
Left Rotate Matrix K times
Difficulty: MediumAccuracy: 41.89%Submissions: 26K+Points: 4
You are given an integer k and matrix mat. Rotate the elements of the given matrix to the left k times and return the resulting matrix.

Examples:

Input: k=1, mat=[[1,2,3],[4,5,6],[7,8,9]]
Output:
2 3 1
5 6 4
8 9 7
Explanation: Rotate the matrix by one
1 2 3       2 3 1
4 5 6  =>  5 6 4
7 8 9       8 9 7
Input: k=2, mat=[[1,2,3],[4,5,6],[7,8,9]]
Output:
3 1 2
6 4 5
9 7 8
Explanation: After rotating the matrix looks like
1 2 3       2 3 1       3 1 2
4 5 6  =>  5 6 4  =>   6 4 5
7 8 9       8 9 7       9 7 8
Expected Time Complexity: O(n*m)
Expected Auxillary Space: O(n*m)

Constraints:
1<= mat.size, mat[0].size, mat[i][j] <=1000
1<=k<=10000
*/

/*
Intuition:
- The task is to rotate each row of the given matrix to the right by k positions.
- Using modulo operation helps in managing the rotation efficiently.

Time Complexity:
- O(n * m): We traverse each element of the matrix once.

Space Complexity:
- O(n * m): We use an additional matrix of the same size as the input matrix.

Approach:
1. Determine the dimensions of the matrix (n rows and m columns).
2. Calculate the effective rotation by taking k modulo m.
3. Create a new matrix `ans` to store the rotated rows.
4. For each element in the matrix, calculate its new position after rotation and place it in the `ans` matrix.
5. Return the `ans` matrix as the result.
*/

class Solution {
public:
    vector<vector<int>> rotateMatrix(int k, vector<vector<int>> mat) {
        // Determine the dimensions of the matrix
        int n = mat.size();
        int m = mat[0].size();
        
        // Calculate effective rotations
        k = k % m;
        if (k == 0) return mat;
        
        // Create a new matrix to store the result
        vector<vector<int>> ans(n, vector<int>(m));
        
        // Rotate each row
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans[i][(j + k) % m] = mat[i][j];
            }
        }
        
        return ans;
    }
};