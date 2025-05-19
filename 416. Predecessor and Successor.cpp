/*
Predecessor and Successor
Difficulty: MediumAccuracy: 47.36%Submissions: 139K+Points: 4
You are given root node of the BST and an integer key. You need to find the in-order successor and predecessor of the given key. If either predecessor or successor is not found, then set it to NULL.

Note:- In an inorder traversal the number just smaller than the target is the predecessor and the number just greater than the target is the successor. 

Examples :

Input: root[] = [8, 1, 9, N, 4, N, 10, 3, N, N, N], key = 8

Output: 4 9
Explanation: In the given BST the inorder predecessor of 8 is 4 and inorder successor of 8 is 9.
Input: root[] = [10, 2, 11, 1, 5, N, N, N, N, 3, 6, N, 4, N, N], key = 11

Output: 10 -1
Explanation: In given BST, the inorder predecessor of 11 is 10 whereas it does not have any inorder successor.
Input: root[] = [2, 1, 3], key = 3

Output: 2 -1
Explanation: In given BST, the inorder predecessor of 3 is 2 whereas it does not have any inorder successor.
Constraints: 
1 <= no. of nodes <= 105
1 <= node->data <= 106
1 <= key <= 106
*/

/*
Approach:
- We are given a BST and a key.
- The goal is to find:
  1. The **predecessor**: largest value smaller than the key.
  2. The **successor**: smallest value greater than the key.

- Since it's a BST, we can use the property:
  - If current node < key → it's a candidate for predecessor → move right.
  - If current node > key → it's a candidate for successor → move left.

Intuition:
- Traverse like normal BST search while tracking potential candidates.
- Predecessor is updated when moving right (values less than key).
- Successor is updated when moving left (values greater than key).

Time Complexity:
- O(H), where H is the height of the tree (O(log N) for balanced BST, O(N) for skewed).
Space Complexity:
- O(1), iterative approach uses no extra space.
*/

class Solution {
  public:
    vector<Node*> findPreSuc(Node* root, int key) {
        Node* pre = NULL;
        Node* suc = NULL;
        Node* curr = root;

        // Find predecessor
        while (curr) {
            if (curr->data < key) {
                pre = curr;            // Current node is a potential predecessor
                curr = curr->right;    // Try to find a closer value on the right
            } else {
                curr = curr->left;     // Go left to find smaller values
            }
        }

        curr = root;

        // Find successor
        while (curr) {
            if (curr->data > key) {
                suc = curr;            // Current node is a potential successor
                curr = curr->left;     // Try to find a closer value on the left
            } else {
                curr = curr->right;    // Go right to find larger values
            }
        }

        // Return -1 nodes if predecessor/successor not found
        return { pre ? pre : new Node(-1), suc ? suc : new Node(-1) };
    }
};
