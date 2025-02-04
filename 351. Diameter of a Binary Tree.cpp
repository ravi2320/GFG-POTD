/*
Diameter of a Binary Tree
Difficulty: MediumAccuracy: 47.37%Submissions: 313K+Points: 4Average Time: 20m
Given a binary tree, the diameter (also known as the width) is defined as the number of edges on the longest path between two leaf nodes in the tree. This path may or may not pass through the root. Your task is to find the diameter of the tree.

Examples:

Input: root[] = [1, 2, 3]

Output: 2
Explanation: The longest path has 2 edges (node 2 -> node 1 -> node 3).

Input: root[] = [5, 8, 6, 3, 7, 9]

Output: 4
Explanation: The longest path has 4 edges (node 3 -> node 8 -> node 5 -> node 6 -> node 9).

Constraints:
1 ≤ number of nodes ≤ 105
0 ≤ node->data ≤ 105
*/

/*
Approach:
1. The **diameter of a binary tree** is the length of the longest path between any two nodes in the tree. 
   - This path may or may not pass through the root.
   - The diameter is measured in terms of the number of edges.

2. For each node, we calculate:
   - The **height of the left subtree**.
   - The **height of the right subtree**.
   - The **diameter at the current node** = left height + right height.
   - We keep track of the maximum diameter found during the traversal.

3. We use a helper function `solve()` that:
   - Returns the height of the subtree rooted at the current node.
   - Updates the maximum diameter (`res`) during the traversal.

Intuition:
- The key insight is that the longest path (diameter) will always be the sum of the heights of the left and right subtrees at some node in the tree.

Time Complexity:
- **O(N)** where N is the number of nodes in the binary tree. Each node is visited exactly once.

Space Complexity:
- **O(H)** where H is the height of the binary tree due to the recursion stack.
  - In the worst case (skewed tree), it can be **O(N)**.
  - In the best case (balanced tree), it is **O(log N)**.
*/

class Solution {
public:
    // Helper function to calculate the height of the tree and update the diameter
    int solve(Node* root, int &res) {
        if (!root) {
            return 0;  // Base case: height of an empty subtree is 0
        }
        
        // Recursively calculate the height of the left and right subtrees
        int left = solve(root->left, res);
        int right = solve(root->right, res);
        
        // Update the diameter (maximum path length) at the current node
        res = max(res, left + right);
        
        // Return the height of the current subtree
        return 1 + max(left, right);
    }

    // Function to calculate the diameter of the binary tree
    int diameter(Node* root) {
        if (!root) {
            return 0;  // Edge case: empty tree has a diameter of 0
        }
        
        int res = 0;  // To store the maximum diameter found during traversal
        
        solve(root, res);  // Start the DFS traversal to calculate the diameter
        
        return res;  // The diameter is the longest path found
    }
};