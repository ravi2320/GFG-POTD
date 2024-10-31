/*
Insert in Sorted way in a Sorted DLL
Difficulty: MediumAccuracy: 28.25%Submissions: 41K+Points: 4
Given a sorted doubly linked list and an element x, you need to insert the element x into the correct position in the sorted Doubly linked list(DLL).

Note: The DLL is sorted in ascending order

Example:

Input: LinkedList: 3->5->8->10->12 , x = 9

Output: 3->5->8->9->10->12

Explanation: Here node 9 is inserted in the Doubly Linked-List.
Input: LinkedList: 1->4->10->11 , x = 15

Output: 1->4->10->11->15

Constraints:
1 <= number of nodes <= 103
1 <= node -> data , x <= 104
*/

/*
Approach:
1. This function inserts a node with value `x` into a sorted doubly linked list in its correct position.
2. First, we handle the case where `x` is less than or equal to the head node's data. In this case, we insert `x` at the beginning and update `head`.
3. We traverse the list to find the appropriate position to insert `x`:
   - If `x` lies between `curr->data` and `curr->next->data`, we insert the new node between `curr` and `curr->next`.
4. If we reach the end of the list (i.e., `x` is larger than all elements), we add `x` at the end.
5. We create a helper function `getNode(int x)` to initialize new nodes.

Time Complexity: O(n), where `n` is the number of nodes in the list.
Space Complexity: O(1), as we only use constant additional space.
*/

class Solution {
public:
    // Helper function to create a new node
    Node* getNode(int x) {
        Node* node = new Node(x);
        node->next = nullptr;
        node->prev = nullptr;
        return node;
    }

    Node* sortedInsert(Node* head, int x) {
        // If the new node should be the new head
        if (x <= head->data) {
            Node* node = getNode(x);
            node->next = head;
            head->prev = node;
            return node;
        }

        Node* curr = head;

        // Traverse to find the correct position for `x`
        while (curr->next) {
            if (curr->data <= x && x <= curr->next->data) {
                Node* node = getNode(x);
                node->next = curr->next;
                curr->next->prev = node;
                curr->next = node;
                node->prev = curr;
                return head;
            }
            curr = curr->next;
        }

        // Insert `x` at the end
        Node* node = getNode(x);
        node->prev = curr;
        curr->next = node;
        return head;
    }
};
