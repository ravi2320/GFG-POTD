/*
DFS of Graph
Difficulty: EasyAccuracy: 63.07%Submissions: 327K+Points: 2Average Time: 5m
Given a connected undirected graph represented by a 2-d adjacency list adj[][], where each adj[i] represents the list of vertices connected to vertex i. Perform a Depth First Search (DFS) traversal starting from vertex 0, visiting vertices from left to right as per the given adjacency list, and return a list containing the DFS traversal of the graph.

Note: Do traverse in the same order as they are in the given adjacency list.

Examples:

Input: adj[][] = [[2, 3, 1], [0], [0, 4], [0], [2]]

Output: [0, 2, 4, 3, 1]
Explanation: Starting from 0, the DFS traversal proceeds as follows:
Visit 0 → Output: 0 
Visit 2 (the first neighbor of 0) → Output: 0, 2 
Visit 4 (the first neighbor of 2) → Output: 0, 2, 4 
Backtrack to 2, then backtrack to 0, and visit 3 → Output: 0, 2, 4, 3 
Finally, backtrack to 0 and visit 1 → Final Output: 0, 2, 4, 3, 1
Input: adj[][] = [[1, 2], [0, 2], [0, 1, 3, 4], [2], [2]]

Output: [0, 1, 2, 3, 4]
Explanation: Starting from 0, the DFS traversal proceeds as follows: 
Visit 0 → Output: 0 
Visit 1 (the first neighbor of 0) → Output: 0, 1 
Visit 2 (the first neighbor of 1) → Output: 0, 1, 2 
Visit 3 (the first neighbor of 2) → Output: 0, 1, 2, 3 
Backtrack to 2 and visit 4 → Final Output: 0, 1, 2, 3, 4
Constraints:
1 ≤ adj.size() ≤ 104
1 ≤ adj[i][j] ≤ 104
*/

/*
Approach:
1. **Convert Adjacency List to HashMap**: Store the graph as an adjacency list using an unordered map.
2. **Depth-First Search (DFS)**: 
   - Start traversal from node 0.
   - Use a recursive function to visit all connected nodes.
   - Mark visited nodes to avoid cycles.
   - Store nodes in the result vector in the order they are visited.

Intuition:
- DFS explores as deep as possible along each branch before backtracking.
- The visited array ensures we do not visit the same node multiple times.
- Using an adjacency map makes accessing neighbors efficient.

Time Complexity: **O(V + E)** - Visiting all vertices and edges once.
Space Complexity: **O(V + E)** - Storing the adjacency list and visited array.
*/

class Solution {
  public:
    void dfsHelper(int currNode, unordered_map<int, vector<int>> &adjMap, 
                   vector<int> &res, vector<bool> &visited) {
        // Store the current node in the result
        res.push_back(currNode);
        visited[currNode] = true;

        // Visit all unvisited adjacent nodes
        for (int &node : adjMap[currNode]) {
            if (!visited[node]) {
                dfsHelper(node, adjMap, res, visited);
            }
        }
    }

    vector<int> dfs(vector<vector<int>>& adj) {
        int n = adj.size();
        unordered_map<int, vector<int>> adjMap;

        // Step 1: Convert adjacency list to unordered_map
        for (int i = 0; i < n; i++) {
            for (int &node : adj[i]) {
                adjMap[i].push_back(node);
            }
        }

        vector<int> res;
        vector<bool> visited(n, false);

        // Step 2: Perform DFS starting from node 0
        dfsHelper(0, adjMap, res, visited);

        return res;
    }
};
