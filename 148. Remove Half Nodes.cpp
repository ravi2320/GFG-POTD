/*
Remove Half Nodes
Difficulty: EasyAccuracy: 59.67%Submissions: 28K+Points: 2
You are given a binary tree and you need to remove all the half nodes (which have only one child). Return the root node of the modified tree after removing all the half-nodes.

Note: The output will be judged by the inorder traversal of the resultant tree, inside the driver code.

Examples:

Input: tree = 5
            /   \
          7     8
        / 
      2
Output: 2 5 8
Explanation: In the above tree, the node 7 has only single child. After removing the node the tree becomes  2<-5->8. Hence, the answer is 2 5 8 & it is in inorder traversal.
Input:  tree = 2   
              / \   
            7   5 
Output: 7 2 5
Explanation: Here there are no nodes which has only one child. So the tree remains same.
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(height of the binary tree)

Constraints:
1<=number of nodes<=104
*/


/**
 * Intuition:
 * - The goal is to remove all nodes from a binary tree that have only one child.
 * - A node with only one child is called a half node.
 * - To solve this problem, we perform a post-order traversal (left, right, root) because we need to process the children before the parent node.
 * - If a node is a half node, we replace it with its non-null child.
 * - If a node is not a half node, we simply return the node.
 * 
 * Time Complexity:
 * - O(n), where n is the number of nodes in the binary tree. We visit each node exactly once.
 * 
 * Space Complexity:
 * - O(h), where h is the height of the binary tree. This is the space required by the call stack during the depth-first traversal. In the worst case, this could be O(n) for a skewed tree.
 */

// Definition for a binary tree node.
struct Node {
    int data;
    Node *left, *right;
    Node(int x) : data(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    Node* RemoveHalfNodes(Node* root) {
        // If the root is null, return null
        if (!root) return root;
        
        // Recursively remove half nodes in the left subtree
        root->left = RemoveHalfNodes(root->left);
        
        // Recursively remove half nodes in the right subtree
        root->right = RemoveHalfNodes(root->right);
        
        // If the current node has only a left child, return the left child
        if (root->left && !root->right) {
            return root->left;
        }
        
        // If the current node has only a right child, return the right child
        if (root->right && !root->left) {
            return root->right;
        }
        
        // If the current node has either two children or no children, return the current node
        return root;
    }
};
