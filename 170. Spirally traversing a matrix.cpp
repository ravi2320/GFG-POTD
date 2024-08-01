/*
Spirally traversing a matrix
Difficulty: MediumAccuracy: 35.2%Submissions: 264K+Points: 4
You are given a rectangular matrix, and your task is to return an array while traversing the matrix in spiral form.

Examples:

Input: matrix[][] = [[1, 2, 3, 4],
                  [5, 6, 7, 8],
                  [9, 10, 11, 12],
                  [13, 14, 15,16]]
Output: [1, 2, 3, 4, 8, 12, 16, 15, 14, 13, 9, 5, 6, 7, 11, 10]
Explanation:

Input: matrix[][] = [[1, 2, 3, 4],
                  [5, 6, 7, 8],
                  [9, 10, 11, 12]]
Output: [1, 2, 3, 4, 8, 12, 11, 10, 9, 5, 6, 7]
Explanation: Applying same technique as shown above, output for the 2nd testcase will be 1 2 3 4 8 12 11 10 9 5 6 7.
Expected Time Complexity: O(n2)
Expected Auxiliary Space: O(n2)

Constraints:
1 <= matrix.size(), matrix[0].size() <= 100
0 <= matrix[i][j]<= 100
*/

/*
Intuition:
The problem requires traversing a 2D matrix in a spiral order. The idea is to maintain four boundaries (left, right, top, and bottom) and traverse the matrix in four directions: left to right, top to bottom, right to left, and bottom to top. After traversing one boundary, we adjust the boundaries accordingly and continue until all elements are traversed.

Time Complexity:
The time complexity is O(m * n), where m is the number of rows and n is the number of columns in the matrix. This is because each element of the matrix is visited exactly once.

Space Complexity:
The space complexity is O(1) if we exclude the space required for the output list `ans`. The output list will contain all the elements of the matrix, so its space complexity is O(m * n).

*/

class Solution {
public:
    vector<int> spirallyTraverse(vector<vector<int>>& matrix) {
        int n = matrix.size();      // Number of rows
        int m = matrix[0].size();   // Number of columns
        int left = 0;               // Initialize left boundary
        int right = m - 1;          // Initialize right boundary
        int top = 0;                // Initialize top boundary
        int bottom = n - 1;         // Initialize bottom boundary
        vector<int> ans;            // Resultant vector to store spiral order elements

        // Continue traversing the matrix while there are elements left to visit
        while (left <= right && top <= bottom) {
            // Traverse from left to right along the top boundary
            for (int i = left; i <= right; i++) {
                ans.push_back(matrix[top][i]);
            }
            top++;  // Move the top boundary down

            // Traverse from top to bottom along the right boundary
            for (int i = top; i <= bottom; i++) {
                ans.push_back(matrix[i][right]);
            }
            right--;  // Move the right boundary left

            // Traverse from right to left along the bottom boundary, if there are remaining rows
            if (top <= bottom) {
                for (int i = right; i >= left; i--) {
                    ans.push_back(matrix[bottom][i]);
                }
                bottom--;  // Move the bottom boundary up
            }

            // Traverse from bottom to top along the left boundary, if there are remaining columns
            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    ans.push_back(matrix[i][left]);
                }
                left++;  // Move the left boundary right
            }
        }

        return ans;  // Return the resultant spiral order
    }
};
