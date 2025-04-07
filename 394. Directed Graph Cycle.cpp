/*
Directed Graph Cycle
Difficulty: MediumAccuracy: 27.88%Submissions: 464K+Points: 4
Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, check whether it contains any cycle or not.
The graph is represented as a 2D vector edges[][], where each entry edges[i] = [u, v] denotes an edge from verticex u to v.

Examples:

Input: V = 4, edges[][] = [[0, 1], [1, 2], [2, 3], [3, 3]]



Output: true
Explanation: 3 -> 3 is a cycle
Input: V = 3, edges[][] = [[0, 1], [1, 2]]



Output: false
Explanation: no cycle in the graph
Constraints:
1 ≤ V, E ≤ 105


*/

/*
Approach:
1. We use **DFS with recursion tracking** to detect cycles in a **directed graph**.
2. For each node, we:
   - Mark it visited.
   - Mark it as currently in the recursion stack (`inRecursion`).
   - For each neighbor:
     - If it hasn't been visited, recursively DFS it.
     - If it **is in the recursion stack**, a cycle is detected.
3. Once DFS on the node is complete, remove it from the recursion stack.

Intuition:
- In a **directed graph**, a cycle exists if we visit a node that’s already in the current DFS recursion path.

Time Complexity: **O(V + E)**  
Space Complexity: **O(V + E)**  
- `V` is number of vertices.
- `E` is number of edges.
- `visited[]` and `inRecursion[]` take O(V) space, and the adjacency list uses O(E) space.
*/

class Solution {
  public:
    // DFS helper to detect cycle
    bool isCycleDFS(int node, unordered_map<int, vector<int>> &adj, vector<bool> &visited, vector<bool> &inRecursion) {
        visited[node] = true;
        inRecursion[node] = true;

        // Explore all neighbors
        for (int &ngbr : adj[node]) {
            if (!visited[ngbr] && isCycleDFS(ngbr, adj, visited, inRecursion)) {
                return true;
            }
            else if (inRecursion[ngbr]) {
                // Found a back edge -> cycle
                return true;
            }
        }

        inRecursion[node] = false; // Backtrack
        return false;
    }

    // Main function to detect cycle in directed graph
    bool isCyclic(int V, vector<vector<int>> &edges) {
        unordered_map<int, vector<int>> adj;

        // Build adjacency list from edge list
        for (auto &edge : edges) {
            adj[edge[0]].push_back(edge[1]);
        }

        vector<bool> visited(V, false);
        vector<bool> inRecursion(V, false);

        // Check each component
        for (int u = 0; u < V; u++) {
            if (!visited[u] && isCycleDFS(u, adj, visited, inRecursion)) {
                return true;
            }
        }

        return false;
    }
};
