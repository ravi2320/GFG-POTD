/*
Binary Tree to DLL
Difficulty: HardAccuracy: 53.36%Submissions: 138K+Points: 8
Given a Binary Tree (BT), convert it to a Doubly Linked List (DLL) in place. The left and right pointers in nodes will be used as previous and next pointers respectively in converted DLL. The order of nodes in DLL must be the same as the order of the given Binary Tree. The first node of Inorder traversal (leftmost node in BT) must be the head node of the DLL.

Note: h is the tree's height, and this space is used implicitly for the recursion stack.

TreeToList

Examples:

Input:
      1
    /  \
   3    2
Output:
3 1 2 
2 1 3

Explanation: DLL would be 3<=>1<=>2
Input:
       10
      /   \
     20   30
   /   \
  40   60
Output:
40 20 60 10 30 
30 10 60 20 40

Explanation:  DLL would be 40<=>20<=>60<=>10<=>30.
Expected Time Complexity: O(no. of nodes)
Expected Space Complexity: O(height of the tree)

Constraints:
1 ≤ Number of nodes ≤ 105
0 ≤ Data of a node ≤ 105
*/

/*
Approach:
1. We need to convert a Binary Tree to a Doubly Linked List (DLL) in-place where the DLL should be sorted in the order of an in-order traversal.
2. The in-order traversal of the Binary Tree naturally visits nodes in a sorted order (left subtree, root, right subtree).
3. We use an auxiliary function `inorder` that:
   - Recursively visits each node.
   - Converts the node to a DLL node and links it to the current position in the list.
4. We maintain two pointers, `head` (pointing to the head of the DLL) and `curr` (tracking the current node in the DLL).

Time Complexity:
- O(n): We traverse each node of the tree exactly once during the in-order traversal.

Space Complexity:
- O(h): The space complexity is O(h), where `h` is the height of the binary tree, due to the recursion stack for the in-order traversal. In the worst case (for a skewed tree), this could be O(n), but for a balanced tree, it is O(log n).

*/

class Solution {
  public:
    // Helper function to perform in-order traversal and convert tree to DLL
    void inorder(Node* root, Node* &head, Node* &curr) {
        if (!root) return;
        
        // Traverse the left subtree
        inorder(root->left, head, curr);
        
        // Process the current node
        if (!head) {
            // If head is null, it means this is the first node being processed (smallest node)
            head = new Node(root->data);  // Set the head of the DLL
            curr = head;  // Current node points to head initially
        } else {
            // Create a new DLL node and link it with the previous node
            curr->right = new Node(root->data);  // Link the new node to the right
            curr->right->left = curr;  // Link the current node to the previous node (left)
            curr = curr->right;  // Move to the new current node
        }
        
        // Traverse the right subtree
        inorder(root->right, head, curr);
    }
    
    // Main function to convert a binary tree to a doubly linked list
    Node* bToDLL(Node* root) {
        if (!root) return NULL;
        
        Node* head = NULL;  // Head of the doubly linked list
        Node* curr = NULL;  // Current node pointer for constructing the DLL
        
        // Perform in-order traversal and build the DLL
        inorder(root, head, curr);
        
        return head;  // Return the head of the DLL
    }
};
