/*
Check if all leaves are at same level
EasyAccuracy: 39.47%Submissions: 108K+Points: 2
Internship Alert!
Become an SDE Intern by topping this monthly leaderboard! 

banner
 


Take a moment and Share your insight on January special.


 

Given a binary tree with n nodes, determine whether all the leaf nodes are at the same level or not. Return true if all leaf nodes are at the same level, and false otherwise.

Example 1:

Input:
Tree:
    1
   / \
  2   3
Output:
true
Explanation:
The binary tree has a height of 2 and the leaves are at the same level.
Example 2:

Input:
Tree:
    10
   /  \
 20   30
 /  \
 10   15
Output:
false
Explanation:
The binary tree has a height of 3 and the leaves are not at the same level.
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(height of tree)

Your Task:
Implement the function check() that checks whether all the leaf nodes in the given binary tree are at the same level or not. The function takes the root node of the tree as an input and should return a boolean value (true/false) based on the condition.

Constraints:
1 ≤ n ≤ 105
*/

class Solution{
  public:
    /*You are required to complete this method*/
    
    bool check(Node *root)
    {
        //Your code here
        if(!root) return 1;
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        int same = -1;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                Node *front = q.front().first;
                int level = q.front().second;
                q.pop();
                if(!front->right && !front->left){
                    if(same == -1) same = level;
                    else if(same != level) return false;
                }
                if(front->right) q.push({front->right, level+1});
                if(front->left) q.push({front->left, level+1});
            }
        }
        return true;
    }
};