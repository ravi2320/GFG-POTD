/*
Burning Tree
Difficulty: HardAccuracy: 53.53%Submissions: 76K+Points: 8
Given a binary tree and a node data called target. Find the minimum time required to burn the complete binary tree if the target is set on fire. It is known that in 1 second all nodes connected to a given node get burned. That is its left child, right child, and parent.
Note: The tree contains unique values.


Examples : 

Input:      
          1
        /   \
      2      3
    /  \      \
   4    5      6
       / \      \
      7   8      9
                   \
                   10
Target Node = 8
Output: 7
Explanation: If leaf with the value 8 is set on fire. 
After 1 sec: 5 is set on fire.
After 2 sec: 2, 7 are set to fire.
After 3 sec: 4, 1 are set to fire.
After 4 sec: 3 is set to fire.
After 5 sec: 6 is set to fire.
After 6 sec: 9 is set to fire.
After 7 sec: 10 is set to fire.
It takes 7s to burn the complete tree.
Input:      
          1
        /   \
      2      3
    /  \      \
   4    5      7
  /    / 
 8    10
Target Node = 10
Output: 5

Expected Time Complexity: O(number of nodes)
Expected Auxiliary Space: O(height of tree)


Constraints:
1 ≤ number of nodes ≤ 105

1 ≤ values of nodes ≤ 105
*/

/*
Intuition:
- The problem is to find the minimum time required to burn a binary tree starting from a given target node. The fire spreads to the adjacent nodes (parent, left child, right child).
- To solve this, we need to traverse the tree and maintain a mapping of each node to its parent. This allows us to simulate the spread of fire not only to the child nodes but also to the parent node.
- We then perform a breadth-first search (BFS) starting from the target node, counting the time as we traverse the tree. The maximum depth (or distance) we can reach from the target node will give us the minimum time required to burn the entire tree.

Time Complexity:
- The time complexity is O(n), where `n` is the number of nodes in the tree. We traverse each node twice, once to map the parent and another during the BFS traversal.

Space Complexity:
- The space complexity is O(n) due to the space required for the parent mapping, visited map, and the BFS queue.

*/

#include <unordered_map>
#include <queue>

struct Node {
    int data;
    Node* left;
    Node* right;
};

class Solution {
  public:
    // Function to find the maximum distance from the target node to any other node
    int findMaxDist(std::unordered_map<Node*, Node*> &mp, Node* target) {
        std::queue<Node*> q;
        q.push(target);
        
        std::unordered_map<Node*, int> vis; // To keep track of visited nodes
        vis[target] = 1;
        int maxi = 0;
        
        // BFS traversal to simulate the spread of fire
        while (!q.empty()) {
            int n = q.size();
            int flag = 0;
            
            // Process all nodes at the current distance level
            for (int i = 0; i < n; i++) {
                Node* node = q.front();
                q.pop();
                
                // Visit the left child if not already visited
                if (node->left && !vis[node->left]) {
                    vis[node->left] = 1;
                    q.push(node->left);
                    flag = 1;
                }
                
                // Visit the right child if not already visited
                if (node->right && !vis[node->right]) {
                    vis[node->right] = 1;
                    q.push(node->right);
                    flag = 1;
                }
                
                // Visit the parent node if not already visited
                if (mp[node] && !vis[mp[node]]) {
                    vis[mp[node]] = 1;
                    q.push(mp[node]);
                    flag = 1;
                }
            }
            
            // If any new nodes were visited, increase the distance counter
            if (flag) maxi++;
        }
        
        return maxi;
    }
    
    // Function to map each node to its parent and return the target node
    Node* mapParent(Node* root, std::unordered_map<Node*, Node*> &mp, int target) {
        std::queue<Node*> q;
        q.push(root);
        Node* res = nullptr;
         
        while (!q.empty()) {
            Node* node = q.front();
            q.pop();
            
            if (node->data == target) res = node;
             
            // Map the left child to its parent
            if (node->left) {
                mp[node->left] = node;
                q.push(node->left);
            }
             
            // Map the right child to its parent
            if (node->right) {
                mp[node->right] = node;
                q.push(node->right);
            }
        }
         
        return res;
    }
    
    // Function to return the minimum time required to burn the tree from the target node
    int minTime(Node* root, int target) {
        std::unordered_map<Node*, Node*> mp; // Map to store parent pointers
        Node* t = mapParent(root, mp, target); // Get the target node
        int maxi = findMaxDist(mp, t); // Find the maximum distance to any node
        return maxi;
    }
};
