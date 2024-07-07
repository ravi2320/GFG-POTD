/*
Ancestors in Binary Tree
Difficulty: MediumAccuracy: 40.34%Submissions: 42K+Points: 4
Given a Binary Tree and an integer target. Find all the ancestors of the given target.

Note:

The ancestor of node x is node y, which is at the upper level of node x, and x is directly connected with node y. Consider multiple levels of ancestors to solve this problem.
In case there are no ancestors available, return an empty list.
Examples:

Input:
         1
       /   \
      2     3
    /  \    /  \
   4   5  6   8
  /
 7
target = 7
Output: [4 2 1]
Explanation: The given target is 7, if we go above the level of node 7, then we find 4, 2 and 1. Hence the ancestors of node 7 are 4 2 and 1
Input:
        1
      /   \
     2     3
target = 1
Output: [ ]
Explanation: Since 1 is the root node, there would be no ancestors. Hence we return an empty list.
Expected Time Complexity: O(n).
Expected Auxiliary Space: O(height of tree)

Constraints:
1 ≤ no. of nodes ≤ 103
1 ≤ data of node ≤ 104
*/

/*
 * Intuition:
 * The problem is to find all the ancestors of a given target node in a binary tree. 
 * We perform a depth-first search (DFS) to traverse the tree and keep track of the path from the root to the target node. 
 * Once the target node is found, we store the current path as the ancestors and return it.
 *
 * Time Complexity: O(n), where n is the number of nodes in the tree, because we potentially visit all nodes in the worst case.
 * Space Complexity: O(h), where h is the height of the tree, due to the recursion stack and the space required to store the path.
 */

class Solution {
  public:
    vector<int> ans; // Stores the ancestors of the target node

    // Helper function to traverse the tree and find ancestors
    void traverse(struct Node *root, int &target, vector<int> &arr) {
        if (!root) return; // If the node is null, return

        if (root->data == target) {
            ans = arr; // If the target node is found, store the current path as ancestors
            return;
        }

        arr.push_back(root->data); // Add the current node to the path
        traverse(root->left, target, arr); // Recur for the left subtree
        traverse(root->right, target, arr); // Recur for the right subtree
        arr.pop_back(); // Remove the current node from the path when backtracking
    }

    // Main function to find ancestors of the target node
    vector<int> Ancestors(struct Node *root, int target) {
        vector<int> arr; // Temporary vector to store the path
        traverse(root, target, arr); // Start DFS traversal from the root
        reverse(ans.begin(), ans.end()); // Reverse the ancestors list to get the correct order
        return ans; // Return the ancestors list
    }
};
