/*
Symmetric Tree
Difficulty: EasyAccuracy: 44.96%Submissions: 161K+Points: 2Average Time: 20m
Given the root of a binary tree, check whether it is symmetric, i.e., whether the tree is a mirror image of itself.


A binary tree is symmetric if the left subtree is a mirror reflection of the right subtree.

Examples:

Input: root[] = [1, 2, 2, 3, 4, 4, 3]
   ex-1_1
Output: True
Explanation: As the left and right half of the above tree is mirror image, tree is symmetric.
Input: root[] = [1, 2, 2, N, 3, N, 3]
   ex-2_1
Output: False
Explanation:  As the left and right half of the above tree is not the mirror image, tree is not symmetric. 
Constraints:
1  ≤ number of nodes ≤ 2000
*/

/*
Approach:
This is the iterative version of checking if a binary tree is symmetric.
We use a queue to simulate the comparison between nodes that should be mirrors.
Initially, we enqueue the left and right child of the root.

In each step, we dequeue two nodes (t1 and t2) and compare:
- If both are null, we continue.
- If one is null or their values don't match, the tree is not symmetric.

Then we enqueue children in a mirrored fashion:
- t1->left with t2->right
- t1->right with t2->left

Intuition:
We simulate the recursive isMirror check using a queue and process it level by level.

Time Complexity: O(n)
Each node is visited once.

Space Complexity: O(n)
In worst case, the queue holds O(n) nodes (i.e., at the bottom level).
*/

class Solution {
  public:
    bool isSymmetric(Node* root) {
        if (!root) return false;  // Empty tree is not symmetric per problem constraints

        queue<Node*> q;
        q.push(root->left);
        q.push(root->right);

        while (!q.empty()) {
            Node* t1 = q.front(); q.pop();
            Node* t2 = q.front(); q.pop();

            // If both nodes are null, continue to next pair
            if (!t1 && !t2) continue;

            // If one is null or values are different, not symmetric
            if (!t1 || !t2 || t1->data != t2->data) return false;

            // Enqueue mirrored children
            q.push(t1->left);
            q.push(t2->right);
            q.push(t1->right);
            q.push(t2->left);
        }

        return true;  // Tree is symmetric
    }
};


/*
Approach:
To check if a binary tree is symmetric, we recursively compare the left and right
subtrees. The tree is symmetric if the left subtree is a mirror reflection of the right.

We use a helper function `isMirror(t1, t2)` that returns true if:
- t1 and t2 are both null, or
- t1 and t2 are not null, their values are equal, and:
    - left child of t1 is a mirror of right child of t2, and
    - right child of t1 is a mirror of left child of t2.

Intuition:
Mirror trees have structure: 
left of one == right of the other and right of one == left of the other.

Time Complexity: O(n)
We visit each node once to check symmetry.

Space Complexity: O(h)
Where h is the height of the tree (due to recursive call stack). Worst case O(n), best case O(log n).
*/

class Solution {
  public:
    // Recursive helper to check if two trees are mirror images
    bool isMirror(Node* t1, Node* t2) {
        if (!t1 && !t2) return true;  // Both nodes are null: symmetric
        if (!t1 || !t2) return false; // One is null, the other isn't: not symmetric

        // Check current node data and mirror subtrees
        return (t1->data == t2->data) &&
               isMirror(t1->left, t2->right) &&
               isMirror(t1->right, t2->left);
    }

    // Main function to check if tree is symmetric around root
    bool isSymmetric(Node* root) {
        if (!root) return false;  // Empty tree is not symmetric per problem constraint
        return isMirror(root->left, root->right);  // Start mirror check from root's children
    }
};