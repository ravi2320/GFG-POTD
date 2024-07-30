/*
Rat in a Maze Problem - I
Difficulty: MediumAccuracy: 35.75%Submissions: 271K+Points: 4
Consider a rat placed at (0, 0) in a square matrix mat of order n* n. It has to reach the destination at (n - 1, n - 1). Find all possible paths that the rat can take to reach from source to destination. The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). Value 0 at a cell in the matrix represents that it is blocked and rat cannot move to it while value 1 at a cell in the matrix represents that rat can be travel through it.
Note: In a path, no cell can be visited more than one time. If the source cell is 0, the rat cannot move to any other cell. In case of no path, return an empty list. The driver will output "-1" automatically.

Examples:

Input: mat[][] = [[1, 0, 0, 0],
                [1, 1, 0, 1], 
                [1, 1, 0, 0],
                [0, 1, 1, 1]]
Output: DDRDRR DRDDRR
Explanation: The rat can reach the destination at (3, 3) from (0, 0) by two paths - DRDDRR and DDRDRR, when printed in sorted order we get DDRDRR DRDDRR.
Input: mat[][] = [[1, 0],
                [1, 0]]
Output: -1
Explanation: No path exists and destination cell is blocked.
Expected Time Complexity: O(3n^2)
Expected Auxiliary Space: O(l * x)
Here l = length of the path, x = number of paths.

Constraints:
2 ≤ n ≤ 5
0 ≤ mat[i][j] ≤ 1
*/

/*
Intuition:
The problem is to find all possible paths from the top-left corner to the bottom-right corner in a matrix, moving only through cells containing '1'. The solution uses Depth First Search (DFS) to explore all possible paths, ensuring to mark cells as visited to avoid cycles. Backtracking is employed to explore different paths from each cell.

Time Complexity:
The time complexity is O(4^(n*n)), where n is the size of the matrix. This is because from each cell, we can move in 4 possible directions (left, right, up, down), and potentially, all cells could be part of a path.

Space Complexity:
The space complexity is O(n*n) for the recursion stack in the worst case and the space used to store the result and temporary path string.

*/

class Solution {
public:
    vector<string> result; // To store all the paths found

    // Helper function to perform DFS and find paths
    void help(int i, int j, vector<vector<int>> &mat, int n, string &temp) {
        // Boundary checks and if the current cell is a wall or visited
        if (i < 0 || i >= n || j < 0 || j >= n || mat[i][j] == 0) {
            return;
        }

        // If the destination cell is reached
        if (i == n - 1 && j == n - 1) {
            result.push_back(temp);
            return;
        }

        // Mark the cell as visited
        mat[i][j] = 0;

        // Move Left
        temp.push_back('L');
        help(i, j - 1, mat, n, temp);
        temp.pop_back(); // Backtrack

        // Move Right
        temp.push_back('R');
        help(i, j + 1, mat, n, temp);
        temp.pop_back(); // Backtrack

        // Move Up
        temp.push_back('U');
        help(i - 1, j, mat, n, temp);
        temp.pop_back(); // Backtrack

        // Move Down
        temp.push_back('D');
        help(i + 1, j, mat, n, temp);
        temp.pop_back(); // Backtrack

        // Unmark the cell as visited (backtracking)
        mat[i][j] = 1;
    }

    // Function to find all paths from the top-left to the bottom-right corner
    vector<string> findPath(vector<vector<int>> &mat) {
        if (mat[0][0] == 0) return {}; // If starting cell is blocked, return empty result

        int n = mat.size();
        string path = "";

        // Start DFS from the top-left corner
        help(0, 0, mat, n, path);

        return result;
    }
};
