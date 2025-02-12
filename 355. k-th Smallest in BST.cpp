/*
k-th Smallest in BST
Difficulty: MediumAccuracy: 43.53%Submissions: 134K+Points: 4Average Time: 40m
Given a BST and an integer k, the task is to find the kth smallest element in the BST. If there is no kth smallest element present then return -1.

Examples:

Input: root = [2, 1, 3], k = 2
    
Output: 2
Explanation: 2 is the 2nd smallest element in the BST.
Input: root = [2, 1, 3], k = 5
    
Output: -1
Explanation: There is no 5th smallest element in the BST as the size of BST is 3.
Input: root = [20, 8, 22, 4, 12, N, N, N, N, 10, 14], k = 3
     
Output: 10
Explanation: 10 is the 3rd smallest element in the BST.
Constraints:

1 <= number of nodes, k <= 105
1 <= node->data <= 105
*/

/*
Approach:
1. **Inorder traversal (Left → Root → Right)**:
   - This **naturally sorts** the BST elements in ascending order.
   - Traverse the BST **recursively**, decrementing `k` at each visited node.
   - When `k == 0`, store the `root->data` as the answer and return.

Intuition:
- A BST's inorder traversal gives **sorted order**.
- By maintaining a **counter `k`**, we can stop early when `k == 0`.

Time Complexity: **O(H + K)**  
- In the **worst case**, traversal goes down to the leaf nodes **O(H)**.
- It stops early when **K-th element is found**, making it **O(K)**.

Space Complexity:  
- **O(H)** for recursive call stack (where H = height of BST).
- **O(log N)** for a **balanced BST**.
- **O(N)** for a **skewed BST**.
*/

class Solution {
public:
    // Helper function for inorder traversal
    void inorder(Node* root, int &k, int &ans) {
        if (!root) return;

        inorder(root->left, k, ans); // Visit left subtree

        k--; // Decrement K when visiting a node
        if (k == 0) {
            ans = root->data; // Found the Kth smallest element
            return;
        }

        inorder(root->right, k, ans); // Visit right subtree
    }

    int kthSmallest(Node* root, int k) {
        int ans = -1; // Default value if not found
        inorder(root, k, ans);
        return ans;
    }
};