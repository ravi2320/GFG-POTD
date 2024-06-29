/*
Identical Linked Lists
Difficulty: BasicAccuracy: 47.49%Submissions: 138K+Points: 1
Given the two singly Linked Lists respectively. The task is to check whether two linked lists are identical or not. 
Two Linked Lists are identical when they have the same data and with the same arrangement too. If both Linked Lists are identical then return true otherwise return false. 

Examples:

Input:
LinkedList1: 1->2->3->4->5->6
LinkedList2: 99->59->42->20
Output: false
Explanation:

As shown in figure linkedlists are not identical.
Input:
LinkedList1: 1->2->3->4->5
LinkedList2: 1->2->3->4->5
Output: true
Explanation: 
 
As shown in figure both are identical.
Expected Time Complexity: O(n)
Expected Auxilliary Space: O(1)

Constraints:
1 <= length of lists <= 103
*/

// Intuition:
// To determine if two linked lists are identical, we need to compare each corresponding node.
// We'll iterate through both linked lists simultaneously. If we find a pair of nodes that have different data, we'll return false.
// If we reach the end of both lists without finding any differences, we'll return true.
// If one list is longer than the other, we'll also return false.

// Time Complexity: O(n), where n is the length of the longer list, since we need to traverse each node once.
// Space Complexity: O(1), as we are using a constant amount of extra space.

bool areIdentical(struct Node *head1, struct Node *head2) {
    Node *t1 = head1;
    Node *t2 = head2;

    while (t1 && t2) {
        if (t1->data != t2->data) {
            return false;
        }
        t1 = t1->next;
        t2 = t2->next;
    }
    
    // Check if both lists reached the end
    return (!t1 && !t2);
}
