/*
Find the Sum of Last N nodes of the Linked List
Difficulty: EasyAccuracy: 61.47%Submissions: 53K+Points: 2
Given a single linked list, calculate the sum of the last n nodes.

Note: It is guaranteed that n <= number of nodes.

Examples:

Input: Linked List: 5->9->6->3->4->10, n = 3

Output: 17
Explanation: The sum of the last three nodes in the linked list is 3 + 4 + 10 = 17.
Input: Linked List: 1->2, n = 2

Output: 3
Explanation: The sum of the last two nodes in the linked list is 2 + 1 = 3.
Constraints:
1 <= number of nodes, n <= 105
1 <= node->data <= 103
*/

/*
Approach:
- The task is to find the sum of the last 'n' nodes of a singly linked list.
- First, calculate the total length of the linked list by traversing it and maintaining a sum of all node values.
- Then, subtract the first (length - n) nodes' values from the total sum to get the sum of the last 'n' nodes.

Time Complexity: O(L), where L is the length of the linked list. We traverse the list twice: once to calculate the length and total sum, and a second time to adjust the sum for the first (L-n) nodes.
Space Complexity: O(1), since no extra space is used apart from a few variables.
*/

class Solution {
  public:
    /* Structure of the node of the linked list
    struct Node {
        int data;
        struct Node* next;

        Node(int x){
            data = x;
            next = NULL;
        }
    };
    */
    
    // Function to return sum of last n nodes
    int sumOfLastN_Nodes(struct Node* head, int n) {
        int len = 0;  // To store the total length of the list
        int sum = 0;  // To store the sum of all nodes
        Node* curr = head;  // Pointer to traverse the list
        
        // First pass: calculate the total length and the sum of all nodes
        while (curr) {
            len++;
            sum += curr->data;
            curr = curr->next;
        }
        
        // Adjust the sum by subtracting the first (length - n) nodes' values
        len -= n;
        while (len--) {
            sum -= head->data;
            head = head->next;
        }
        
        return sum;  // Return the sum of the last 'n' nodes
    }
};