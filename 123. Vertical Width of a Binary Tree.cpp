/*
Vertical Width of a Binary Tree
Difficulty: MediumAccuracy: 43.48%Submissions: 52K+Points: 4
Given a Binary Tree. You need to find and return the vertical width of the tree.

Examples :

Input:
         1
       /    \
      2      3
     / \    /  \
    4   5  6   7
            \   \
             8   9
Output: 6
Explanation: The width of a binary tree is
the number of vertical paths in that tree.



The above tree contains 6 vertical lines.
Input:
     1
    /  \
   2    3
Output: 3
Explanation: The above tree has 3 vertical lines, hence the answer is 3.
Expected Time Complexity: O(nlogn)
Expected Auxiliary Space: O(height of the tree).

Constraints:
0 <= number of nodes <= 104
*/

/*
 * Intuition:
 * The vertical width of a binary tree is the number of unique vertical lines that pass through at least one node of the tree. 
 * To find the vertical width, we perform a depth-first traversal of the tree and track the horizontal distance (pos) from the root for each node.
 * By keeping track of the minimum and maximum horizontal distances encountered, we can determine the vertical width.
 *
 * Time Complexity: O(n), where n is the number of nodes in the tree. We traverse each node once.
 * Space Complexity: O(h), where h is the height of the tree. This is the space used by the recursion stack.
 */

class Solution {
public:
    // Helper function to determine the minimum and maximum horizontal distances from the root.
    void help(Node* root, int &mn, int &mx, int pos) {
        if (!root) return;

        // Update the minimum and maximum horizontal distances
        mx = max(mx, pos);
        mn = min(mn, pos);

        // Recur for the left and right subtrees with updated horizontal distances
        help(root->left, mn, mx, pos - 1);
        help(root->right, mn, mx, pos + 1);
    }

    // Function to find the vertical width of a binary tree.
    int verticalWidth(Node* root) {
        if (!root)
            return 0;

        int mn = 0, mx = 0;
        help(root, mn, mx, 0);

        // The vertical width is the number of unique vertical lines, calculated as the range between mx and mn plus one.
        return mx + abs(mn) + 1;
    }
};
