/*
Construct Binary Tree from Parent Array
Difficulty: MediumAccuracy: 47.34%Submissions: 47K+Points: 4
Given an array parent that is used to represent a tree. The array indices (0-based indexing) are the values of the tree nodes and parent[i] denotes the parent node of a particular node. The parent of the root node would always be -1, as there is no parent for the root. Construct the standard linked representation of Binary Tree from this array representation and return the root node of the constructed tree.

Note: If two elements have the same parent, the one that appears first in the array will be the left child and the other is the right child. You don't need to print anything, the driver code will print the level order traversal of the returned root node to verify the output.

Examples:

Input: parent[] = [-1, 0, 0, 1, 1, 3,5]
Output: 0 1 2 3 4 5 6
Explanation: the tree generated
will have a structure like 
          0
        /   \
       1     2
      / \
     3   4
    /
   5
 /
6
Input: parent[] = [2, 0, -1]
Output: 2 0 1
Explanation: the tree generated will
have a sturcture like
             2
            /   
           0      
          /   
         1     
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(n)

Constraints:
1 ≤ parent.size() ≤ 103

*/

class Solution {
  public:
    // Function to construct a binary tree from a parent array.
    Node *createTree(vector<int> parent) {
        // Intuition:
        // - We need to create a binary tree from a given parent array where each index represents
        //   a node and the value at each index represents the parent of that node.
        // - If the value is -1, it means that the node is the root.
        // - We first create nodes for each index and then link the nodes according to the parent array.
        
        // Time Complexity: O(N)
        // - We iterate through the parent array twice, so the time complexity is linear with respect to
        //   the number of nodes, which is N.
        
        // Space Complexity: O(N)
        // - We use additional space to store the nodes in a vector, so the space complexity is linear
        //   with respect to the number of nodes, which is N.
        
        int n = parent.size();  // Get the size of the parent array
        Node* root = NULL;  // Initialize the root to NULL
        vector<Node*> arr(n);  // Create a vector to store the nodes

        // Create nodes for each index
        for (int i = 0; i < n; i++) {
            if (parent[i] == -1) {
                arr[i] = new Node(i);  // Create the root node
                root = arr[i];  // Set the root
            } else {
                arr[i] = new Node(i);  // Create a node for each index
            }
        }

        // Link the nodes according to the parent array
        for (int i = 0; i < n; i++) {
            if (parent[i] != -1) {
                if (arr[parent[i]]->left == NULL) {
                    arr[parent[i]]->left = arr[i];  // Set left child
                } else {
                    arr[parent[i]]->right = arr[i];  // Set right child
                }
            }
        }

        return root;  // Return the root of the constructed tree
    }
};
