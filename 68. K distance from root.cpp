/*
K distance from root
EasyAccuracy: 52.18%Submissions: 91K+Points: 2
 Done with winning Geekbits? Now win GfG Bag, GfG T-shirt & much more just by writing your experiences. Start Writing, Start Winning.
banner
Given a binary tree having n nodes and an integer k. Print all nodes that are at distance k from the root (root is considered at distance 0 from itself). Nodes should be printed from left to right.

Example 1:

Input:
k = 0
      1
    /   \
   3     2
Output: 
1
Explanation: 
1 is the only node which is 0 distance from the root 1.
Example 2:

Input:
k = 3
        1
       /
      2
       \
        1
      /  \
     5    3
Output: 
5 3
Explanation:  
5 and 3 are the nodes which are at distance 3 from the root 3.
Here, returning 3 5 will be incorrect.
Your Task:
You don't have to take input. Complete the function Kdistance() that accepts root node and k as parameters and returns the value of the nodes that are at a distance k from the root.

Expected Time Complexity: O(n).
Expected Auxiliary Space: O(Height of the Tree).

Constraints:
1 <= n <= 104
0 <= k <= 30
*/

// Intuition:
// This class provides a method to find nodes at distance k from the root in a binary tree.
// It performs a level-order traversal of the binary tree using a queue.
// It counts the levels traversed until it reaches the kth level.
// Then, it extracts the nodes at that level and returns them as the result.

// Time Complexity: O(N)
// - N is the number of nodes in the binary tree.
// - The algorithm traverses all nodes in the worst case.

// Space Complexity: O(N)
// - The space required for the queue can be up to O(N) in the worst case.

#include <vector>
#include <queue>
using namespace std;

// Definition for a binary tree node.
struct Node {
    int data;
    Node* left;
    Node* right;
};

class Solution {
public:
    // Function to find nodes at distance k from the root
    vector<int> Kdistance(struct Node* root, int k) {
        if (k == 0)
            return {root->data}; // If k is 0, return the root's data

        queue<struct Node*> q;
        q.push(root);
        int level = 0; // Variable to track the current level

        // Traverse the binary tree level by level until reaching the kth level
        while (!q.empty()) {
            int size = q.size();
            level++;

            // Process nodes at the current level
            while (size--) {
                struct Node* temp = q.front();
                q.pop();

                // Enqueue the left and right children of the current node, if they exist
                if (temp->left) q.push(temp->left);
                if (temp->right) q.push(temp->right);
            }

            // If the current level is equal to k, break the loop
            if (level == k) break;
        }

        vector<int> ans;

        // Extract nodes at distance k from the root
        while (!q.empty()) {
            struct Node* temp = q.front();
            ans.push_back(temp->data);
            q.pop();
        }

        return ans; // Return the nodes at distance k from the root
    }
};
