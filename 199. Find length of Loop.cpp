/*
Find length of Loop
Difficulty: EasyAccuracy: 44.26%Submissions: 182K+Points: 2
Given the head of a linked list, determine whether the list contains a loop. If a loop is present, return the number of nodes in the loop, otherwise return 0.



Note: 'c' is the position of the node which is the next pointer of the last node of the linkedlist. If c is 0, then there is no loop.

Examples:

Input: LinkedList: 25->14->19->33->10->21->39->90->58->45, c = 4
Output: 7
Explanation: The loop is from 33 to 45. So length of loop is 33->10->21->39-> 90->58->45 = 7. 
The number 33 is connected to the last node of the linkedlist to form the loop because according to the input the 4th node from the beginning(1 based indexing) 
will be connected to the last node for the loop.
 
Input: LinkedList: 5->4, c = 0
Output: 0
Explanation: There is no loop.

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)

Constraints:
1 <= no. of nodes <= 106
0 <= node.data <=106
0 <= c<= n-1
*/

/*
**Intuition:**
In a linked list, if a loop exists, it can be detected using two pointers moving at different speeds (slow and fast). Once a loop is detected, counting the number of nodes in the loop can be done by traversing the loop with one pointer until it meets the starting point again.

**Approach:**
1. **Detect Loop:**
   - Initialize two pointers, `slow` and `fast`, both starting from the head.
   - Move `slow` by one step and `fast` by two steps.
   - If they meet, a loop exists; otherwise, if `fast` reaches the end (`NULL`), no loop exists.

2. **Count Loop Nodes:**
   - After detecting a loop, keep `fast` stationary and move `slow` one step at a time.
   - Count the number of steps it takes for `slow` to meet `fast` again, which gives the number of nodes in the loop.

**Time Complexity:** O(N), where N is the number of nodes in the linked list.
**Space Complexity:** O(1), as no extra space is used apart from pointers.
*/

class Solution {
  public:
    // Function to find the length of a loop in the linked list.
    int countNodesinLoop(Node *head) {
        Node* slow = head;
        Node* fast = head;

        // Detecting the loop using Floyd's Cycle-Finding Algorithm
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            // Loop detected
            if (slow == fast) {
                int cnt = 1;
                slow = slow->next;

                // Counting the number of nodes in the loop
                while (slow != fast) {
                    slow = slow->next;
                    cnt++;
                }
                return cnt;
            }
        }

        // No loop found
        return 0;
    }
};

// Example usage:
int main() {
    // Creating a linked list with a loop
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = head->next; // Creating a loop

    Solution sol;
    int loopLength = sol.countNodesinLoop(head);

    // Expected Output: 3 (The loop contains 3 nodes)
    std::cout << "Length of the loop is: " << loopLength << std::endl;

    return 0;
}
