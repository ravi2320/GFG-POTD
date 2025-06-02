/*
Unique Paths in a Grid
Difficulty: MediumAccuracy: 50.47%Submissions: 39K+Points: 4
You are given a 2d list grid[][] of size n x m consisting of values 0 and 1.
A value of 0 means that you can enter that cell and 1 implies that entry to that cell is not allowed.
You start at the upper-left corner of the grid (1, 1) and you have to reach the bottom-right corner (n, m) such that you can only move in the right or down direction from every cell.
Your task is to calculate the total number of ways of reaching the target.

Note: The first (1, 1) and last (n, m) cell of the grid can also be 1.
It is guaranteed that the total number of ways will fit within a 32-bit integer.

Examples:

Input: n = 3, m = 3,
grid[][] = [[0, 0, 0], [0, 1, 0], [0, 0, 0]]
Output: 2
Explanation: There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right
Input: n = 1, m = 3,
grid[][] = [[1, 0, 1]]
Output: 0
Explanation: There is no possible path to reach the end.
Constraints:
1 ≤ n*m ≤ 106
*/

/*
Approach:
- Use DFS with memoization (Top-Down DP) to count the number of unique paths from (0, 0) to (n-1, m-1).
- We can only move either right or down at any point, and we cannot move into a cell with an obstacle (grid[i][j] == 1).
- We recursively explore both directions and memoize the results in a dp table to avoid recomputation.

Intuition:
- From any cell (i, j), the number of ways to reach the bottom-right corner is the sum of the number of ways
  from the cell to the right and the cell below.
- If a path leads into an obstacle or out of bounds, it's invalid and returns 0.
- Use memoization to store results of overlapping subproblems.

Time Complexity: O(n * m)
- Each cell is visited at most once due to memoization.

Space Complexity: O(n * m)
- For the dp table and recursion stack in the worst case.
*/

class Solution {
    int n, m;
    // Directions: right and down
    vector<vector<int>> directions = {{0, 1}, {1, 0}};
    
public:
    // Helper function for memoized DFS
    int solve(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp) {
        // If we reach the bottom-right corner, it's one valid path
        if(i == n - 1 && j == m - 1)
            return 1;

        // If already computed, return memoized result
        if(dp[i][j] != -1)
            return dp[i][j];

        int ways = 0;
        // Explore both right and down directions
        for(auto &dir : directions) {
            int i_ = i + dir[0];
            int j_ = j + dir[1];

            // Check bounds and obstacle
            if(i_ >= 0 && i_ < n && j_ >= 0 && j_ < m && grid[i_][j_] == 0) {
                ways += solve(i_, j_, grid, dp);
            }
        }

        // Store result and return
        return dp[i][j] = ways;
    }

    int uniquePaths(vector<vector<int>> &grid) {
        n = grid.size();
        m = grid[0].size();

        // If the starting point is blocked, no path exists
        if(grid[0][0] == 1)
            return 0;

        // Initialize dp table with -1 (unvisited)
        vector<vector<int>> dp(n, vector<int>(m, -1));

        return solve(0, 0, grid, dp);
    }
};


/*
Approach:
- Use dynamic programming (bottom-up/tabulation) to count the number of unique paths from (0, 0) to (n-1, m-1).
- Initialize a DP table where dp[i][j] represents the number of ways to reach cell (i, j).
- Start from the top-left cell and fill in the table using values from the top and left neighbors,
  provided they are not obstacles (i.e., grid[i][j] != 1).

Intuition:
- We can only move right or down.
- If grid[i][j] is not an obstacle, then the number of ways to reach it is:
    dp[i][j] = dp[i-1][j] + dp[i][j-1] (if within bounds and no obstacle).
- The base case is dp[0][0] = 1 if it's not blocked.

Time Complexity: O(n * m)
- Every cell in the grid is visited once.

Space Complexity: O(n * m)
- For the dp table.
*/

class Solution {
public:
    int uniquePaths(vector<vector<int>> &grid) {
        int n = grid.size(), m = grid[0].size();

        // If the starting cell is blocked, return 0
        if(grid[0][0] == 1)
            return 0;

        // Initialize the dp table
        vector<vector<int>> dp(n, vector<int>(m, 0));
        dp[0][0] = 1;

        // Fill the dp table
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                // Skip if current cell is an obstacle
                if(grid[i][j] == 1) continue;

                // Add ways from the top cell if valid
                if(i > 0 && grid[i-1][j] == 0)
                    dp[i][j] += dp[i-1][j];

                // Add ways from the left cell if valid
                if(j > 0 && grid[i][j-1] == 0)
                    dp[i][j] += dp[i][j-1];
            }
        }

        // Return the number of ways to reach bottom-right corner
        return dp[n-1][m-1];
    }
};
