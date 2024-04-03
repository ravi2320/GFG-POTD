/*
Kth common ancestor in BST
MediumAccuracy: 58.93%Submissions: 19K+Points: 4
Given a BST with n (n>=2) nodes, find the kth common ancestor of nodes x and y in the given tree. Return -1 if kth ancestor does not exist.

Nodes x and y will always be present in the input of a BST, and x != y.

Example 1:

Input: 
Input tree

k = 2, x = 40, y = 60 
Output:
30
Explanation:
Their 2nd common ancestor is 30.
Example 2:

Input: 
Input tree

k = 2, x = 40, y = 60
Output:
-1
Explanation:
LCA of 40 and 60 is 50, which is root itself. There does not exists 2nd common ancestor in this case.
Your task :
You don't have to read input or print anything. Your task is to complete the function kthCommonAncestor() that takes the root of the tree, k, x and y as input and returns the kth common ancestor of x and y.
 
Expected Time Complexity: O(Height of the Tree)
Expected Space Complexity: O(Height of the Tree)
 
Your Task :
1 <= n, k <= 105
1 <= node->data, x, y <= 109

*/

/**
 * Intuition:
 * - Traverse the binary search tree to find the common ancestor of nodes with values x and y.
 * - Start from the root and move down the tree based on the values of x and y.
 * - Count the total number of nodes traversed until reaching the common ancestor.
 * - Once the total count is obtained, traverse the tree again to find the kth common ancestor.
 * - Decrement the total count by k and traverse the tree until reaching the kth common ancestor.
 * - Return the value of the kth common ancestor.
 * 
 * Time Complexity: O(log N) on average for balanced BST, where N is the number of nodes in the tree.
 *                  O(N) in the worst case for skewed BST.
 * Space Complexity: O(1) additional space.
 */

class Solution {
public:
    /*You are required to complete below function */
    int kthCommonAncestor(Node *root, int k, int x, int y) {
        // your code goes here
        int total = 1;
        Node* temp = root;
        
        // Traverse to find the common ancestor
        while (root) {
            if (root->data > x && root->data > y) {
                total++;
                root = root->left;
            } else if (root->data < x && root->data < y) {
                total++;
                root = root->right;
            } else
                break;
        }
        
        root = temp;
        total -= k;
        int cnt = 0;
        
        // Traverse to find the kth common ancestor
        while (root) {
            if (cnt == total)
                return root->data;
                
            if (root->data > x && root->data > y) {
                root = root->left;
                cnt++;
            } else if (root->data < x && root->data < y) {
                root = root->right;
                cnt++;
            } else
                break;
        }
        
        return -1;
    }
};