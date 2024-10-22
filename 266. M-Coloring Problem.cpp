/*
M-Coloring Problem
Difficulty: MediumAccuracy: 34.42%Submissions: 135K+Points: 4
You are given an undirected graph consisting of v vertices and a list of edges, along with an integer m. Your task is to determine whether it is possible to color the graph using at most m different colors such that no two adjacent vertices share the same color. Return true if the graph can be colored with at most m colors, otherwise return false.

Note: The graph is indexed with 0-based indexing.

Examples:

Input: v = 4, edges[] = [(0,1),(1,2),(2,3),(3,0),(0,2)], m = 3
Output: true
Explanation: It is possible to color the given graph using 3 colors, for example, vertices can be colored as follows:
Vertex 0: Color 1
Vertex 1: Color 2
Vertex 2: Color 3
Vertex 3: Color 1
Input: v = 3, edges[] = [(0,1),(1,2),(0,2)], m = 2
Output: false
Explanation: It is not possible to color the given graph using only 2 colors because vertices 0, 1, and 2 form a triangle.
Expected Time Complexity: O(mV)
Expected Auxiliary Space: O(v2)

Constraints:
1 ≤ v ≤ 20
1 ≤ edges.size() ≤ (v*(v-1))/2
0 ≤ edges[i][j] ≤ n-1
1 ≤ m ≤ v
*/

/*
Approach:
This solution uses backtracking to solve the m-coloring problem in a graph. 
We represent the graph using an adjacency list, and then recursively try to assign colors to each vertex while ensuring no two adjacent vertices share the same color.

- `isSafe` checks if assigning a specific color to a vertex is valid by verifying that none of its adjacent vertices have the same color.
- `solve` is a recursive function that attempts to assign colors to vertices, backtracking if a valid color assignment is not possible.

Time Complexity: O(m^v), where 'v' is the number of vertices and 'm' is the number of colors. In the worst case, we may have to try all color combinations.
Space Complexity: O(v) for storing the color assignments.
*/

class Solution {
  public:
    // Function to check if it is safe to assign a color to the node
    bool isSafe(int node, unordered_map<int, vector<int>> &adj, vector<int> &color, int col) {
        for(auto &adjNode : adj[node]) {
            // If an adjacent node already has the same color, return false
            if(color[adjNode] == col)
                return false;
        }
        return true;
    }
    
    // Recursive function to solve the graph coloring problem
    bool solve(int node, int v, unordered_map<int, vector<int>> &adj, vector<int> &color, int m) {
        // Base case: if all vertices have been assigned a color, return true
        if(node == v) {
            return true;
        }
        
        // Try all possible colors for the current vertex
        for(int col = 1; col <= m; col++) {
            // Check if it is safe to color the current node with the current color
            if(isSafe(node, adj, color, col)) {
                // Assign the color to the current node
                color[node] = col;
                // Recursively color the next node
                if(solve(node + 1, v, adj, color, m)) {
                    return true;
                }
                // If coloring the next node is not possible, backtrack and try the next color
                color[node] = 0;
            }
        }
        
        // If no valid color assignment is possible for this node, return false
        return false;
    }
    
    // Main function to check if the graph can be colored with at most m colors
    bool graphColoring(int v, vector<pair<int, int>>& edges, int m) {
        // Create an adjacency list for the graph
        unordered_map<int, vector<int>> adj;
        for(auto &edge : edges) {
            int u = edge.first;
            int v = edge.second;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        // Initialize a color array to keep track of colors assigned to each vertex
        vector<int> color(v, 0);
        
        // Start the coloring process from the 0th node
        return solve(0, v, adj, color, m);
    }
};