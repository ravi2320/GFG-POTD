/*
Find the number of islands
Difficulty: MediumAccuracy: 42.12%Submissions: 203K+Points: 4
Given a grid of size n*m (n is the number of rows and m is the number of columns in the grid) consisting of '0's (Water) and '1's(Land). Find the number of islands.

Note: An island is either surrounded by water or the boundary of a grid and is formed by connecting adjacent lands horizontally or vertically or diagonally i.e., in all 8 directions.

Examples:

Input: grid = [[0,1],[1,0],[1,1],[1,0]]
Output: 1
Explanation:
The grid is-

All lands are connected.
Input: grid = [[0,1,1,1,0,0,0],[0,0,1,1,0,1,0]]
Output: 2
Expanation:
The grid is-
 
There are two islands :- one is colored in "blue" and other in "red".
Expected Time Complexity: O(n*m)
Expected Space Complexity: O(n*m)

Constraints:
1 ≤ n, m ≤ 500
grid[i][j] = {'0', '1'}
*/

/*
Approach:
1. **Depth First Search (DFS)**:
   - The function `dfs` is used to mark all parts of an island (connected '1's) as visited by converting them to '0'. 
   - It recursively explores all 8 directions (left, right, up, down, and diagonals) from a given cell in the grid.

2. **Counting Islands**:
   - In the `numIslands` function, we iterate through each cell of the grid.
   - If we find a '1' (part of an island), we initiate a DFS from that cell to mark the entire island as visited and increment the island count.

Time Complexity:
- The time complexity is **O(n * m)**, where `n` is the number of rows and `m` is the number of columns. Each cell is visited at most once during the DFS traversal.

Space Complexity:
- The space complexity is **O(n * m)** due to the recursion stack for DFS in the worst case where the entire grid is an island.

*/

class Solution {
  public:
    // Helper function to perform DFS on the grid
    void dfs(int i, int j, vector<vector<char>> &grid, int n, int m) {
        // Base case: if out of bounds or the current cell is '0', return
        if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == '0') {
            return;
        }
        
        // Mark the current cell as visited by setting it to '0'
        grid[i][j] = '0';
        
        // Explore all 8 possible directions (left, right, up, down, and diagonals)
        dfs(i, j - 1, grid, n, m); // Left
        dfs(i - 1, j, grid, n, m); // Up
        dfs(i + 1, j, grid, n, m); // Down
        dfs(i, j + 1, grid, n, m); // Right
        dfs(i - 1, j - 1, grid, n, m); // Upper-left diagonal
        dfs(i - 1, j + 1, grid, n, m); // Upper-right diagonal
        dfs(i + 1, j - 1, grid, n, m); // Lower-left diagonal
        dfs(i + 1, j + 1, grid, n, m); // Lower-right diagonal
    }

    // Function to count the number of islands in the grid
    int numIslands(vector<vector<char>>& grid) {
        int islandCount = 0; // Initialize island count
        int n = grid.size();  // Number of rows
        int m = grid[0].size(); // Number of columns
        
        // Loop through each cell of the grid
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // If the current cell is '1', start DFS and count it as an island
                if (grid[i][j] == '1') {
                    dfs(i, j, grid, n, m);
                    islandCount++;  // Increment the island count after completing DFS
                }
            }
        }
        
        return islandCount;  // Return the total number of islands found
    }
};
