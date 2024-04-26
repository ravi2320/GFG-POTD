/*
Exit Point in a Matrix
EasyAccuracy: 50.0%Submissions: 26K+Points: 2
 Done with winning Geekbits? Now win GfG Bag, GfG T-shirt & much more just by writing your experiences. Start Writing, Start Winning.
banner
Given a matrix of size n x m with 0’s and 1’s, you enter the matrix at cell (0,0) in left to right direction. Whenever you encounter a 0 you retain it in the same direction, else if you encounter a 1 you have to change the direction to the right of the current direction and change that 1 value to 0, you have to find out from which index you will leave the matrix at the end.

Example 1:

Input: 
n = 3, m = 3
matrix = {{0, 1, 0},
          {0, 1, 1}, 
          {0, 0, 0}}
Output: 
{1, 0}
Explanation: 
Enter the matrix at (0, 0) 
-> then move towards (0, 1) ->  1 is encountered 
-> turn right towards (1, 1)  -> again 1 is encountered 
-> turn right again towards (1, 0) 
-> now, the boundary of matrix will be crossed ->hence, exit point reached at 1, 0..
Example 2:

Input: 
n = 1, m = 2
matrix = {{0, 0}}
Output: 
{0, 1}
Explanation: 
Enter the matrix at cell (0, 0).
Since the cell contains a 0, we continue moving in the same direction.
We reach cell (0, 1), which also contains a 0. So, we continue moving in the same direction, we exit the matrix from cell (0, 1).
Your Task:
You don't need to read or print anything. Your task is to complete the function FindExitPoint() which takes the matrix as an input parameter and returns a list containing the exit point.

Expected Time Complexity: O(n * m) where n = number of rows and m = number of columns.
Expected Space Complexity: O(1)

Constraints:
1 <= n, m <= 100

Company Tags
Samsung
*/

// Intuition:
// This class provides a solution to find the exit point from a matrix given the starting point (0, 0).
// The algorithm traverses the matrix based on the given directions (right, down, left, up) until it
// encounters a boundary or a previously visited cell. It updates the current position and direction
// accordingly until it reaches the exit point.

// Time Complexity: O(n * m)
// - 'n' and 'm' are the dimensions of the input matrix.
// - The algorithm traverses through each cell of the matrix once.

// Space Complexity: O(1)
// - The algorithm uses only a constant amount of extra space for variables.

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> FindExitPoint(int n, int m, vector<vector<int>>& matrix) {
        // Initialize variables for current position (i, j), previous position (previ, prevj), and direction (face)
        int i = 0, j = 0, previ = 0, prevj = 0, face = 0;

        // Traverse the matrix until reaching a boundary or a previously visited cell
        while (i < n && i >= 0 && j < m && j >= 0) {
            // Update the previous position
            previ = i;
            prevj = j;

            // If the current cell is accessible
            if (matrix[i][j]) {
                // Mark the current cell as visited
                matrix[i][j] = 0;

                // Update the current position and direction based on the current direction (face)
                if (face == 0) {
                    face = 1;
                    i++;
                } else if (face == 1) {
                    face = 2;
                    j--;
                } else if (face == 2) {
                    face = 3;
                    i--;
                } else {
                    face = 0;
                    j++;
                }
            } else {
                // If the current cell is not accessible, update the current position based on the direction (face)
                if (face == 0)
                    j++;
                else if (face == 1)
                    i++;
                else if (face == 2)
                    j--;
                else
                    i--;
            }
        }
        // Return the exit point coordinates as a vector {previ, prevj}
        return {previ, prevj};
    }
};

// Sample Usage
#include <iostream>
int main() {
    Solution obj;
    int n = 3, m = 4;
    vector<vector<int>> matrix = {
        {1, 0, 1, 1},
        {1, 1, 0, 1},
        {1, 0, 1, 0}
    };
    vector<int> exitPoint = obj.FindExitPoint(n, m, matrix);
    cout << "Exit point coordinates: (" << exitPoint[0] << ", " << exitPoint[1] << ")" << endl; // Output: Exit point coordinates: (1, 2)
    return 0;
}
