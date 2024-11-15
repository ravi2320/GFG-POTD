/*
Queue using Linked List
Difficulty: BasicAccuracy: 45.6%Submissions: 129K+Points: 1
Implement a Queue using Linked List. 
A Query Q is of 2 Types
(i) 1 x   (a query of this type means  pushing 'x' into the queue)
(ii) 2     (a query of this type means to pop an element from the queue and print the poped element)

Example 1:

Input:
Q = 5
Queries = 1 2 1 3 2 1 4 2
Output: 2 3
Explanation: n the first testcase
1 2 the queue will be {2}
1 3 the queue will be {2 3}
2   poped element will be 2 the
    queue will be {3}
1 4 the queue will be {3 4}
2   poped element will be 3.

Example 2:

Input:
Q = 4
Queries = 1 2 2 2 1 3 
Output: 2 -1
Explanation: In the second testcase 
1 2 the queue will be {2}
2   poped element will be {2} then
    the queue will be empty. 
2   the queue is empty and hence -1
1 3 the queue will be {3}.
Your Task:
Complete the function push() which takes an integer as input parameter and pop() which will remove and return an element(-1 if queue is empty).

Expected Time Complexity: O(1).
Expected Auxiliary Space: O(1).

Constraints:
1 <= Q <= 100
1 <= x <= 100
*/

/*
Approach:
1. **Push Operation**:
   - To add an element to the queue, create a new node with the given value.
   - If the queue is empty (i.e., `rear` is `NULL`), set both `front` and `rear` to point to the new node.
   - If the queue is not empty, link the current `rear` node's `next` to the new node and update the `rear` pointer.

2. **Pop Operation**:
   - To remove an element from the front, check if the queue is empty (i.e., `front` is `NULL`). If it's empty, return -1.
   - If not, save the `front` node's data and move the `front` pointer to the next node.
   - If the queue becomes empty after the pop operation (i.e., `front` becomes `NULL`), set `rear` to `NULL` as well.
   - Delete the removed node and return the saved data.

Time Complexity:
- Push Operation: O(1) — Adding a new element at the end of the linked list.
- Pop Operation: O(1) — Removing an element from the beginning of the linked list.

Space Complexity:
- O(1) — Only using a few additional pointers for each operation.
*/

// Function to push an element `x` into the queue
void MyQueue::push(int x)
{
    // Create a new node with the value `x`
    QueueNode* newNode = new QueueNode(x);
    
    // If the queue is empty, initialize both front and rear to the new node
    if (!rear) {
        rear = newNode;
        front = newNode;
    }
    // If the queue is not empty, link the new node to the end of the queue and update rear
    else {
        rear->next = newNode;
        rear = rear->next;
    }
}

// Function to pop the front element from the queue and return its value
int MyQueue::pop()
{
    // If the queue is empty, return -1
    if (!front) return -1;
    
    // Save the data of the front node
    QueueNode* temp = front;
    front = front->next; // Move the front pointer to the next node
    int data = temp->data;
    
    // If the queue becomes empty after the pop, set rear to NULL
    if (!front) {
        rear = NULL;
    }
    
    // Delete the removed node and return the data
    delete temp;
    return data;
}
