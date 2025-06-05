/*
Count the paths
Difficulty: MediumAccuracy: 42.71%Submissions: 38K+Points: 4Average Time: 10m
Given a Directed Acyclic Graph (DAG) with V nodes labeled from 0 to V-1, and a list of directed edges, count the total number of distinct paths from a given start node to a destination node. Each edge is represented as edges[i] = [u, v], indicating a directed edge from u to v.

Examples :

Input: edges[][] = [[0,1], [0,3], [2,0], [2,1], [1,3]], V = 4, src = 2, dest = 3
Output: 3
Explanation: There are three ways to reach at 3 from 2. These are: 2 -> 1 -> 3, 2 -> 0 -> 3 and 2 -> 0 -> 1 -> 3.
Print-all-paths-1
Input: edges[][] = [[0,1], [1,2], [1,3], [2,3]], V = 4, src = 0, dest = 3
Output: 2
Explanation: There is two way to reach at 3 from 0 that is : 0 -> 1 -> 2 -> 3 and 0 -> 1 -> 3.
Print-all-paths-2
Constraints:
2  ≤  V  ≤  103
1  ≤   E = edges.size()  ≤  (V * (V - 1)) / 2
*/

/*
Approach:
- This is a classic **DFS with Memoization** (Top-down DP) to count all paths from `src` to `dest` in a **DAG (Directed Acyclic Graph)**.
- We use an adjacency list to store the graph and a `dp[]` array to memoize the number of paths from each node to `dest`.

Intuition:
- For each node, the total number of paths to `dest` is the sum of paths from its neighbors to `dest`.
- If we’ve already computed the number of paths from a node, we reuse the result (memoization) to avoid recomputation.

Time Complexity: O(V + E)
- Each node is visited once and all its outgoing edges are traversed once due to memoization.

Space Complexity: O(V + E) for adjacency list and dp array
- `O(V)` for `dp`, `O(E)` for edges.
*/

class Solution {
  public:
    // Helper DFS function to count paths from `node` to `dest`
    int dfs(int node, vector<vector<int>> &adj, int dest, vector<int> &dp){
        // If reached the destination, one valid path is found
        if(node == dest){
            return 1;
        }

        // If already computed, return the memoized result
        if(dp[node] != -1){
            return dp[node];
        }

        int cnt = 0;
        // Traverse all neighbors of the current node
        for(auto &ngbr : adj[node]){
            cnt += dfs(ngbr, adj, dest, dp);
        }

        // Memoize and return
        return dp[node] = cnt;
    }

    int countPaths(vector<vector<int>>& edges, int V, int src, int dest) {
        // Build adjacency list from edge list
        vector<vector<int>> adj(V);

        for(auto &edge : edges){
            adj[edge[0]].push_back(edge[1]);
        }

        // Initialize dp array with -1 for memoization
        vector<int> dp(V, -1);

        // Start DFS from source
        return dfs(src, adj, dest, dp);
    }
};
