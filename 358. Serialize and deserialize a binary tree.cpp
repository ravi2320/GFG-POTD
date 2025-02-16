/*
Serialize and deserialize a binary tree
Difficulty: MediumAccuracy: 51.67%Submissions: 87K+Points: 4Average Time: 45m
Serialization is to store a tree in an array so that it can be later restored and deserialization is reading tree back from the array. Complete the functions

serialize() : stores the tree into an array a and returns the array.
deSerialize() : deserializes the array to the tree and returns the root of the tree.
Note: Multiple nodes can have the same data and the node values are always positive integers. Your code will be correct if the tree returned by deSerialize(serialize(input_tree)) is same as the input tree. Driver code will print the in-order traversal of the tree returned by deSerialize(serialize(input_tree)).

Examples :

Input: root = [1, 2, 3]
      
Output: [2, 1, 3]
Input: root = [10, 20, 30, 40, 60, N, N]
      
Output: [40, 20, 60, 10, 30]
Constraints:
1 <= Number of nodes <= 104
1 <= Data of a node <= 109
*/

class Solution {
    int i = 0; // Index for deserialization
    
  public:
    /**
     * Approach:
     * - **Serialization:** Perform a **preorder traversal** (Root -> Left -> Right), 
     *   appending `-1` for NULL nodes.
     * - **Deserialization:** Reconstruct the tree using the stored values, 
     *   processing elements in order.
     * 
     * Intuition:
     * - The tree structure is preserved as we traverse in **preorder**.
     * - `-1` acts as a marker for NULL, ensuring correct reconstruction.
     * 
     * Time Complexity:
     * - `serialize()`: O(N) since we visit every node once.
     * - `deSerialize()`: O(N) as we construct each node once.
     * 
     * Space Complexity:
     * - O(N) for the serialized vector.
     * - O(H) recursive stack space for tree reconstruction (H = logN for balanced, N for skewed).
     */

    // Function to perform preorder traversal and serialize the tree.
    void preorder(Node *root, vector<int> &arr) {
        if (!root) {
            arr.push_back(-1); // Mark NULL nodes
            return;  
        } 
        
        arr.push_back(root->data); // Store current node
        preorder(root->left, arr); // Serialize left subtree
        preorder(root->right, arr); // Serialize right subtree
    }

    // Function to serialize a tree into a list of integers.
    vector<int> serialize(Node *root) {
        vector<int> arr;
        preorder(root, arr);
        return arr;
    }

    // Function to deserialize a list and reconstruct the tree.
    Node* deSerialize(vector<int> &arr) {
        int val = arr[i++];
        if (val == -1) {
            return NULL; // NULL node encountered
        }
        
        Node *newNode = new Node(val);
        newNode->left = deSerialize(arr); // Construct left subtree
        newNode->right = deSerialize(arr); // Construct right subtree
        
        return newNode;
    }
};