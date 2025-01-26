/*
Remove loop in Linked List
Difficulty: MediumAccuracy: 27.66%Submissions: 483K+Points: 4
Given the head of a linked list that may contain a loop.  A loop means that the last node of the linked list is connected back to a node in the same list. The task is to remove the loop from the linked list (if it exists).

Custom Input format:

A head of a singly linked list and a pos (1-based index) which denotes the position of the node to which the last node points to. If pos = 0, it means the last node points to null, indicating there is no loop.

The generated output will be true if there is no loop in list and other nodes in the list remain unchanged, otherwise, false.

Examples:

Input: head = 1 -> 3 -> 4, pos = 2
Output: true
Explanation: The linked list looks like

A loop is present in the list, and it is removed.
Input: head = 1 -> 8 -> 3 -> 4, pos = 0
Output: true
Explanation: 

The Linked list does not contains any loop. 
Input: head = 1 -> 2 -> 3 -> 4, pos = 1
Output: true
Explanation: The linked list looks like 

A loop is present in the list, and it is removed.
Constraints:
1 ≤ size of linked list ≤ 105
*/

/*
Approach:
1. Use Floyd’s Cycle Detection Algorithm (slow and fast pointers) to detect the loop in the linked list.
2. If a loop is detected:
   - Reset the `slow` pointer to the head of the list.
   - If the `slow` pointer meets the `fast` pointer at the head, it indicates the loop connects directly to the head. Traverse until the node just before the head and break the loop.
   - Otherwise, move both pointers one step at a time until they meet at the starting point of the loop.
   - Keep track of the previous node (`fastPrev`) of the `fast` pointer and set its `next` to `NULL` to remove the loop.

Intuition:
- A loop can be detected in a linked list using the fast and slow pointer method.
- Breaking the loop requires identifying the starting node of the loop and disconnecting it.

Time Complexity:
- Loop detection: O(n), where `n` is the number of nodes in the list.
- Removing the loop: O(n) in the worst case.
- Overall: O(n).

Space Complexity:
- Constant extra space: O(1).

*/

class Solution {
public:
    // Function to remove a loop in the linked list.
    void removeLoop(Node* head) {
        // Initialize slow and fast pointers
        Node* slow = head;
        Node* fast = head;

        // Detect if a loop exists
        while (fast && fast->next) {
            slow = slow->next;          // Move slow by 1 step
            fast = fast->next->next;    // Move fast by 2 steps

            // If slow and fast meet, a loop exists
            if (slow == fast) {
                // Reset slow to head to find the start of the loop
                slow = head;

                // Special case: Loop connects directly to head
                if (slow == fast) {
                    while (fast->next != slow) {
                        fast = fast->next; // Traverse to the last node in the loop
                    }
                    fast->next = NULL; // Break the loop
                    return;
                }

                // Find the node before the start of the loop
                Node* fastPrev = NULL;
                while (slow != fast) {
                    fastPrev = fast;
                    slow = slow->next;
                    fast = fast->next;
                }

                // Break the loop by setting the last node's next to NULL
                fastPrev->next = NULL;
                return;
            }
        }
    }
};