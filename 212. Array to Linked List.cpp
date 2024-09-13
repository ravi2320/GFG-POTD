/*
Array to Linked List
Difficulty: EasyAccuracy: 66.76%Submissions: 46K+Points: 2
Given an array of integer arr. Your task is to construct the linked list from arr & return the head of the linked list.

Examples:

Input: arr = [1, 2, 3, 4, 5]
Output: LinkedList: 1->2->3->4->5
Explanation: Linked list for the given array will be

Input: arr = [2, 4, 6, 7, 5, 1, 0]
Output: LinkedList: 2->4->6->7->5->1->0
Explanation: Linked list for the given array will be

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(n)

Constraints:
1 <= arr.size() <= 106
1 <= arr[i] <= 106
*/

/*
Approach:
1. The task is to construct a singly linked list from a given array of integers.
2. We will start by creating the head node using the first element of the array.
3. Then, we will iterate over the array, and for each subsequent element, create a new node and link it to the current node.
4. Continue this process until all elements of the array are added to the linked list.

Time Complexity:
- O(n): We traverse the entire array of size `n` and create a corresponding linked list node for each element.

Space Complexity:
- O(n): We create `n` nodes for the linked list, where `n` is the size of the array.

*/

class Solution {
  public:
    Node* constructLL(vector<int>& arr) {
        int n = arr.size();
        if (n == 0) return NULL;  // If the array is empty, return NULL.
        
        // Step 1: Create the head of the linked list using the first element.
        Node* head = new Node(arr[0]);
        Node* curr = head;

        // Step 2: Iterate over the rest of the array and create the linked list.
        for (int i = 1; i < n; i++) {
            curr->next = new Node(arr[i]);  // Create a new node for arr[i].
            curr = curr->next;              // Move the current pointer to the newly created node.
        }
        
        return head;  // Return the head of the constructed linked list.
    }
};
