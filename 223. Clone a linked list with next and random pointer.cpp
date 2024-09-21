/*
Clone a linked list with next and random pointer
Difficulty: HardAccuracy: 64.8%Submissions: 80K+Points: 8
You are given a special linked list where each node has a next pointer pointing to its next node. You are also given some random pointers, where you will be given some pairs denoting two nodes a and b i.e. a->random = b (random is a pointer to a random node).

Construct a copy of the given list. The copy should consist of the same number of new nodes, where each new node has its value set to the value of its corresponding original node. Both the next and random pointer of the new nodes should point to new nodes in the copied list such that the original and copied list pointers represent the same list state. None of the pointers in the new list should point to nodes in the original list.

For example, if there are two nodes x and y in the original list, where x->random = y, then for the corresponding two nodes xnew and ynew in the copied list, xnew->random = ynew.

Return the head of the copied linked list.

NOTE : 
1. If there is any node whose arbitrary pointer is not given then it's by default NULL. 
2. Don't make any changes to the original linked list.

ArbitLinked List1

Note: The diagram isn't part of any example, it just depicts an example of how the linked list may look.

Examples:

Input: LinkedList: 1->2->3->4 , pairs = [{1,2},{2,4}]
Output: true
Explanation: In this test case, there are 4 nodes in linked list.  Among these 4 nodes,  2 nodes have arbitrary pointer set, rest two nodes have arbitrary pointer as NULL. Second line tells us the value of four nodes. The third line gives the information about arbitrary pointers. The first node arbitrary pointer is set to node 2.  The second node arbitrary pointer is set to node 4.
Input: LinkedList: 1->3->5->9 , pairs[] = [{1,1},{3,4}]
Output: true
Explanation: In the given testcase, applying the method as stated in the above example, the output will be 1.
Expected Time Complexity: O(n)
Expected Auxilliary Space: O(1)

Constraints:
1 <= numbers of random pointer <= number of nodes <= 100
0 <= node->data <= 1000
1 <= a, b <= 100
*/

/*
Approach:
1. **Check for empty list**: 
   - If the head is null or only one node exists, return the head.

2. **Create a mapping for nodes**:
   - Use an unordered map to store the mapping of original node values to new nodes.
   - Iterate through the original list, creating a new node for each unique node and storing it in the map.

3. **Construct the new list**:
   - Reset the temp pointer to the head of the original list.
   - Initialize pointers for the new list (`newHead` and `curr`).
   - Traverse the original list again:
     - For each node, set the next pointer of the corresponding new node.
     - Also set the random pointer if it exists using the mapping from the unordered map.

4. **Return the new head**:
   - Finally, return the head of the newly created list.

Time Complexity:
- **O(n)**: We traverse the list twice. The first traversal creates new nodes, and the second traversal sets the next and random pointers.

Space Complexity:
- **O(n)**: We use an unordered map to store the mapping of original nodes to their copies.

*/

class Solution {
  public:
    Node *copyList(Node *head) {
        // Return if the list is empty or has only one node
        if (!head || !head->next) return head;
        
        unordered_map<int, Node*> mp; // To store original to copied node mapping
        Node* temp = head;
        
        // Create copies of nodes and store in the map
        mp[temp->data] = new Node(temp->data);
        
        while (temp) {
            if (temp->next) {
                mp[temp->next->data] = new Node(temp->next->data);
            }
            temp = temp->next; // Move to the next node
        }
        
        temp = head; // Reset temp to the head of the original list
        Node *curr = NULL, *newHead = NULL; // Pointers for new list
        
        while (temp) {
            if (!newHead) { // Initialize newHead and curr
                newHead = mp[temp->data];
                if (temp->next) newHead->next = mp[temp->next->data];
                if (temp->random) newHead->random = mp[temp->random->data];
                curr = newHead;
            } else { // Set next and random pointers for subsequent nodes
                if (temp->next) curr->next = mp[temp->next->data];
                if (temp->random) curr->random = mp[temp->random->data];
            }
            temp = temp->next; // Move to the next node
            curr = curr->next; // Move curr to the next node in the new list
        }
        
        return newHead; // Return the head of the copied list
    }
};


/*
Approach:
1. **Interweaving Original and Copy**:
   - Traverse the original list and create a copy of each node.
   - Insert the copied nodes directly after their corresponding original nodes.
   - This results in a list that looks like: original -> copy -> original -> copy ...

2. **Setting Random Pointers**:
   - Traverse the modified list again.
   - For each original node, set the random pointer of the copied node to point to the copied version of the original node's random pointer.

3. **Separating the Lists**:
   - Finally, traverse the list a third time to separate the original and copied nodes.
   - Restore the original list while also forming the new list of copied nodes.

Time Complexity:
- **O(n)**: Each node is visited three times (once for copying, once for setting random pointers, and once for separating the lists).

Space Complexity:
- **O(1)**: We only use a few extra pointers, and the space used for the copied nodes is part of the original list structure.

*/

class Solution {
  public:
    Node *copyList(Node *head) {
        // Return if the list is empty
        if (!head) return NULL;

        Node* curr = head;
        
        // Step 1: Create a copy of each node and interweave it with the original nodes
        while (curr) {
            Node* temp = new Node(curr->data);
            temp->next = curr->next; // Point the new node to the next original node
            curr->next = temp; // Link the original node to its copy
            curr = temp->next; // Move to the next original node
        }
        
        curr = head; // Reset to the head of the original list
        
        // Step 2: Set the random pointers for the copied nodes
        while (curr) {
            curr->next->random = curr->random ? curr->random->next : NULL;
            curr = curr->next->next; // Move to the next original node
        }
        
        curr = head; // Reset to the head of the original list
        Node *cloneHead = head->next; // Head of the copied list
        Node *clone = cloneHead; // Pointer for the copied nodes
        
        // Step 3: Separate the two lists
        while (clone) {
            curr->next = curr->next->next; // Restore the original list
            if (clone->next)
                clone->next = clone->next->next; // Move to the next copied node
            
            curr = curr->next; // Move to the next original node
            clone = clone->next; // Move to the next copied node
        }
        
        return cloneHead; // Return the head of the copied list
    }
};
