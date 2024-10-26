/*
Occurence of an integer in a Linked List
Difficulty: EasyAccuracy: 80.07%Submissions: 74K+Points: 2
Given a singly linked list and a key, count the number of occurrences of the given key in the linked list.

Examples:

Input: Linked List: 1->2->1->2->1->3->1, key = 1

Output: 4
Explanation: 1 appears 4 times. 
Input: Linked List: 1->2->1->2->1, key = 3

Output: 0
Explanation: 3 appears 0 times.
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ number of nodes, key ≤ 105
1 ≤ data of node ≤ 105
*/

/*
Approach:
1. Traverse the linked list from the head to the end.
2. Maintain a counter `cnt` initialized to 0.
3. For each node, check if its data matches the given key.
   - If it matches, increment the counter.
4. Once the traversal is complete, return the counter as the result.

Time Complexity: O(n), where `n` is the number of nodes in the linked list.
Space Complexity: O(1), as we are only using a single integer for counting.
*/

class Solution {
  public:
    int count(struct Node* head, int key) {
        // Initialize the counter for occurrences of the key
        int cnt = 0;

        // Traverse through the linked list
        while (head) {
            // Check if the current node's data matches the key
            if (head->data == key)
                cnt++;
            
            // Move to the next node
            head = head->next;
        }

        // Return the count of nodes with data equal to the key
        return cnt;
    }
};
