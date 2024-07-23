/*
Merge two BST 's
Difficulty: MediumAccuracy: 64.95%Submissions: 69K+Points: 4
Given two BSTs, return elements of merged BSTs in sorted form.

Examples :

Input:
BST1:
       5
     /   \
    3     6
   / \
  2   4  
BST2:
        2
      /   \
     1     3
            \
             7
            /
           6
Output: 1 2 2 3 3 4 5 6 6 7
Explanation: After merging and sorting the two BST we get 1 2 2 3 3 4 5 6 6 7.
Input:
BST1:
       12
     /   
    9
   / \    
  6   11
BST2:
      8
    /  \
   5    10
  /
 2
Output: 2 5 6 8 9 10 11 12
Explanation: After merging and sorting the two BST we get 2 5 6 8 9 10 11 12.
Expected Time Complexity: O(m+n)
Expected Auxiliary Space: O(Height of BST1 + Height of BST2 + m + n)

Constraints:
1 ≤ Number of Nodes ≤ 105
*/

/**
 * Intuition:
 * 1. **Inorder Traversal:** Traverse both BSTs in inorder to get their elements in sorted order.
 * 2. **Merge Sorted Arrays:** Merge the two sorted arrays obtained from the inorder traversals.
 *
 * Time Complexity: O(n + m)
 * - O(n + m) for inorder traversal of both trees.
 * - O(n + m) for merging the two sorted arrays.
 *
 * Space Complexity: O(n + m)
 * - Space for storing the inorder traversal results of both trees.
 */

class Solution {
  public:
    // Helper function to perform inorder traversal and collect nodes in a list
    void inorder(Node* root, vector<int> &res){
        if(!root) return;
        
        inorder(root->left, res);
        res.push_back(root->data);
        inorder(root->right, res);
    }
    
    // Function to return a list of integers denoting the node values of both the BST in sorted order
    vector<int> merge(Node *root1, Node *root2) {
        vector<int> first, second;
        inorder(root1, first);
        inorder(root2, second);
        
        vector<int> ans;
        int n = first.size();
        int m = second.size();
        int i = 0;
        int j = 0;
        
        // Merge the two sorted lists
        while(i < n && j < m){
            if(first[i] <= second[j]){
                ans.push_back(first[i++]);
            }
            else{
                ans.push_back(second[j++]);
            }
        }
        
        // Add remaining elements from first list if any
        while(i < n){
            ans.push_back(first[i++]);
        }
        
        // Add remaining elements from second list if any
        while(j < m){
            ans.push_back(second[j++]);
        }
        
        return ans;
    }
};
