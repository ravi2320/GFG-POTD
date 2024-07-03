/*
Remove all occurences of duplicates in a linked list
Difficulty: MediumAccuracy: 49.82%Submissions: 34K+Points: 4
Given a sorted linked list, delete all nodes that have duplicate numbers (all occurrences), leaving only numbers that appear once in the original list, and return the head of the modified linked list. 

Examples:

Input: Linked List = 23->28->28->35->49->49->53->53
Output: 23 35
Explanation: 

The duplicate numbers are 28, 49 and 53 which are removed from the list.
Input: Linked List = 11->11->11->11->75->75
Output: Empty list
Explanation: 

All the nodes in the linked list have duplicates. Hence the resultant list would be empty.
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)
Constraints:
1 ≤ size(list) ≤ 105
*/

// Intuition:
// The problem is to remove all nodes that have duplicate numbers, leaving only distinct numbers from the original list.
// We can achieve this by maintaining a count of each node's value and linking only nodes that appear exactly once.

// Time Complexity: O(n), where n is the number of nodes in the linked list. We traverse the list once to count duplicates and once to build the new list.
// Space Complexity: O(1), no extra space is used except for a few pointers.

class Solution {
public:
    Node* removeAllDuplicates(struct Node* head) {
        Node* ans = new Node(-1); // Dummy node to handle edge cases easily
        Node* temp = ans;
        Node* prev = head;
        head = head->next;
        int cnt = 1;

        // Traverse the linked list
        while(head) {
            if(prev->data == head->data) {
                cnt++; // Increment count if duplicate is found
            } else {
                if(cnt == 1) {
                    temp->next = prev; // Link node if it is unique
                    temp = temp->next;
                }
                cnt = 1; // Reset count for new value
            }
            prev = head;
            head = head->next;
        }

        // Check the last node
        if(cnt == 1) {
            temp->next = prev; // Link last node if it is unique
        } else {
            temp->next = NULL; // Terminate the list if last node is not unique
        }

        return ans->next; // Return the head of the new list, skipping the dummy node
    }
};
