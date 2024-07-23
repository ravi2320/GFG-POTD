/*
Largest BST
Difficulty: MediumAccuracy: 29.73%Submissions: 142K+Points: 4
Given a binary tree. Find the size of its largest subtree which is a Binary Search Tree.
Note: Here Size equals the number of nodes in the subtree.

Examples :

Input:   1
        /  \
        4   4              
       / \ 
      6   8
Output: 1 
Explanation: There's no sub-tree with size greater than 1 which forms a BST. All the leaf Nodes are the BSTs with size equal to 1.

Input:    6
        /   \
      6      2              
       \    / \
        2  1   3
Output: 3
Explanation: The following sub-tree is a BST of size 3:  2
                                                       /   \
                                                      1     3
Expected Time Complexity: O(n).
Expected Auxiliary Space: O(Height of the BST).

Constraints:
1 ≤ Number of nodes ≤ 105
1 ≤ Data of a node ≤ 106
*/

/**
 * Intuition:
 * 1. **BST Property Verification:** For each node, check if the left subtree's maximum value is less than the current node's value and the right subtree's minimum value is greater than the current node's value.
 * 2. **Recursive Approach:** Use a helper function that returns a custom object containing the minimum value, maximum value, and size of the largest BST subtree for each node.
 * 3. **Updating Results:** If the current subtree rooted at a node is a BST, update the size of the largest BST. If not, propagate the largest BST size found in either subtree.
 *
 * Time Complexity: O(n)
 * - We traverse each node of the tree once.
 *
 * Space Complexity: O(h)
 * - The space complexity is due to the recursion stack, where h is the height of the tree.
 */

class NodeVal {
public:
    int minVal, maxVal, maxSize;
    NodeVal(int minVal, int maxVal, int maxSize) {
        this->minVal = minVal;
        this->maxVal = maxVal;
        this->maxSize = maxSize;
    }
};

class Solution {
public:
    // Helper function to return a NodeVal object containing the minimum value, maximum value, and size of the largest BST subtree for a given node
    NodeVal help(Node *root) {
        if (!root)
            return NodeVal(INT_MAX, INT_MIN, 0);
        
        NodeVal left = help(root->left);
        NodeVal right = help(root->right);
        
        if (left.maxVal < root->data && root->data < right.minVal) {
            return NodeVal(min(left.minVal, root->data), max(root->data, right.maxVal), left.maxSize + right.maxSize + 1);
        }
        
        return NodeVal(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize));
    }

    // Function to find the size of the largest sub-tree which is also a BST
    int largestBst(Node *root) {
        return help(root).maxSize;
    }
};
