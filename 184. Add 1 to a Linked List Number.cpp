/*
Add 1 to a Linked List Number
Difficulty: MediumAccuracy: 31.91%Submissions: 234K+Points: 4
You are given a linked list where each element in the list is a node and have an integer data. You need to add 1 to the number formed by concatinating all the list node numbers together and return the head of the modified linked list. 

Note: The head represents the first element of the given array.

Examples :

Input: LinkedList: 4->5->6
Output: 457

Explanation: 4->5->6 represents 456 and when 1 is added it becomes 457. 
Input: LinkedList: 1->2->3
Output: 124
 
Explanation:  1->2->3 represents 123 and when 1 is added it becomes 124. 
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)

Constraints:
1 <= len(list) <= 105
0 <= list[i] <= 9
*/

/*
Intuition:
- The problem requires adding one to a number represented as a linked list, where each node contains a single digit. The challenge is handling the carry that might be generated when adding one, especially when the digits are arranged in reverse order.
- We can reverse the linked list to make addition easier, then perform the addition digit by digit. After adding, we reverse the list back to its original order.

Time Complexity:
- The time complexity is O(n), where n is the number of nodes in the linked list. We traverse the list three times: once for reversing, once for addition, and once for reversing again.

Space Complexity:
- The space complexity is O(1) as we only use a constant amount of extra space for pointers during the reversal and addition operations.

Approach:
1. Reverse the linked list so that the least significant digit (rightmost) becomes the first node.
2. Traverse the reversed list, adding one to the first node and propagating any carry.
3. Reverse the list again to restore the original order.
4. If there is a remaining carry after processing all nodes, add a new node at the beginning of the list.

*/

class Solution {
public:
    // Helper function to reverse a linked list
    Node* reverse(Node *root) {
        Node *prev = NULL;  // Initialize the previous pointer
        Node *curr = root;  // Start with the current node as the head
        Node *next = NULL;  // Next pointer to store the next node temporarily
        
        // Traverse the list, reversing the links between nodes
        while (curr) {
            next = curr->next;  // Store the next node
            curr->next = prev;   // Reverse the current node's next pointer
            prev = curr;         // Move the previous pointer forward
            curr = next;         // Move the current pointer forward
        }
        
        // Return the new head (previously the tail)
        return prev;
    }

    Node* addOne(Node* head) {
        // Reverse the linked list to start addition from the least significant digit
        head = reverse(head);
        Node *temp = head;  // Pointer to traverse the reversed list
        
        int carry = 1;  // Initialize carry as 1 because we are adding one
        while (temp) {
            int val = temp->data + carry;  // Add carry to the current node's data
            temp->data = val % 10;  // Update the node's data to the remainder (current digit)
            carry = val / 10;  // Update carry (will be 0 or 1)
            if (!carry) break;  // If there's no carry left, stop
            
            temp = temp->next;  // Move to the next node
        }
        
        // Reverse the list back to its original order
        head = reverse(head);
        
        // If there's still a carry, we need to add a new node at the beginning
        if (carry) {
            Node *newNode = new Node(1);
            newNode->next = head;
            return newNode;
        }
        
        // Return the modified head of the list
        return head;
    }
};


/*
Intuition:
- This problem involves adding one to a number represented by a linked list where each node contains a single digit.
- The linked list is given in its normal order (most significant digit first), so we need to handle the carry as we propagate back from the least significant digit to the most significant.
- We solve this problem recursively by traversing to the end of the list and then handling the addition as we return from the recursion.

Time Complexity:
- The time complexity is O(n), where n is the number of nodes in the linked list. We traverse the list once in a recursive manner.

Space Complexity:
- The space complexity is O(n) due to the recursion stack, which grows with the depth of the recursion (equal to the length of the list).

Approach:
1. Define a recursive function `solve` that traverses to the end of the linked list.
2. On the way back from the recursion, add one to the node value and handle the carry.
3. If a carry remains after processing all nodes, create a new node at the head to accommodate it.

*/

class Solution {
public:
    // Recursive helper function to add one and manage carry
    int solve(Node *head) {
        // Base case: if head is NULL, return carry as 1 (to start adding 1)
        if (head == NULL) {
            return 1;
        }
        
        // Recursively solve for the next node
        int carry = solve(head->next);
        
        // Add carry to the current node's data
        int val = head->data + carry;
        head->data = val % 10;  // Update current node with the new digit
        carry = val / 10;  // Update carry for the previous node
        
        return carry;  // Return the carry to the previous node
    }

    Node* addOne(Node* head) {
        // Solve the addition problem recursively
        int carry = solve(head);
        
        // If there's still a carry after the entire list is processed, create a new node at the head
        if (carry) {
            Node *newNode = new Node(1);  // Create a new node with data 1
            newNode->next = head;  // Link the new node to the current head
            return newNode;  // The new node becomes the head of the list
        }
        
        // If no carry is left, return the head as is
        return head;
    }
};
