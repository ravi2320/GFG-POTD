/*
Max DAG Edges

avatar
Discuss Approach
arrow-up
Difficulty: MediumAccuracy: 80.4%Submissions: 1K+Points: 4
Given a directed acyclic graph (DAG) with V vertices numbered from 0 to V-1 and E edges, represented as a 2D array edges[][], where each entry edges[i] = [u, v] denotes a directed edge from vertex u to vertex v, find the maximum number of additional edges that can be added to the graph without forming any cycles.

Note: The resulting graph must remain a DAG, meaning that adding any further edge would not create a cycle.

Examples:

Input: V = 3, E = 2, edges[][] = [[0, 1], [1, 2]]
Output: 1
Explanation: The given DAG allows one more edge, 0 -> 2, which keeps the structure acyclic. Adding anything else would create a cycle.
Input: V = 4, E = 4, edges[][] = [[0, 1], [0, 2], [1, 2], [2, 3]]
Output: 2
Explanation: Two additional edges (0 -> 3, 1 -> 3) can be added without forming cycles.
Constraints:
1 ≤ V ≤ 103
0 ≤ E ≤ (V*(V-1))/2
0 ≤ edges[i][0], edges[i][1] < V
*/


// Intuition:
// The problem asks us to find the maximum number of edges we can add to a graph while keeping it connected.
// Given V vertices, the maximum number of edges in a simple undirected graph is (V * (V-1)) / 2,
// which is the total number of edges in a complete graph. The number of edges already present in the graph is provided as input.
// To find the number of edges we can still add, we subtract the number of existing edges from the maximum possible edges.

// Time Complexity:
// The solution only requires a constant amount of operations: calculating the total edges and subtracting the current edges.
// Thus, the time complexity is O(1).

// Space Complexity:
// We are only using a constant amount of extra space (a few variables), so the space complexity is O(1).

class Solution {
public:
    // Function to calculate the maximum number of edges that can be added
    int maxEdgesToAdd(int V, vector<vector<int>>& edges) {
        // Step 1: Calculate the number of edges already present in the graph
        int given_edges = edges.size();
        
        // Step 2: Calculate the maximum number of edges possible in a complete graph with V vertices
        int total_edges_form = (V * (V-1)) / 2;
        
        // Step 3: Return the difference between the maximum possible edges and the current edges
        return total_edges_form - given_edges;
    }
};
