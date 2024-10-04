/*
Deletion and Reverse in Circular Linked List
Difficulty: MediumAccuracy: 60.7%Submissions: 40K+Points: 4
Given a Circular Linked List. The task is to delete the given node, key in the circular linked list, and reverse the circular linked list.

Note:

You don't have to print anything, just return the head of the modified list in each function.
Nodes may consist of Duplicate values.
The key may or may not be present.
Examples:

Input: Linked List: 2->5->7->8->10, key = 8

Output: 10->7->5->2 
Explanation: After deleting 8 from the given circular linked list, it has elements as 2, 5, 7, 10. Now, reversing this list will result in 10, 7, 5, 2 & the resultant list is also circular.
Input: Linked List: 1->7->8->10, key = 8

Output: 10->7->1
Explanation: After deleting 8 from the given circular linked list, it has elements as 1, 7,10. Now, reversing this list will result in 10, 7, 1 & the resultant list is also circular.
Input: Linked List: 3->6->4->10, key = 9
Output: 10->4->6->3
Explanation: As there no key present in the list, so simply reverse the list & the resultant list is also circular.
Expected Time Complexity: O(n)
Expected Auxillary Space: O(1)

Constraints:
2 <= number of nodes, key  <= 105
1 <= node -> data <= 105
*/

/*
Approach:
1. **reverse**:
   - The function reverses a circular linked list by iterating over the nodes, adjusting their `next` pointers, and finally fixing the head node's `next` pointer to maintain the circular nature of the list.
   - We use three pointers: `prev`, `curr`, and `next` to reverse the list while ensuring that the head pointer gets updated to point to the new first node after the reversal.
   
2. **deleteNode**:
   - This function deletes a node from a circular linked list. If the node to be deleted is the head, we copy the data from the next node into the head, adjust pointers, and delete the next node.
   - For any other node, we traverse the list, find the node with the matching key, adjust the pointers, and then delete the target node.

Time Complexity:
- **reverse**: O(N), where N is the number of nodes in the circular linked list (each node is visited once).
- **deleteNode**: O(N) in the worst case (where the key is at the end of the list or doesn't exist).

Space Complexity:
- O(1) for both functions, as they only use a few additional pointers.
*/

class Solution {
  public:
    // Function to reverse a circular linked list
    Node* reverse(Node* head) {
        // Handle edge case for empty or single-node list
        if (!head || head->next == head) return head;
        
        Node* prev = head;           // Starting with head as previous node
        Node* curr = head->next;     // Current node starts from the next of head
        
        // Traverse the list and reverse the links until we loop back to the head
        while (curr != head) {
            Node* next = curr->next;  // Store the next node
            curr->next = prev;        // Reverse the current node's next pointer
            prev = curr;              // Move prev pointer forward
            curr = next;              // Move curr pointer forward
        }
        
        head->next = prev;  // Fix the last node to point to the new head
        return prev;        // Return the new head (which is the last node of the original list)
    }

    // Function to delete a node from the circular linked list
    Node* deleteNode(Node* head, int key) {
        // If head itself contains the key, handle the case
        if (head->data == key) {
            // Special case when there's only one node in the list
            if (head->next == head) {
                delete head;
                return NULL;
            }
            
            // Copy data from the next node and delete the next node
            Node* temp = head->next;
            head->data = temp->data;
            head->next = temp->next;
            temp->next = NULL;
            delete temp;
            return head;
        }
        
        // General case: traverse to find the node with the key
        Node* temp = head;
        while (temp->next != head) {
            // If the next node contains the key, delete it
            if (temp->next->data == key) {
                Node* delNode = temp->next;  // Node to be deleted
                temp->next = temp->next->next;  // Adjust the next pointer
                delNode->next = NULL;
                delete delNode;  // Delete the node
                break;
            }
            temp = temp->next;  // Move to the next node
        }
        
        return head;  // Return the modified head
    }
};
