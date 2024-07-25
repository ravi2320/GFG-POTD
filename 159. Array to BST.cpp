/*
Array to BST
Difficulty: EasyAccuracy: 46.02%Submissions: 67K+Points: 2
Given a sorted array. Convert it into a Height Balanced Binary Search Tree (BST). Return the root of the BST.

Height-balanced BST means a binary tree in which the depth of the left subtree and the right subtree of every node never differ by more than 1.

Note: The driver code will check the BST, if it is a Height-balanced BST, the output will be true otherwise the output will be false.

Examples :

Input: nums = [1, 2, 3, 4]
Output: true
Explanation: The preorder traversal of the following BST formed is [2, 1, 3, 4]:
           2
         /   \
        1     3
               \
                4
Input: nums = [1, 2, 3, 4, 5, 6, 7]
Ouput: true
Explanation: The preorder traversal of the following BST formed is [4, 2, 1, 3, 6, 5, 7]:
        4
       / \
      2   6
     / \   / \
    1 3  5 7
Expected Time Complexity: O(n)
Expected Auxillary Space: O(n)

Constraints:
1 ≤ nums.size() ≤ 105
1 ≤ nums[i] ≤ 105
*/

/**
 * Intuition:
 * - **Building BST from Inorder Traversal:** Given a sorted array, the middle element should be the root of the BST to maintain the balanced property. The elements to the left of the middle element form the left subtree, and the elements to the right form the right subtree. This can be done recursively.
 *
 * Time Complexity: O(n)
 * - Each element in the array is processed once, resulting in a linear time complexity.
 *
 * Space Complexity: O(log n)
 * - The space complexity is due to the recursive call stack. In the best case (perfectly balanced tree), the depth of recursion is log(n).
 */

class Solution {
  public:
    // Helper function to build a BST from a sorted array.
    Node* buildBstFromInorder(vector<int> &nums, int start, int end) {
        if (start > end) {
            return NULL;
        }
        
        int mid = (start + end) / 2;
        
        // Create a new node with the middle element of the array.
        Node* node = new Node(nums[mid]);
        
        // Recursively build the left and right subtrees.
        node->left = buildBstFromInorder(nums, start, mid - 1);
        node->right = buildBstFromInorder(nums, mid + 1, end);
        
        return node;
    }

    // Function to convert a sorted array into a balanced BST.
    Node* sortedArrayToBST(vector<int>& nums) {
        // Start the recursive process with the full array.
        return buildBstFromInorder(nums, 0, nums.size() - 1);
    }
};
