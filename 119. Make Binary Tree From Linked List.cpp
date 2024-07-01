/*
Make Binary Tree From Linked List
Difficulty: MediumAccuracy: 65.65%Submissions: 49K+Points: 4
Given a Linked List Representation of Complete Binary Tree. Your task is to construct the Binary tree from the given linkedlist and return the root of the tree.
The result will be judged by printing the level order traversal of the Binary tree. 
Note: The complete binary tree is represented as a linked list in a way where if the root node is stored at position i, its left, and right children are stored at position 2*i+1, and 2*i+2 respectively. H is the height of the tree and this space is used implicitly for the recursion stack.

Examples:

Input: list = 1->2->3->4->5
Output: 1 2 3 4 5
Explanation: The tree would look like
      1
    /   \
   2     3
 /  \
4   5
Now, the level order traversal of
the above tree is 1 2 3 4 5.
Input: list = 5->4->3->2->1
Output: 5 4 3 2 1
Explanation: The tree would look like
     5
   /  \
  4    3
 / \
2   1
Now, the level order traversal of
the above tree is 5 4 3 2 1.
Expected Time Complexity: O(n).
Expected Auxiliary Space: O(n).
Constraints:
1 <= size(list) <= 105
1 <= node.data <= 105
*/

// Intuition:
// The problem is to convert a singly linked list into a complete binary tree. 
// The approach involves first storing the linked list elements in an array. 
// Using this array, the binary tree is constructed by recursively setting the left and right children of each node.

// Time Complexity: O(n), where n is the number of elements in the linked list. 
// We traverse the list once to create the array and then traverse the array to construct the tree.
// Space Complexity: O(n), as we store the elements of the linked list in an array.

class Solution {
public:
    // Helper function to construct the binary tree from the array
    void constructBinaryTree(int idx, vector<int> &arr, TreeNode* &node) {
        node = new TreeNode(arr[idx]); // Create a new tree node with the current element
        
        int left = idx * 2 + 1;  // Calculate the index of the left child
        int right = idx * 2 + 2; // Calculate the index of the right child
        
        // Recursively construct the left subtree if the index is within bounds
        if (left < arr.size())
            constructBinaryTree(left, arr, node->left);
        else
            return;
            
        // Recursively construct the right subtree if the index is within bounds
        if (right < arr.size())
            constructBinaryTree(right, arr, node->right);
    }
    
    // Function to convert a linked list to a binary tree
    void convert(Node *head, TreeNode *&root) {
        vector<int> arr;  // Vector to store the elements of the linked list
        Node* temp = head; // Temporary pointer to traverse the linked list
        
        // Traverse the linked list and store the elements in the array
        while (temp) {
            arr.push_back(temp->data);
            temp = temp->next;
        }
        
        // Construct the binary tree from the array
        constructBinaryTree(0, arr, root);
    }
};
