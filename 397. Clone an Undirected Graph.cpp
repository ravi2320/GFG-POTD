/*
Clone an Undirected Graph
Difficulty: MediumAccuracy: 67.49%Submissions: 35K+Points: 4
Given a connected undirected graph represented by adjacency list, adjList[][] with n nodes, having a distinct label from 0 to n-1, where each adj[i] represents the list of vertices connected to vertex i.

Create a clone of the graph, where each node in the graph contains an integer val and an array (neighbors) of nodes, containing nodes that are adjacent to the current node.

class Node {
    val: integer
    neighbors: List[Node]
}
Your task is to complete the function cloneGraph( ) which takes a starting node of the graph as input and returns the copy of the given node as a reference to the cloned graph.

Note: If you return a correct copy of the given graph, then the driver code will print true; and if an incorrect copy is generated or when you return the original node, the driver code will print false.

Examples :

Input: n = 4, adjList[][] = [[1, 2], [0, 2], [0, 1, 3], [2]]
Output: true
Explanation: 

As the cloned graph is identical to the original one the driver code will print true.
Input: n = 3, adjList[][] = [[1, 2], [0], [0]]
Output: true
Explanation: 

As the cloned graph is identical to the original one the driver code will print true.
Constraints:
1 ≤ n ≤ 104
0 ≤ no. of edges ≤ 105
0 ≤ adjList[i][j] < n
*/

/*
Intuition:
----------
To clone a graph, we need to create a deep copy such that each node and its edges are duplicated,
but without referencing any of the original graph nodes.

Approach:
---------
- Use DFS traversal to clone the graph.
- Maintain a hash map (unordered_map) to keep track of already cloned nodes.
  - Key: pointer to original node
  - Value: pointer to corresponding cloned node
- For each node:
  - If it hasn't been cloned yet, clone it and recursively visit all its neighbors.
  - If it's already cloned, just use the clone from the map.
- Start DFS from the given node.

Time Complexity:
----------------
O(N + E), where N = number of nodes and E = number of edges in the graph,
since each node and edge is visited exactly once.

Space Complexity:
-----------------
O(N), for the hashmap to store already created clones.
*/

class Solution {
    unordered_map<Node*, Node*> mp;
public:
    void DFS(Node* node, Node* cloneNode) {
        for(Node* n : node->neighbors) {
            // If neighbor hasn't been cloned yet
            if(mp.find(n) == mp.end()) {
                Node* clone = new Node(n->val);  // Create a new node
                mp[n] = clone;  // Map original to clone
                cloneNode->neighbors.push_back(clone);  // Link in the graph

                DFS(n, clone);  // Recurse
            } else {
                // If already cloned, just link the clone
                cloneNode->neighbors.push_back(mp[n]);
            }
        }
    }

    Node* cloneGraph(Node* node) {
        if(!node) return NULL;

        mp.clear();  // Clear previous mappings if any

        Node* cloneNode = new Node(node->val);  // Clone the starting node
        mp[node] = cloneNode;  // Map it

        DFS(node, cloneNode);  // Start DFS traversal and cloning

        return cloneNode;
    }
};
