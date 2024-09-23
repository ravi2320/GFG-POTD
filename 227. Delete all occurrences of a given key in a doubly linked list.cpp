/*
Delete all occurrences of a given key in a doubly linked list
Difficulty: MediumAccuracy: 50.04%Submissions: 27K+Points: 4
You are given the head_ref of a doubly Linked List and a Key. Your task is to delete all occurrences of the given key if it is present and return the new DLL.

Example1:

Input: 
2<->2<->10<->8<->4<->2<->5<->2
2
Output: 
10<->8<->4<->5
Explanation: 
All Occurences of 2 have been deleted.

Example2:

Input: 
9<->1<->3<->4<->5<->1<->8<->4
9
Output: 
1<->3<->4<->5<->1<->8<->4
Explanation: 
All Occurences of 9 have been deleted.
Your Task:

Complete the function void deleteAllOccurOfX(struct Node** head_ref, int key), which takes the reference of the head pointer and an integer value key. Delete all occurrences of the key from the given DLL.

Expected Time Complexity: O(N).

Expected Auxiliary Space: O(1).

Constraints:

1<=Number of Nodes<=105

0<=Node Value <=109


*/

/*
 * Approach:
 * 1. This function deletes all occurrences of a given value `x` from a doubly linked list.
 * 2. It first handles the special case of removing occurrences of `x` from the head of the list.
 * 3. Then, it traverses the rest of the list, checking each node and deleting nodes with value `x` while ensuring that the list remains properly linked.
 * 4. After each deletion, the code updates both `next` and `prev` pointers to maintain the integrity of the doubly linked list.
 *
 * Time Complexity: O(n), where `n` is the number of nodes in the list (since each node is visited once).
 * Space Complexity: O(1), as no extra space is used except a few pointers for traversal.
 */

class Solution {
public:
    void deleteAllOccurOfX(struct Node** head_ref, int x) {
        // First, delete occurrences of x from the head
        while(*head_ref && (*head_ref)->data == x) {
            Node* temp = *head_ref;  // Store the node to be deleted
            *head_ref = (*head_ref)->next;  // Move the head to the next node
            if (*head_ref) {
                (*head_ref)->prev = NULL;  // Update the new head's prev pointer to NULL
            }
            delete temp;  // Delete the node
        }

        // Traverse and delete occurrences of x in the rest of the list
        Node* temp = *head_ref;  // Start from the updated head
        while(temp && temp->next) {
            if(temp->next->data == x) {
                Node* delNode = temp->next;  // Store the node to be deleted
                temp->next = temp->next->next;  // Update next pointer to skip the deleted node
                if (temp->next) {
                    temp->next->prev = temp;  // Update prev pointer of the new next node
                }
                // Clean up the deleted node's pointers
                delNode->prev = NULL;
                delNode->next = NULL;
                delete delNode;  // Delete the node
            } else {
                temp = temp->next;  // Move to the next node only if no deletion
            }
        }
    }
};
