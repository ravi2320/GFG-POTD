/*
Stack using Linked List
Difficulty: EasyAccuracy: 53.98%Submissions: 159K+Points: 2
Let's give it a try! You have a linked list and must implement the functionalities push and pop of stack using this given linked list. Your task is to use the class as shown in the comments in the code editor and complete the functions push() and pop() to implement a stack. 
The push() method takes one argument, an integer 'x' to be pushed into the stack and pop() which returns an integer present at the top and popped out from the stack. If the stack is empty then return -1 from the pop() method.
Note: The input is given in the form of queries. Since there are two operations push() and pop(), there is two types of queries as described below:
(i) 1   (a query of this type takes x as another parameter and pushes it into the stack)
(ii) 2  (a query of this type means to pop an element from the stack and return the popped element)
Input is separated by space and as described above. 

Examples :

Input: [[1,2], [1,3], [2], [1,4], [2]]
Output: [3, 4]
Explanation: 
push(2)  : the stack will be {2}
push(3)  : the stack will be {2 3}
pop()    : poped element will be 3,the stack will be {2}
push(4)  : the stack will be {2 4}
pop()    : poped element will be 4
Input: [[2], [1,4], [1,5], [2]]
Output: [-1, 4]
Explanation: 
pop()    : the stack is empty so its -1.
push(4)  : the stack will be {4}
push(5)  : the stack will be {4 5}
pop()    : poped element will be 5, the stack will be {4}
Expected Time Complexity: O(1)
Expected Auxillary Space: O(1)

Constraints:
1 <= numbers of calls made to push, pop <= 100
1 <= x <= 100
*/

/*
Approach:
1. A stack is implemented using a linked list where each node contains a data value and a pointer to the next node.
2. The `top` pointer indicates the top element of the stack.
3. Functions:
   - `push(int x)`: Inserts a new element at the top of the stack by creating a new node and updating the `top` pointer.
   - `pop()`: Removes the top element from the stack and updates the `top` pointer. If the stack is empty, it returns -1.
   - `MyStack()`: Constructor that initializes the `top` to `NULL`, indicating an empty stack.

Time Complexity:
- `push(int x)`: O(1) — Inserting at the beginning of the list.
- `pop()`: O(1) — Removing the top element from the list.

Space Complexity:
- O(n) — Where `n` is the number of elements in the stack due to the storage of nodes in the linked list.

*/

class MyStack {
private:
    // StackNode structure to represent each node in the stack
    struct StackNode {
        int data;          // Data value stored in the node
        StackNode *next;   // Pointer to the next node

        // Constructor to initialize a new node with data
        StackNode(int x) : data(x), next(nullptr) {}
    };
    
    StackNode *top; // Pointer to the top element of the stack

public:
    // Constructor to initialize the stack
    MyStack() {
        top = nullptr; // Initially, the stack is empty
    }

    // Function to push a new element onto the stack
    void push(int x) {
        // Create a new node with the given value
        StackNode* node = new StackNode(x);
        
        // Link the new node to the current top
        node->next = top;
        
        // Update the top to the new node
        top = node;
    }

    // Function to pop the top element from the stack
    int pop() {
        // If the stack is empty, return -1
        if (!top) return -1;
        
        // Temporarily store the current top node
        StackNode *temp = top;
        
        // Update the top to the next node
        top = top->next;
        
        // Get the data from the popped node
        int data = temp->data;
        
        // Delete the popped node to free memory
        delete temp;
        
        // Return the data of the popped node
        return data;
    }
};
