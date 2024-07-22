/*
Linked List Insertion At End
Difficulty: BasicAccuracy: 43.96%Submissions: 215K+Points: 1
Given the head of a Singly Linked List and a value x, insert that value x at the end of the LinkedList and return the modified Linked List.

Examples :

Input: LinkedList: 1->2->3->4->5 , x = 6
Output: 1->2->3->4->5->6
Explanation: 

We can see that 6 is inserted at the end of the linkedlist.
Input: LinkedList: 5->4 , x = 1
Output: 5->4->1
Explanation: 

We can see that 1 is inserted at the end of the linkedlist.
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)

Constraints:
0 <= number of nodes <= 105
1 <= node->data , x <= 103
*/

/**
 * Intuition:
 * 1. **Appending to End:** We need to append a new node with value `x` at the end of the linked list.
 * 2. **Traversal:** Traverse the linked list to find the last node.
 * 3. **Edge Case:** If the list is initially empty (head is NULL), the new node becomes the head.
 *
 * Time Complexity: O(n)
 * - We traverse the entire list to find the last node.
 *
 * Space Complexity: O(1)
 * - We use a constant amount of extra space.
 */

class Solution {
  public:
    Node *insertAtEnd(Node *head, int x) {
        // If the list is empty, the new node becomes the head
        if(head == NULL)
            return new Node(x);
        
        // Traverse to the end of the list
        Node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        
        // Append the new node at the end
        temp->next = new Node(x);
        
        return head;
    }
};
