/*
Duplicate Subtrees
Difficulty: MediumAccuracy: 23.98%Submissions: 44K+Points: 4
Given a binary tree, your task is to find all duplicate subtrees from the given binary tree.

Duplicate Subtree : Two trees are duplicates if they have the same structure with the same node values.

Note:  Return the root of each tree in the form of a list array & the driver code will print the tree in pre-order tree traversal in lexicographically increasing order.

Examples:

Input : 
 
Output: 2 4   
        4
Explanation: The above tree have two duplicate subtrees.i.e 
  2
 /
4  and 4. Therefore, you need to return the above tree root in the form of a list.
Input:     5
          / \
         4   6
        / \
       3   4
          / \
         3   6
Output: 
3
6
Explanation: In the above tree, there are two duplicate subtrees.i.e
3 and 6. Therefore, you need to return the above subtrees root in the form of a list.
Expected Time Complexity: O(n)
Expected Space Complexity: O(n)

Constraints:
1<= size of binary tree <=100
*/

/**
 * Definition for a binary tree node.
 * struct Node {
 *     int data;
 *     Node* left;
 *     Node* right;
 *     Node(int val) : data(val), left(nullptr), right(nullptr) {}
 * };
 */

// Intuition:
// The problem is to find all duplicate subtrees in a binary tree. We can use a post-order traversal to serialize each subtree and use a map to count occurrences of each serialized subtree.
// If a serialized subtree appears more than once, we add the root node of that subtree to the result list.

// Time Complexity: O(n^2), where n is the number of nodes in the tree. In the worst case, each serialization operation can take O(n) time due to string concatenation.
// Space Complexity: O(n^2), where n is the number of nodes. This includes space for storing serialized strings and the recursion stack.

// Explanation:
// - We perform a post-order traversal of the tree to serialize each subtree.
// - We use a map to count the number of times each serialized subtree appears.
// - If a serialized subtree appears exactly twice, we add the root node of that subtree to the result list.

class Solution {
public:
    // Helper function to serialize the tree and count duplicates
    string solve(Node* root, unordered_map<string, int> &mp, vector<Node*> &ans) {
        if (!root)
            return "N";  // Null node is represented as "N"
            
        // Serialize the current subtree
        string s = to_string(root->data) + "," + solve(root->left, mp, ans) + "," + solve(root->right, mp, ans);
        mp[s]++;
        
        // If the subtree has been seen exactly twice, add the root to the result
        if (mp[s] == 2) {
            ans.push_back(root);
        }
        
        return s;
    }
    
    // Main function to find all duplicate subtrees
    vector<Node*> printAllDups(Node* root) {
        unordered_map<string, int> mp;  // Map to store serialized subtrees and their counts
        vector<Node*> ans;  // Result vector to store root nodes of duplicate subtrees
        solve(root, mp, ans);
        return ans;
    }
};
