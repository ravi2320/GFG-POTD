/*
XOR Linked List
Difficulty: MediumAccuracy: 58.15%Submissions: 17K+Points: 4
An ordinary Doubly Linked List requires space for two address fields to store the addresses of previous and next nodes. A memory-efficient version of the Doubly Linked List can be created using only one space for the address field with every node. This memory-efficient Doubly Linked List is called XOR Linked List or Memory Efficient as the list uses bit-wise XOR operation to save space for one address.

Given a stream of data of size N for the linked list, your task is to complete the function insert() and getList(). The insert() function pushes (or inserts at the beginning) the given data in the linked list and the getList()  function returns the linked list as a list.

Note:

A utility function XOR() takes two Node pointers to get the bit-wise XOR of the two Node pointers. Use this function to get the XOR of the two pointers.
The driver code prints the returned list twice, once forward and once backwards.
Examples:

Input:
LinkedList: 9<->5<->4<->7<->3<->10

Output:
10 3 7 4 5 9
9 5 4 7 3 10
Input:
LinkedList: 58<->96<->31

Output:
31 96 58
58 96 31
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)

Constraints:
1 <= number of nodes, data of nodes <= 105
*/

/*
Approach:
1. **XOR Linked List**: 
   - In an XOR linked list, instead of storing a `next` pointer, each node stores the XOR of the previous and next node addresses.
   - The XOR of two pointers can be obtained using the provided `XOR` utility function.

2. **Insert Function**:
   - To insert at the front of the list, create a new node and set its `npx` to the current head.
   - If the list is not empty, update the `npx` of the current head to reflect the XOR of the new node and the old `npx` of the head.

3. **getList Function**:
   - Traverse the XOR linked list by maintaining a `prev` pointer and using the XOR operation to calculate the `next` pointer.
   - Collect the data values from each node and return them as a vector.

Time Complexity:
- **Insert**: O(1), since we only update the new node and the head node's `npx`.
- **getList**: O(n), where `n` is the number of nodes in the list, as we need to traverse through all nodes.

Space Complexity:
- **Insert**: O(1), constant space usage.
- **getList**: O(n), due to the vector that stores the node data.

*/

#include <vector>
#include <cstdint>

// Structure of the XOR linked list node
struct Node {
    int data;
    struct Node* npx;  // XOR of previous and next node

    Node(int x) {
        data = x;
        npx = NULL;
    }
};

// Utility function to get XOR of two Node pointers
struct Node* XOR (struct Node *a, struct Node *b) {
    return (struct Node*) ((uintptr_t) (a) ^ (uintptr_t) (b));
}

// Function to insert a new node at the front of the XOR linked list
struct Node* insert(struct Node *head, int data) {
    // Create a new node with the given data
    Node* temp = new Node(data);
    
    // Set the new node's npx to the current head
    temp->npx = head;
    
    // If the list is not empty, update the head's npx
    if(head) {
        head->npx = XOR(temp, head->npx);
    }
    
    // Return the new head of the list
    return temp;
}

// Function to get the list elements by traversing the XOR linked list
std::vector<int> getList(struct Node *head) {
    Node* curr = head;  // Current node
    Node* prev = NULL;  // Previous node (initially NULL)
    Node* next = NULL;  // Next node (calculated using XOR)
    std::vector<int> ans;  // Vector to store the result

    // Traverse the list until we reach the end
    while(curr) {
        ans.push_back(curr->data);  // Add the current node's data to the result

        // Calculate the next node using XOR of prev and curr->npx
        next = XOR(prev, curr->npx);

        // Move the prev and curr pointers one step forward
        prev = curr;
        curr = next;
    }
    
    return ans;  // Return the collected list elements
}
