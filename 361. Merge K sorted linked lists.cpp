/*
Merge K sorted linked lists
Difficulty: MediumAccuracy: 57.01%Submissions: 92K+Points: 4Average Time: 60m
Given an array arr[] of n sorted linked lists of different sizes. The task is to merge them in such a way that after merging they will be a single sorted linked list, then return the head of the merged linked list.

Examples:

Input: arr[] = [1 -> 2 -> 3, 4 -> 5, 5 -> 6, 7 -> 8]
Output: 1 -> 2 -> 3 -> 4 -> 5 -> 5 -> 6 -> 7 -> 8
Explanation:
The arr[] has 4 sorted linked list of size 3, 2, 2, 2.
1st list: 1 -> 2-> 3
2nd list: 4 -> 5
3rd list: 5 -> 6
4th list: 7 -> 8
The merged list will be:
 
Input: arr[] = [1 -> 3, 8, 4 -> 5 -> 6]
Output: 1 -> 3 -> 4 -> 5 -> 6 -> 8
Explanation:
The arr[] has 3 sorted linked list of size 2, 3, 1.
1st list: 1 -> 3
2nd list: 8
3rd list: 4 -> 5 -> 6
The merged list will be:

Constraints
1 <= total no. of nodes <= 105
1 <= node->data <= 103
*/

/**
 * Approach:
 * - Use a **min-heap (priority queue)** to efficiently merge `K` sorted linked lists.
 * - Insert the head of each linked list into the priority queue.
 * - Extract the smallest element, attach it to the merged list, and insert its next node.
 * - Continue until the heap is empty.
 *
 * Intuition:
 * - A min-heap ensures that we always extract the **smallest element** among the heads of the lists.
 * - This avoids unnecessary comparisons and results in an **O(N log K)** time complexity.
 * - Using a dummy node simplifies edge cases for linked list merging.
 *
 * Time Complexity:
 * - **O(N log K)**: Each node is pushed and popped once from the heap (`log K` operations per node).
 *
 * Space Complexity:
 * - **O(K)**: The priority queue stores at most `K` elements at any time.
 */

struct compareNode {
    bool operator()(Node* a, Node* b) {
        return a->data > b->data; // Min-heap based on node values
    }
};

class Solution {
public:
    Node* mergeKLists(vector<Node*>& arr) {
        int n = arr.size();
        priority_queue<Node*, vector<Node*>, compareNode> pq;

        // Insert the head of each linked list into the min-heap
        for (int i = 0; i < n; i++) {
            if (arr[i]) {
                pq.push(arr[i]);
            }
        }

        // Dummy node to simplify list merging
        Node* head = new Node(0);
        Node* curr = head;

        // Process the heap until all nodes are merged
        while (!pq.empty()) {
            Node* node = pq.top();
            pq.pop();

            curr->next = node;
            curr = curr->next;

            if (node->next) {
                pq.push(node->next);
            }
        }

        return head->next; // Return the merged list without the dummy node
    }
};