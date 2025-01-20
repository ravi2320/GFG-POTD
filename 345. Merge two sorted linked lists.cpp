/*
Merge two sorted linked lists
Difficulty: MediumAccuracy: 62.91%Submissions: 172K+Points: 4
Given the head of two sorted linked lists consisting of nodes respectively. The task is to merge both lists and return the head of the sorted merged list.

Examples:

Input: head1 = 5 -> 10 -> 15 -> 40, head2 = 2 -> 3 -> 20
Output: 2 -> 3 -> 5 -> 10 -> 15 -> 20 -> 40
Explanation:

Input: head1 = 1 -> 1, head2 = 2 -> 4
Output: 1 -> 1 -> 2 -> 4
Explanation:

Constraints:
1 <= no. of nodes<= 103
0 <= node->data <= 105
*/

/*
Approach:
1. Use a dummy node to simplify appending nodes to the merged list.
2. Traverse both lists, comparing nodes, and append the smaller node to the merged list.
3. Append any remaining nodes from one of the lists once the other is exhausted.

Time Complexity: O(n + m)
- Each node in the two linked lists is processed exactly once.

Space Complexity: O(1)
- Merging is performed in-place without using extra memory.

*/

class Solution {
  public:
    Node* sortedMerge(Node* head1, Node* head2) {
        // Create a dummy node to simplify merging logic
        Node* dummy = new Node(0);
        Node* current = dummy;

        // Traverse both lists
        while (head1 && head2) {
            if (head1->data <= head2->data) {
                // Append the smaller node (head1)
                current->next = head1;
                head1 = head1->next;
            } else {
                // Append the smaller node (head2)
                current->next = head2;
                head2 = head2->next;
            }
            // Move the current pointer forward
            current = current->next;
        }

        // Append remaining nodes from head1, if any
        if (head1) {
            current->next = head1;
        }

        // Append remaining nodes from head2, if any
        if (head2) {
            current->next = head2;
        }

        // The merged list starts from dummy->next
        Node* mergedHead = dummy->next;
        delete dummy; // Free the memory of the dummy node
        return mergedHead;
    }
};