/*
Minimum Operations to Connect Hospitals

You are given an undirected network of V hospitals numbered from 0 to V - 1, represented as a 2D array edges[][], where each element edges[i] = [u, v] denotes a direct connection between hospital u and hospital v.
In one operation, you are allowed to remove any existing link and reconnect it between two hospitals that are currently not directly or indirectly connected.

Your task is to determine the minimum number of operations required to make sure that all hospitals become connected, either directly or indirectly, using the given links.


Note: If it is impossible to connect all hospitals into a single network, return -1.

Examples:

Input: V = 4, E = 3, edges[][] = [[0, 1], [0, 2], [1, 2]]
Output: 1
Explanation: Remove the connection between hospitals 1 and 2 and connect the hospitals 1 and 3.

Input: V = 5, E = 4, edges[][] = [[0, 1], [0, 2], [2, 3], [3, 4]]
Output: 0
Explanation: All hospitals are already connected directly or indirectly. No rearrangement of connections is required.

Constraints:
1 ≤ V ≤ 103
0 ≤ E ≤ V*(V-1)/2
0 ≤ edges[i][0], edges[i][1] < V
*/

// Intuition:
// - The problem is asking for the minimum number of edges required to make a graph connected, given a list of edges.
// - We need to first check if the graph is already connected. If not, the answer will be impossible, and we return -1.
// - If the graph is not connected, the minimum number of edges to add is the number of disconnected components minus 1 (to connect them all together).

// Approach:
// - Create an adjacency list to represent the graph using a `unordered_map<int, vector<int>>`.
// - Use a Depth-First Search (DFS) to traverse the graph and identify disconnected components. Each time we encounter an unvisited node, we increment the count of required components.
// - The minimum edges required to connect the components is simply the number of components - 1 (because you need one less edge than the number of components to connect them all).

// Time Complexity:
// - Building the adjacency list takes O(E), where E is the number of edges.
// - The DFS traversal of all nodes and edges takes O(V + E), where V is the number of vertices and E is the number of edges.
// So, the overall time complexity is O(V + E).

// Space Complexity:
// - The space complexity is O(V + E) due to the adjacency list and the visited array.

class Solution {
public:
    // Helper function to perform DFS on the graph
    void dfs(int node, unordered_map<int, vector<int>> &adj, vector<int> &visited) {
        // If the node is already visited, there's nothing to do
        if(visited[node]) {
            return;
        }
        
        // Mark the current node as visited
        visited[node] = 1;
        
        // Traverse all neighbors of the current node
        for(auto &ngbr : adj[node]) {
            // If a neighbor is not visited, perform DFS on it
            if(visited[ngbr] == 0) {
                dfs(ngbr, adj, visited);
            }
        }
    }

    // Function to find the minimum number of edges to connect the graph
    int minConnect(int V, vector<vector<int>>& edges) {
        int n = edges.size();
        
        // If there are not enough edges to connect all nodes, return -1
        if(n < V - 1) {
            return -1;
        }
        
        // Create an adjacency list to represent the graph
        unordered_map<int, vector<int>> adj;
        for(auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        // Vector to track visited nodes
        vector<int> visited(V, 0);
        
        // Variable to count the number of connected components
        int req = 0;
        
        // Loop through all nodes to identify disconnected components
        for(int i = 0; i < V; i++) {
            // If the node is not visited, perform DFS starting from this node
            if(visited[i] == 0) {
                dfs(i, adj, visited);
                req++;  // Increment the number of components
            }
        }
        
        // To connect all components, we need req-1 edges
        return req - 1;
    }
};
