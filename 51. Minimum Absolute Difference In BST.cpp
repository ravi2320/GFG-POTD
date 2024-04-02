/*
Minimum Absolute Difference In BST
MediumAccuracy: 56.22%Submissions: 15K+Points: 4
Given a binary search tree having n (n>1) nodes, the task is to find the minimum absolute difference between any two nodes.

Example 1:

Input:
Input tree

Output:
10
Explanation:
There are no two nodes whose absolute difference is smaller than 10.
Example 2:

Input:
Input tree

Output:
20
Explanation:
There are no two nodes whose absolute difference is smaller than 20.
Your Task:
You don't have to take any input. Just complete the function absolute_diff() , that takes root as input and return minimum absolute difference between any two nodes.

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(Height of tree)

Constraints:
2 <= n <= 105
1 <= Node->data <= 109

*/

/*
Intuition:
- We perform an in-order traversal of the binary tree to collect the values of nodes in a vector.
- After traversal, we iterate through the vector to compute the absolute difference between adjacent elements.
- We keep track of the minimum absolute difference found during this iteration.
- Finally, we return the minimum absolute difference.

Time Complexity: O(N)
- We traverse each node of the binary tree once during the in-order traversal to collect node values.
- We also iterate through the vector containing node values once to compute the absolute differences.
- N is the number of nodes in the binary tree.

Space Complexity: O(N)
- The space complexity is determined by the size of the vector used to store node values during the traversal.
- N is the number of nodes in the binary tree.
*/

class Solution
{
public:
    // Helper function for in-order traversal to collect node values in a vector
    void traverse(Node *root, vector<int> &arr)
    {
        if (root == NULL)
            return;

        // Traverse left subtree
        traverse(root->left, arr);

        // Push current node's value into the vector
        arr.push_back(root->data);

        // Traverse right subtree
        traverse(root->right, arr);
    }

    // Function to compute the minimum absolute difference in a binary tree
    int absolute_diff(Node *root)
    {
        vector<int> arr; // Vector to store node values during traversal
        traverse(root, arr); // Perform in-order traversal to collect node values

        int n = arr.size();
        int ans = INT_MAX; // Initialize the minimum absolute difference with INT_MAX

        // Iterate through the vector to compute absolute differences between adjacent elements
        for (int i = 0; i < n - 1; i++)
        {
            ans = min(ans, abs(abs(arr[i]) - abs(arr[i + 1]))); // Update minimum absolute difference
        }

        return ans; // Return the minimum absolute difference
    }
};



/*
Intuition:
- We perform an in-order traversal of the binary tree, keeping track of the previous node's value.
- At each node, we compute the absolute difference between the current node's value and the previous node's value.
- We update the minimum absolute difference found so far.
- Finally, we return the minimum absolute difference.

Time Complexity: O(N)
- We traverse each node of the binary tree once during the in-order traversal.
- N is the number of nodes in the binary tree.

Space Complexity: O(H)
- The space complexity is determined by the call stack during the recursive traversal.
- H is the height of the binary tree, which represents the maximum depth of the call stack.
*/

class Solution
{
public:
    // Helper function for in-order traversal to compute absolute difference
    void traverse(Node *root, int &prev, int &ans)
    {
        if (root == NULL)
            return;

        // Traverse left subtree
        traverse(root->left, prev, ans);

        // Calculate absolute difference between current node and previous node
        if (prev != INT_MAX) // Check if prev has been set
            ans = min(ans, abs(abs(root->data) - abs(prev)));

        // Update prev for the next iteration
        prev = root->data;

        // Traverse right subtree
        traverse(root->right, prev, ans);
    }

    // Function to compute the minimum absolute difference in a binary tree
    int absolute_diff(Node *root)
    {
        int prev = INT_MAX; // Initialize prev with INT_MAX
        int ans = INT_MAX;  // Initialize ans with INT_MAX

        // Perform in-order traversal to compute minimum absolute difference
        traverse(root, prev, ans);

        return ans;
    }
};
