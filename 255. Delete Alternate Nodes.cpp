/*
Delete Alternate Nodes
Difficulty: EasyAccuracy: 56.09%Submissions: 69K+Points: 2
Given a Singly Linked List, Delete all alternate nodes of the list ie delete all the nodes present in even positions.

Examples :

Input: LinkedList: 1->2->3->4->5->6
 
Output: 1->3->5

Explanation: Deleting alternate nodes ie 2, 4, 6 results in the linked list with elements 1->3->5.
Input: LinkedList: 99->59->42->20
 
Output: 99->42
 
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)

Constraints:
1 <= number of nodes <= 105
1 <= node->data <= 103
*/

/*
Approach:
1. Start from the head and traverse the linked list.
2. For each node, delete the next node by setting head->next = head->next->next.
3. Continue until the list is fully traversed.

Time Complexity: O(n), where n is the number of nodes in the linked list.
Space Complexity: O(1), as no extra space is required apart from pointers.
*/

class Solution {
  public:
    void deleteAlt(struct Node *head) {
        // Traverse the linked list
        while(head && head->next) {
            // Skip the next node by updating the next pointer
            head->next = head->next->next;

            // Move to the next node (which is now 2 steps ahead)
            head = head->next;
        }
    }
};
