/*
Delete node in Doubly Linked List
Difficulty: EasyAccuracy: 42.98%Submissions: 105K+Points: 2
Given a doubly Linked list and a position. The task is to delete a node from a given position (position starts from 1) in a doubly linked list and return the head of the doubly Linked list.

Examples:

Input: LinkedList = 1 <--> 3 <--> 4, x = 3
Output: 1 3  
Explanation: 
After deleting the node at position 3 (position starts from 1),the linked list will be now as 1 <--> 3.
 
Input: LinkedList = 1 <--> 5 <--> 2 <--> 9, x = 1
Output: 5 2 9
Explanation:

Expected Time Complexity: O(n)
Expected Auxilliary Space: O(1)

Constraints:
2 <= size of the linked list(n) <= 105
1 <= x <= n
1 <= node.data <= 109
*/

class Solution {
public:
    Node* deleteNode(Node* head, int x) {
        if (!head) return nullptr;  // Handle the case where the list is empty
        if (x == 1) {
            Node* newHead = head->next;
            if (newHead) {
                newHead->prev = nullptr;
            }
            delete head;  // Free the memory of the deleted node
            return newHead;
        }
        
        Node* temp = head;
        int cnt = 1;
        
        while (temp && cnt < x) {
            temp = temp->next;
            cnt++;
        }
        
        if (temp == nullptr) return head;  // x is larger than the size of the list
        
        Node* prevNode = temp->prev;
        Node* nextNode = temp->next;
        
        if (prevNode) {
            prevNode->next = nextNode;
        }
        if (nextNode) {
            nextNode->prev = prevNode;
        }
        
        delete temp;  // Free the memory of the deleted node
        
        return head;
    }
};