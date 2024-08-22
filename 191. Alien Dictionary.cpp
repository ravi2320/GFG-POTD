/*
Alien Dictionary
Difficulty: HardAccuracy: 47.81%Submissions: 120K+Points: 8
Given a sorted dictionary of an alien language having N words and k starting alphabets of standard dictionary. Find the order of characters in the alien language.
Note: Many orders may be possible for a particular test case, thus you may return any valid order and output will be 1 if the order of string returned by the function is correct else 0 denoting incorrect string returned.

Examples :

Input:  n = 5, k = 4, dict = {"baa","abcd","abca","cab","cad"}
Output: 1
Explanation: Here order of characters is 'b', 'd', 'a', 'c' Note that words are sorted and in the given language "baa" comes before "abcd", therefore 'b' is before 'a' in output.
Similarly we can find other orders.
Input: n = 3, k = 3, dict = {"caa","aaa","aab"}
Output: 1
Explanation: Here order of characters is 'c', 'a', 'b' Note that words are sorted and in the given language "caa" comes before "aaa", therefore 'c' is before 'a' in output.
Similarly we can find other orders.
Expected Time Complexity: O(n * |s| + k)
Expected Auxillary Space: O(k)

Constraints:
1 ≤ n≤ 104
1 ≤ k ≤ 26
1 ≤ Length of words ≤ 50
*/

/*
Intuition:
- The problem involves determining the order of characters (or alphabet) from a given dictionary of alien words. This is a classic problem of finding the order of characters in a Directed Acyclic Graph (DAG), where the vertices represent characters and edges represent the precedence relation.
- To solve this, we construct a graph where each character is a node, and an edge from character 'A' to 'B' signifies that 'A' comes before 'B' in the alien language.
- After constructing the graph, a topological sort gives us the order of characters.

Time Complexity:
- The time complexity is `O(V + E)`, where `V` is the number of unique characters (26 in the English alphabet, represented by `k` here), and `E` is the number of edges in the graph. This is because we are performing a depth-first search (DFS) on the graph to find the topological order.

Space Complexity:
- The space complexity is `O(V + E)` for storing the adjacency list and the stack used in DFS. Additionally, the visited array and the final result string contribute to the space complexity.

*/

class Solution {
public:
    // Function to perform DFS and push nodes to the stack once all adjacent nodes are visited
    void dfs(int node, int vis[], stack<int> &st, vector<int> adj[]) {
        vis[node] = 1; // Mark the node as visited
        
        for(auto itr : adj[node]) {
            if(!vis[itr]) { // If the adjacent node is not visited, do a DFS on it
                dfs(itr, vis, st, adj);
            }
        }
        
        st.push(node); // Push the current node to the stack after all its neighbors are visited
    }
    
    // Function to perform topological sort using DFS
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
  
    // Function to find the order of characters in the alien dictionary
    string findOrder(string dict[], int n, int k) {
        vector<int> adj[k]; // Adjacency list for the graph
        
        // Build the graph by comparing adjacent words in the dictionary
        for(int i = 0; i < n - 1; i++) {
            string str1 = dict[i];
            string str2 = dict[i + 1];
            int len = min(str1.length(), str2.length());
            
            // Compare characters of the two words to determine the order
            for(int ptr = 0; ptr < len; ptr++) {
                if(str1[ptr] != str2[ptr]) {
                    adj[str1[ptr] - 'a'].push_back(str2[ptr] - 'a');
                    break; // Stop after finding the first difference
                }
            }
        }
        
        // Perform topological sort on the graph
        vector<int> topo = topoSort(k, adj);
        
        // Convert the topological sort result to the final order string
        string ans;
        for(int &x : topo) {
            ans.push_back(x + 'a'); // Convert integer node to corresponding character
        }
        
        return ans;
    }
};
