/*
BFS of graph
Difficulty: EasyAccuracy: 44.09%Submissions: 474K+Points: 2Average Time: 10m
Given a connected undirected graph containing V vertices, represented by a 2-d adjacency list adj[][], where each adj[i] represents the list of vertices connected to vertex i. Perform a Breadth First Search (BFS) traversal starting from vertex 0, visiting vertices from left to right according to the given adjacency list, and return a list containing the BFS traversal of the graph.

Note: Do traverse in the same order as they are in the given adjacency list.

Examples:

Input: adj[][] = [[2, 3, 1], [0], [0, 4], [0], [2]]

Output: [0, 2, 3, 1, 4]
Explanation: Starting from 0, the BFS traversal will follow these steps: 
Visit 0 → Output: 0 
Visit 2 (first neighbor of 0) → Output: 0, 2 
Visit 3 (next neighbor of 0) → Output: 0, 2, 3 
Visit 1 (next neighbor of 0) → Output: 0, 2, 3, 
Visit 4 (neighbor of 2) → Final Output: 0, 2, 3, 1, 4
Input: adj[][] = [[1, 2], [0, 2], [0, 1, 3, 4], [2], [2]]

Output: [0, 1, 2, 3, 4]
Explanation: Starting from 0, the BFS traversal proceeds as follows: 
Visit 0 → Output: 0 
Visit 1 (the first neighbor of 0) → Output: 0, 1 
Visit 2 (the next neighbor of 0) → Output: 0, 1, 2 
Visit 3 (the first neighbor of 2 that hasn't been visited yet) → Output: 0, 1, 2, 3 
Visit 4 (the next neighbor of 2) → Final Output: 0, 1, 2, 3, 4
Constraints:
1 ≤ V = adj.size() ≤ 104
1 ≤ adj[i][j] ≤ 104
*/

/*
Approach:
1. **Use a queue for BFS traversal**:
   - Start from node `0` (assuming the graph is 0-indexed).
   - Push the node into the queue and mark it as visited.

2. **Iterate until the queue is empty**:
   - Dequeue a node, add it to the result list.
   - Visit all its adjacent nodes that haven’t been visited yet, mark them visited, and push them into the queue.

Intuition:
- BFS explores all nodes at the current level before moving to the next level.
- The queue ensures nodes are processed in the correct order.

Time Complexity: **O(V + E)** - Each node and edge is processed once.  
Space Complexity: **O(V)** - To store the queue and visited nodes.
*/

class Solution {
  public:
    // Function to return Breadth First Traversal of the given graph.
    vector<int> bfs(vector<vector<int>> &adj) {
        int n = adj.size();  // Number of nodes
        queue<int> q;  // Queue for BFS
        vector<int> res;  // Stores BFS traversal order
        vector<bool> visited(n, false);  // Visited array

        // Start BFS from node 0
        q.push(0);
        visited[0] = true;

        while (!q.empty()) {
            int node = q.front();  // Get the front node
            q.pop();

            res.push_back(node);  // Add node to result

            // Process all adjacent nodes
            for (int &curr : adj[node]) {
                if (!visited[curr]) {  
                    visited[curr] = true;  // Mark as visited
                    q.push(curr);  // Push into queue
                }
            }
        }

        return res;  // Return BFS traversal order
    }
};