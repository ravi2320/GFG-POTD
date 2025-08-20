/*
Search in fully rotated sorted 2D matrix

avatar
Discuss Approach
arrow-up
Difficulty: MediumAccuracy: 56.77%Submissions: 11K+Points: 4Average Time: 20m
You are given a 2D matrix mat[][] of size n x m that was initially filled in the following manner:


Each row is sorted in increasing order from left to right.
The first element of every row is greater than the last element of the previous row.

This implies that if the matrix is flattened row-wise, it forms a strictly sorted 1D array.
Later, this sorted 1D array was rotated at some unknown pivot. The rotated array was then written back into the matrix row-wise to form the current matrix.


Given such a matrix mat[][] and an integer x, determine whether x exists in the matrix.


Examples:

Input: x = 3,
mat[][] = [[7, 8, 9, 10],           
          [11, 12, 13, 1],
          [2, 3, 4, 5]] 
Output: true
Explanation: 3 is located at the 3rd row and 2nd column.
Input: x = 10,
mat[][] = [[6, 7, 8],                         
          [9, 1, 2],
          [3, 4, 5]]
Output: false
Explanation: The value 10 does not exist in the matrix.
Constraint:
1 ≤ n × m ≤ 105
1 ≤ mat[i][j], x ≤ 106
*/

/*
Approach:
- We are given a sorted 2D matrix (rows and columns sorted).
- Instead of searching row by row, we can treat the matrix as a sorted 1D array of size m*n.
- Apply binary search on this virtual array, and convert the mid index back to (row, col) using:
    row = mid / n, col = mid % n.
- Compare mat[row][col] with x:
    - If equal → return true.
    - If smaller → move right (low = mid + 1).
    - If greater → move left (high = mid - 1).
- If loop ends without finding → return false.

Intuition:
- Since the matrix is sorted and can be viewed as a continuous sorted list, binary search ensures efficient searching.
- We avoid linear traversal and directly leverage sorted property.

Time Complexity: O(log(m*n))  
- Binary search over m*n elements.
Space Complexity: O(1)  
- No extra space used, only a few variables.
*/

class Solution {
  public:
    bool searchMatrix(vector<vector<int>> &mat, int x) {
        int m = mat.size(), n = mat[0].size();
        int low = 0, high = m * n - 1;  // treating as a flattened 1D array

        while(low <= high){
            int mid = low + (high - low) / 2;

            // Convert 1D index back to 2D coordinates
            int row = mid / n;
            int col = mid % n;

            if(mat[row][col] == x){
                return true;  // found the element
            }
            else if(mat[row][col] < x){
                low = mid + 1;  // search right half
            }
            else{
                high = mid - 1; // search left half
            }
        }
        return false;  // element not found
    }
};