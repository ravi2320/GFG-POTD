/*
Check for BST
Difficulty: EasyAccuracy: 25.37%Submissions: 518K+Points: 2
Given the root of a binary tree. Check whether it is a BST or not.
Note: We are considering that BSTs can not contain duplicate Nodes.
A BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
Examples:

Input:
   2
 /    \
1      3
        \
         5
Output: true 
Explanation: 
The left subtree of every node contains smaller keys and right subtree of every node contains greater. Hence, the tree is a BST.
Input:
  2
   \
    7
     \
      6
       \
        9
Output: false 
Explanation: 
Since the node with value 7 has right subtree nodes with keys less than 7, this is not a BST. 
Input:
   10
 /    \
5      20
      /   \
     9     25
Output: false
Explanation: The node is present in the right subtree of 10, but it is smaller than 10.
Expected Time Complexity: O(n) 
Expected Auxiliary Space: O(Height of the tree)
where n is the number of nodes in the given tree

Constraints:
1 ≤ Number of nodes ≤ 105
1 ≤ Data of a node ≤ 105
*/

Check for BST
Difficulty: EasyAccuracy: 25.37%Submissions: 518K+Points: 2
Given the root of a binary tree. Check whether it is a BST or not.
Note: We are considering that BSTs can not contain duplicate Nodes.
A BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
Examples:

Input:
   2
 /    \
1      3
        \
         5
Output: true 
Explanation: 
The left subtree of every node contains smaller keys and right subtree of every node contains greater. Hence, the tree is a BST.
Input:
  2
   \
    7
     \
      6
       \
        9
Output: false 
Explanation: 
Since the node with value 7 has right subtree nodes with keys less than 7, this is not a BST. 
Input:
   10
 /    \
5      20
      /   \
     9     25
Output: false
Explanation: The node is present in the right subtree of 10, but it is smaller than 10.
Expected Time Complexity: O(n) 
Expected Auxiliary Space: O(Height of the tree)
where n is the number of nodes in the given tree

Constraints:
1 ≤ Number of nodes ≤ 105
1 ≤ Data of a node ≤ 105
*/

/**
 * Intuition:
 * - **Inorder Traversal:** In a Binary Search Tree (BST), an inorder traversal produces sorted values in ascending order. By keeping track of the previous value and ensuring it is always less than the current node's value, we can determine if the tree is a BST.
 *
 * Time Complexity: O(n)
 * - The algorithm visits each node exactly once.
 *
 * Space Complexity: O(h)
 * - Where h is the height of the tree, corresponding to the stack space used by the recursion.
 */

class Solution {
public:
    // Helper function for inorder traversal with BST check
    void inorder(Node* root, int &prev, bool &flag) {
        if (!root) return;

        inorder(root->left, prev, flag);  // Traverse left subtree

        // Check if the current node's data is greater than the previous node's data
        if (root->data <= prev) {
            flag = false;  // Set flag to false if BST property is violated
        }
        prev = root->data;  // Update prev to the current node's data

        inorder(root->right, prev, flag);  // Traverse right subtree
    }

    // Function to check whether a Binary Tree is BST or not.
    bool isBST(Node* root) {
        int prev = INT_MIN;  // Initialize previous node's value to the smallest possible integer
        bool flag = true;    // Flag to check BST property
        
        inorder(root, prev, flag);  // Perform inorder traversal and check BST property
        
        return flag;  // Return the result
    }
};
