/*
Sum Tree
Difficulty: MediumAccuracy: 37.17%Submissions: 241K+Points: 4
Given a Binary Tree. Check for the Sum Tree for every node except the leaf node. Return true if it is a Sum Tree otherwise, return false.

A SumTree is a Binary Tree where the value of a node is equal to the sum of the nodes present in its left subtree and right subtree. An empty tree is also a Sum Tree as the sum of an empty tree can be considered to be 0. A leaf node is also considered a Sum Tree.

Examples :

Input:
    3
  /   \    
 1     2
Output: true
Explanation: The sum of left subtree and right subtree is 1 + 2 = 3, which is the value of the root node. Therefore,the given binary tree is a sum tree.
Input:
          10
        /    \
      20      30
    /   \ 
   10    10
Output: false
Explanation: The given tree is not a sum tree. For the root node, sum of elements in left subtree is 40 and sum of elements in right subtree is 30. Root element = 10 which is not equal to 30+40.
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(Height of the Tree)

Constraints:
2 ≤ number of nodes ≤ 105
1 ≤ node value ≤ 105

*/

// Intuition:
// The problem is to determine if a given binary tree is a "Sum Tree".
// A binary tree is considered a Sum Tree if the value of every non-leaf node 
// is equal to the sum of the values of its left and right subtrees. 
// The approach is to perform a post-order traversal where for each node, 
// we calculate the sum of values of its left and right subtrees and check 
// if it equals the node's value. If any node violates this property, the 
// tree is not a Sum Tree.

// Time Complexity: O(N), where N is the number of nodes in the tree.
// Space Complexity: O(H), where H is the height of the tree (due to recursion stack).

class Solution {
public:
    // Helper function to check the sum tree property
    int solve(Node* root, bool &flag) {
        if (!root) return 0;  // Base case: empty node contributes 0 to the sum
        
        if (!root->left && !root->right) {
            return root->data;  // Leaf node directly returns its value
        }

        // Recursively calculate the sum of left and right subtrees
        int leftSum = solve(root->left, flag);
        int rightSum = solve(root->right, flag);

        // Check if the current node's value is equal to the sum of its left and right subtrees
        if (leftSum + rightSum != root->data) {
            flag = false;  // If the property is violated, set flag to false
        }

        // Return the total sum including the current node's value
        return leftSum + rightSum + root->data;
    }

    // Main function to determine if the tree is a Sum Tree
    bool isSumTree(Node* root) {
        bool flag = true;  // Flag to track if any node violates the sum tree property
        solve(root, flag); // Start the recursion from the root
        return flag;       // Return the final result
    }
};
