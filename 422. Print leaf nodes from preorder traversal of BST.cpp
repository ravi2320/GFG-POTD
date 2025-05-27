/*
Print leaf nodes from preorder traversal of BST
Difficulty: MediumAccuracy: 47.26%Submissions: 31K+Points: 4
Given a preorder traversal of a BST, find the leaf nodes of the tree without building the tree.


Examples:

Input: preorder[] = [5, 2, 10]
Output: [2, 10]
Explaination: 

2 and 10 are the leaf nodes as shown in the figure.
Input: preorder[] = [4, 2, 1, 3, 6, 5]
Output: [1, 3, 5]
Explaination: 

1, 3 and 5 are the leaf nodes as shown in the figure.
Input: preorder[] = [8, 2, 5, 10, 12]
Output: [5, 12]
Explaination: 

5 and 12 are the leaf nodes as shown in the figure.

Constraints:
1 ≤ preorder.size() ≤ 103
1 ≤ preorder[i] ≤ 103
*/

/*
Approach:
- Use a stack to simulate the traversal of a Binary Search Tree (BST) based on preorder.
- For each node in the preorder:
  - If the current value is smaller than the top of the stack, it goes to the left subtree.
  - If it is greater, nodes are popped until we find the correct parent for the right subtree.
  - If two or more nodes are popped during this process, it indicates the last popped node is a leaf.
- Finally, the last remaining node on the stack is also a leaf.

Intuition:
- In BST preorder, whenever you pop more than one node from the stack,
  it means you are finishing a subtree, and the last popped node has no children → it's a leaf.
- The last element in the stack at the end is also a leaf node (rightmost leaf).

Time Complexity: O(n)
- Each element is pushed and popped at most once.

Space Complexity: O(n)
- Stack can grow up to n in the worst case (strictly decreasing preorder).
*/

class Solution {
public:
    vector<int> leafNodes(vector<int>& preorder) {
        vector<int> ans;
        stack<int> st;
        int n = preorder.size();

        // Push the root node (first element)
        st.push(preorder[0]);

        for (int i = 1; i < n; i++) {
            // If current node is in the left subtree
            if (!st.empty() && st.top() > preorder[i]) {
                st.push(preorder[i]);
            } else {
                int temp = st.top();
                int cnt = 0;

                // Pop elements from stack smaller than current node
                while (!st.empty() && st.top() < preorder[i]) {
                    st.pop();
                    cnt++;
                }

                // Push current node (start of right subtree)
                st.push(preorder[i]);

                // If 2 or more nodes were popped, the last popped is a leaf
                if (cnt >= 2) {
                    ans.push_back(temp);
                }
            }
        }

        // The last node in the stack is also a leaf
        ans.push_back(st.top());

        return ans;
    }
};
