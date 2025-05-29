/*
Sum of nodes on the longest path
Difficulty: MediumAccuracy: 52.39%Submissions: 119K+Points: 4
Given a binary tree root[], you need to find the sum of the nodes on the longest path from the root to any leaf node. If two or more paths have the same length, the path with the maximum sum of node values should be considered.

Examples:

Input: root[] = [4, 2, 5, 7, 1, 2, 3, N, N, 6, N]
 
Output: 13
Explanation:

The highlighted nodes (4, 2, 1, 6) above are part of the longest root to leaf path having sum = (4 + 2 + 1 + 6) = 13
Input: root[] = [1, 2, 3, 4, 5, 6, 7]

Output: 11
Explanation: 

The longest root-to-leaf path is 1 -> 3 -> 7, with sum 11.
Input: root[] = [10, 5, 15, 3, 7, N, 20, 1]

Output: 19
Explanation: 

The longest root-to-leaf path is 10 -> 5 -> 3 -> 1 with a sum of 10 + 5 + 3 + 1 = 19.
Constraints:
1 <= number of nodes <= 106
0 <= node->data <= 104
*/

/*
Approach:
- Perform DFS traversal from root to each leaf node.
- Track:
    - The current path length `len`
    - The current path sum `sum`
    - The maximum length seen so far `maxLen`
    - The maximum sum for the longest path `maxSum`
- At each leaf node, compare the current length with maxLen:
    - If greater, update both maxLen and maxSum.
    - If equal, update maxSum to the maximum of the two sums.
- Finally, return the maxSum.

Intuition:
- The goal is to find the root-to-leaf path that is the **longest**.
- If multiple such paths exist, pick the one with the **maximum sum**.
- This problem is solved naturally using DFS + path tracking.

Time Complexity: O(N), where N is the number of nodes in the tree (every node is visited once)
Space Complexity: O(H), where H is the height of the tree (due to recursion stack)
*/

class Solution {
  public:
    // Helper function to perform DFS and track maxSum and maxLen
    void solve(Node* root, int sum, int& maxSum, int len, int& maxLen) {
        if (root == NULL) {
            // If this path is longer than previous, update maxLen and maxSum
            if (len > maxLen) {
                maxLen = len;
                maxSum = sum;
            }
            // If length is same, pick the greater sum
            else if (len == maxLen) {
                maxSum = max(maxSum, sum);
            }
            return;
        }

        // Add current node's value to path sum
        sum += root->data;

        // Recurse to left and right child
        solve(root->left, sum, maxSum, len + 1, maxLen);
        solve(root->right, sum, maxSum, len + 1, maxLen);
    }

    int sumOfLongRootToLeafPath(Node* root) {
        int len = 0, maxLen = 0;
        int sum = 0, maxSum = 0;

        // Start DFS
        solve(root, sum, maxSum, len, maxLen);

        return maxSum;
    }
};
