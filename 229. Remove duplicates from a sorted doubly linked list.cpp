/*
Remove duplicates from a sorted doubly linked list
Difficulty: EasyAccuracy: 50.36%Submissions: 33K+Points: 2
Given a doubly linked list of n nodes sorted by values, the task is to remove duplicate nodes present in the linked list.

Example 1:

Input:
n = 6
1<->1<->1<->2<->3<->4
Output:
1<->2<->3<->4
Explanation:
Only the first occurance of node with value 1 is 
retained, rest nodes with value = 1 are deleted.
Example 2:

Input:
n = 7
1<->2<->2<->3<->3<->4<->4
Output:
1<->2<->3<->4
Explanation:
Only the first occurance of nodes with values 2,3 and 4 are 
retained, rest repeating nodes are deleted.
Your Task:
You have to complete the method removeDuplicates() which takes 1 argument: the head of the linked list.  Your function should return a pointer to a linked list with no duplicate element.

Constraint:
1 <= n <= 105
Expected Time Complexity: O(n)
Expected Space Complexity: O(1)
*/

/*
 * Approach:
 * 1. This function removes duplicates from a sorted doubly linked list. 
 *    Since the list is sorted, any duplicates will be consecutive.
 * 2. The algorithm first removes duplicates from the head, ensuring the head does not have duplicate nodes.
 * 3. It then iterates through the rest of the list, deleting nodes with duplicate data and adjusting the `next` and `prev` pointers.
 * 4. Deleting a duplicate node involves updating the `next` pointer of the current node and the `prev` pointer of the subsequent node (if it exists).
 *
 * Time Complexity: O(n), where `n` is the number of nodes in the list (single pass through the list).
 * Space Complexity: O(1) for extra space, excluding the input list.
 */

class Solution {
public:
    // Function to remove duplicates from a sorted doubly linked list
    Node* removeDuplicates(Node* head) {
        // Handle case where head is null or list has only one element
        if (!head || !head->next) return head;

        // First, handle duplicates at the head of the list
        while (head && head->next && head->data == head->next->data) {
            Node* delNode = head;
            head = head->next;  // Move head to the next node
            head->prev = NULL;  // Set the new head's prev to NULL
            delNode->next = NULL;  // Disconnect the deleted node
            delete delNode;  // Delete the duplicate node
        }

        Node* temp = head;  // Start traversal from the head

        // Traverse the rest of the list
        while (temp && temp->next) {
            // If current node and next node have the same data, remove the next node
            if (temp->data == temp->next->data) {
                Node* delNode = temp->next;  // Node to be deleted
                temp->next = temp->next->next;  // Bypass the duplicate node
                if (temp->next) {
                    temp->next->prev = temp;  // Update the previous pointer of the next node
                }
                delNode->next = NULL;  // Disconnect the deleted node
                delNode->prev = NULL;
                delete delNode;  // Delete the duplicate node
            } else {
                temp = temp->next;  // Move to the next node if no duplicate is found
            }
        }

        return head;  // Return the modified list without duplicates
    }
};
