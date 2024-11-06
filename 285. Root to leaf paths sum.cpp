/*
Root to leaf paths sum
Difficulty: MediumAccuracy: 58.4%Submissions: 35K+Points: 4
Given a binary tree, where every node value is a number. Find the sum of all the numbers that are formed from root to leaf paths. The formation of the numbers would be like 10*parent + current (see the examples for more clarification).

Examples:

Input :      

Output: 13997
Explanation : There are 4 leaves, resulting in leaf path of 632, 6357, 6354, 654 sums to 13997.
Input :    

Output : 2630
Explanation: There are 3 leaves, resulting in leaf path of 1240, 1260, 130 sums to 2630.
Input :    
           1
          /
         2                    
Output : 12
Explanation: There is 1 leaf, resulting in leaf path of 12.
Constraints:
1 ≤ number of nodes ≤ 31
1 ≤ node->data ≤ 100
*/

/*
Approach:
1. We perform a Depth-First Search (DFS) on the tree, constructing each root-to-leaf path as a number.
2. For each node, the current path's number is accumulated by multiplying the current sum by 10 and adding the node's data.
3. When a leaf node is reached, the path number is added to the total sum.
4. The recursive function traverses left and right subtrees, updating the path's sum as it moves along.
5. Finally, the total sum of all root-to-leaf path numbers is returned.

Time Complexity: O(N), where N is the number of nodes, as we visit each node once.
Space Complexity: O(H), where H is the height of the tree, for the recursive call stack.

*/

class Solution {
public:
    // Helper function to perform DFS and accumulate path sums
    void f(Node* root, int currSum, int &sum) {
        // Base case: if root is NULL, return
        if (!root) return;
        
        // Update the current path sum by appending the node's value
        currSum = currSum * 10 + root->data;
        
        // If a leaf node is reached, add the path sum to the total sum
        if (!root->left && !root->right) {
            sum += currSum;
            return;
        }
        
        // Recursively call for left and right subtrees
        f(root->left, currSum, sum);
        f(root->right, currSum, sum);
    }

    // Function to calculate the sum of all root-to-leaf paths
    int treePathsSum(Node *root) {
        int sum = 0;
        f(root, 0, sum);
        return sum;
    }
};
