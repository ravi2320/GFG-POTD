/*
Root to leaf path sum
Difficulty: EasyAccuracy: 40.79%Submissions: 117K+Points: 2
Given a binary tree and an integer target, check whether there is a root-to-leaf path with its sum as target.

Examples :

Input: tree = 1, target = 2
            /   \
          2     3
Output: false
Explanation: There is no root to leaf path with sum 2.
Input: tree = 1,  target = 4
            /   \
          2     3
Output: true
Explanation: The sum of path from leaf node 3 to root 1 is 4.
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(height of tree)

Constraints:
1 ≤ number of nodes ≤ 104
1 ≤ target ≤ 106
*/

/*
 * Intuition:
 * The goal is to determine if there exists a root-to-leaf path in the binary tree where the sum of the node values equals the given target sum.
 * We use depth-first search (DFS) to explore all possible paths from the root to the leaves.
 * 
 * Time Complexity: O(n), where n is the number of nodes in the binary tree.
 * Space Complexity: O(h), where h is the height of the binary tree (due to the recursion stack).
 */

class Solution {
public:
    bool dfs(Node *root, int sum, int target) {
        // Base case: if the node is a leaf node, check if the current path sum equals the target sum
        if (!root->left && !root->right) {
            return (sum + root->data == target);
        }
        
        bool left = false;
        bool right = false;
        
        // Recursive case: explore left and right subtrees
        if (root->left) {
            left = dfs(root->left, sum + root->data, target);
        }
        
        if (root->right) {
            right = dfs(root->right, sum + root->data, target);
        }
        
        // Return true if either left or right subtree has a path sum equal to the target
        return left || right;
    }
  
    bool hasPathSum(Node *root, int target) {
        // Edge case: if the root is null, there can't be any path
        if (!root) {
            return false;
        }
        
        // Start DFS traversal from the root
        return dfs(root, 0, target);
    }
};
