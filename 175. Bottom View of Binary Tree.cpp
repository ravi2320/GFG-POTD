/*
Bottom View of Binary Tree
Difficulty: MediumAccuracy: 54.18%Submissions: 246K+Points: 4
Given a binary tree, return an array where elements represent the bottom view of the binary tree from left to right.

Note: If there are multiple bottom-most nodes for a horizontal distance from the root, then the latter one in the level traversal is considered. For example, in the below diagram, 3 and 4 are both the bottommost nodes at a horizontal distance of 0, here 4 will be considered.

                      20
                    /    \
                  8       22
                /   \     /   \
              5      3 4     25
                     /    \      
                 10       14

For the above tree, the output should be 5 10 4 14 25.

Examples :

Input:
       1
     /   \
    3     2
Output: 3 1 2
Explanation: First case represents a tree with 3 nodes and 2 edges where root is 1, left child of 1 is 3 and right child of 1 is 2.

Thus bottom view of the binary tree will be 3 1 2.
Input:
         10
       /    \
      20    30
     /  \
    40   60
Output: 40 20 60 30
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(n)

Constraints:
1 <= Number of nodes <= 105
1 <= Data of a node <= 105
*/

#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Intuition: To get the bottom view of a binary tree, we use a breadth-first traversal (level order traversal)
// and keep track of the horizontal distance of each node from the root. The bottom view will contain the last
// node at each horizontal distance as seen from the bottom.

// Time Complexity: O(n), where n is the number of nodes in the binary tree. Each node is processed once.

// Space Complexity: O(n) for the map and queue used to store nodes and their horizontal distances.

class Solution {
public:
    vector<int> bottomView(Node* root) {
        vector<int> ans;
        if (!root) return ans;
        
        map<int, int> mp; // map to store the bottom-most node at each horizontal distance
        queue<pair<Node*, int>> q; // queue for level order traversal (node, horizontal distance)
        
        q.push({root, 0});
        
        while (!q.empty()) {
            auto itr = q.front();
            q.pop();
            
            Node* node = itr.first;
            int line = itr.second;
            
            // Update the map with the current node at the given horizontal distance
            mp[line] = node->data;
            
            // If left child exists, push it to the queue with horizontal distance line-1
            if (node->left) {
                q.push({node->left, line - 1});
            }
            
            // If right child exists, push it to the queue with horizontal distance line+1
            if (node->right) {
                q.push({node->right, line + 1});
            }
        }
        
        // Collect the bottom-most nodes from the map into the result vector
        for (auto& itr : mp) {
            ans.push_back(itr.second);
        }
        
        return ans;
    }
};

int main() {
    Node* root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(22);
    root->left->left = new Node(5);
    root->left->right = new Node(3);
    root->right->left = new Node(4);
    root->right->right = new Node(25);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(14);

    Solution sol;
    vector<int> result = sol.bottomView(root);

    for (int val : result) {
        cout << val << " ";
    }
    // Output: 5 10 4 14 25

    return 0;
}
