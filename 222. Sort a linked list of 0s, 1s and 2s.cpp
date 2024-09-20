/*
Sort a linked list of 0s, 1s and 2s
Difficulty: EasyAccuracy: 60.75%Submissions: 197K+Points: 2
Given a linked list where nodes can contain values 0s, 1s, and 2s only. The task is to segregate 0s, 1s, and 2s linked list such that all zeros segregate to the head side, 2s at the end of the linked list, and 1s in the middle of 0s and 2s.

Examples:

Input: LinkedList: 1->2->2->1->2->0->2->2
Output: 0->1->1->2->2->2->2->2
Explanation: All the 0s are segregated to the left end of the linked list, 2s to the right end of the list, and 1s in between.
 
Input: LinkedList: 2->2->0->1
Output: 0->1->2->2
Explanation: After arranging all the 0s,1s and 2s in the given format, the output will be 0 1 2 2.

Expected Time Complexity: O(n).
Expected Auxiliary Space: O(n).

Constraints:
1 <= no. of nodes <= 106
0 <= node->data <= 2
*/

/*
Approach:
1. **Count the occurrence of 0s, 1s, and 2s**:
   - Traverse the linked list to count the number of 0s, 1s, and 2s.
   
2. **Modify the linked list**:
   - Traverse the linked list again, filling the nodes with 0s, 1s, and 2s based on the counts.

This approach makes two passes through the list:
- **First pass**: Count occurrences.
- **Second pass**: Modify the nodes to reorder them.

Time Complexity:
- **O(n)**: We traverse the linked list twice, once to count and once to modify the list.
  - First traversal takes O(n).
  - Second traversal also takes O(n).
  - Overall complexity is O(n).

Space Complexity:
- **O(1)**: Only a constant amount of extra space is used for the counting variables.

*/

class Solution {
  public:
    // Function to sort a linked list of 0s, 1s, and 2s.
    Node* segregate(Node* head) {
        // Initialize counters for 0s, 1s, and 2s
        int cnt0 = 0, cnt1 = 0, cnt2 = 0;

        // First traversal to count occurrences of 0s, 1s, and 2s
        Node* temp = head;
        while (temp) {
            if (temp->data == 0) 
                cnt0++;
            else if (temp->data == 1)
                cnt1++;
            else
                cnt2++;
            
            temp = temp->next; // Move to the next node
        }
        
        // Second traversal to update the linked list based on counts
        temp = head;
        while (temp) {
            if (cnt0) {
                temp->data = 0; // Set node data to 0
                cnt0--;         // Decrement 0 counter
            }
            else if (cnt1) {
                temp->data = 1; // Set node data to 1
                cnt1--;         // Decrement 1 counter
            }
            else {
                temp->data = 2; // Set node data to 2
                cnt2--;         // Decrement 2 counter
            }
                
            temp = temp->next;  // Move to the next node
        }
        
        return head; // Return the head of the modified list
    }
};


/*
Approach:
1. **Create dummy nodes for three separate lists (0s, 1s, and 2s)**:
   - We create three dummy nodes to keep track of the start of the lists for nodes with values 0, 1, and 2.
   - As we traverse the original list, we attach nodes to the corresponding list (0, 1, or 2) based on their values.

2. **Combine the three lists**:
   - After segregating the nodes, we connect the list of 0s to the list of 1s (if it exists), and then connect the list of 1s to the list of 2s.

3. **Return the new head of the sorted list**:
   - The head of the sorted list is the first node in the 0s list, which is `zeroHead->next`.

Time Complexity:
- **O(n)**: We traverse the linked list once to separate the nodes and then adjust pointers to merge the lists. This takes linear time.

Space Complexity:
- **O(1)**: We are only using a constant amount of extra space for dummy nodes and pointers, regardless of the input size.

*/

class Solution {
  public:
    // Function to sort a linked list of 0s, 1s, and 2s.
    Node* segregate(Node* head) {
        // Dummy nodes for lists of 0s, 1s, and 2s
        Node* zeroHead = new Node(-1);
        Node* zero = zeroHead;
        
        Node* oneHead = new Node(-1);
        Node* one = oneHead;
        
        Node* twoHead = new Node(-1);
        Node* two = twoHead;
        
        // Traverse the original linked list
        while (head) {
            if (head->data == 0) {
                // Attach node to 0s list
                zero->next = head;
                zero = zero->next;
            } else if (head->data == 1) {
                // Attach node to 1s list
                one->next = head;
                one = one->next;
            } else {
                // Attach node to 2s list
                two->next = head;
                two = two->next;
            }
            head = head->next; // Move to the next node
        }
        
        // Connect the three lists: 0s -> 1s -> 2s
        zero->next = oneHead->next == NULL ? twoHead->next : oneHead->next;
        one->next = twoHead->next;
        two->next = NULL;  // Terminate the list
        
        // The head of the new sorted list is zeroHead->next
        head = zeroHead->next;
        
        // Clean up dummy nodes
        delete zeroHead;
        delete oneHead;
        delete twoHead;
        
        return head; // Return the head of the sorted list
    }
};
