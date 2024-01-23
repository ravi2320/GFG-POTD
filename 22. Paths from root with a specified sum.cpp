/*
Paths from root with a specified sum
MediumAccuracy: 55.0%Submissions: 35K+Points: 4
30+ People have Claimed their 90% Refunds. Start Your Journey Today! 

banner
Given a Binary tree and a sum S, print all the paths, starting from root, that sums upto the given sum. Path not necessarily end on a leaf node.

Example 1:

Input : 
sum = 8
Input tree
         1
       /   \
     20      3
           /    \
         4       15   
        /  \     /  \
       6    7   8    9      

Output :
1 3 4
Explanation : 
Sum of path 1, 3, 4 = 8.
Example 2:

Input : 
sum = 38
Input tree
          10
       /     \
     28       13
           /     \
         14       15
        /   \     /  \
       21   22   23   24
Output :
10 28
10 13 15  
Explanation :
Sum of path 10, 28 = 38 and
Sum of path 10, 13, 15 = 38.
Your task :
You don't have to read input or print anything. Your task is to complete the function printPaths() that takes the root of the tree and sum as input and returns a vector of vectors containing the paths that lead to the sum.
 
Expected Time Complexity: O(N)
Expected Space Complexity: O(N2)
 
Your Task :
1 <= N <= 2*103
-103 <= sum, Node.key <= 103
*/

class Solution
{
    public:
    void f(Node *root, int sum, int cs, vector<int> temp, vector<vector<int>> &ans){
        if(root==NULL) return;
        temp.push_back(root->key);
        cs+=root->key;
        if(cs == sum){
            
            ans.push_back(temp);
        }
        
        f(root->right, sum, cs, temp, ans);
        f(root->left, sum, cs, temp, ans);
    }
    vector<vector<int>> printPaths(Node *root, int sum)
    {
        //code here
        vector<vector<int>> ans;
        vector<int> temp;
        int cs=0;
        f(root, sum, cs, temp, ans);
        return ans;
    }
};