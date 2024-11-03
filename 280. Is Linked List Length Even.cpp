/*
Is Linked List Length Even?
Difficulty: BasicAccuracy: 71.58%Submissions: 74K+Points: 1
Given a linked list, your task is to complete the function isLengthEven() which contains the head of the linked list, and check whether the length of the linked list is even or not. Return true if it is even, otherwise false.

Examples:

Input: Linked list: 12->52->10->47->95->0

Output: true
Explanation: The length of the linked list is 6 which is even, hence returned true.
Input: Linked list: 9->4->3

Output: false
Explanation: The length of the linked list is 3 which is odd, hence returned false.
Expected Time Complexity: O(n)
Expected Auxillary Space: O(1)

Constraints:
1 <= number of nodes <= 105
1 <= elements of the linked list <= 105
*/

/*
Approach:
1. Traverse the linked list and count the number of nodes.
2. If the count is even, return true; otherwise, return false.

Time Complexity: O(n), where `n` is the number of nodes in the list.
Space Complexity: O(1), as we only use a few variables for traversal.
*/

class Solution {
  public:
    bool isLengthEven(struct Node **head) {
        // Initialize length counter
        int len = 0;
        
        // Traverse through the linked list
        Node* curr = *head;
        while (curr) {
            len++;        // Increment count for each node
            curr = curr->next;
        }
        
        // Check if the length is even
        return len % 2 == 0;
    }
};
