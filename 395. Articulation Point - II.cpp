/*
Articulation Point - II
Difficulty: HardAccuracy: 55.15%Submissions: 12K+Points: 8Average Time: 30m
You are given an undirected graph with V vertices and E edges. The graph is represented as a 2D array edges[][], where each element edges[i] = [u, v] indicates an undirected edge between vertices u and v.
Your task is to return all the articulation points (or cut vertices) in the graph.
An articulation point is a vertex whose removal, along with all its connected edges, increases the number of connected components in the graph.

Note: The graph may be disconnected, i.e., it may consist of more than one connected component.
If no such point exists, return {-1}.

Examples :

Input: V = 5, edges[][] = [[0, 1], [1, 4], [4, 3], [4, 2], [2, 3]]

Output: [1, 4]
Explanation: Removing the vertex 1 or 4 will disconnects the graph as-
   
Input: V = 4, edges[][] = [[0, 1], [0, 2]]
Output: [0]
Explanation: Removing the vertex 0 will increase the number of disconnected components to 3.  
Constraints:
1 ≤ V, E ≤ 104
*/

/*
Approach:
- Use DFS to assign discovery and low times to each node.
- For each node, if there exists a child where low[child] >= tin[node] and node is not root,
  then it's an articulation point.
- If the node is root and has more than 1 child, it's also an articulation point.

Time Complexity: O(V + E)
Space Complexity: O(V + E) for graph, O(V) for aux arrays (tin, low, vis, mark)
*/

class Solution {
    int timer = 1;

public:
    void dfs(int node, int parent, vector<int> &low, vector<int> &tin,
             vector<int> &vis, unordered_map<int, vector<int>> &adj, vector<int> &mark) {

        vis[node] = 1;
        tin[node] = low[node] = timer++;

        int child = 0;

        for (int &ngbr : adj[node]) {
            if (ngbr == parent) continue;

            if (!vis[ngbr]) {
                dfs(ngbr, node, low, tin, vis, adj, mark);
                low[node] = min(low[node], low[ngbr]);

                // Articulation condition for non-root
                if (low[ngbr] >= tin[node] && parent != -1) {
                    mark[node] = 1;
                }
                child++;
            } else {
                // Back edge
                low[node] = min(low[node], tin[ngbr]);
            }
        }

        // Articulation condition for root
        if (parent == -1 && child > 1) {
            mark[node] = 1;
        }
    }

    vector<int> articulationPoints(int V, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;

        // Building undirected graph
        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> low(V, -1), tin(V, -1);
        vector<int> mark(V, 0), vis(V, 0);

        // Call DFS for all components
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, -1, low, tin, vis, adj, mark);
            }
        }

        vector<int> ans;
        for (int i = 0; i < V; i++) {
            if (mark[i]) ans.push_back(i);
        }

        // No articulation point found
        if (ans.empty()) return {-1};

        return ans;
    }
};
