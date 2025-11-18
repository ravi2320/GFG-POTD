/*
Number of Ways to Arrive at Destination

avatar
Discuss Approach
arrow-up
Difficulty: MediumAccuracy: 61.13%Submissions: 85K+Points: 4Average Time: 30m
You are given an undirected weighted graph with V vertices numbered from 0 to V-1 and E edges, represented as a 2D array edges[][], where edges[i] = [ui, vi, timei] means that there is an undirected edge between nodes ui and vi that takes timei minutes to reach.
Your task is to return in how many ways you can travel from node 0 to node V - 1 in the shortest amount of time.

Examples:

Input: V = 4, edges[][] = [[0, 1, 2], [1, 2, 3], [0, 3, 5], [1, 3, 3], [2, 3, 4]]
    
Output: 2
Explanation: The shortest path from 0 to 3 is 5.
Two ways to reach 3 in 5 minutes are:
0 -> 3
0 -> 1 -> 3
Input: V = 6, edges[][] = [[0, 2, 3], [0, 4, 2], [0, 5, 7], [2, 3, 1], [2, 5, 5], [5, 3, 3], [5, 1, 4], [1, 4, 1], [4, 5, 5]]
    
Output: 4
Explanation: The shortest path from 0 to 5 is 7.
Four ways to reach 5 in 7 minutes are:
0 -> 5
0 -> 4 -> 5
0 -> 4 -> 1 -> 5
0 -> 2 -> 3 -> 5
Constraints:
1 ≤ V ≤ 200
V - 1 ≤ edges.size() ≤ V * (V - 1) / 2
0 ≤ ui, vi ≤ V - 1
1 ≤ timei ≤ 105
ui != vi
*/

    /**
     * Intuition:
     * This problem is essentially about finding the number of shortest paths from node 0 to node V-1 
     * in a weighted undirected graph.
     * We will use a modified version of Dijkstra's algorithm to compute the shortest path distances.
     * Additionally, we will maintain a count of the number of ways to reach each node with the shortest path.

     * Approach:
     * 1. Use Dijkstra's algorithm to compute the shortest path distances from node 0 to all other nodes.
     * 2. While processing each node in the priority queue, keep track of the number of ways to reach each node.
     * 3. If a shorter path to a node is found, update the distance and set the count of ways to reach that node.
     * 4. If an equal path is found, add the number of ways to reach the current node to the count of ways to reach the neighbor.
     * 5. The result will be the number of shortest paths from node 0 to node V-1.

     * Time Complexity:
     * - Building the adjacency list: O(E), where E is the number of edges.
     * - Dijkstra's algorithm with a priority queue: O((V + E) * log(V)), where V is the number of vertices and E is the number of edges.
     * 
     * Overall complexity: O((V + E) * log(V))

     * Space Complexity:
     * - Adjacency list: O(V + E)
     * - Distance array (res): O(V)
     * - Path count array (pathCount): O(V)
     * 
     * Overall space complexity: O(V + E)
     */


class Solution {
    // Pair to store (distance, node)
    typedef pair<long long, int> P;
    // Modulo value to avoid overflow
    int mod = 1e9+7;
  
  public:
    int countPaths(int V, vector<vector<int>>& edges) {
        // Adjacency list to store the graph as an undirected graph
        unordered_map<int, vector<pair<int, int>>> adj;
        
        // Build the graph
        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
        
        // Min-heap (priority queue) to store the nodes with their current shortest path distance
        priority_queue<P, vector<P>, greater<P>> minQ;
        
        // Array to store the shortest path distances from the source node 0
        vector<int> res(V, 1e9);  // Initialize all distances as infinity (large number)
        
        // Array to store the number of shortest paths to each node
        vector<int> pathCount(V, 0);
        
        // Start from node 0, initial distance is 0, and there is 1 way to reach node 0
        minQ.push({0, 0});
        res[0] = 0;
        pathCount[0] = 1;
        
        // Dijkstra's algorithm loop
        while (!minQ.empty()) {
            // Extract the node with the smallest current distance
            int time = minQ.top().first;
            int node = minQ.top().second;
            minQ.pop();
            
            // Explore the neighbors of the current node
            for (auto &ngbr : adj[node]) {
                int currTime = ngbr.second;  // weight of the edge to the neighbor
                int currNode = ngbr.first;   // neighbor node
                
                // If a shorter path to currNode is found
                if (time + currTime < res[currNode]) {
                    res[currNode] = time + currTime;
                    minQ.push({res[currNode], currNode});
                    pathCount[currNode] = pathCount[node];  // Reset the count to the current node's count
                }
                // If an equal-length path to currNode is found
                else if (time + currTime == res[currNode]) {
                    pathCount[currNode] = (pathCount[currNode] + pathCount[node]) % mod;
                }
            }
        }
        
        // Return the number of shortest paths to node V-1 (the destination)
        return pathCount[V-1];
    }
};
