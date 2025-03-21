/*
Topological sort
Difficulty: MediumAccuracy: 56.52%Submissions: 269K+Points: 4Average Time: 15m
Given an adjacency list for a Directed Acyclic Graph (DAG) where adj[u] contains a list of all vertices v such that there exists a directed edge u -> v. Return topological sort for the given graph.

Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for every directed edge u -> v, vertex u comes before v in the ordering.
Note: As there are multiple Topological orders possible, you may return any of them. If your returned Topological sort is correct then the output will be 1 else 0.

Examples:

Input: adj = [[], [0], [0], [0]] 

Output: 1
Explanation: The output 1 denotes that the order is valid. Few valid Topological orders for the given graph are:
[3, 2, 1, 0]
[1, 2, 3, 0]
[2, 3, 1, 0]
Input: adj = [[], [3], [3], [], [0,1], [0,2]]

Output: 1
Explanation: The output 1 denotes that the order is valid. Few valid Topological orders for the graph are:
[4, 5, 0, 1, 2, 3]
[5, 2, 4, 0, 1, 3]
Constraints:
2  ≤  V  ≤  103
1  ≤  E  ≤  (V * (V - 1)) / 2
*/

// ---------------------------------------------------------
// 🚀 Approach, Intuition, Time & Space Complexity:
//
// Approach & Intuition:
// - Use **Kahn's Algorithm (BFS-based Topological Sort)**.
// - First, calculate the in-degree of every vertex.
// - Push all vertices with in-degree 0 into a queue.
// - Pop elements from the queue, add to result, and reduce in-degree of neighbors.
// - If in-degree becomes zero, push it into the queue.
// 
// Time Complexity: O(V + E)
// - V = number of vertices
// - E = number of edges (since we traverse all edges)
//
// Space Complexity: O(V + E)
// - Adjacency list: O(E)
// - In-degree array & result: O(V)
// - Queue storage: O(V)
// ---------------------------------------------------------

class Solution {
public:
    // Function to return list containing vertices in Topological order.
    vector<int> topologicalSort(vector<vector<int>>& adj) {
        int n = adj.size(); // Number of vertices
        
        // Step 1: Calculate in-degree of each vertex
        vector<int> indegree(n, 0);
        for (int u = 0; u < n; u++) {
            for (int &v : adj[u]) {
                indegree[v]++;
            }
        }
        
        // Step 2: Push vertices with in-degree 0 to the queue
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        
        // Step 3: Perform BFS
        vector<int> result;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            result.push_back(u); // Add current vertex to result
            
            // Decrease in-degree of all neighbors
            for (int &v : adj[u]) {
                indegree[v]--;
                if (indegree[v] == 0) {
                    q.push(v);
                }
            }
        }
        
        return result;
    }
};
