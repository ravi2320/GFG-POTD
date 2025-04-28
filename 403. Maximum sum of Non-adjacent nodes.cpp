/*
Maximum sum of Non-adjacent nodes
Difficulty: MediumAccuracy: 55.35%Submissions: 83K+Points: 4Average Time: 45m
Given a binary tree with a value associated with each node. Your task is to select a subset of nodes such that the sum of their values is maximized, with the condition that no two selected nodes are directly connected that is, if a node is included in the subset, neither its parent nor its children can be included.

Examples:

Input: root[] = [11, 1, 2]

Output: 11
Explanation: The maximum sum is obtained by selecting the node 11.

Input: root[] = [1, 2, 3, 4, N, 5, 6]

Output: 16
Explanation: The maximum sum is obtained by selecting the nodes 1, 4, 5, and 6, which are not directly connected to each other. Their total sum is 16.  

Constraints:
1 ≤ no. of nodes in the tree ≤ 104
1 ≤ Node.val ≤ 105
*/

/*
Intuition:
- We need to find the maximum sum of non-adjacent nodes in a binary tree.
- For each node:
    - Either include the node's value and skip its immediate children.
    - Or exclude the node and consider the maximum sum from its children.

Approach:
- Use DFS recursion:
    - `include`: sum when we include current node (root->data + left's exclude + right's exclude).
    - `exclude`: sum when we exclude current node (max of left include/exclude + max of right include/exclude).
- At each node, return a pair {include, exclude} to parent.
- Final answer is max of the two at the root.

Time Complexity: O(N)
- We visit every node exactly once.

Space Complexity: O(H)
- Recursive call stack height (H = height of tree), O(N) in worst case (skewed tree).

*/

class Solution {
public:
    // Helper function to compute {include, exclude} sums
    pair<int, int> solve(Node* root) {
        if (!root) {
            return {0, 0}; // Base case: null node
        }
        
        // Solve recursively for left and right subtrees
        auto left = solve(root->left);
        auto right = solve(root->right);
        
        // If including this node, can't include immediate children
        int include = root->data + left.second + right.second;
        
        // If excluding this node, take max of including or excluding child nodes
        int exclude = max(left.first, left.second) + max(right.first, right.second);
        
        return {include, exclude};
    }
    
    int getMaxSum(Node* root) {
        auto ans = solve(root);
        return max(ans.first, ans.second); // Return maximum of including or excluding root
    }
};