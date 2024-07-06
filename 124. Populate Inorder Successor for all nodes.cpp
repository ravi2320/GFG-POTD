/*
Populate Inorder Successor for all nodes
Difficulty: MediumAccuracy: 51.2%Submissions: 49K+Points: 4
Given a Binary Tree, complete the function to populate the next pointer for all nodes. The next pointer for every node should point to the Inorder successor of the node.
You do not have to return or print anything. Just make changes in the root node given to you.

Note: The node having no in-order successor will be pointed to -1. You don't have to add -1 explicitly, the driver code will take care of this.

Examples :

Input:
       10
       /  \
      8   12
     /
    3
Output: 3->8 8->10 10->12 12->-1
Explanation: The inorder of the above tree is : 3 8 10 12. So the next pointer of node 3 is pointing to 8 , next pointer of 8 is pointing to 10 and so on.And next pointer of 12 is pointing to -1 as there is no inorder successor of 12.
Input:
       1
      /  
     2 
   /
 3  
Output: 3->2 2->1 1->-1
Explanation: The inorder of the above tree is: 3 2 1. So the next pointer of node 3 is pointing to 2 , next pointer of 2 is pointing to 1. And next pointer of 1 is pointing to -1 as there is no inorder successor of 1.
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)

Constraints:
1<= no. of nodes <=105
1<= data of the node <=105
*/

/*
 * Intuition:
 * The goal is to populate the 'next' pointer of each node in a binary tree to point to the in-order successor of that node.
 * Using in-order traversal, we can visit nodes in the correct sequence and keep track of the previous node to update the 'next' pointer.
 *
 * Time Complexity: O(n), where n is the number of nodes in the tree, since each node is visited once.
 * Space Complexity: O(h), where h is the height of the tree, due to the recursion stack in in-order traversal.
 */

class Solution {
  public:
    Node* prev = NULL;

    // Function to populate the 'next' pointer of each node
    void populateNext(Node *root) {
        if (!root) return;  // Base case: if the node is NULL, return

        // Recursively traverse the left subtree
        populateNext(root->left);

        // Set the 'next' pointer of the previous node to the current node
        if (prev)
            prev->next = root;

        // Update the previous node to the current node
        prev = root;

        // Recursively traverse the right subtree
        populateNext(root->right);
    }
};
