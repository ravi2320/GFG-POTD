/*
Maximum path sum from any node
Difficulty: MediumAccuracy: 42.92%Submissions: 89K+Points: 4Average Time: 45m
Given a binary tree, the task is to find the maximum path sum. The path may start and end at any node in the tree.

Examples:

Input: root[] = [10, 2, 10, 20, 1, N, -25, N, N, N, N, 3, 4]
Output: 42
Explanation: 

Max path sum is represented using green colour nodes in the above binary tree.
Input: root[] = [-17, 11, 4, 20, -2, 10]
Output: 31
Explanation: 

Max path sum is represented using green colour nodes in the above binary tree.
Constraints:
1 ≤ number of nodes ≤ 103
-104 ≤ node->data ≤ 104
*/

/*
Approach:
1. Use a recursive function `solve` to calculate the maximum path sum starting from each node.
2. At each node:
   - Compute the maximum sum from the left and right subtrees.
   - If both left and right subtree sums are positive, update the global `maxi` with the sum including the current node.
   - If both are negative, consider only the current node's value.
   - Otherwise, take the maximum path sum from either subtree including the current node.
3. Return the maximum sum that can be contributed to the parent node.
4. The result is stored in `maxi`, which is updated throughout the recursion.

Intuition:
- The problem requires finding the **maximum path sum** from any node to any node in the tree.
- Since the path can start and end at any node, we need to explore all possible subpaths recursively.
- We update `maxi` at each step to ensure we capture the highest sum encountered.

Time Complexity: **O(N)**
- Each node is visited once, leading to a linear time complexity.

Space Complexity: **O(H)**
- The recursive stack depth is at most `H` (height of the tree).
- In the worst case (skewed tree), `H = O(N)`, but for a balanced tree, `H = O(log N)`.
*/

class Solution {
  public:
    // Helper function to compute max path sum from any node
    int solve(Node* root, int &maxi){
        if (!root) return 0; // Base case: Null node contributes 0
        
        // Compute max path sum for left and right subtrees
        int leftSum = solve(root->left, maxi);
        int rightSum = solve(root->right, maxi);
        
        // Update maxi based on different cases
        if (leftSum > 0 && rightSum > 0) {
            maxi = max(maxi, root->data + leftSum + rightSum);
        } 
        else if (leftSum < 0 && rightSum < 0) {
            maxi = max(maxi, root->data);
        } 
        else {
            maxi = max(maxi, root->data + max(leftSum, rightSum));
        }
        
        // Return max sum that can be contributed to the parent
        return max(0, root->data + max(leftSum, rightSum));
    }

    // Function to return the maximum path sum in a tree
    int findMaxSum(Node *root) {
        int maxi = INT_MIN; // Initialize max path sum
        
        solve(root, maxi); // Compute max sum
        
        return maxi;
    }
};