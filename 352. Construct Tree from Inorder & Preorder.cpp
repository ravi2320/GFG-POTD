/*
Construct Tree from Inorder & Preorder
Difficulty: MediumAccuracy: 34.59%Submissions: 180K+Points: 4Average Time: 20m
Given two arrays representing the inorder and preorder traversals of a binary tree, construct the tree and return the root node of the constructed tree.

Note: The output is written in postorder traversal.

Examples:

Input: inorder[] = [1, 6, 8, 7], preorder[] = [1, 6, 7, 8]
Output: [8, 7, 6, 1]
Explanation: The tree will look like

Input: inorder[] = [3, 1, 4, 0, 2, 5], preorder[] = [0, 1, 3, 4, 2, 5]
Output: [3, 4, 1, 5, 2, 0]
Explanation: The tree will look like

Input: inorder[] = [2, 5, 4, 1, 3], preorder[] = [1, 4, 5, 2, 3]
Output: [2, 5, 4, 3, 1]
Explanation: The tree will look like

Constraints:
1 ≤ number of nodes ≤ 103
0 ≤ nodes -> data ≤ 103
Both the inorder and preorder arrays contain unique values.
*/

/*
Approach:
1. Use the **preorder traversal** to determine the root node:
   - The first element in the preorder list is the root of the current subtree.
2. Find the position of the root in the **inorder traversal**:
   - Elements to the left of the root in the inorder traversal form the left subtree.
   - Elements to the right form the right subtree.
3. Recursively build the left and right subtrees using the identified partitions in the inorder traversal.
4. Continue this process until all nodes are correctly positioned.

Intuition:
- Preorder gives us the root first, and inorder helps us split the tree into left and right subtrees.

Time Complexity:
- **O(N²)** in the worst case due to the linear search for root in inorder.
  - Can be improved to **O(N)** using a hashmap for inorder index lookup.

Space Complexity:
- **O(N)** for recursion stack (in case of skewed trees).
*/

class Solution {
  public:
    // Helper function to construct the tree
    Node* solve(vector<int> &inorder, vector<int> &preorder, int start, int end , int &idx){
        if (start > end) {
            return NULL;  // Base case: no elements to construct the tree
        }
        
        // Select the current root from preorder traversal
        int rootVal = preorder[idx++];
        Node* root = new Node(rootVal);
        
        // Find the root in the inorder traversal
        int i = start;
        while (i <= end) {
            if (inorder[i] == rootVal) {
                break;
            }
            i++;
        }
        
        // Construct the left and right subtrees
        root->left = solve(inorder, preorder, start, i - 1, idx);
        root->right = solve(inorder, preorder, i + 1, end, idx);
        
        return root;
    }
    
    // Main function to build the tree
    Node* buildTree(vector<int> &inorder, vector<int> &preorder) {
        int idx = 0; // Index to keep track of the current root in preorder traversal
        return solve(inorder, preorder, 0, inorder.size() - 1, idx);
    }
};

/*
Optimized Approach with HashMap:
- Preprocessing the inorder traversal to store the index of each value for O(1) lookup.
- This eliminates the O(N) search in the inorder traversal for each recursive call.

Time Complexity: O(N)
Space Complexity: O(N) (due to hashmap and recursion stack)
*/

class Solution {
  public:
    Node* solve(vector<int> &inorder, vector<int> &preorder, int start, int end, int &idx, unordered_map<int, int> &inorderMap) {
        if (start > end) {
            return NULL;
        }

        int rootVal = preorder[idx++];
        Node* root = new Node(rootVal);

        int i = inorderMap[rootVal];  // O(1) lookup for root index

        root->left = solve(inorder, preorder, start, i - 1, idx, inorderMap);
        root->right = solve(inorder, preorder, i + 1, end, idx, inorderMap);

        return root;
    }

    Node* buildTree(vector<int> &inorder, vector<int> &preorder) {
        unordered_map<int, int> inorderMap;
        for (int i = 0; i < inorder.size(); i++) {
            inorderMap[inorder[i]] = i;  // Preprocessing
        }

        int idx = 0;
        return solve(inorder, preorder, 0, inorder.size() - 1, idx, inorderMap);
    }
};