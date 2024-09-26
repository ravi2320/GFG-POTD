/*
Flattening a Linked List
Difficulty: MediumAccuracy: 51.53%Submissions: 159K+Points: 4
Given a Linked List, where every node represents a sub-linked-list and contains two pointers:
(i) a next pointer to the next node,
(ii) a bottom pointer to a linked list where this node is head.
Each of the sub-linked lists is in sorted order.
Flatten the Link List so all the nodes appear in a single level while maintaining the sorted order.

Note: The flattened list will be printed using the bottom pointer instead of the next pointer. Look at the printList() function in the driver code for more clarity.

Examples:

Input:

Output:  5-> 7-> 8- > 10 -> 19-> 20-> 22-> 28-> 30-> 35-> 40-> 45-> 50.
Explanation: The resultant linked lists has every node in a single level.(Note: | represents the bottom pointer.)
Input:
 
Output: 5-> 7-> 8-> 10-> 19-> 22-> 28-> 30-> 50
Explanation: The resultant linked lists has every node in a single level.(Note: | represents the bottom pointer.)
Note: In the output section of the above examples, the -> represents the bottom pointer.

Expected Time Complexity: O(n * n * m)
Expected Auxiliary Space: O(n)

Constraints:
0 <= number of nodes <= 50
1 <= no. of nodes in sub-LinkesList(mi) <= 20
1 <= node->data <= 103
*/

/*
 * Approach:
 * 1. Traverse the entire 2D linked list (where each node has a `next` and a `bottom` pointer).
 * 2. Collect all the values from the nodes into a vector.
 * 3. Sort the vector to arrange the values in ascending order.
 * 4. Create a new flattened linked list using the sorted values, with each node linked using the `bottom` pointer.
 * 5. Return the head of the newly created flattened linked list.
 * 
 * Time Complexity: O(N log N), where N is the total number of nodes in the 2D linked list. This is due to the sorting step.
 * Space Complexity: O(N), to store all the node values in the vector.
 */

class Solution {
public:
    // Function which returns the root of the flattened linked list.
    Node* flatten(Node* root) {
        vector<int> arr;          // Vector to store the values of all nodes
        Node* temp = root;        // Pointer to traverse the main linked list

        // Traverse the 2D linked list and collect all values
        while (temp) {
            Node* t2 = temp;
            // Traverse the bottom list for each node in the main list
            while (t2) {
                arr.push_back(t2->data);  // Collect the value of the current node
                t2 = t2->bottom;          // Move to the next node in the bottom list
            }
            temp = temp->next;            // Move to the next node in the main list
        }

        // Sort the collected values
        sort(arr.begin(), arr.end());

        // Create a new linked list from the sorted values
        Node* head = new Node(arr[0]);  // Initialize the head with the first value
        temp = head;
        int n = arr.size();

        // Build the flattened list using the sorted values
        for (int i = 1; i < n; i++) {
            temp->bottom = new Node(arr[i]);  // Link the nodes using the bottom pointer
            temp = temp->bottom;              // Move to the next node in the list
        }

        return head;  // Return the head of the flattened list
    }
};


/*
 * Approach:
 * 1. Use a recursive approach to flatten the linked list by merging two lists at a time.
 * 2. Define a helper function `mergeList` to merge two sorted linked lists where nodes are connected via the `bottom` pointer.
 * 3. Recursively flatten the main list by processing the `next` pointers.
 * 4. Merge the current node's bottom list with the flattened list from the rest of the main list.
 * 
 * Time Complexity: O(N), where N is the total number of nodes in the list. Each node is processed once.
 * Space Complexity: O(1) for merging and O(N) for recursion stack space due to the recursive approach.
 */

class Solution {
public:
    // Helper function to merge two sorted linked lists using bottom pointers
    Node* mergeList(Node* l1, Node* l2) {
        // Create a dummy node to ease the merging process
        Node* dummyNode = new Node(-1);
        Node* res = dummyNode;

        // Merge the two lists while both have nodes remaining
        while (l1 && l2) {
            if (l1->data < l2->data) {
                l1->next = NULL;        // Break the `next` link to ensure only `bottom` is used
                res->bottom = l1;       // Attach l1's node to the result
                l1 = l1->bottom;        // Move to the next node in l1
            } else {
                l2->next = NULL;        // Break the `next` link to ensure only `bottom` is used
                res->bottom = l2;       // Attach l2's node to the result
                l2 = l2->bottom;        // Move to the next node in l2
            }
            res = res->bottom;          // Move the result pointer forward
        }

        // Attach the remaining nodes of l1 or l2, if any
        if (l1) res->bottom = l1;
        else res->bottom = l2;

        return dummyNode->bottom;       // Return the merged list starting from the first real node
    }

    // Function to flatten the linked list
    Node* flatten(Node* root) {
        // Base case: if the list is empty or has only one row, return it
        if (!root || !root->next) {
            return root;
        }

        // Recursively flatten the rest of the list beyond the current node
        Node* mergeHead = flatten(root->next);

        // Merge the current node's bottom list with the flattened list obtained from recursion
        root = mergeList(root, mergeHead);

        return root;  // Return the root of the fully flattened list
    }
};
