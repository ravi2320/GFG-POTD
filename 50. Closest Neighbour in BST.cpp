/*
Closest Neighbour in BST
EasyAccuracy: 36.98%Submissions: 31K+Points: 2
Given the root of a binary search tree and a number n, find the greatest number in the binary search tree that is less than or equal to n. 

Example 1 :

Input : 

n = 24
Output : 
21
Explanation : The greatest element in the tree which 
              is less than or equal to 24, is 21. 
              (Searching will be like 5->12->21)
Example 2 :

Input : 

n = 4
Output : 
3
Explanation : The greatest element in the tree which 
              is less than or equal to 4, is 3. 
              (Searching will be like 5->2->3)
Your task :
You don't need to read input or print anything. Your task is to complete the function findMaxForN() which takes the root of the BST, and the integer n as input parameters and returns the greatest element less than or equal to n in the given BST, Return -1 if no such element exists.

Expected Time Complexity: O(Height of the BST)
Expected Auxiliary Space: O(Height of the BST).

Constraints:
1 <= n <= 103
 
*/

/*
Intuition:
- We traverse down the BST starting from the root.
- At each node, if the node's key is less than the target 'n', we update the answer to the maximum of the current node's key and the previous answer.
- We move to the right child if the current node's key is less than 'n', and to the left child otherwise.
- We continue this process until we reach a leaf node or a node with key equal to 'n'.

Time Complexity: O(log(N))
- In the worst-case scenario, we traverse the height of the BST, which is O(log(N)), where N is the number of nodes in the BST.

Space Complexity: O(1)
- We use only a constant amount of additional space regardless of the size of the input BST.
*/

#include <iostream>
using namespace std;

// Definition of a node in the BST
struct Node {
    int key;
    Node *left, *right;
    Node(int x) : key(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    // Function to find the maximum key less than or equal to 'n' in the BST
    int findMaxForN(Node* root, int n) {
        // Initialize the answer to -1
        int ans = -1;

        // Traverse down the BST
        while(root){
            // If the current node's key is equal to 'n', return 'n'
            if(root->key == n) 
                return root->key;
            // If the current node's key is less than 'n', update the answer and move to the right child
            else if(root->key < n){
                ans = max(root->key, ans);
                root = root->right;
            }
            // If the current node's key is greater than 'n', move to the left child
            else
                root = root->left;
        }

        // Return the maximum key less than or equal to 'n'
        return ans;
    }
};
