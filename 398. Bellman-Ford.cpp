/*
Bellman-Ford
Difficulty: MediumAccuracy: 48.11%Submissions: 184K+Points: 4Average Time: 25m
Given an weighted graph with V vertices numbered from 0 to V-1 and E edges, represented by a 2d array edges[][], where edges[i] = [u, v, w] represents a direct edge from node u to v having w edge weight. You are also given a source vertex src.

Your task is to compute the shortest distances from the source to all other vertices. If a vertex is unreachable from the source, its distance should be marked as 108. Additionally, if the graph contains a negative weight cycle, return [-1] to indicate that shortest paths cannot be reliably computed.

Examples:

Input: V = 5, edges[][] = [[1, 3, 2], [4, 3, -1], [2, 4, 1], [1, 2, 1], [0, 1, 5]], src = 0

Output: [0, 5, 6, 6, 7]
Explanation: Shortest Paths:
For 0 to 1 minimum distance will be 5. By following path 0 → 1
For 0 to 2 minimum distance will be 6. By following path 0 → 1  → 2
For 0 to 3 minimum distance will be 6. By following path 0 → 1  → 2 → 4 → 3 
For 0 to 4 minimum distance will be 7. By following path 0 → 1  → 2 → 4
Input: V = 4, edges[][] = [[0, 1, 4], [1, 2, -6], [2, 3, 5], [3, 1, -2]], src = 0

Output: [-1]
Explanation: The graph contains a negative weight cycle formed by the path 1 → 2 → 3 → 1, where the total weight of the cycle is negative.
Constraints:
1 ≤ V ≤ 100
1 ≤ E = edges.size() ≤ V*(V-1)
-1000 ≤ w ≤ 1000
0 ≤ src < V
*/

/*
Intuition:
----------
The Bellman-Ford algorithm is used to find the shortest path from a source node to all other nodes in a graph, 
even when the graph contains negative weight edges. Unlike Dijkstra’s algorithm, it can handle such edges safely.

Approach:
---------
- Initialize the distance of all vertices from the source as infinity (or a large number like 1e8), except the source which is 0.
- Relax all edges V-1 times (where V is the number of vertices).
- In each relaxation step, update the distance of a vertex if a shorter path is found via any edge.
- After all relaxation steps, check once more for negative weight cycles by trying to relax the edges again.
- If any distance can still be updated, it indicates a negative weight cycle, so return {-1}.

Time Complexity:
----------------
O(V * E), where V is the number of vertices and E is the number of edges.

Space Complexity:
-----------------
O(V), for storing the distance array.
*/

class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        vector<int> dist(V, 1e8);  // Initialize distances with large number
        dist[src] = 0;

        // Relax all edges V-1 times
        for(int i = 0; i < V - 1; i++) {
            for(auto &edge : edges) {
                int u = edge[0];
                int v = edge[1];
                int wt = edge[2];

                if(dist[u] != 1e8 && dist[u] + wt < dist[v]) {
                    dist[v] = dist[u] + wt;
                }
            }
        }

        // Check for negative weight cycles
        for(auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            if(dist[u] != 1e8 && dist[u] + wt < dist[v]) {
                return {-1}; // Negative weight cycle detected
            }
        }

        return dist;
    }
};
