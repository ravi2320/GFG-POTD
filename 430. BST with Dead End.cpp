/*
BST with Dead End
Difficulty: MediumAccuracy: 35.99%Submissions: 86K+Points: 4
You are given a Binary Search Tree (BST) containing unique positive integers greater than 0.

Your task is to determine whether the BST contains a dead end.

Note: A dead end is a leaf node in the BST such that no new node can be inserted in the BST at or below this node while maintaining the BST property and the constraint that all node values must be > 0.

Examples:

Input: root[] = [8, 5, 9, 2, 7, N, N, 1]

Output: true
Explanation: Node 1 is a Dead End in the given BST.
Input: root[] = [8, 7, 10, 2, N, 9, 13]

Output: true
Explanation: Node 9 is a Dead End in the given BST.
Constraints:
1 ≤ number of nodes ≤ 3000
1 ≤ node->data ≤ 105
*/

/*
Approach:
- The idea is to identify *leaf nodes* that cannot be expanded further in a Binary Search Tree (BST).
- A dead end exists if there is a leaf node such that no other node can be inserted after it — i.e., the range around it is completely filled.
- So, for each leaf node, check:
   (root->data - lower == 1) and (upper - root->data == 1)
- This means you cannot insert a node either on the left or right of that leaf, due to BST property constraints.

Intuition:
- Use recursion to keep track of valid value ranges `[lower, upper]` for each node.
- A node is a dead end if it's a leaf and its valid range collapses (no space to insert).

Time Complexity: O(N)
- We traverse every node once.

Space Complexity: O(H)
- Recursive stack can go as deep as the height of the tree (H).
- In worst case (skewed tree), H = N; in best case (balanced), H = log N.
*/

class Solution {
  public:
    // Recursive helper to detect dead end
    bool checkDeadEnd(Node* root, int lower, int upper){
        if(!root){
            return false;
        }

        // If current node is a leaf
        if(!root->left && !root->right){
            // Check if there's no room to insert left or right due to BST rules
            if(root->data - lower == 1 && upper - root->data == 1){
                return true;
            }
        }

        // Recursively check left and right subtree
        return checkDeadEnd(root->left, lower, root->data) ||
               checkDeadEnd(root->right, root->data, upper);
    }

    // Main function to check if there's any dead end in BST
    bool isDeadEnd(Node *root) {
        return checkDeadEnd(root, 0, INT_MAX);
    }
};
