/*
Insert a node in a BST
Difficulty: EasyAccuracy: 47.15%Submissions: 157K+Points: 2
Given a BST and a key k. If k is not present in the BST, Insert a new Node with a value equal to k into the BST. If k is already present in the BST, don't modify the BST. Return the root of the modified BST after inserting k. 

Note: The generated output contains the inorder traversal of the modified tree.

Examples :

Input: k = 4
     2
   /   \   
  1     3
Output: 1 2 3 4
Explanation: After inserting the node 4 Inorder traversal will be 1 2 3 4.
Input: k = 4
        2
      /   \
     1     3
             \
              6
Output: 1 2 3 4 6
Explanation: After inserting the node 4 Inorder traversal of the above tree will be 1 2 3 4 6.
Expected Time Complexity: O(Height of the BST).
Expected Auxiliary Space: O(Height of the BST).

Constraints:
1 <= Number of nodes initially in BST <= 105
1 <= k <= 109
*/

/**
 * Intuition:
 * - To insert a node into a BST, we start from the root and find the appropriate position for the new node.
 * - We traverse the tree based on the BST property: 
 *     - If the current node's value is less than the new node's value, we move to the right child.
 *     - If the current node's value is greater than the new node's value, we move to the left child.
 * - Once we find the correct position (where the left or right child is NULL), we insert the new node there.
 * 
 * Time Complexity:
 * - O(h), where h is the height of the BST. 
 * - In the worst case, the height can be O(n) for a skewed tree, and O(log n) for a balanced tree.
 * 
 * Space Complexity:
 * - O(1), as we are not using any extra space apart from a few variables.
 * - The iterative approach ensures that no additional space is used for recursion stack.
 */

class Solution {
public:
    // Function to insert a new node with given data in the BST.
    Node* insert(Node* node, int data) {
        // If the tree is empty, create a new node and return it.
        if (node == NULL) 
            return new Node(data);

        Node *curr = node;

        // Traverse the tree to find the appropriate position for the new node.
        while (true) {
            if (curr->data < data) {
                // If the current node's data is less than the new data, move to the right child.
                if (curr->right)
                    curr = curr->right;
                else {
                    // If the right child is NULL, insert the new node here.
                    curr->right = new Node(data);
                    break;
                }
            } else if (curr->data > data) {
                // If the current node's data is greater than the new data, move to the left child.
                if (curr->left)
                    curr = curr->left;
                else {
                    // If the left child is NULL, insert the new node here.
                    curr->left = new Node(data);
                    break;
                }
            } else {
                // If the node with the given data already exists, do nothing and return the original node.
                break;
            }
        }

        return node; // Return the unchanged node pointer
    }
};
