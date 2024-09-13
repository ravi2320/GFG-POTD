/*
Mirror Tree
Difficulty: EasyAccuracy: 72.67%Submissions: 187K+Points: 2
Given a Binary Tree, convert it into its mirror.
MirrorTree1            

Examples:

Input:
      1
    /  \
   2    3
Output: 3 1 2
Explanation: The tree is
   1    (mirror)  1
 /  \    =>      /  \
2    3          3    2
The inorder of mirror is 3 1 2
Input:
      10
     /  \
    20   30
   /  \
  40  60
Output: 30 10 60 20 40
Explanation: The tree is
      10               10
    /    \  (mirror) /    \
   20    30    =>   30    20
  /  \                   /   \
 40  60                 60   40
The inroder traversal of mirror is
30 10 60 20 40.
Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Height of the Tree).

Constraints:
1 ≤ Number of nodes ≤ 105
1 ≤ Data of a node ≤ 105
*/

/*
Approach:
1. The problem asks to convert a binary tree into its mirror image.
   - The mirror of a binary tree is formed by swapping the left and right children of every node.
2. We use a recursive approach:
   - For each node, swap its left and right children.
   - Recursively perform the same operation on the left and right subtrees.

Time Complexity:
- O(n): We visit every node once to perform the swap operation, where `n` is the number of nodes in the tree.

Space Complexity:
- O(h): The space complexity is determined by the recursion stack, where `h` is the height of the tree. In the worst case, the height can be `n` (for a skewed tree), but in a balanced tree, it would be O(log n).

*/

class Solution {
  public:
    // Function to convert a binary tree into its mirror tree.
    void mirror(Node* node) {
        // Base case: if the node is NULL, return.
        if (!node) return;
        
        // Swap the left and right child of the current node.
        Node* temp = node->left;
        node->left = node->right;
        node->right = temp;
        
        // Recursively call the function on the left and right subtrees.
        mirror(node->left);
        mirror(node->right);
    }
};
