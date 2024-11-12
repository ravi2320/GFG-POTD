/*
Queue Using Array
Difficulty: BasicAccuracy: 47.24%Submissions: 194K+Points: 1
Implement a Queue using an Array. Queries in the Queue are of the following type:
(i) 1 x   (a query of this type means  pushing 'x' into the queue)
(ii) 2     (a query of this type means to pop an element from the queue and print the popped element)

We just have to implement the functions push and pop and the driver code will handle the output.

Examples:

Input: Q = 5, Queries = 1 2 1 3 2 1 4 2
Output: 2 3
Explanation:
In the first test case for query 
1 2 the queue will be {2}
1 3 the queue will be {2 3}
2   poped element will be 2 the 
    queue will be {3}
1 4 the queue will be {3 4}
2   poped element will be 3 
Input: Q = 4, Queries = 1 3 2 2 1 4   
Output: 3 -1
Explanation:
In the second testcase for query 
1 3 the queue will be {3}
2   poped element will be 3 the
    queue will be empty
2   there is no element in the
    queue and hence -1
1 4 the queue will be {4}. 
Constraints:
1 ≤ Q ≤ 105
0 ≤ x ≤ 105
*/

/*
Approach:
1. `push(int x)`: Adds an element to the queue's rear if there is space. It uses modular arithmetic for circular wrapping.
2. `pop()`: Removes an element from the front if the queue is non-empty, returns the element, and advances the front index.
3. Circular wrapping is used to prevent the queue from reaching the array bounds by using `% 100005`.

Functions:
- `push(int x)`: Adds an element to the rear and updates the `rear` index.
- `pop()`: Removes and returns an element from the front, updating the `front` index.

Time Complexity:
- `push(int x)`: O(1) for a single insertion.
- `pop()`: O(1) for a single deletion.

Space Complexity: O(1), as it uses a fixed-size array.

*/

class MyQueue {
private:
    int arr[100005];
    int front;
    int rear;

public:
    MyQueue() { front = 0; rear = 0; }

    // Function to push an element x in the queue
    void push(int x) {
        if (front == (rear + 1) % 100005) return; // Queue full check
        arr[rear] = x; // Add element at rear
        rear = (rear + 1) % 100005; // Update rear position
    }

    // Function to pop an element from the queue and return that element
    int pop() {
        if (front == rear) return -1; // Queue empty check
        int ele = arr[front]; // Store front element
        front = (front + 1) % 100005; // Update front position
        return ele; // Return popped element
    }
};
