/*
Shortest path in Undirected Graph
Difficulty: MediumAccuracy: 49.98%Submissions: 88K+Points: 4
You are given an Undirected Graph having unit weight of the edges, find the shortest path from src to all the vertex and if it is unreachable to reach any vertex, then return -1 for that vertex.

Examples :

Input:
n = 9, m = 10
edges=[[0,1],[0,3],[3,4],[4,5],[5,6],[1,2],[2,6],[6,7],[7,8],[6,8]] 
src=0
Output:
0 1 2 1 2 3 3 4 4

Input:
n = 4, m = 2
edges=[[1,3],[3,0]] 
src=3
Output:
1 1 -1 0

Constraint:
1<=n,m<=104
0<=edges[i][j]<=n-1

Expected Time Complexity: O(N + E), where N is the number of nodes and E is the edges
Expected Space Complexity: O(N)
*/

/*
Intuition:
- The problem is about finding the shortest path from a source node to all other nodes in an unweighted graph. 
- Since the graph is unweighted, the Breadth-First Search (BFS) is the optimal approach for finding the shortest path. 
- BFS explores nodes layer by layer (i.e., all nodes at distance 1, then all nodes at distance 2, etc.), ensuring that the shortest path to each node is found first.

Time Complexity:
- The time complexity is `O(N + M)`, where `N` is the number of nodes, and `M` is the number of edges. This is because each node and edge is processed exactly once during the BFS traversal.

Space Complexity:
- The space complexity is `O(N + M)` for storing the adjacency list and `O(N)` for the distance array and BFS queue.

*/

class Solution {
public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N, int M, int src) {
        // Create an adjacency list for the graph
        unordered_map<int, vector<int>> adj;
        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u); // Since the graph is undirected, add both directions
        }
        
        vector<int> dist(N, INT_MAX); // Distance array initialized to a large value (INT_MAX)
        dist[src] = 0; // Distance to the source is 0
        
        queue<int> q; // Queue for BFS
        q.push(src); // Start BFS from the source node
        
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            
            // Traverse all the neighbors of the current node
            for (auto &ngbr : adj[node]) {
                
                // If a shorter path to the neighbor is found, update the distance
                if (dist[node] + 1 < dist[ngbr]) {
                    dist[ngbr] = dist[node] + 1;
                    q.push(ngbr); // Add the neighbor to the queue for further exploration
                }
            }
        }
        
        // If any node is unreachable (i.e., distance is still INT_MAX), set its distance to -1
        for (int i = 0; i < N; i++) {
            if (dist[i] == INT_MAX) {
                dist[i] = -1;
            }
        }
        
        return dist; // Return the distance array
    }
};
