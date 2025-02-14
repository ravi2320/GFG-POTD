/*
Fixing Two nodes of a BST
Difficulty: HardAccuracy: 53.68%Submissions: 56K+Points: 8Average Time: 45m
Given the root of a Binary search tree(BST), where exactly two nodes were swapped by mistake. Your task is to fix (or correct) the BST by swapping them back. Do not change the structure of the tree.
Note: It is guaranteed that the given input will form BST, except for 2 nodes that will be wrong. All changes must be reflected in the original Binary search tree(BST).
 
Examples :
Input: root = [10, 5, 8, 2, 20]
     
Output: 1
       

Explanation: The nodes 20 and 8 were swapped. 
Input: root = [5, 10, 20, 2, 8]
     
Output: 1 
     
Explanation: The nodes 10 and 5 were swapped.
Constraints:
1 ≤ Number of nodes ≤ 103
*/

/*
Approach:
1. **Use Inorder Traversal** to identify misplaced nodes.
2. **Identify Violations**:
   - If a node violates BST property (`prev->data > root->data`), mark:
     - `first = prev`
     - `temp = root` (potential second misplaced node)
     - If already found `first`, then `second = root`.
3. **Fix by swapping**:
   - If two nodes (`first` and `second`) are found, swap them.
   - Otherwise, swap `first` and `temp`.

Time Complexity: **O(N)** (single inorder traversal)
Space Complexity: **O(H)** (recursion stack, where H = height of BST)
*/

class Solution {
    Node *first, *second, *temp, *prev;
    
public:
    void inorder(Node* root) {
        if (!root) return;
        
        inorder(root->left);
        
        // Identify misplaced nodes
        if (prev && prev->data > root->data) {
            if (!first) {
                first = prev;
                temp = root;
            } else {
                second = root;
            }
        }
        
        prev = root;
        
        inorder(root->right);
    }

    void correctBST(Node* root) {
        first = second = temp = prev = NULL;
        
        inorder(root);
        
        // Swap the correct misplaced nodes
        if (second) {
            swap(first->data, second->data);
        } else {
            swap(first->data, temp->data);
        }
    }
};