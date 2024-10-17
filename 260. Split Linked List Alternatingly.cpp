/*
Split Linked List Alternatingly
Difficulty: EasyAccuracy: 42.46%Submissions: 27K+Points: 2
Given a singly linked list's head. Your task is to complete the function alternatingSplitList() that splits the given linked list into two smaller lists. The sublists should be made from alternating elements from the original list.
Note: 

The sublist should be in the order with respect to the original list.
Your have to return an array containing the both sub-linked lists.
Examples:

Input: LinkedList = 0->1->0->1->0->1
Output: 0->0->0 , 1->1->1
Explanation: After forming two sublists of the given list as required, we have two lists as: 0->0->0 and 1->1->1.

Input: LinkedList = 2->5->8->9->6
Output: 2->8->6 , 5->9
Explanation: After forming two sublists of the given list as required, we have two lists as: 2->8->6 and 5->9.
Input: LinkedList: 7 
Output: 7 , <empty linked list>
Constraints:
1 <= number of nodes <= 100
1 <= node -> data <= 104
*/

/*
Approach:
- The task is to split a given linked list into two lists such that nodes are alternated between the two lists.
- We keep track of two new linked lists (`head1` and `head2`) where:
  - `head1` will contain nodes from odd positions (0th, 2nd, 4th, etc.).
  - `head2` will contain nodes from even positions (1st, 3rd, 5th, etc.).
- We traverse the original list once, placing nodes alternately in `head1` and `head2` based on a counter.
- After the loop, we ensure the `next` pointers of the last nodes in both lists are set to `NULL`.

Time Complexity:
- O(n), where `n` is the number of nodes in the linked list. We only traverse the list once.

Space Complexity:
- O(1), since no extra space is used apart from a few pointers.

*/

class Solution {
public:
    // Function to split a linked list into two lists alternately
    vector<Node*> alternatingSplitList(struct Node* head) {
        // Initialize pointers for the two new lists
        Node* head1 = NULL;  // Head of the first list (for odd-indexed nodes)
        Node* head2 = NULL;  // Head of the second list (for even-indexed nodes)
        Node* temp1 = NULL;  // Pointer to keep track of the current node in the first list
        Node* temp2 = NULL;  // Pointer to keep track of the current node in the second list
        int cnt = 0;  // Counter to track if the current node is odd or even

        // Traverse the original list
        while (head) {
            if (cnt % 2 == 0) {  // Even index (0-based), place in the first list
                if (!head1) {
                    head1 = head;  // Initialize head1 if it's null
                    temp1 = head1;
                } else {
                    temp1->next = head;  // Add current node to the first list
                    temp1 = temp1->next;  // Move temp1 to the next node
                }
            } else {  // Odd index (0-based), place in the second list
                if (!head2) {
                    head2 = head;  // Initialize head2 if it's null
                    temp2 = head2;
                } else {
                    temp2->next = head;  // Add current node to the second list
                    temp2 = temp2->next;  // Move temp2 to the next node
                }
            }
            head = head->next;  // Move to the next node in the original list
            cnt++;  // Increment the counter
        }

        // Terminate both lists properly
        if (temp1) temp1->next = NULL;
        if (temp2) temp2->next = NULL;

        // Return the two new lists
        return {head1, head2};
    }
};

/*
Approach:
- The task is to split the given linked list into two separate lists in an alternating fashion.
- One list will contain the nodes at odd indices, and the other list will contain the nodes at even indices.
- The solution uses two pointers: one for traversing the odd-indexed nodes (`first`) and one for the even-indexed nodes (`second`).
- We adjust the `next` pointers of both lists alternately and stop when either list runs out of nodes.

Steps:
1. Initialize two pointers: `firstHead` pointing to the first node and `secondHead` pointing to the second node.
2. Traverse the list, updating the `next` pointers of both `first` and `second` nodes so that they alternate.
3. Return the heads of both new lists.

Time Complexity:
- O(n), where `n` is the number of nodes in the original list. Each node is visited once.

Space Complexity:
- O(1) since no extra space is used apart from a few pointers.

*/

class Solution {
public:
    // Function to split a linked list into two lists alternately
    vector<Node*> alternatingSplitList(struct Node* head) {
        if (!head || !head->next) return {head, nullptr};  // Edge case: if less than 2 nodes, second list will be empty

        // Initialize two heads: one for odd positions, one for even positions
        Node* firstHead = head;         // The first list starting from the first node
        Node* secondHead = head->next;  // The second list starting from the second node

        // Pointers to traverse both lists
        Node* first = head;
        Node* second = head->next;

        // Traverse the linked list and adjust pointers
        while (first && first->next && second && second->next) {
            first->next = first->next->next;  // Move `first` to the next odd node
            first = first->next;  // Update the `first` pointer

            second->next = second->next->next;  // Move `second` to the next even node
            second = second->next;  // Update the `second` pointer
        }

        // Return the two heads of the newly split lists
        return {firstHead, secondHead};
    }
};
