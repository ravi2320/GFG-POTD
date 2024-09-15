/*
Reverse a Doubly Linked List
Difficulty: EasyAccuracy: 70.38%Submissions: 138K+Points: 2
Given a doubly linked list. Your task is to reverse the doubly linked list and return its head.

Examples:

Input: LinkedList: 3 <-> 4 <-> 5
Output: 5 <-> 4 <-> 3

Input: LinkedList: 75 <-> 122 <-> 59 <-> 196
Output: 196 <-> 59 <-> 122 <-> 75

Expected Time Complexity: O(n).
Expected Auxiliary Space: O(1).

Constraints:
1 <= number of nodes <= 106
0 <= node->data <= 104
*/

class Solution {
  public:
    // Function to reverse a doubly linked list
    DLLNode* reverseDLL(DLLNode* head) {
        // Your code here
        stack<int> st;
        DLLNode* temp = head;
        while(temp){
            st.push(temp->data);
            temp = temp->next;
        }
        
        temp = head;
        while(temp){
            temp->data = st.top();
            st.pop();
            temp = temp->next;
        }
        
        return head;
    }
};

/*
Approach:
1. Traverse through the doubly linked list and for each node, swap its `next` and `prev` pointers.
2. Once you reach the end of the list, set the last node as the new head.
3. Return the new head.

Time Complexity:
- O(n): We traverse the list once to reverse the pointers.

Space Complexity:
- O(1): We don't use any extra space apart from the temporary pointer.
*/

DLLNode* reverseDLL(DLLNode* head) {
    // Edge case: If the list is empty, return nullptr.
    if (!head) return nullptr;

    DLLNode* temp = nullptr;
    DLLNode* current = head;

    // Traverse the list and swap next and prev pointers for each node.
    while (current != nullptr) {
        // Swap the `next` and `prev` pointers.
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;

        // Move to the next node (which is current->prev after swapping).
        current = current->prev;
    }

    // After the loop, temp will point to the new head (previously the last node).
    if (temp != nullptr) {
        head = temp->prev;
    }

    return head;
}
