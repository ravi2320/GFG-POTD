/*
Sort a k sorted doubly linked list
Difficulty: EasyAccuracy: 67.12%Submissions: 6K+Points: 2
Given a doubly linked list, each node is at most k-indices away from its target position. The problem is to sort the given doubly linked list. The distance can be assumed in either of the directions (left and right).

Examples :

Input: Doubly Linked List : 3 <-> 2 <-> 1 <-> 5 <-> 6 <-> 4 , k = 2
Output: 1 <-> 2 <-> 3 <-> 4 <-> 5 <-> 6

Explanation: After sorting the given 2-sorted list is 1 <-> 2 <-> 3 <-> 4 <-> 5 <-> 6.
Input: Doubly Linked List : 5 <-> 6 <-> 7 <-> 3 <-> 4 <-> 4 , k = 3
Output: 3 <-> 4 <-> 4 <-> 5 <-> 6 <-> 7

Explanation: After sorting the given 3-sorted list is 3 <-> 4 <-> 4 <-> 5 <-> 6 <-> 7.
Expected Time Complexity: O(n*logk)
Expected Auxiliary Space: O(k)
Constraints:
1 <= number of nodes <= 105
1 <= k < number of nodes
1 <= node->data <= 109
*/

/*
Approach:
- The problem is to sort a k-sorted doubly linked list, where every node is at most k positions away from its correct sorted position.
- A priority queue (min-heap) is used to sort the list:
  1. Traverse the list and maintain a min-heap of size `k+1`.
  2. As we traverse, for each node, we push the node's data into the heap.
  3. Once the heap reaches a size of `k+1`, we extract the minimum element (top of the heap) and assign it to the current node in the sorted list.
  4. After processing all nodes in the list, if there are still elements in the heap, we assign the remaining elements to the list.
  
Time Complexity:
- O(N log k), where N is the number of nodes in the doubly linked list and k is the distance a node can be from its sorted position. Each insertion and extraction from the heap takes O(log k) time.

Space Complexity:
- O(k), due to the space used by the heap to store `k+1` elements.

*/

class Solution {
public:
    // Function to sort a k-sorted doubly linked list
    DLLNode *sortAKSortedDLL(DLLNode *head, int k) {
        // Initialize two pointers: temp1 for traversing, temp2 for modifying the list
        DLLNode *temp1 = head; 
        DLLNode *temp2 = head;

        // Min-heap to store the node values within the range of k+1 elements
        priority_queue<int, vector<int>, greater<int>> pq;

        // Traverse the list, pushing values into the heap
        while (temp1) {
            pq.push(temp1->data);  // Push current node's data into the heap
            
            // If heap size exceeds k+1, pop the smallest element and assign it to the sorted list
            if (pq.size() == k + 1) {
                temp2->data = pq.top();  // Assign the smallest element to temp2
                pq.pop();  // Remove the smallest element from the heap
                temp2 = temp2->next;  // Move temp2 to the next node in the list
            }
            
            temp1 = temp1->next;  // Move temp1 to the next node in the list
        }

        // After traversing the list, process the remaining elements in the heap
        while (!pq.empty()) {
            temp2->data = pq.top();  // Assign the remaining smallest elements to the list
            pq.pop();  // Remove the element from the heap
            temp2 = temp2->next;  // Move to the next node
        }

        // Return the head of the sorted doubly linked list
        return head;
    }
};
