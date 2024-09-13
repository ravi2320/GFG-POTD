/*
Search in Linked List
Difficulty: EasyAccuracy: 65.4%Submissions: 52K+Points: 2
Given a linked list of n nodes and a key , the task is to check if the key is present in the linked list or not.

Example:

Input:
n = 4
1->2->3->4
Key = 3
Output:
True
Explanation:
3 is present in Linked List, so the function returns true.
Your Task:
Your task is to complete the given function searchKey(), which takes a head reference and key as Input and returns true or false boolean value by checking the key is present or not in the linked list.

Constraint:
1 <= n <= 105
1 <= key <= 105

Expected Time Complexity: O(n)
Expected Space Complexity: O(1)
*/

/*
Approach:
1. The task is to search for a given key in a singly linked list.
2. We will iterate through the linked list starting from the head node.
3. For each node, we will check if the `data` field matches the key.
4. If we find a match, we return `true`. If we reach the end of the list without finding the key, we return `false`.

Time Complexity:
- O(n): We may have to traverse the entire linked list of `n` nodes in the worst case.

Space Complexity:
- O(1): Only a constant amount of extra space is used for storing pointers and variables.

*/

class Solution {
  public:
    // Function to search for a key in a linked list.
    bool searchKey(int n, struct Node* head, int key) {
        // Iterate through the linked list until we reach the end.
        while (head) {
            // If the current node's data matches the key, return true.
            if (head->data == key) {
                return true;
            }
            head = head->next;  // Move to the next node in the list.
        }
        // If the key was not found, return false.
        return false;
    }
};
