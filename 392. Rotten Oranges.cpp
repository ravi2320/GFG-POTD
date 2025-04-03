/*
Rotten Oranges
Difficulty: MediumAccuracy: 46.02%Submissions: 166K+Points: 4Average Time: 20m
Given a matrix mat[][] of dimension n * m where each cell in the matrix can have values 0, 1 or 2 which has the following meaning:
0 : Empty cell
1 : Cell have fresh oranges
2 : Cell have rotten oranges

We have to determine what is the earliest time after which all the oranges are rotten. A rotten orange at index (i, j) can rot other fresh orange at indexes (i-1, j), (i+1, j), (i, j-1), (i, j+1) (up, down, left and right) in a unit time.

Note: Your task is to return the minimum time to rot all the fresh oranges. If not possible returns -1.

Examples:

Input: mat[][] = [[0, 1, 2], [0, 1, 2], [2, 1, 1]]
Output: 1
Explanation: Oranges at positions (0,2), (1,2), (2,0) will rot oranges at (0,1), (1,1), (2,2) and (2,1) in unit time.
Input: mat[][] = [[2, 2, 0, 1]]
Output: -1
Explanation: Oranges at (0,0) and (0,1) can't rot orange at (0,3).
Input: mat[][] = [[2, 2, 2], [0, 2, 0]]
Output: 0
Explanation: There is no fresh orange. 
Constraints:
1 ≤ mat.size() ≤ 500
1 ≤ mat[0].size() ≤ 500
mat[i][j] = {0, 1, 2} 
*/

/*
Approach:
1. **Identify rotten and fresh oranges**:
   - Traverse the grid to count total oranges.
   - Push initial rotten oranges into the queue for BFS.

2. **Perform BFS to rot adjacent fresh oranges**:
   - Use a queue to track rotten oranges and process them level by level.
   - For each rotten orange, rot its 4-directional neighbors (up, down, left, right).

3. **Track time and check completion**:
   - Maintain a `total_time` counter.
   - If all oranges rot, return the time taken; otherwise, return `-1`.

Intuition:
- BFS ensures that oranges rot in the correct order, simulating real-life spread.

Time Complexity: **O(N × M)** - Each cell is processed at most once.  
Space Complexity: **O(N × M)** - Worst case, all oranges are in the queue.
*/

class Solution {
  public:
    int orangesRotting(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        int total_oranges = 0, rotten_oranges = 0;
        queue<pair<int, int>> q;

        // Step 1: Count total oranges and enqueue rotten ones
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 1 || mat[i][j] == 2) 
                    total_oranges++;
                if (mat[i][j] == 2) 
                    q.push({i, j});
            }
        }

        if (total_oranges == 0) return 0; // No oranges to rot

        vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
        int total_time = 0;

        // Step 2: BFS to rot adjacent fresh oranges
        while (!q.empty()) {
            int size = q.size();
            rotten_oranges += size;
            total_time++;

            for (int k = 0; k < size; k++) {
                int i = q.front().first, j = q.front().second;
                q.pop();

                for (auto &dir : directions) {
                    int ni = i + dir[0], nj = j + dir[1];

                    if (ni >= 0 && nj >= 0 && ni < n && nj < m && mat[ni][nj] == 1) {
                        mat[ni][nj] = 2; // Rot the orange
                        q.push({ni, nj});
                    }
                }
            }
        }

        // Step 3: Check if all oranges are rotten
        return total_oranges == rotten_oranges ? total_time - 1 : -1;
    }
};
