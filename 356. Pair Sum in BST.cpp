/*
Pair Sum in BST
Difficulty: MediumAccuracy: 44.02%Submissions: 68K+Points: 4Average Time: 40m
Given a Binary Search Tree(BST) and a target. Check whether there's a pair of Nodes in the BST with value summing up to the target. 

Examples:

Input: root = [7, 3, 8, 2, 4, N, 9], target = 12
       bst
Output: True
Explanation: In the binary tree above, there are two nodes (8 and 4) that add up to 12.
Input: root = [9, 5, 10, 2, 6, N, 12], target = 23
          bst-3
Output: False
Explanation: In the binary tree above, there are no such two nodes exists that add up to 23.
Constraints:

1 ≤ Number of Nodes ≤ 105
1 ≤ target ≤ 106
*/

/*
Approach:
1. **Use an unordered_set (hash set)**:
   - Store values of nodes while performing an inorder traversal.
   - Check if `target - currentNodeValue` already exists in the set.
   - If it does, return `true` (pair found).
   - Otherwise, insert the current node’s value into the set.

2. **Inorder Traversal**:
   - Since it's a BST, **inorder traversal** gives elements in **sorted order**.
   - This ensures that we efficiently check for a pair sum while traversing.

Intuition:
- A **BST** allows for efficient searching.
- Using a **hash set** allows us to check for complement values in **O(1)**.
- The traversal ensures we check each value only once, leading to an efficient solution.

Time Complexity: **O(N)**
- Each node is **visited once** → O(N) traversal.
- Checking and inserting in an **unordered_set** is **O(1)** on average.
- Thus, overall complexity is **O(N)**.

Space Complexity: **O(N)**
- In the worst case, the **hash set** stores all `N` values → O(N).
*/

class Solution {
  public:
    void inorder(Node* root, int &target, unordered_set<int> &st, bool &ans) {
        if (!root || ans) return; // Stop if root is NULL or answer is already found
        
        // Inorder traversal: Left -> Root -> Right
        inorder(root->left, target, st, ans);

        // Check if the complement exists in the set
        if (st.count(target - root->data)) {
            ans = true;
            return;
        }
        
        // Insert current node value into the set
        st.insert(root->data);

        inorder(root->right, target, st, ans);
    }

    bool findTarget(Node *root, int target) {
        unordered_set<int> st; // Hash set to store visited values
        bool ans = false; 
        
        inorder(root, target, st, ans);
        
        return ans;
    }
};
