/*
Topological sort
Difficulty: MediumAccuracy: 56.52%Submissions: 229K+Points: 4
Given an adjacency list for a Directed Acyclic Graph (DAG) where adj_list[i] contains a list of all vertices j such that there is a directed edge from vertex i to vertex j, with  V  vertices and E  edges, your task is to find any valid topological sorting of the graph.

 

In a topological sort, for every directed edge u -> v,  u must come before v in the ordering.

 

Example 1:

Input:

Output:
1
Explanation:
The output 1 denotes that the order is
valid. So, if you have, implemented
your function correctly, then output
would be 1 for all test cases.
One possible Topological order for the
graph is 3, 2, 1, 0.
Example 2:

Input:

Output:
1
Explanation:
The output 1 denotes that the order is
valid. So, if you have, implemented
your function correctly, then output
would be 1 for all test cases.
One possible Topological order for the
graph is 5, 4, 2, 1, 3, 0.
Your Task:
You don't need to read input or print anything. Your task is to complete the function topoSort()  which takes the integer V denoting the number of vertices and adjacency list as input parameters and returns an array consisting of the vertices in Topological order. As there are multiple Topological orders possible, you may return any of them. If your returned topo sort is correct then the console output will be 1 else 0.

Expected Time Complexity: O(V + E).
Expected Auxiliary Space: O(V).

Constraints:
2 ≤ V ≤ 104
1 ≤ E ≤ (N*(N-1))/2
*/

/*
Intuition:
- Topological sorting of a Directed Acyclic Graph (DAG) is a linear ordering of its vertices such that for every directed edge `u -> v`, vertex `u` comes before `v` in the ordering.
- The idea is to use Depth-First Search (DFS). When visiting a node, after all its adjacent nodes have been visited, the node is pushed onto a stack. Finally, popping from the stack gives the topological order.

Time Complexity:
- The time complexity is `O(V + E)`, where `V` is the number of vertices and `E` is the number of edges in the graph. This is because each vertex and edge is visited exactly once during the DFS traversal.

Space Complexity:
- The space complexity is `O(V + E)` for storing the adjacency list and the stack used in DFS. Additionally, the visited array and the result vector contribute to the space complexity.
*/

class Solution {
public:
    // Helper function to perform DFS and push nodes onto the stack once all adjacent nodes are visited
    void dfs(int node, int vis[], stack<int> &st, vector<int> adj[]) {
        vis[node] = 1; // Mark the node as visited
        
        // Traverse all adjacent vertices
        for(auto itr : adj[node]) {
            if(!vis[itr]) { // If the adjacent node is not visited, perform DFS on it
                dfs(itr, vis, st, adj);
            }
        }
        
        // After visiting all adjacent nodes, push the current node onto the stack
        st.push(node);
    }
    
    // Function to return a list containing vertices in Topological order
    vector<int> topoSort(int V, vector<int> adj[]) {
        int vis[V] = {0}; // Visited array to keep track of visited nodes
        stack<int> st; // Stack to store the topological order
        
        // Perform DFS from every unvisited node
        for(int i = 0; i < V; i++) {
            if(!vis[i]) {
                dfs(i, vis, st, adj);
            }
        }
        
        vector<int> ans; // Vector to store the topological sort result
        
        // Pop nodes from the stack to get the topological order
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        
        return ans;
    }
};
