/*
Left View of Binary Tree
Difficulty: EasyAccuracy: 33.74%Submissions: 508K+Points: 2
Given a Binary Tree, return Left view of it. Left view of a Binary Tree is set of nodes visible when tree is visited from Left side. The task is to complete the function leftView(), which accepts root of the tree as argument. If no left view is possible, return an empty tree.

Left view of following tree is 1 2 4 8.

          1
       /     \
     2        3
   /     \    /    \
  4     5   6    7
   \
     8   

Examples :

Input:
   1
 /  \
3    2
Output: 1 3

Input:

Output: 10 20 40
Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
0 <= Number of nodes <= 105
0 <= Data of a node <= 105
*/

/*
Intuition:
- The left view of a binary tree consists of the leftmost nodes at each level. 
- A pre-order traversal (root, left, right) is well-suited for this task because we can explore the left subtree before the right subtree.
- By keeping track of the level during the traversal and checking if the current level has been visited, we can ensure that only the first node encountered at each level is added to the result.

Time Complexity:
- The time complexity is O(n), where n is the number of nodes in the binary tree. We visit each node exactly once.

Space Complexity:
- The space complexity is O(h), where h is the height of the tree. This accounts for the recursion stack during the traversal, which can go as deep as the height of the tree.
*/

void preOrder(Node *root, int level, vector<int> &ans) {
    if (!root) return; // Base case: if the node is null, return
    
    // If we are visiting this level for the first time, add the node's data to the result
    if (level == ans.size()) {
        ans.push_back(root->data);
    }
    
    // Recursively traverse the left subtree
    preOrder(root->left, level + 1, ans);
    // Recursively traverse the right subtree
    preOrder(root->right, level + 1, ans);
}

vector<int> leftView(Node *root) {
   // Vector to store the left view nodes
   vector<int> ans;
   
   // Start the pre-order traversal from the root at level 0
   preOrder(root, 0, ans);
   
   // Return the result
   return ans;
}
