/*
Delete Middle of Linked List
EasyAccuracy: 54.52%Submissions: 115K+Points: 2
 Done with winning Geekbits? Now win GfG Bag, GfG T-shirt & much more just by writing your experiences. Start Writing, Start Winning.
banner
Given a singly linked list, delete middle of the linked list. For example, if given linked list is 1->2->3->4->5 then linked list should be modified to 1->2->4->5.
If there are even nodes, then there would be two middle nodes, we need to delete the second middle element. For example, if given linked list is 1->2->3->4->5->6 then it should be modified to 1->2->3->5->6.
If the input linked list has single node, then it should return NULL.

Example 1:

Input:
LinkedList: 1->2->3->4->5
Output: 
1 2 4 5
Example 2:

Input:
LinkedList: 2->4->6->7->5->1
Output: 
2 4 6 5 1
Your Task:
The task is to complete the function deleteMid() which takes head of the linkedlist  and return head of the linkedlist with middle element deleted from the linked list. If the linked list is empty or contains single element then it should return NULL.

Expected Time Complexity: O(n).
Expected Auxiliary Space: O(1).

Constraints:
1 <= n <= 105
1 <= value[i] <= 109

Company Tags
FlipkartAmazonMicrosoft
*/

// Intuition:
// This class provides a solution to delete the middle node of a singly linked list.
// The algorithm uses the two-pointer technique, where one pointer (slow) moves one node at a time,
// and another pointer (fast) moves two nodes at a time. When the fast pointer reaches the end of the list,
// the slow pointer will be at the middle node. Then, the middle node is removed by updating pointers.

// Time Complexity: O(n)
// - 'n' is the number of nodes in the linked list.
// - The algorithm iterates through the linked list once.

// Space Complexity: O(1)
// - The algorithm uses only a constant amount of extra space for variables.

#include <iostream>
using namespace std;

// Define the structure for a singly linked list node
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class Solution {
public:
    // Function to delete the middle node of the linked list
    Node* deleteMid(Node* head) {
        // Initialize two pointers: slow and fast
        Node* slow = head;
        Node* fast = head->next;

        // Base case: if the list has only one node, return NULL (no middle node to delete)
        if (!fast)
            return NULL;

        // Move the pointers until the fast pointer reaches the end of the list
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Remove the middle node by updating pointers
        slow->next = slow->next->next;

        // Return the head of the modified linked list
        return head;
    }
};

// Helper function to print the linked list
void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Sample Usage
int main() {
    // Create a sample linked list: 1 -> 2 -> 3 -> 4 -> 5
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    Solution obj;
    cout << "Original linked list: ";
    printList(head); // Output: Original linked list: 1 2 3 4 5

    // Delete the middle node
    head = obj.deleteMid(head);
    cout << "Linked list after deleting the middle node: ";
    printList(head); // Output: Linked list after deleting the middle node: 1 2 4 5

    return 0;
}
