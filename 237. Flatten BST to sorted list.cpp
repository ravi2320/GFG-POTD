/*
Flatten BST to sorted list
Difficulty: MediumAccuracy: 68.49%Submissions: 29K+Points: 4
You are given a Binary Search Tree (BST) with n nodes, each node has a distinct value assigned to it. The goal is to flatten the tree such that, the left child of each element points to nothing (NULL), and the right child points to the next element in the sorted list of elements of the BST (look at the examples for clarity). You must accomplish this without using any extra storage, except for recursive calls, which are allowed.

Note: If your BST does have a left child, then the system will print a -1 and will skip it, resulting in an incorrect solution.

Example 1:

Input:
          5
        /    \
       3      7
      /  \    /   \
     2   4  6     8
Output: 2 3 4 5 6 7 8
Explanation: 
After flattening, the tree looks
like this
    2
     \
      3
       \
        4
         \
          5
           \
            6
             \
              7
               \
                8
Here, left of each node points
to NULL and right contains the
next node.
Example 2:

Input:
       5
        \
         8
       /   \
      7     9  
Output: 5 7 8 9
Explanation:
After flattening, the tree looks like this:
   5
    \
     7
      \
       8
        \
         9
Your Task:
You don't need to read input or print anything. Your task is to complete the function flattenBST() which takes root node of the BST as input parameter and returns the root node after transforming the tree.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)

Constraints:
1 <= Number of nodes <= 103
1 <= Data of a node <= 105
*/

/*
 * Approach:
 * - The function recursively flattens the left and right subtrees of the BST.
 * - After flattening the left subtree, the current root node's left pointer is set to `NULL`,
 *   and its right pointer is linked to the result of the recursive flattening of the right subtree.
 * - The flattened left subtree (if exists) is linked to the current node, followed by linking the right subtree.
 *
 * Time Complexity:
 * - O(n): Where n is the number of nodes in the BST. Each node is visited once.
 *
 * Space Complexity:
 * - O(h): The space complexity is determined by the depth of the recursion stack, which can be up to the height (h) of the tree. In the worst case (unbalanced tree), h = n, and in the best case (balanced tree), h = log(n).
 */

class Solution
{
public:
    // Function to flatten a binary search tree into a sorted linked list
    Node *flattenBST(Node *root)
    {
        // Base case: if root is null, return null
        if (!root) return root;

        // Recursively flatten the left subtree
        Node* head = flattenBST(root->left);

        // Set the left pointer of the current root to null
        root->left = NULL;

        // Recursively flatten the right subtree and attach to the current root
        root->right = flattenBST(root->right);

        // If the left subtree exists (head is not null), link the current root to the rightmost node
        if (head) {
            Node* temp = head;
            // Traverse to the rightmost node of the flattened left subtree
            while (temp && temp->right) {
                temp = temp->right;
            }
            // Link the rightmost node of the left subtree to the current root
            temp->right = root;
        } else {
            // If the left subtree doesn't exist, the head becomes the current root
            head = root;
        }

        return head; // Return the head of the flattened BST
    }
};
