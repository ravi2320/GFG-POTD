/*
Linked List Group Reverse
Difficulty: HardAccuracy: 57.08%Submissions: 221K+Points: 8
Given the head a linked list, the task is to reverse every k node in the linked list. If the number of nodes is not a multiple of k then the left-out nodes in the end, should be considered as a group and must be reversed.

Examples:

Input: head = 1 -> 2 -> 2 -> 4 -> 5 -> 6 -> 7 -> 8, k = 4
Output: 4 -> 2 -> 2 -> 1 -> 8 -> 7 -> 6 -> 5

Explanation: The first 4 elements 1, 2, 2, 4 are reversed first and then the next 4 elements 5, 6, 7, 8. Hence, the resultant linked list is 4 -> 2 -> 2 -> 1 -> 8 -> 7 -> 6 -> 5.
Input: head = 1 -> 2 -> 3 -> 4 -> 5, k = 3
Output: 3 -> 2 -> 1 -> 5 -> 4

Explanation: The first 3 elements 1, 2, 3 are reversed first and then left out elements 4, 5 are reversed. Hence, the resultant linked list is 3 -> 2 -> 1 -> 5 -> 4.
Constraints:
1 <= size of linked list <= 105
1 <= data of nodes <= 106
1 <= k <= size of linked list 
*/

/*
Approach:
1. Reverse the first k nodes of the list.
2. Recursively call the function for the remaining list and attach the result to the current group's tail.
3. Return the new head of the reversed list.

Time Complexity: O(n) - Each node is visited once.
Space Complexity: O(n/k) - Recursive calls for every k nodes.
*/

class Solution {
public:
    Node* reverseKGroup(Node* head, int k) {
        if (!head) return head; // Base case: If the list is empty, return NULL.

        Node *curr = head, *prev = NULL, *next = NULL;
        int count = 0;

        // Check if there are at least k nodes to reverse
        Node* temp = head;
        for (int i = 0; i < k; i++) {
            if (!temp) return head; // If fewer than k nodes, return the original head.
            temp = temp->next;
        }

        // Reverse the first k nodes
        while (curr && count < k) {
            next = curr->next;    // Save the next node
            curr->next = prev;    // Reverse the link
            prev = curr;          // Move prev to current node
            curr = next;          // Move curr to the next node
            count++;
        }

        // Recursively process the remaining nodes
        if (next) {
            head->next = reverseKGroup(next, k);
        }

        // Return the new head of the reversed group
        return prev;
    }
};