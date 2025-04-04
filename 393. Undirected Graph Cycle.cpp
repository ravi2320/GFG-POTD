/*
Undirected Graph Cycle
Difficulty: MediumAccuracy: 30.13%Submissions: 546K+Points: 4Average Time: 20m
Given an undirected graph with V vertices and E edges, represented as a 2D vector edges[][], where each entry edges[i] = [u, v] denotes an edge between vertices u and v, determine whether the graph contains a cycle or not.

Examples:

Input: V = 4, E = 4, edges[][] = [[0, 1], [0, 2], [1, 2], [2, 3]]
Output: true
Explanation: 
 
1 -> 2 -> 0 -> 1 is a cycle.
Input: V = 4, E = 3, edges[][] = [[0, 1], [1, 2], [2, 3]]
Output: false
Explanation: 
 
No cycle in the graph.
Constraints:
1 ≤ V ≤ 105
1 ≤ E = edges.size() ≤ 105
*/

/*
Approach:
1. **Graph Representation**:
   - Construct an adjacency list using an unordered map.

2. **Depth-First Search (DFS) for Cycle Detection**:
   - Use a `visited` array to track visited nodes.
   - Maintain a `parent` parameter to avoid counting backward edges as cycles.
   - If we visit an already visited node that is not the parent, a cycle exists.

3. **Iterate Over Components**:
   - Since the graph may be disconnected, check all unvisited nodes.

Intuition:
- DFS explores the graph deeply and detects back edges, which indicate a cycle.

Time Complexity: **O(V + E)** (Each node and edge is visited once).  
Space Complexity: **O(V + E)** (Adjacency list + visited array + recursion stack).
*/

class Solution {
  public:
    // Helper DFS function to detect cycle
    bool dfs(int node, int parent, unordered_map<int, vector<int>> &adj, vector<bool> &visited) {
        visited[node] = true;

        for (int &ngbr : adj[node]) {
            if (ngbr == parent) continue;  // Ignore the parent node

            if (visited[ngbr]) return true;  // Found a back edge, cycle detected

            if (dfs(ngbr, node, adj, visited)) return true;
        }

        return false;
    }

    // Main function to check if a cycle exists in the graph
    bool isCycle(int V, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        vector<bool> visited(V, false);

        // Step 1: Build the adjacency list
        for (auto &edge : edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // Step 2: Check for cycles in each component
        for (int u = 0; u < V; u++) {
            if (!visited[u] && dfs(u, -1, adj, visited)) {
                return true;  // Cycle found
            }
        }

        return false;  // No cycle detected
    }
};

/*
Approach:
1. **Graph Representation**:
   - Construct an adjacency list using an unordered map.

2. **Breadth-First Search (BFS) for Cycle Detection**:
   - Use a queue to implement BFS and track (node, parent) pairs.
   - If we revisit a node that is **not the parent**, it means a cycle exists.

3. **Iterate Over Components**:
   - Since the graph may be disconnected, check all unvisited nodes.

Intuition:
- BFS explores nodes level by level, maintaining a queue to track the parent.
- If a node is found in the queue that was already visited and is **not the parent**, a cycle exists.

Time Complexity: **O(V + E)** (Each node and edge is visited once).  
Space Complexity: **O(V + E)** (Adjacency list + visited array + queue storage).
*/

class Solution {
  public:
    // Helper BFS function to detect cycle
    bool bfs(int node, unordered_map<int, vector<int>> &adj, vector<bool> &visited) {
        queue<pair<int, int>> q;
        q.push({node, -1});
        visited[node] = true;

        while (!q.empty()) {
            int currNode = q.front().first;
            int parent = q.front().second;
            q.pop();

            for (int &ngbr : adj[currNode]) {
                if (ngbr == parent) continue;  // Ignore parent node

                if (visited[ngbr]) return true;  // Found a cycle

                visited[ngbr] = true;
                q.push({ngbr, currNode});
            }
        }

        return false;
    }

    // Main function to check if a cycle exists in the graph
    bool isCycle(int V, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        vector<bool> visited(V, false);

        // Step 1: Build the adjacency list
        for (auto &edge : edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // Step 2: Check for cycles in each component
        for (int u = 0; u < V; u++) {
            if (!visited[u] && bfs(u, adj, visited)) {
                return true;  // Cycle found
            }
        }

        return false;  // No cycle detected
    }
};