/*
Replace O's with X's

avatar
Discuss Approach
arrow-up
Difficulty: MediumAccuracy: 34.0%Submissions: 129K+Points: 4Average Time: 20m
You are given a grid[][] of size n*m, where every element is either 'O' or 'X'. You have to replace all 'O' or a group of 'O' with 'X' that are surrounded by 'X'.

A 'O' (or a set of 'O') is considered to be surrounded by 'X' if there are 'X' at locations just below, just above, just left and just right of it.

Examples:

Input: 
grid[][] = [['X', 'X', 'X', 'X'], 
          ['X', 'O', 'X', 'X'], 
          ['X', 'O', 'O', 'X'], 
          ['X', 'O', 'X', 'X'], 
          ['X', 'X', 'O', 'O']]
Output: 
[['X', 'X', 'X', 'X'], 
['X', 'X', 'X', 'X'], 
['X', 'X', 'X', 'X'], 
['X', 'X', 'X', 'X'], 
['X', 'X', 'O', 'O']]
Explanation: We only changed those 'O' that are surrounded by 'X'
Input: 
grid[][] = [['X', 'O', 'X', 'X'], 
          ['X', 'O', 'X', 'X'], 
          ['X', 'O', 'O', 'X'], 
          ['X', 'O', 'X', 'X'], 
          ['X', 'X', 'O', 'O']]
Output: 
[['X', 'O', 'X', 'X'], 
['X', 'O', 'X', 'X'], 
['X', 'O', 'O', 'X'], 
['X', 'O', 'X', 'X'], 
['X', 'X', 'O', 'O']]
Explanation: There's no 'O' that's surround by 'X'.
Input: 
grid[][] = [['X', 'X', 'X'], 
          ['X', 'O', 'X'], 
          ['X', 'X', 'X']]
Output: 
[['X', 'X', 'X'], 
['X', 'X', 'X'], 
['X', 'X', 'X']]
Explanation: There's only one 'O' that's surround by 'X'.
Constraints:
1 ≤ grid.size() ≤ 100
1 ≤ grid[0].size() ≤ 100
*/

// Intuition:
// The goal is to convert all 'O's that are not connected to the boundary (either the first or last row or column)
// into 'X'. The 'O's that are connected to the boundary cannot be converted, as they are part of the unbounded region of 'O's.
// We can use DFS to mark all the 'O's connected to the boundary as visited. Once we have marked these, any 'O' 
// that is not visited will be surrounded by 'X's and should be converted.

// Time Complexity:
// The DFS function will visit each cell once. In the worst case, we might have to visit every cell in the grid, 
// which would take O(n * m) time where n is the number of rows and m is the number of columns. Hence, the overall 
// time complexity is O(n * m).

// Space Complexity:
// We use a 2D visited array of size n * m to keep track of the visited cells, which results in a space complexity 
// of O(n * m). Additionally, the recursion stack for DFS may go as deep as O(n * m) in the worst case, so the space
// complexity is also O(n * m) due to recursion stack and the visited array.

class Solution {
    // Directions array for 4 possible moves (right, down, left, up)
    vector<vector<int>> directions = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    
  public:
    // DFS function to mark all 'O's connected to the boundary
    void dfs(int i, int j, int n, int m, vector<vector<char>>& grid, vector<vector<int>> &visited){
        
        // If out of bounds, already visited, or cell is 'X', stop
        if(i < 0 || j < 0 || i >= n || j >= m || visited[i][j] == 1 || grid[i][j] == 'X')
            return;
        
        // Mark the current cell as visited
        visited[i][j] = 1;
        
        // Explore all four possible directions (up, down, left, right)
        for(auto dir : directions){
            int i_ = i + dir[0];
            int j_ = j + dir[1];
            
            // Recursively visit the neighboring cells
            dfs(i_, j_, n, m, grid, visited);
        }
    }

    // Main function to fill 'O's with 'X's except for those connected to the boundary
    void fill(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        
        // Create a 2D array to track visited cells
        vector<vector<int>> visited(n, vector<int>(m, 0));
        
        // Run DFS from all boundary cells (first and last rows, first and last columns)
        for(int i = 0; i < n; i++){
            // Check the first column
            if(grid[i][0] == 'O'){
                dfs(i, 0, n, m, grid, visited);
            }
            
            // Check the last column
            if(grid[i][m - 1] == 'O'){
                dfs(i, m - 1, n, m, grid, visited);
            }
        }
        
        for(int i = 0; i < m; i++){
            // Check the first row
            if(grid[0][i] == 'O'){
                dfs(0, i, n, m, grid, visited);
            }
            
            // Check the last row
            if(grid[n - 1][i] == 'O'){
                dfs(n - 1, i, n, m, grid, visited);
            }
        }
        
        // Now, go through the grid and replace unvisited 'O's with 'X'
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!visited[i][j]){
                    grid[i][j] = 'X'; // Convert 'O' to 'X' if not visited
                }
            }
        }
    }
};
